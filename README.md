![AudioON Logo](https://github.com/gauravslnk/AudioON/blob/main/resources/ico/AudioON.png)

# **AudioON** 🎵

**AudioON** is a lightweight **terminal-based music player** built in C++ using the **Windows Multimedia API**.

Designed for simplicity and speed, it allows you to play `.wav` audio files directly from your terminal with a smooth and interactive experience.

---

## 🎯 Features

- 🎛️ Menu-driven interface for easy song selection.
- 🔊 Real-time playback of `.wav` audio files.
- 🔁 Loop support until the user stops the song.
- 🧠 Async non-blocking audio playback.
- 🚪 Graceful exit options from anywhere in the menu.
- ➕ Add new songs by placing `.wav` files in `resources/sounds/`.
- 💻 **Cross-platform** (Windows ✅ | Linux 🐧 — support growing!)

---

## 📁 File Structure

```

AudioON/
├── AudioON.exe
├── include/
│   ├── AudioON.h        // Class declarations for sound playback
│   └── AudioHelper.h    // Helper functions for directory & file handling
├── src/
│   ├── main.cpp         // Program entry, menu, user input handling
│   ├── AudioON.cpp      // AudioON class implementation (PlaySound etc.)
│   └── AudioHelper.cpp  // Directory traversal and file searching
├── resources/
│   └── sounds/          // Your .wav audio files go here
└── README.md

````

---

## 🚀 How to Install & Run

You can **either build from source** or directly use the precompiled installer (Windows only).

---

### ✅ Option 1: Windows Installer (Recommended)

1. Go to the [**Releases**](https://github.com/gauravslnk/AudioON/releases).
2. Download the `AudioON-installer.exe`.
3. Run it and follow the on-screen steps.
4. Launch `AudioON` from the installed location.
5. Place your `.wav` files in the `resources/sounds/` folder.

> ℹ️ The installer will be uploaded under the **Releases** tab.

---

### 🛠️ Option 2: Build from Source (Windows & Linux)

Whether you're on **Windows** or a **Linux terminal warrior**, AudioON is ready for you!

---

#### 🪟 Windows

##### Requirements

* Windows OS
* C++ compiler (like `g++`, `MSVC`)
* WinMM library (usually included by default in Windows)

##### Build & Run (MinGW Example)

```bash
g++ src/*.cpp -o AudioON.exe -lwinmm
./AudioON.exe
```

Make sure your `.wav` files are placed inside the `resources/sounds/` directory.

---

#### 🐧 Linux (Experimental)

Yes, it works on Linux too!
For playback, it uses external tools like `aplay` to play `.wav` files.

##### Requirements

* Linux OS
* C++ compiler (`g++`)
* `aplay` installed (or any terminal-based `.wav` player)

##### Build & Run

```bash
g++ src/*.cpp -o AudioON -std=c++17
./AudioON
```

Make sure your `.wav` files are inside the `resources/sounds/` directory.

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
