#include <cctype>
#include "AudioON.h"


#ifdef _WIN32
#include <conio.h>
#include <windows.h>

void setupTerminal() {
    SetConsoleOutputCP(CP_UTF8);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= 0x0004;  // ENABLE_VIRTUAL_TERMINAL_PROCESSING
            SetConsoleMode(hOut, dwMode);
        }
    }
}

int kbhit() { return _kbhit(); }
int getch() { return _getch(); }

#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <cstdio>



void setupTerminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

bool kbhit() {
    unsigned char ch;
    ssize_t n = read(STDIN_FILENO, &ch, 1);
    if (n > 0) {
        ungetc(ch, stdin);
        return true;
    }
    return false;
}

char getch() {
    return getchar();
}
#endif

int main() {
    setupTerminal();
    AudioON audioPlayer;
    bool isRunning = true;
    char ch;

    audioPlayer.displayMenu(audioPlayer.getCurrentTrackIndex(), audioPlayer.getIsPaused());

    while (isRunning) {
        if (kbhit()) {
            ch = getch();
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
