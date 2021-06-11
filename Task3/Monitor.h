#pragma once
#include "Window.h"

using namespace std;

class Monitor {
    Window W;
public:
    void display() const;
    Monitor();
    void move();
    void resize();
    virtual ~Monitor() = default;
};

void Monitor::display() const {
  Point center = W.getWindow().first;
  int width = W.getWindow().second.first, height = W.getWindow().second.second;
  int x = center.getPoint().first, y = center.getPoint().second;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 80; j++) {
      if ((j >= x) && (j < x + width) && (i >= y) && (i < y + height)) {
        cout << "1";
      } else cout << "0";
    }
    cout << endl;
  }
}

Monitor::Monitor() {
  W = Window();
  W.createWindow();
}

void Monitor::move() {
  W.move();
}

void Monitor::resize() {
  W.resize();
}