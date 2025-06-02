#include "AudioON.h"
#include "AudioHelper.h"
#include <iostream>
#include<string>
#include <ctime>

#ifdef _WIN32
    #include <windows.h>
    #include <mmsystem.h>
    #pragma comment(lib, "winmm.lib")
#else
    #include <cstdlib>
#endif

AudioON::AudioON() : currentTrackIndex(-1), isPaused(false), folderPath("./resources/sounds/"), playMode(PlayMode::NORMAL) {
    audioFiles = getAudioFilesInFolder(folderPath);
    std::srand(std::time(nullptr));
}

void AudioON::displayMenu(int currentTrackIndex, bool isPaused) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Clear screen
    system("cls");

    // Display header with borders
    SetConsoleTextAttribute(hConsole, 11); // Cyan
    std::cout << R"(╔═════════════════════════════════════════════╗)" << std::endl;
    std::cout <<   "║        🎵  AudioON Music Player  🎵         ║" << std::endl;
    std::cout << R"(╚═════════════════════════════════════════════╝)" << std::endl;

    // Display current track
    if (currentTrackIndex >= 0 && currentTrackIndex < audioFiles.size()) {
        SetConsoleTextAttribute(hConsole, 14); // Yellow
        std::cout << "   Current Track: " << audioFiles[currentTrackIndex] << "  ";
        SetConsoleTextAttribute(hConsole, 9); // Blue
        std::cout << (isPaused ? "⏸ Paused..." : "▶ Playing...  ") << std::endl;
    } else {
        std::cout << "               No track selected              " << std::endl;
    }

    SetConsoleTextAttribute(hConsole, 10);
    std::string modeStr;
    switch (playMode) {
        case PlayMode::SHUFFLE: modeStr = "                Mode: Shuffle 🔀"; break;
        case PlayMode::LOOP_ONE: modeStr = "                Mode: Loop One 🔁"; break;
        case PlayMode::LOOP_ALL: modeStr = "                Mode: Loop All 🔁🔁"; break;
        default: modeStr = "                Mode: Normal ▶"; break;
    }
    std::cout << modeStr << std::endl;


    SetConsoleTextAttribute(hConsole, 11); // Cyan
    std::cout << R"(╔═════════════════════════════════════════════╗)" << std::endl;
    std::cout <<   "║ P - Play/Pause  S - Stop   N - Next Track   ║" << std::endl;
    std::cout <<   "║ L - Previous    R - Loop   H - Shuffle      ║" << std::endl;
    std::cout <<   "║                 Q - Quit                    ║" << std::endl;
    std::cout << R"(╚═════════════════════════════════════════════╝)" << std::endl;

    // Display available tracks
    SetConsoleTextAttribute(hConsole, 7); // Reset to white
    std::cout << "Available Tracks:" << std::endl;
    for (size_t i = 0; i < audioFiles.size(); ++i) {
        std::cout << "  " << (i == currentTrackIndex ? "[▶]" : "[ ]") << " " << i + 1 << ". " << audioFiles[i] << std::endl;
    }
    std::cout << "Press N To start AudioON" << std::endl;
    std::cout << "Use the keys above to control playback." << std::endl;
}

void AudioON::playSound(const std::string& fileName) {
    std::string fullPath = folderPath + fileName;

    #ifdef _WIN32

        PlaySoundA(fullPath.c_str(), NULL, SND_FILENAME | SND_ASYNC);

    #else

        std::string command = "apaly \"" + fullPath + "\" &";
        system(command.c_str());

    #endif

        isPaused = false;
}

void AudioON::stopSound() {

#ifdef _WIN32
    PlaySoundA(NULL, 0, 0);
#else
    system("killall aplay 2>/dev/null");
#endif
    isPaused = true;
}

void AudioON::togglePause() {
    if (isPaused) {
        if (currentTrackIndex >= 0 && currentTrackIndex < audioFiles.size()) {
            playSound(audioFiles[currentTrackIndex]);
        }
    } else {
        stopSound();
    }
}

void AudioON::nextTrack() {
    if (audioFiles.empty()) return;

    switch (playMode) {
        case PlayMode::SHUFFLE:
            currentTrackIndex = std::rand() % audioFiles.size();
            break;
        case PlayMode::LOOP_ONE:
            break;
        case PlayMode::LOOP_ALL:
            currentTrackIndex = (currentTrackIndex + 1) % audioFiles.size();
            break;
        case PlayMode::NORMAL:
        default:
            if (currentTrackIndex < static_cast<int>(audioFiles.size()) - 1) {
                ++currentTrackIndex;
            } else {
                std::cout << "End of playlist.\n";
                return;
            }
            break;
    }
    playSound(audioFiles[currentTrackIndex]);
}

void AudioON::previousTrack() {
    if (!audioFiles.empty()) {
        currentTrackIndex = (currentTrackIndex - 1 + audioFiles.size()) % audioFiles.size();
        playSound(audioFiles[currentTrackIndex]);
    }
}

void AudioON::toggleShuffle() {
    playMode = (playMode == PlayMode::SHUFFLE) ? PlayMode::NORMAL : PlayMode::SHUFFLE;
}

void AudioON::toggleLoopMode() {
    switch (playMode) {
        case PlayMode::LOOP_ONE: playMode = PlayMode::LOOP_ALL; break;
        case PlayMode::LOOP_ALL: playMode = PlayMode::NORMAL; break;
        default: playMode = PlayMode::LOOP_ONE; break;
    }
}

const std::vector<std::string>& AudioON::getAudioList() const {
    return audioFiles;
}

bool AudioON::getIsPaused() const {
    return isPaused;
}

int AudioON::getCurrentTrackIndex() const {
    return currentTrackIndex;
}

PlayMode AudioON::getPlayMode() const {
    return playMode;
}
