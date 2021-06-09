#include "Player.h"

using namespace std;

int main() {
  int n;
  string command;
  auto* MyPlayer = new Player;
  cout << "Enter number of tracks to add: ";
  cin >> n;
  while (n != 0) {
    MyPlayer->addTrack();
    n--;
  }
  while (true) {
    cout << "Enter command: ";
    cin >> command;
    if (command == "play") MyPlayer->play();
    else if (command == "pause") MyPlayer->pause();
    else if (command == "resume") MyPlayer->resume();
    else if (command == "stop") MyPlayer->stop();
    else if (command == "next") MyPlayer->next();
    else if (command == "exit") {
      cout << "Goodbye!";
      delete MyPlayer;
      break;
    } else cout << "Incorrect command! Try again." << endl;
  }
  return 0;
}
