![AudioON Logo](https://github.com/gauravslnk/AudioON/blob/main/resources/ico/AudioON.png)

# **AudioON** – Console-Based Music Player 🎵

AudioON is a lightweight, **terminal-based music player** written in C++ designed primarily for **Windows**, with experimental support for Linux. It provides a simple menu-driven interface to play `.wav` audio files from a predefined folder. Built using native multimedia libraries, it aims for fast, real-time playback directly from the terminal.

AudioON is built for users who want a quick and minimalistic way to play `.wav` files without the overhead of a full GUI music player. It uses the **Windows Multimedia API (`winmm.lib`)** on Windows to handle sound playback asynchronously, allowing users to select tracks from a list and control playback in real-time.

While Windows support is mature and stable, Linux support is experimental, relying on external command-line players such as `aplay` to play audio files.

---

## 🎯 Features

- 🎛️ Menu-driven interface for easy song selection.
- 🔊 Real-time playback of `.wav` audio files.
- 🔁 Loop support until the user stops the song.
- 🧠 Async non-blocking audio playback.
- ➕ Add new songs by placing `.wav` files in `resources/sounds/`.
- 💻 **Cross-platform** (Windows ✅ | Linux 🐧 — support growing!)

---

## 📁 File Structure

```
AudioON/
├── AudioON.exe               # Compiled executable (Windows)
├── include/
│   ├── AudioON.h            # Class declarations for sound playback
│   └── AudioHelper.h        # Helper functions for directory & file handling
├── src/
│   ├── main.cpp             # Entry point, user interaction, menu
│   ├── AudioON.cpp          # AudioON class implementation
│   └── AudioHelper.cpp      # Directory traversal and audio file loading
├── resources/
│   ├── sounds/              # Place your .wav files here
│   └── ico/
│       ├── appicon.ico      # Icon file (Windows)
│       ├── appicon.rc       # Resource script
│       └── appicon.res      # Compiled resource file
└── README.md

````

---

## 🚀 How to Install & Run

You can **either build from source** or directly use the precompiled installer (Windows only).


### ✅ Option 1: Windows Installer (Recommended)

1. Go to the [**Releases**](https://github.com/gauravslnk/AudioON/releases).
2. Download the `AudioON-installer.exe`.
3. Run it and follow the on-screen steps.
4. Launch `AudioON` from the installed location.
5. Place your `.wav` files in the `resources/sounds/` folder.

---

### 🛠️ Option 2: Build from Source (Windows & Linux)

Whether you're on **Windows** or a **Linux terminal warrior**, AudioON is ready for you!

## ⚙️ Platform Details & Libraries Used

### Windows

- Uses **Windows Multimedia API (`winmm.lib`)** for audio playback.
- Playback uses `PlaySound` function for asynchronous sound playing.
- Linking requires `-lwinmm` during compilation.
- Supports `.wav` files natively.
- Icon embedding via `.rc` and `.res` resource files.
- Recommended build command (MinGW):

  ```bash
  g++ src/*.cpp -Iinclude -o AudioON.exe -lwinmm
  ./AudioON.exe ```

Make sure your `.wav` files are placed inside the `resources/sounds/` directory.

---

#### 🐧 Linux (Experimental)

Yes, it works on Linux too!
For playback, it uses external tools like `aplay` to play `.wav` files.

- AudioON attempts Linux compatibility.

- Does not use native audio libraries directly.

- Uses external tools like `aplay` (from alsa-utils) for playing `.wav` files via system calls.

- Requires aplay to be installed `(sudo apt-get install alsa-utils or equivalent)`.

- No embedded icon support on Linux.


##### Build & Run

```bash
g++ src/*.cpp -Iinclude -o AudioON -std=c++17
./AudioON
```

Make sure your `.wav` files are inside the `resources/sounds/` directory.

---

## ❗ Known Issues & Limitations

- **Play/Pause Functionality:** Currently, pause and resume controls do not work as expected. When pausing and resuming, playback restarts the song from the beginning rather than continuing from the pause point.

- **Loop Mode:** Looping works but can sometimes cause brief audio glitches or restart delays depending on the platform. Also, the player stops after one song, so you have to manually press `N` (next song) and `P` (play/pause) to continue listening.

- **Linux Support:** Linux support is minimal and depends heavily on external utilities. Advanced features like pause, stop, or loop might not work properly.

- **File Format:** Only supports `.wav` files. Other audio formats are not supported.

- **UI:** Being terminal-based, the interface is minimalistic and lacks advanced controls like volume adjustment or playlists.

- **Cross-Platform Differences:** Some features (like icon embedding and asynchronous playback) are Windows-only or behave differently across operating systems.

---

> 🧪 *Linux friends!* If anything breaks, feel free to open an [issue](https://github.com/gauravslnk/AudioON/issues).
> Bonus points if you help fix it and earn eternal respect from fellow devs 😄

---

## 🤝 Now Open for Contributions!

**AudioON** has been a solo project so far — but now it's **open to the community**! 💥

If you love terminal tools, C++, or just want to help make this player better:

* 🐛 Report bugs or issues
* 💡 Suggest new features
* 🤖 Improve cross-platform compatibility
* 🎨 Add UI polish or sound enhancements
* 📚 Help with documentation

> Fork it 🍴, star it ⭐, and send your pull requests!
> Let’s build something cool together. 🔧

---

## 📸 Logo

You can find the logo inside the `resources/ico/` folder.
Feel free to use it for packaging or promotions.

---

## 📬 Contact

Built with ❤️ by **Gaurav Solanki**

* 📷 [Instagram](https://instagram.com/gauravslnk)
* 💼 [LinkedIn](https://linkedin.com/in/gaurav-solanki-07a5a6321)
* 📧 [gauravsolanki443@gmail.com](mailto:gauravsolanki443@gmail.com)

---
Thank you for checking out AudioON!
Happy listening 🎶

