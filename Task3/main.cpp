#include "Monitor.h"

int main() {
  string command;
  Monitor M;
  M.W.createWindow();
  while (true) {
    cout << "Enter command: ";
    cin >> command;
    if (command == "move") M.W.move();
    else if (command == "resize") M.W.resize();
    else if (command == "display") M.display();
    else if (command == "close") {
      cout << "Goodbye!" << endl;
      break;
    } else cout << "Incorrect command! Try again." << endl;
  }
  return 0;
}
