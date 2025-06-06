#include "AudioHelper.h"
#include <iostream>
#include <algorithm>

#ifdef _WIN32
    #include <windows.h>
    #include <filesystem>
    namespace fs = std::filesystem;
#else
    #include <dirent.h>    // POSIX directory functions
    #include <sys/types.h>
#endif

using namespace std;

// Supported audio file extensions
const vector<string> audioExtensions = { ".mp3", ".wav", ".flac", ".aac", ".ogg" };

// Helper function to check if a file has a valid audio extension
bool isAudioFile(const string& filename) {
    string lowerFilename = filename;
    transform(lowerFilename.begin(), lowerFilename.end(), lowerFilename.begin(), ::tolower);

    for (const string& ext : audioExtensions) {
        if (lowerFilename.size() >= ext.size() &&
            lowerFilename.compare(lowerFilename.size() - ext.size(), ext.size(), ext) == 0) {
            return true;
        }
    }
    return false;
}

// Function to list audio files from a given folder
vector<string> getAudioFilesInFolder(const string& folderPath) {
    vector<string> audioFiles;

#ifdef _WIN32
    for(const auto& entry : fs::directory_iterator(folderPath)) {
        if(entry.is_regular_file()) {
            string fileName = entry.path().filename().string();
            if (isAudioFile(fileName)) {
                audioFiles.push_back(fileName);
            }
        }
    }
#else
    DIR* dir = opendir(folderPath.c_str());
    if (!dir) {
        cerr << "Error: Unable to open folder: " << folderPath << endl;
        return audioFiles;
    }

    dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        string fileName = entry->d_name;
        if (isAudioFile(fileName)) {
            audioFiles.push_back(fileName);
        }
    }
    closedir(dir);
#endif

    // Sort the audio files alphabetically
    sort(audioFiles.begin(), audioFiles.end());
    return audioFiles;
}
