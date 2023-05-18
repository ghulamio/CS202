#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "AccompanimentHashing.h"
#include "SnackHashing.h"

using namespace std;


int main(int argc, char* argv[]) {
  if (argc < 2) {
    cout << "No commands given" << endl;
    return 0;
  }

  SnackHashing snackHashing;
  AccompanimentHashing accompanimentHashing;

  string commands = argv[1];
  size_t pos = 0;
  string delimiter = "\n";
  commands += "\n";

  while ((pos = commands.find(delimiter)) != string::npos) {
    string command = commands.substr(0, pos);
    commands.erase(0, pos + delimiter.length());

    if (command[0] == 'S') {
      string name = command.substr(2);

      Snack* snack = new Snack(name);
      snackHashing.addSnack(snack);
      cout << "Snack '" << name << "' created" << endl;
    } else if (command[0] == 'C') {
      stringstream ss(command);
      string c, snack1, snack2;
      ss >> c >> snack1 >> snack2;

      Snack* snackA = snackHashing.getSnack(snack1);
      Snack* snackB = snackHashing.getSnack(snack2);

      if (snackA != nullptr && snackB != nullptr) {
        snackA->addAccompaniment(snackB);
        snackB->addAccompaniment(snackA);

        string accompanimentName = snack1 + snack2;
        Accompaniment* accompaniment = new Accompaniment(accompanimentName, snackA, snackB);
        accompanimentHashing.addAccompaniment(accompaniment);

        // cout << "Snacks '" << snack1 << "' and '" << snack2 << "' can be given together" << endl;
      
      } else {
        cout << "Snack '" << snack1 << "' or '" << snack2 << "' does not exist" << endl;
      }
    } else if (command[0] == 'D') {
      stringstream ss(command);
      string c, snack1, snack2;
      ss >> c >> snack1 >> snack2;

      Snack* snackA = snackHashing.getSnack(snack1);
      Snack* snackB = snackHashing.getSnack(snack2);

      if (snackA != nullptr && snackB != nullptr) {
        snackA->removeAccompaniment(snackB);
        snackB->removeAccompaniment(snackA);

        string accompanimentName = snack1 + snack2;
        Accompaniment* accompaniment = accompanimentHashing.getAccompaniment(accompanimentName);
        if (accompaniment != nullptr) {
          accompanimentHashing.removeAccompaniment(accompaniment);
        }

        // cout << "Snacks '" << snack1 << "' and '" << snack2 << "' can no longer be given together" << endl;
      } else {
        cout << "Snack '" << snack1 << "' or '" << snack2 << "' does not exist" << endl;
      }
    } else if (command[0] == 'L') {
      stringstream ss(command);
      string c, snack1;
      ss >> c >> snack1;

      Snack* snack = snackHashing.getSnack(snack1);

      if (snack != nullptr) {
        // cout << "Snack '" << snack1 << "' can be accompanied with: ";
        // for (Snack* accompaniment : snack->accompaniments) {
        //   cout << accompaniment->name << " ";
        // }

        for (int i = 0; i < snack->accompaniments.size; i++) {
          cout << snack->accompaniments[i]->name << " ";
        }
        cout << endl;
      } else {
        cout << "Snack '" << snack1 << "' does not exist" << endl;
      }
    } else if (command[0] == 'Q') {
      stringstream ss(command);
      string c, snack1, snack2;
      ss >> c >> snack1 >> snack2;

      Snack* snackA = snackHashing.getSnack(snack1);
      Snack* snackB = snackHashing.getSnack(snack2);

      if (snackA != nullptr && snackB != nullptr) {
        string accompanimentName = snack1 + snack2;
        Accompaniment* accompaniment = accompanimentHashing.getAccompaniment(accompanimentName);

        if (accompaniment != nullptr) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      } else {
        cout << "Snack '" << snack1 << "' or '" << snack2 << "' does not exist" << endl;
      }
    } else if (command[0] == 'X') {
      break;
    } else {
      cout << "Invalid command" << endl;
    }
  }
  return 0;
}
