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
  MyContact->setContact();
  phonebook.push_back(*MyContact);
  delete MyContact;
}

Number Phone::getNumber() {
  bool found = false;
  auto *line = new Number;
  cout << "Enter name or number: ";
  line->setNumber();
  if (!line->isCorrect()) {
    for (auto &i : phonebook) {
      if (line->getNumber() == i.getContact().first) {
        line->putNumber(i.getContact().second);
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "Contact not found!" << endl;
      Number n;
      line->putNumber(n);
    }
  }
  return *line;
}

void Phone::call() {
  string s = this->getNumber().getNumber();
  if (s != "NULL") cout << "Calling " << s << "..." << endl;
  else return;
}

void Phone::sms() {
  string s = this->getNumber().getNumber();
  if (s != "NULL") {
    string text;
    cin.ignore();
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Sent to " << s << "!" << endl;
    cout << "'" << text << "'" << endl;
  } else return;
}


