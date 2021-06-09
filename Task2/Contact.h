#pragma once
#include "Number.h"

using namespace std;

class Contact {
    string name = "NULL";
    Number cell;
public:
    void getContact();
    friend class Phone;
};

void Contact::getContact() {
  cout << "Enter name: ";
  cin >> name;
  while (true) {
    cout << "Enter number: ";
    cin >> cell.number;
    if (cell.isCorrect()) break;
    else cout << "Wrong input! Try again." << endl;
  }
  cout << "Contact added!" << endl;
}