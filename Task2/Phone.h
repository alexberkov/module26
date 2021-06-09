#pragma once
#include "Contact.h"
#include <vector>

using namespace std;

class Phone {
    vector<Contact> phonebook;
public:
    void add();
    Number getNumber();
    void call();
    void sms();
};

void Phone::add() {
  auto* MyContact = new Contact;
  MyContact->getContact();
  phonebook.push_back(*MyContact);
  delete MyContact;
}

Number Phone::getNumber() {
  bool found = false;
  auto *line = new Number;
  cout << "Enter name or number: ";
  cin >> line->number;
  if (!line->isCorrect()) {
    for (auto &i : phonebook) {
      if (line->number == i.name) {
        line->number = i.cell.number;
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "Contact not found!" << endl;
      line->number = "NULL";
    }
  }
  return *line;
}

void Phone::call() {
  string s = this->getNumber().number;
  if (s != "NULL") cout << "Calling " << s << "..." << endl;
  else return;
}

void Phone::sms() {
  string s = this->getNumber().number;
  if (s != "NULL") {
    string text;
    cin.ignore();
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Sent to " << s << "!" << endl;
    cout << "'" << text << "'" << endl;
  } else return;
}


