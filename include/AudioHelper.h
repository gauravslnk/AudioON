#ifndef AUDIO_HELPER_H
#define AUDIO_HELPER_H

#include <vector>
#include <string>

// Returns a list of audio file names from the given folder
std::vector<std::string> getAudioFilesInFolder(const std::string& folderPath);

#endif // AUDIO_HELPER_H
