#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

class Track {
    string name;
    int duration;
    tm birth{};
public:
    Track();
    void play();
    static void pause();
    static void resume();
    void stop();
    void showDuration() const;
    friend class Player;
    virtual ~Track () = default;
};

Track::Track() {
  time_t t = time(nullptr);
  name = "NULL";
  duration = 0;
  birth = *localtime(&t);
}

void Track::showDuration() const {
  cout << (duration / 60) << ":";
  if (duration % 60 < 10) cout << "0";
  cout << (duration % 60);
}

void Track::play() {
    cout << "Now playing: " << name << ", ";
    this->showDuration();
    cout << ", created: " << put_time(&birth, "%Y/%m/%d %H:%M:%S") << endl;
}

void Track::pause() {
    cout << "Paused || " << endl;
}

void Track::resume() {
    cout << "Playing |>" << endl;
}

void Track::stop() {
  cout << "Stopped: " << name << endl;
}
