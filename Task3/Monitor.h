#pragma once
#include "Window.h"

using namespace std;

class Monitor {
public:
    Window W;
    void display() const;
    Monitor();
    virtual ~Monitor() = default;
};

void Monitor::display() const {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 80; j++) {
      if ((j >= W.corner.x) && (j < W.corner.x + W.width) && (i >= W.corner.y) && (i < W.corner.y + W.height)) {
        cout << "1";
      } else cout << "0";
    }
    cout << endl;
  }
}

Monitor::Monitor() {
  W = Window();
}
