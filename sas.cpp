#include "header.h"
#include <cstdlib>
#include <chrono>
#include <fstream>

// Gets the current date and time and turns it into a string
std::string getDateTime();
// Stores the command to run
std::string command;
// Opens the parsed log file and copies its data to log_lines
void openLog();
// Formats the log file and puts it into formatted_log
void formatLog();
// Stores the data from the opened log
std::vector<std::string> log_lines;
// Stores the data of the formatted log
std::vector<std::string> formatted_log;
// Adds debug info
void debugInfo();

// Main Programme Function
// Calls SAS
// Opens the parsed log and reads it
// Puts the log into text_lines and formats it using HTML
void sas()
{
    // Clear text
    log_lines.clear();
    formatted_log.clear();
    text_lines.clear();
    
    // Creates the file name
    output_name = getDateTime();

    // Creates the command string
    command = "sas.lnk ";
    command = command + "\"" + steam_username + "\" "
        + "\"" + log_location + "\" "
        + "\"" + output_dir + "\" "
        + "\"" + output_name + "\" "
        + "\"" + std::to_string(_outputFile) + "\" "
        + "\"" + std::to_string(_debugInfo) + "\" "
        + "\"" + std::to_string(_allInfo) + "\" "
        + "\"" + std::to_string(_playerConnectionInfo) + "\" "
        + "\"" + std::to_string(_otherPlayerConnectionInfo) + "\" "
        + "\"" + std::to_string(_sideSwitchInfo) + "\" "
        + "\"" + std::to_string(_otherPlayerSideSwitchInfo) + "\" "
        + "\"" + std::to_string(_newMissionLoadInfo) + "\" "
        + "\"" + std::to_string(_newMissionInfo) + "\" "
        + "\"" + std::to_string(_battleStartedInfo) + "\" "
        + "\"" + std::to_string(_battleEndInfo) + "\" "
        + "\"" + std::to_string(_destructionInfo) + "\" "
        + "\"" + std::to_string(_destructionUnrelatedInfo) + "\" "
        + "\"" + std::to_string(_landingInfo) + "\" "
        + "\"" + std::to_string(_otherLandingInfo) + "\" "
        + "\"" + std::to_string(_bailInfo) + "\" "
        + "\"" + std::to_string(_otherBailInfo) + "\" "
        + "\"" + std::to_string(_crashInfo) + "\" "
        + "\"" + std::to_string(_otherCrashInfo) + "\" "
        + "\"" + std::to_string(_otherPlayerStats) + "\" "
        + "\"" + std::to_string(_showChat) + "\" "
        + "\"" + std::to_string(_colour) + "\" "
        + "\"" + std::to_string(_colourFG) + "\" "
        + "\"" + std::to_string(_headless) + "\" ";
    // Calls the command
    std::system(command.c_str());

    // Opens the file
    openLog();

    // Formats the log with HTML codes
    formatLog();

    // Adds the variable values if _debugInfo
    if (_debugInfo) { debugInfo(); }

    // Adds the formatted log to text_lines
    text_lines.push_back("");
    for (auto& i : formatted_log)
    {
        text_lines.push_back(i);
    }
}


// Gets the current date and time and turns it into a string
std::string getDateTime()
{
    // Gets the date and time and saves it to a string
    auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
    std::string dateTime = std::format("{:%Y-%m-%d_%X}", time);
    // Checks if the ":"s need to be replaced
    for (int i = 0; i < dateTime.length(); i++)
    {
        if (dateTime[i] == ':')
        {
            dateTime[i] = '-';
        }
    }
    // Returns the date & time
    return dateTime;
}

// Opens the log file
void openLog()
{
    // Gets rid of the "\" at the end of the output dir
    size_t x = output_dir.find_last_of("\\");
    log_file_dir = output_dir.substr(0, x);
    // Adds output_name+.txt to output_dir
    log_file_dir = log_file_dir + output_name + ".txt";

    // Opens the log file
    std::fstream logFile(log_file_dir, std::ios::in);
    // Write all contents of logFile to log_contents
    std::string logline;
    log_lines.clear();
    while (std::getline(logFile, logline))
    {
        log_lines.push_back(logline);
    }
    // Close logFile
    logFile.close();
}

