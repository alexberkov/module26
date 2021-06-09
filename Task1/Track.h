#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

class Track {
    string name;
    int duration;
    tm birth{};
    bool status;
public:
    Track();
    void play();
    void pause();
    void resume();
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
  status = false;
}

void Track::showDuration() const {
  cout << (duration / 60) << ":";
  if (duration % 60 < 10) cout << "0";
  cout << (duration % 60);
}

void Track::play() {
  if (!status) {
    cout << "Now playing: " << name << ", ";
    this->showDuration();
    cout << ", created: " << put_time(&birth, "%Y/%m/%d %H:%M:%S") << endl;
    status = true;
  } else return;
}

void Track::pause() {
  if (status)  {
    cout << "Paused || " << endl;
    status = false;
  } else return;
}

void Track::resume() {
  if (!status) {
    cout << "Playing |>" << endl;
    status = true;
  } else return;
}

void Track::stop() {
  if (status)  status = false;
  cout << "Stopped: " << name << endl;
}
