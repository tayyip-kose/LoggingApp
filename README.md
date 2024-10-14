LogApp

LogApp is a C++ application developed using the Qt framework. This application is a logging system that creates and manages log files based on the specified configuration settings. LogApp writes log files at specific intervals according to the settings in a JSON file, and manages the maximum file size and the number of log files.

Project Features

LogApp reads configuration settings from the config.json file.
Log files are created at specified time intervals (e.g., every second, minute, hour, or day).
Each log file is named with a UTC timestamp.
When the maximum number of log files or size is reached, the oldest log file is automatically deleted.
The directory where log files are written, the logging frequency, and the log file size can be easily configured via the config.json file.

File Structure

main.cpp: The file where the application is initialized and the logger class is created. It also generates log messages at specific intervals.
logging.cpp: The file where the class responsible for creating log files, managing old logs, and reading the configuration file is implemented.
logging.h: The header file for the Logging class. It contains the methods for logging operations and managing settings.
config.json: The JSON file containing log settings. LogApp reads this file to perform logging operations.

------------------------------
config.json :
LogApp\build\Desktop_Qt_6_8_0_MinGW_64_bit-Debug\config.json

------------------------------
config.json settings :
"logType": "txt" // logType
"logFrequency": "second" // logFrequency (second/minute/hour/day) 
"logSize": 4   // logSize

------------------------------
Save logs :
LogApp\build\Desktop_Qt_6_8_0_MinGW_64_bit-Debug\logs




