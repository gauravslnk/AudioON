// AudioON.h
#ifndef AUDIO_ON_H
#define AUDIO_ON_H

#include <string>
#include <vector>

enum class PlayMode {
    NORMAL,
    SHUFFLE,
    LOOP_ONE,
    LOOP_ALL
};

class AudioON {
private:
    std::vector<std::string> audioFiles;
    std::string folderPath;
    int currentTrackIndex;
    bool isPaused;
    PlayMode playMode;

public:
    AudioON();

    void displayMenu(int currentTrackIndex, bool isPaused);
    void playSound(const std::string& fileName);
    void stopSound();
    void togglePause();
    void nextTrack();
    void previousTrack();
    void toggleShuffle();
    void toggleLoopMode();

    const std::vector<std::string>& getAudioList() const;
    bool getIsPaused() const;
    int getCurrentTrackIndex() const;
    PlayMode getPlayMode() const;
};

#endif