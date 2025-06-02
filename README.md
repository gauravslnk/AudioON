# AudioON – Console-Based Music Player

AudioON is a simple, cross-platform console-based music player application written in C++ (Windows-only). It allows users to select and play .wav audio files from a predefined music library using a menu-driven interface. The project utilizes the Windows multimedia API (winmm.lib) to handle sound playback.

## Features
- Menu-driven interface for song selection.
- Real-time playback of .wav audio files.
- Async playback with loop support until the user stops the song manually.
- Option to exit the application gracefully.
- Easy to extend – just add new .wav files to the resources/sounds/ folder and update the menu.

## File Structure
AudioON/
├── AudioON.exe 
├── include/
│   ├── AudioON.h      // Class declarations for sound playback
│   └── AudioHelper.h  // Helper functions for directory & file handling
├── src/
│   ├── main.cpp       // Program entry, menu, user input handling
│   ├── AudioON.cpp    // AudioON class implementation (PlaySound etc.)
│   └── AudioHelper.cpp// Implements directory traversal and file searching
├── resources/
│   └── sounds/        // Your .wav files (all your audio files should be here)
└── README.md
