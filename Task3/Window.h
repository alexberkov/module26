#pragma once
#include "Point.h"

using namespace std;

class Window {
    Point corner;
    int height = 0, width = 0;
public:
    Window();
    bool isFit();
    void createWindow ();
    void move();
    void resize();
    pair<Point, pair<int, int>> getWindow() const;
    virtual ~Window() = default;
};

Window::Window() {
  corner = Point(0, 0);
  height = 0;
  width = 0;
}

bool Window::isFit() {
  Point d(width, height);
  Point rightCorner = corner;
  rightCorner += d;
  return (corner.isCorrect() && rightCorner.isCorrect());
}

void Window::createWindow() {
  while (true) {
    cout << "Enter top-left corner coordinates: ";
    corner.setPoint();
    cout << "Enter width and height: ";
    cin >> width >> height;
    if (!this->isFit()) {
      cout << "Wrong input! Try again." << endl;
      continue;
    } else break;
  }
}

void Window::move() {
  Point v(0, 0);
  while (true) {
    cout << "Enter vector coordinates: ";
    v.setPoint();
    corner += v;
    if (!this->isFit()) {
      cout << "Wrong input! Try again." << endl;
      corner -= v;
      continue;
    } else break;
  }
  cout << "New coordinates: ";
  corner.showPoint();
}

void Window::resize() {
  while (true) {
    cout << "Enter new width and height: ";
    cin >> width >> height;
    if (width >= 0 && height >= 0 && this->isFit()) break;
    else {
      cout << "Wrong input! Try again." << endl;
      continue;
    }
  }
  cout << "New size: " << width << " x " << height << endl;
}

pair<Point, pair<int, int>> Window::getWindow() const {
  return make_pair(corner, make_pair(width, height));
}
