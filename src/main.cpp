#include "AudioON.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

// Define if not already available
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

void setupTerminal() {
    SetConsoleOutputCP(CP_UTF8);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
}

int main() {
    setupTerminal();
    AudioON audioPlayer;
    bool isRunning = true;
    char ch;

    audioPlayer.displayMenu(audioPlayer.getCurrentTrackIndex(), audioPlayer.getIsPaused());

    while (isRunning) {
        if (_kbhit()) {
            ch = _getch();
            switch (tolower(ch)) {
                case 'p':
                    audioPlayer.togglePause();
                    audioPlayer.displayMenu(audioPlayer.getCurrentTrackIndex(), audioPlayer.getIsPaused());
                    break;
                case 's':
                    audioPlayer.stopSound();
                    audioPlayer.displayMenu(audioPlayer.getCurrentTrackIndex(), audioPlayer.getIsPaused());
                    break;
                case 'n':
                    audioPlayer.nextTrack();
                    audioPlayer.displayMenu(audioPlayer.getCurrentTrackIndex(), audioPlayer.getIsPaused());
                    break;
                case 'l':
                    audioPlayer.previousTrack();
                    audioPlayer.displayMenu(audioPlayer.getCurrentTrackIndex(), audioPlayer.getIsPaused());
                    break;
                case 'r':
                    audioPlayer.toggleLoopMode();
                    break;
                case 'h':
                    audioPlayer.toggleShuffle();
                    break;
                case 'q':
                    isRunning = false;
                    break;
            }
            
            if (isRunning) {
                audioPlayer.displayMenu(audioPlayer.getCurrentTrackIndex(), audioPlayer.getIsPaused());
            }
        }
    }

    return 0;
}
