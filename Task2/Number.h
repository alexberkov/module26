#pragma once
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Number {
    string number = "NULL";
public:
    bool isCorrect();
    string getNumber();
    void setNumber();
    void putNumber(const Number& n);
};

bool Number::isCorrect() {
  return (number[0] == '+' && number[1] == '7' && number.length() == 12);
}

string Number::getNumber() {
  return number;
}

void Number::setNumber() {
  cin >> number;
}

void Number::putNumber(const Number& n) {
  number = n.number;
}
