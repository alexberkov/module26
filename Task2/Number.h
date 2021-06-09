#pragma once
#include <iostream>
#include <string>

using namespace std;

class Number {
    string number = "NULL";
public:
    bool isCorrect();
    friend class Contact;
    friend class Phone;
};

bool Number::isCorrect() {
  return (number[0] == '+' && number[1] == '7' && number.length() == 12);
}
