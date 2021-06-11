#include "Monitor.h"

int main() {
  string command;
  Monitor M;
  while (true) {
    cout << "Enter command: ";
    cin >> command;
    if (command == "move") M.move();
    else if (command == "resize") M.resize();
    else if (command == "display") M.display();
    else if (command == "close") {
      cout << "Goodbye!" << endl;
      break;
    } else cout << "Incorrect command! Try again." << endl;
  }
  return 0;
}
