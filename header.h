#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

void sas();

extern std::string path; // Programme Path
extern std::string config_location; // Location to config.txt
extern std::string log_file_dir;
extern std::vector<std::string> text_lines; // Holds each line to be outputted to the text box
extern std::vector<std::string> log_lines;
extern std::vector<std::string> formatted_log;

// SAS Argument Vars
extern std::string steam_username;
extern std::string log_location;
extern std::string output_dir;
extern int _debugInfo;
extern int _playerConnectionInfo;
extern int _otherPlayerConnectionInfo;
extern int _sideSwitchInfo;
extern int _otherPlayerSideSwitchInfo;
extern int _newMissionLoadInfo;
extern int _newMissionInfo;
extern int _battleStartedInfo;
extern int _battleEndInfo;
extern int _destructionInfo;
extern int _destructionUnrelatedInfo;
extern int _landingInfo;
extern int _otherLandingInfo;
extern int _bailInfo;
extern int _otherBailInfo;
extern int _crashInfo;
extern int _otherCrashInfo;
extern int _otherPlayerStats;
extern int _showChat;
// Set by programme
extern std::string output_name;
// Unchangeable
extern int _outputFile;
extern int _allInfo;
extern int _colour;
extern int _colourFG;
extern int _headless;

// Colours
extern std::string destruction_colour;
extern std::string bail_colour;
extern std::string sideSwitch_colour;
extern std::string startEnd_colour;
extern std::string missionInfo_colour;
extern std::string landing_colour;
extern std::string crash_colour;
extern std::string default_colour;

#endif // HEADER_H
