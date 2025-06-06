#include "AudioON.h"
#include "AudioHelper.h"
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>

#ifdef _WIN32
    #include <windows.h>
    #include <mmsystem.h>
    #pragma comment(lib, "winmm.lib")
#else
    #include <cstdlib>
#endif

AudioON::AudioON() : currentTrackIndex(-1), isPaused(false), folderPath("./resources/sounds/"), playMode(PlayMode::NORMAL) {
    audioFiles = getAudioFilesInFolder(folderPath);
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void AudioON::displayMenu(int currentTrackIndex, bool isPaused) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(hConsole, 11); // Cyan
#else
    std::cout << "\033[2J\033[H\033[36m"; // Clear + Cyan
#endif

    // Header
    std::cout << R"(╔═════════════════════════════════════════════╗)" << std::endl;
    std::cout <<   "║        🎵  AudioON Music Player  🎵         ║" << std::endl;
    std::cout << R"(╚═════════════════════════════════════════════╝)" << std::endl;

    // Track status
    if (currentTrackIndex >= 0 && currentTrackIndex < audioFiles.size()) {
#ifdef _WIN32
        SetConsoleTextAttribute(hConsole, 14); // Yellow
#else
        std::cout << "\033[33m";
#endif
        std::cout << "   Current Track: " << audioFiles[currentTrackIndex] << "  ";
#ifdef _WIN32
        SetConsoleTextAttribute(hConsole, 9);  // Blue
#else
        std::cout << "\033[34m";
#endif
        std::cout << (isPaused ? "⏸ Paused..." : "▶ Playing...") << std::endl;
    } else {
        std::cout << "               No track selected              " << std::endl;
    }

    // Playback mode
    std::string modeStr;
    switch (playMode) {
        case PlayMode::LOOP_ONE: modeStr = "                Mode: Loop One 🔁"; break;
        case PlayMode::LOOP_ALL: modeStr = "                Mode: Loop All 🔁🔁"; break;
        case PlayMode::SHUFFLE:  modeStr = "                Mode: Shuffle 🔀"; break;
        default:                 modeStr = "                Mode: Normal ▶"; break;
    }
#ifdef _WIN32
    SetConsoleTextAttribute(hConsole, 10); // Green
#else
    std::cout << "\033[32m";
#endif
    std::cout << modeStr << std::endl;

    // Instructions
#ifdef _WIN32
    SetConsoleTextAttribute(hConsole, 11); // Cyan
#else
    std::cout << "\033[36m";
#endif
    std::cout << R"(╔═════════════════════════════════════════════╗)" << std::endl;
    std::cout <<   "║ P - Play/Pause  S - Stop   N - Next Track   ║" << std::endl;
    std::cout <<   "║ L - Previous    R - Loop   H - Shuffle      ║" << std::endl;
    std::cout <<   "║ Q - Quit                                    ║" << std::endl;
    std::cout << R"(╚═════════════════════════════════════════════╝)" << std::endl;

#ifdef _WIN32
    SetConsoleTextAttribute(hConsole, 7); // Reset
#else
    std::cout << "\033[0m";
#endif

    // 🎼 Music Box Playlist
    std::cout << "\n🎼 Playlist (" << audioFiles.size() << " tracks):\n";
    std::cout << R"(╔══════════════════════════════════════════════╗)" << std::endl;

    for (size_t i = 0; i < audioFiles.size(); ++i) {
        std::string display = "  " + std::to_string(i + 1) + ". " + audioFiles[i];

        if (i == currentTrackIndex) {
#ifdef _WIN32
            SetConsoleTextAttribute(hConsole, 14); // Yellow
            std::cout << "▶ " << display << std::endl;
            SetConsoleTextAttribute(hConsole, 7);  // Reset
#else
            std::cout << "\033[33m▶ " << display << "\033[0m" << std::endl;
#endif
        } else {
            std::cout << "   " << display << std::endl;
        }
    }

    std::cout << R"(╚══════════════════════════════════════════════╝)" << std::endl;

    if (currentTrackIndex == -1)
        std::cout << "\n🔔 Press N to start AudioON.\n";

    std::cout << "🛈 Use the keys above to control playback.\n";
}

void AudioON::playSound(const std::string& fileName) {
    std::string fullPath = folderPath + fileName;
#ifdef _WIN32
    PlaySoundA(fullPath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
#else
    std::string command = "aplay \"" + fullPath + "\" &";
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
            // Stay on current track
            break;

        case PlayMode::LOOP_ALL:
            currentTrackIndex = (currentTrackIndex + 1) % audioFiles.size();
            break;

        case PlayMode::NORMAL:
        default:
            if (currentTrackIndex < static_cast<int>(audioFiles.size()) - 1) {
                ++currentTrackIndex;
            } else {
                std::cout << "\n🔚 End of playlist.\n";
                std::cout << "[E]xit  |  [C]ontinue from beginning  |  [L]ast track  |  [H]uffle\n";

                char choice;
                while (true) {
                    std::cout << "Choose option (E/C/L/H): ";
                    std::cin >> choice;
                    choice = std::tolower(choice);

                    if (choice == 'e') {
                        std::cout << "👋 Exiting AudioON. Goodbye!\n";
                        stopSound();
                        std::this_thread::sleep_for(std::chrono::seconds(1));  // Added delay before exit
                        exit(0);
                    } else if (choice == 'c') {
                        currentTrackIndex = 0;
                        break;
                    } else if (choice == 'l') {
                        currentTrackIndex = static_cast<int>(audioFiles.size()) - 1;
                        break;
                    } else if (choice == 'h') {
                        toggleShuffle();
                        currentTrackIndex = std::rand() % audioFiles.size();
                        break;
                    } else {
                        std::cout << "❌ Invalid input. Try again.\n";
                    }
                }
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

void AudioON::toggleLoopMode() {
    switch (playMode) {
        case PlayMode::LOOP_ONE:  playMode = PlayMode::LOOP_ALL; break;
        case PlayMode::LOOP_ALL:  playMode = PlayMode::NORMAL; break;
        default:                  playMode = PlayMode::LOOP_ONE; break;
    }
}

void AudioON::toggleShuffle() {
    playMode = (playMode == PlayMode::SHUFFLE) ? PlayMode::NORMAL : PlayMode::SHUFFLE;
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
