#pragma once
#include "Number.h"

using namespace std;

class Contact {
    string name = "NULL";
    Number cell;
public:
    void setContact();
    pair<string,Number> getContact();
};

void Contact::setContact() {
  cout << "Enter name: ";
  cin >> name;
  while (true) {
    cout << "Enter number: ";
    cell.setNumber();
    if (cell.isCorrect()) break;
    else cout << "Wrong input! Try again." << endl;
  }
  cout << "Contact added!" << endl;
}

pair<string,Number> Contact::getContact() {
  return make_pair(name, cell);
}