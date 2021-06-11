#pragma once
#include <iostream>

using namespace std;

class Point {
    int x = 0, y = 0;
public:
    explicit Point (int a = 0, int b = 0);
    Point& operator =(const Point& p);
    Point& operator +=(const Point& p);
    Point& operator -=(const Point& p);
    bool isCorrect() const;
    pair<int, int> getPoint() const;
    void setPoint();
    void showPoint() const;
    virtual ~Point() = default;
};

Point::Point(int a, int b) {
  x = a;
  y = b;
}

Point& Point::operator=(const Point& p) = default;

Point& Point::operator+=(const Point& p) {
  x += p.x;
  y += p.y;
  return *this;
}

Point& Point::operator -=(const Point& p) {
  x -= p.x;
  y -= p.y;
  return *this;
}

bool Point::isCorrect() const {
  return (x >= 0 && y >= 0 && x < 80 && y < 50);
}

void Point::setPoint() {
  cin >> x >> y;
}

void Point::showPoint() const {
  cout << "(" << x << ", " << y << ")" << endl;
}

pair<int, int> Point::getPoint() const {
  return make_pair(x, y);
}