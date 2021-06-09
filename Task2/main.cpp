#include "Phone.h"

using namespace std;

int main() {
  auto* MyPhone = new Phone;
  cout << "Hello!" << endl;
  string command;
  while (true) {
    cout << "Enter command: ";
    cin >> command;
    if (command == "add") MyPhone->add();
    else if (command == "call") MyPhone->call();
    else if (command == "sms") MyPhone->sms();
    else if (command == "exit") {
      cout << "Goodbye!";
      break;
    } else cout << "Incorrect command! Try again.";
  }
  delete MyPhone;
  return 0;
}
