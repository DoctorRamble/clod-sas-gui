# Ramble's SAS GUI
A GUI for [CloD Server Activity Statistics](https://github.com/DoctorRamble/clod-sas).

## Contents
* [About This Programme](#about-this-programme)
* [Run the Source Code](#source-code-installation)
* [Install the Programme](#installation)
* [How to use the config file](#config-file-instructions)
* [NYAQ](#nyaq)
* [About the Icon](#about-the-icon)

## About This Programme
This is a (Windows-exclusive) GUI for [clod-sas](https://github.com/DoctorRamble/clod-sas) that uses Qt6 and C++20.

[ATAG Forum Post](https://theairtacticalassaultgroup.com/forum/showthread.php?t=39090&p=403331#post403331)

## Source Code Installation
Download the source files and open them in Qt Creator or another properly-configured IDE. Place the icon.ico in a new directory (.../assets/icons) relative to where the project/executable lies.

## Installation
To install the programme on Windows:
1. Go to 'Releases' and download the latest release archive.
2. Extract the archive and place the resulting folder in your desired location.
3. To use the programme you will need to create a shortcut (called "sas") that points to your SAS executable. This can be done by right-clicking the SAS exec and clicking "Create Shortcut". Right-click the shortcut and rename it "sas". Cut/copy the shortcut to the SAME directory as "Ramble's SAS GUI.exe". You can find information on SAS here: [https://github.com/DoctorRamble/clod-sas](https://github.com/DoctorRamble/clod-sas)
4. You can right-click "Ramble's SAS GUI.exe", select "Create Shortcut" and place the shortcut in an easily-accessible location, such as your Desktop.
5. For instructions on how to use the config file, go [here](#config-file-instructions)

## Config File Instructions
The config file (config.txt) is located in the ".../config/" directory.

The contents of config.txt have to remain in order, as the 'keys' are only there for user-convenience and the programme only reads the values from after the '='.

1. SteamUsername :: Put your steam username here (E.g. "Linux_Is_Better1234")
2. LogLocation :: The location of CloD's log.txt (E.g. "C:\Users\NinjaCat\Documents\1C SoftClub\il-2 sturmovik cliffs of dover\log.txt")
3. OutputDir :: The directory that SAS will save the parsed logs. Make sure to add two '\\' at the end instead of just one. This is because '\\' is an escape character and will cancel out any ' " 's in the programme. I would also recommend to create a dedicated folder for this (E.g. "C:\Users\Nigel\Desktop\SAS Output\\\\")
4. For items 4-22 refer to the information at [https://github.com/DoctorRamble/clod-sas](https://github.com/DoctorRamble/clod-sas). Generally you can keep these as defaults.
5. Items 23-30 take hexadecimal colour codes (E.g. "#000000")

Use "sas help", "sas.exe help" or "./sas help" for a useful help page.

## NYAQ
Not Yet Asked Questions:
1. Will you be making a Linux version for this? **A:** I do not plan on making a Linux version of this. It would be straightforward and would only take a little while, but the only reason I made this is because the Windows 10 CMD does not support the colour codes that SAS uses in Linux. But then again, looking at my programme's original ATAG post, I said there would be no point in making a GUI for SAS... and here I am, having made a GUI for SAS.
2. Why is your programming so messy and "x-thing" is done incorrectly? **A:** I am aware that my programming may be messy and/or incorrect, but A) I am not a professional, and B) At least I didn't use AI!
3. Are you aware by making a Windows-exclusive programme you are now on Tux's bad-list? **A:** I hope Tux can forgive my transgressions.

## About The Icon
To use the icon with the source code make a new directory (.../assets/icons), relative to the main executable.

**Description:** Cap Badge of the UK Special Air Service Regiment (SAS), New Zealand Special Air Service Regiment (NZ SAS), and the former Rhodesian Special Air Service Regiment.  **Date:** 1941  **Source:** Self-drawn  **Author:** Original design David Stirling for British Army; SVG version by [w:User:Dragases](https://en.wikipedia.org/wiki/User:Dragases)  **Licensing:** This work [created by the United Kingdom Government](https://en.wikipedia.org/wiki/Crown_copyright) is in the [public domain](https://en.wikipedia.org/wiki/public_domain).

For full details go [here](https://en.wikipedia.org/wiki/File:UK_SAS_(badge).svg).
