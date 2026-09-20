#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <cstdint>
#include <map>

#include <pugixml/pugixml.hpp>

#include "Utils/Misc.h"

// Program Details and Settings (Global)
class Config
{
public:
    Config() = delete;
    Config(const Config&) = delete;
    Config& operator= (const Config&) = delete;

    // Const
    static const char* APP_TITLE;
    static const char* APP_VERSION;
    static const char* APP_LOCALE;
    static const uint32_t WINDOW_WIDTH;
    static const uint32_t WINDOW_HEIGHT;
    static const float UI_MAX_SCALE;
    static const float UI_MIN_SCALE;
    static const char* GITHUB_URL;
    static const char* DOCS_URL;

    // Variable
    static float UI_SCALE;

    static void load();
    static void save();

    // Small persisted UI flags: collapsed sections, chosen workflow, and so on.
    // ImGui already persists window geometry and docking to imgui.ini, and the
    // scale lives above, but tree node state is in-memory only.
    static int getUIState(const std::string& key, int defaultValue);
    static void setUIState(const std::string& key, int value);
    static float getUIFloat(const std::string& key, float defaultValue);
    static void setUIFloat(const std::string& key, float value);
    static std::string getUIString(const std::string& key, const std::string& defaultValue);
    static void setUIString(const std::string& key, const std::string& value);

private:
    static std::string CFG_FILENAME;
    static std::map<std::string, std::string> UI_STATE;

};
