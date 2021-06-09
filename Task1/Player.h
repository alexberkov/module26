#pragma once
#include <vector>
#include "Track.h"

using namespace std;

class Player {
    vector<Track> playlist;
    int current = 0;
public:
    void addTrack();
    void play();
    void pause();
    void resume();
    void next();
    void stop();
};

void Player::addTrack() {
  Track song;
  cout << "Enter name: ";
  cin >> song.name;
  cout << "Enter duration: ";
  cin >> song.duration;
  playlist.push_back(song);
}

void Player::play() {
  if (current != 0) playlist[current - 1].stop();
  int i;
  cout << "Enter track number: ";
  cin >> i;
  if (i > 0 && i <= playlist.size()) {
    playlist[i - 1].play();
    current = i;
  } else cout << "No such track!" << endl;
}

void Player::pause() {
  playlist[current - 1].pause();
}

void Player::resume() {
  playlist[current - 1].resume();
}

void Player::next() {
  if (current != 0) playlist[current - 1].stop();
  int prev = current;
  while (current == prev) {
    srand(time(nullptr));
    current = 1 + rand() % playlist.size();
  }
  playlist[current - 1].play();
}

void Player::stop() {
  if (current != 0) {
    playlist[current - 1].stop();
    current = 0;
  } else return;
}

