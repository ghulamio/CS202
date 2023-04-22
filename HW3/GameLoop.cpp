/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#include"GameLoop.h"

using namespace std;

GameLoop::GameLoop(int capacity, const vector<string>& creaturesData, const vector<string>& foodData) {
  foodToSpawn = new minHeap(capacity);
  foodSpawned = new maxHeap(capacity);

  map<int, string> creatureDict;
  for (auto c = creaturesData.begin(); c != creaturesData.end(); c++) {
    stringstream ss(*c);
    string sId;
    getline(ss, sId, ',');
    int id = stoi(sId);
    creatureDict[id] = *c;
  }

  for (auto c = creatureDict.begin(); c != creatureDict.end(); c++) {
    stringstream ss(c->second);
    string* cTemp = new string[4];

    int i = 0;
    while (getline(ss, cTemp[i], ',')) {
      i++;
    }

    int id = stoi(cTemp[0]);
    double x = stod(cTemp[1]);
    double y = stod(cTemp[2]);
    int health = stoi(cTemp[3]);
    delete[] cTemp;

    Creature temp(id, x, y, health);
    creatures.push_back(temp);
  }

  for (auto f = foodData.begin(); f != foodData.end() ; f++) {
    stringstream ss(*f);
    string* fTemp = new string[5];

    int i = 0;
    while (getline(ss, fTemp[i], ',')) {
      i++;
    }

    int id  = stoi(fTemp[0]);
    double x = stod(fTemp[1]);
    double y = stod(fTemp[2]);
    int quality = stoi(fTemp[3]);
    int spawnTime = stoi(fTemp[4]);
    delete[] fTemp;

    Food tempFood(id , x, y, quality, spawnTime);
    foodToSpawn->insert(tempFood);
  }
}


GameLoop::~GameLoop() {
  delete foodToSpawn;
  delete foodSpawned;
}

void GameLoop::creaturesOutput() {
  for (auto c = creatures.begin(); c != creatures.end(); c++) {
    cout  << *c << endl;
  }
}

void GameLoop::spawnFood(const int spawnIteration) {
  Food& f = const_cast<Food&>(foodToSpawn->getRoot());

  while (foodToSpawn->isOccupied() && f.getSpawnTime() == spawnIteration) {
    Food temp;
    foodToSpawn->remove(temp);
    foodSpawned->insert(temp);

    if (foodToSpawn->isOccupied()) {
      f = const_cast<Food&>(foodToSpawn->getRoot());
    }
  }
}

void GameLoop::fight() {
  for (auto c = creatures.begin(); c != creatures.end(); c++) {
    if (c->isAlive()) {
      for (auto c1 = creatures.begin(); c1 != creatures.end(); c1++) {
        // Check if creatures are not the same
        if (c != c1) {
          if (c->getPoint().hypotenuse(c1->getPoint()) <= 2) {
            if (c1->isNotHealthier(*c)) {
              c1->killCreature();
            }
          }
        }
      }
    }
  }
}

void GameLoop::eat() {
  Food& f = const_cast<Food&>(foodSpawned->getRoot());  
  for (auto c = creatures.begin(); c != creatures.end(); c++ ) {
    // Check if food is spawned
    if (foodSpawned->isOccupied() && c->isAlive() && c->getPoint().hypotenuse(f.getPoint()) <= 1) {
      Food temp;
      foodSpawned->remove(temp);
      c->regainHealth(temp.getQuality());
      if (foodSpawned->isOccupied()) {
        f = const_cast<Food&>(foodSpawned->getRoot());
      }
    }
  }
  // Check if food is still spawned
  if (foodSpawned->isOccupied()) {
    for (auto c = creatures.begin(); c != creatures.end(); c++) {
      if (c->isAlive() && c->getPoint().hypotenuse(f.getPoint()) > 1) {
        moveCreatureTowardsFood(c, f);
      }
    } 
  }
}

void GameLoop::moveCreatureTowardsFood(vector<Creature>::iterator c, Food& f) {
  Point2D fPoint = f.getPoint();
  Point2D cPoint = c->getPoint();
  Point2D p = cPoint.getPointTo(fPoint);

  // Move creature towards food
  c->advance(p, fPoint);  
}

void GameLoop::loseHealth() {
  for (auto c = creatures.begin(); c != creatures.end(); c++) {
    if (c->isAlive()) {
      c->decrementHealth();
    }
  }
}

bool GameLoop::aliveCreatures() const {
  for (auto c = creatures.begin(); c != creatures.end(); c++) {
    if (c->isAlive()) return true;
  }
  return false;
}