#include <iostream>
#include <string>

#include "AccompanimentHashing.h"
#include "SnackHashing.h"

using namespace std;


int main() {
  SnackHashing snackHashing;
  AccompanimentHashing accompanimentHashing;

  while (true) {
    string command;
    cin >> command;

    if (command == "S") {
      string name;
      cin >> name;

      Snack* snack = new Snack(name);
      snackHashing.addSnack(snack);
      cout << "Snack '" << name << "' created" << endl;
    } else if (command == "C") {
      string snack1, snack2;
      cin >> snack1 >> snack2;

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
    } else if (command == "D") {
      string snack1, snack2;
      cin >> snack1 >> snack2;

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
    } else if (command == "L") {
      string snack1;
      cin >> snack1;

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
    } else if (command == "Q") {
      string snack1, snack2;
      cin >> snack1 >> snack2;

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
    } else if (command == "X") {
      break;
    } else {
      cout << "Invalid command" << endl;
    }
  }

  return 0;
}