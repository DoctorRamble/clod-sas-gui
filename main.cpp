// Uses C++20

#include "header.h"
#include "window.h"
#include <QApplication>
#include <string>
#include <vector>
#include <fstream>

std::string path;
std::string config_location;
std::string log_file_dir;
std::vector<std::string> config_contents;
std::vector<std::string> text_lines;

// argument variables for SAS
std::string steam_username;
std::string log_location;
std::string output_dir;
int _debugInfo;
int _playerConnectionInfo;
int _otherPlayerConnectionInfo;
int _sideSwitchInfo;
int _otherPlayerSideSwitchInfo;
int _newMissionLoadInfo;
int _newMissionInfo;
int _battleStartedInfo;
int _battleEndInfo;
int _destructionInfo;
int _destructionUnrelatedInfo;
int _landingInfo;
int _otherLandingInfo;
int _bailInfo;
int _otherBailInfo;
int _crashInfo;
int _otherCrashInfo;
int _otherPlayerStats;
int _showChat;
// Set by programme
std::string output_name = "";
// Unchangeable
int _outputFile = 1;
int _allInfo = 0;
int _colour = 0;
int _colourFG = 0;
int _headless = 1;

// Colours
std::string destruction_colour;
std::string bail_colour;
std::string sideSwitch_colour;
std::string startEnd_colour;
std::string missionInfo_colour;
std::string landing_colour;
std::string crash_colour;
std::string default_colour;

// Loads variables from "./config/config.txt"
void loadConfig();
// Gets value of a config line and returns it
// Removes the '=' and everything before it
std::string getConfVal(const std::string& conf_line);

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    // Set path
    std::string argv_str(argv[0]);
    path = argv_str.substr(0, argv_str.find_last_of("\\"));
    config_location = path + "\\config\\config.txt";

    // Load the config
    loadConfig();

    // Set Window
    Window window;

    window.show();

    return app.exec();
}

void loadConfig()
{

    // Opens config.txt
    std::fstream config(config_location, std::ios::in);
    // Writes each line in the config to config_lines
    std::string config_line; // Variable for holding each config line
    while (std::getline(config, config_line)) { config_contents.push_back(config_line); }
    // Closes config.txt
    config.close();

    // Set the variables
    steam_username = getConfVal(config_contents[0]);
    log_location = getConfVal(config_contents[1]);
    output_dir = getConfVal(config_contents[2]);
    _debugInfo = std::stoi(getConfVal(config_contents[3]));
    _playerConnectionInfo = std::stoi(getConfVal(config_contents[4]));
    _otherPlayerConnectionInfo = std::stoi(getConfVal(config_contents[5]));
    _sideSwitchInfo = std::stoi(getConfVal(config_contents[6]));
    _otherPlayerSideSwitchInfo = std::stoi(getConfVal(config_contents[7]));
    _newMissionLoadInfo = std::stoi(getConfVal(config_contents[8]));
    _newMissionInfo = std::stoi(getConfVal(config_contents[9]));
    _battleStartedInfo = std::stoi(getConfVal(config_contents[10]));
    _battleEndInfo = std::stoi(getConfVal(config_contents[11]));
    _destructionInfo = std::stoi(getConfVal(config_contents[12]));
    _destructionUnrelatedInfo = std::stoi(getConfVal(config_contents[13]));
    _landingInfo = std::stoi(getConfVal(config_contents[14]));
    _otherLandingInfo = std::stoi(getConfVal(config_contents[15]));
    _bailInfo = std::stoi(getConfVal(config_contents[16]));
    _otherBailInfo = std::stoi(getConfVal(config_contents[17]));
    _crashInfo = std::stoi(getConfVal(config_contents[18]));
    _otherCrashInfo = std::stoi(getConfVal(config_contents[19]));
    _otherPlayerStats = std::stoi(getConfVal(config_contents[20]));
    _showChat = std::stoi(getConfVal(config_contents[21]));
    // Colours
    default_colour = getConfVal(config_contents[22]);
    destruction_colour = getConfVal(config_contents[23]);
    bail_colour = getConfVal(config_contents[24]);
    sideSwitch_colour = getConfVal(config_contents[25]);
    startEnd_colour = getConfVal(config_contents[26]);
    missionInfo_colour = getConfVal(config_contents[27]);
    landing_colour = getConfVal(config_contents[28]);
    crash_colour = getConfVal(config_contents[29]);

    /* Example Colours:
     * ColourDefault=#000000
     * ColourDestruction=#cc0000
     * ColourBail=#0338a2
     * ColourSideSwitch=#018ca4
     * ColourStartEnd=#ef2929
     * ColourMissionInfo=#19521e
     * ColourLanding=#4e9a06
     * ColourCrash=#f64b00
    */
}

std::string getConfVal(const std::string& conf_line)
{
    std::string line = conf_line;
    size_t x = line.find_last_of("=");
    line = line.substr(x + 1);
    return line;
}