// Formats the log
void formatLog()
{
    bool _enableColour = true;
    for (auto& i : log_lines)
    {
        // Set a string to the current line
        std::string current_line = i;
        // Checks if current_line = "Player Statistics:" (disables colour if so)
        if (current_line == "Player Statistics:")
        {
            _enableColour = false;
        }

        // Checks the first character of current_line
        char character = current_line[0];
        std::string colour;
        if (_enableColour)
        {
            switch (character)
            {
            case '*':
                // Destroyed vehicle
                colour = destruction_colour;
                break;
            case '^':
                // Bail Out Info
                colour = bail_colour;
                break;
            case '#':
                // Side Switch Info
                colour = sideSwitch_colour;
                break;
            case '-':
                // Start/Stop Session Colour
                colour = startEnd_colour;
                break;
            case '!':
                // Mission/Battle info
                colour = missionInfo_colour;
                break;
            case '=':
                // Landing Info
                colour = landing_colour;
                break;
            case '_':
                // Crash/'Good'-Landing
                colour = crash_colour;
                break;
            default:
                colour = default_colour;
                break;
            }
        }
        else
        {
            colour = default_colour;
        }

        // Formats the string
        std::string formatted_str = "<p style=\"color:" + colour + "\"><b>" + current_line + "</b></p>";
        // Adds the string to formatted_log
        formatted_log.push_back(formatted_str);
        // Checks if the current line contains "The battle ended at", if so a new line will be entered
        if (current_line.find("The battle ended at") != std::string::npos)
        {
            formatted_log.push_back("");
        }
    }

}

// Debug Info
void debugInfo()
{
    // User Set Variables
    text_lines.push_back("<b>User Set Vars:</b>");
    text_lines.push_back("  Steam Username: " + steam_username);
    text_lines.push_back("  Log Location: " + log_location);
    text_lines.push_back("  Output Dir: " + output_dir);
    text_lines.push_back("  Debug Info?: " + std::to_string(_debugInfo));
    text_lines.push_back("  Player Connection Info?: " + std::to_string(_playerConnectionInfo));
    text_lines.push_back("  Other Player Connection Info?: " + std::to_string(_otherPlayerConnectionInfo));
    text_lines.push_back("  Side Switch Info?: " + std::to_string(_sideSwitchInfo));
    text_lines.push_back("  Other Player Side Switch Info?: " + std::to_string(_otherPlayerSideSwitchInfo));
    text_lines.push_back("  New Mission Load Info?: " + std::to_string(_newMissionLoadInfo));
    text_lines.push_back("  New Mission Info?: " + std::to_string(_newMissionInfo));
    text_lines.push_back("  Battle Started Info?: " + std::to_string(_battleStartedInfo));
    text_lines.push_back("  Battle Ended Info?: " + std::to_string(_battleEndInfo));
    text_lines.push_back("  Destruction Info?: " + std::to_string(_destructionInfo));
    text_lines.push_back("  Unrelated Destruction Info?: " + std::to_string(_destructionUnrelatedInfo));
    text_lines.push_back("  Landing Info?: " + std::to_string(_landingInfo));
    text_lines.push_back("  Other Landing Info?: " + std::to_string(_otherLandingInfo));
    text_lines.push_back("  Bail Info?: " + std::to_string(_bailInfo));
    text_lines.push_back("  Other Bail Info?: " + std::to_string(_otherBailInfo));
    text_lines.push_back("  Crash Info?: " + std::to_string(_crashInfo));
    text_lines.push_back("  Other Crash Info?: " + std::to_string(_otherCrashInfo));
    text_lines.push_back("  Other Player Stats?: " + std::to_string(_otherPlayerStats));
    text_lines.push_back("  Show Chat?: " + std::to_string(_showChat));
    // Programme Set Variables
    text_lines.push_back("<b>Programme Set Vars:</b>");
    text_lines.push_back("  Output File Name: " + output_name);
    text_lines.push_back("<b>Unchangeable Vars:</b>");
    text_lines.push_back("  Output File?: " + std::to_string(_outputFile));
    text_lines.push_back("  All Info?: " + std::to_string(_allInfo));
    text_lines.push_back("  Colour?: " + std::to_string(_colour));
    text_lines.push_back("  Colour Foreground?: " + std::to_string(_colourFG));
    text_lines.push_back("  Headless?: " + std::to_string(_headless));
    // Command
    text_lines.push_back("<b>Command:</b>");
    text_lines.push_back("  " + command);
    // Misc
    text_lines.push_back("<b>Misc:</b>");
    text_lines.push_back("  Output Log Dir: " + log_file_dir);
}

