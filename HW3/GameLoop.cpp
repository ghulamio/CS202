#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include"GameLoop.h"
#include"Point2D.h"

GameLoop::GameLoop(int HEAP_SIZE) {
  foodToSpawn = new minHeap(HEAP_SIZE);
  foodSpawned = new maxHeap(HEAP_SIZE);
}

GameLoop::~GameLoop() {
  delete foodToSpawn;
  delete foodSpawned;
}

void GameLoop::initCreatures(const std::vector<std::string>& creaturesFromTxt) {
  std::map<int, std::string> creaturesMappedById;
  for (auto itr = creaturesFromTxt.begin(); itr != creaturesFromTxt.end(); itr++) {
    std::stringstream currentStream(*itr);
    std::string IdString;
    std::getline(currentStream, IdString, ',');
    int id = std::stoi(IdString);
    creaturesMappedById[id] = *itr;
  }

  for (auto itr = creaturesMappedById.begin(); itr != creaturesMappedById.end(); itr++) {
    std::stringstream currentStream(itr->second);
    std::string* data = new std::string[4];
    int i = 0;
    while (std::getline(currentStream, data[i], ',')) {
      i++;
    }
    int id = std::stoi(data[0]);
    double x = std::stod(data[1]);
    double y = std::stod(data[2]);
    int health = std::stoi(data[3]);
    delete[] data;

    Creature temp(id, x, y, health);
    creatures.push_back(temp);
  }
}

void GameLoop::initSpawnHeap(const std::vector<std::string>& foodsFromTxt) {
  int index = 0;
  for (auto itr = foodsFromTxt.begin(); itr != foodsFromTxt.end() ; itr++) {
    std::stringstream currentStream(*itr);
    std::string* data = new std::string[5];
    int i = 0;
    while (std::getline(currentStream, data[i], ',')) {
      i++;
    }
    int id  = std::stoi(data[0]);
    double x = std::stod(data[1]);
    double y = std::stod(data[2]);
    int quality = std::stoi(data[3]);
    int spawnTime = std::stoi(data[4]);
    delete[] data;
    Food tempFood(id , x, y, quality, spawnTime);
    foodToSpawn->insert(tempFood);
    index++;
  }
}


void GameLoop::printAllCreatures() {
  for (auto itr = creatures.begin(); itr != creatures.end(); itr++) {
    std::cout  << *itr << std::endl;
  }
}

void GameLoop::placeNewFood(const int spawnIteration) {
  Food& foodToPlace = const_cast<Food&>(foodToSpawn->getRoot());
  while (!foodToSpawn->isEmpty() && foodToPlace.getSpawnTime() == spawnIteration) {
    Food temp;
    foodToSpawn->remove(temp);
    foodSpawned->insert(temp);
    if (!foodToSpawn->isEmpty()) foodToPlace = const_cast<Food&>(foodToSpawn->getRoot());
  }
}

void GameLoop::resolveFights() {
  for (auto creatureInAction = creatures.begin(); creatureInAction != creatures.end(); creatureInAction++) {
    if (creatureInAction->isAlive()) {
      for (auto otherCreature = creatures.begin(); otherCreature != creatures.end(); otherCreature++) {
        if (otherCreature == creatureInAction) continue;
        double distanceBetween = creatureInAction->distanceBetween(*otherCreature);
        if (distanceBetween <= 2) {
          if (otherCreature->getHealth() <= creatureInAction->getHealth()) {
            otherCreature->killCreature();
          }
        }
      }
    }
  }
}

void GameLoop::consumeFood() {
  if (!foodSpawned->isEmpty()) {
    Food& bestFood = const_cast<Food&>(foodSpawned->getRoot());  
    for (auto currentCreature = creatures.begin(); currentCreature != creatures.end(); currentCreature++ ) {
      if (!foodSpawned->isEmpty() && currentCreature->isAlive() && currentCreature->distanceBetween(bestFood) <= 1) {
        Food temp;
        foodSpawned->remove(temp);
        currentCreature->regainHealth(temp.getQuality());
        if (!foodSpawned->isEmpty()) bestFood = const_cast<Food&>(foodSpawned->getRoot());
      }
    }
      
    if (!foodSpawned->isEmpty()) {
      for (auto currentCreature = creatures.begin(); currentCreature != creatures.end(); currentCreature++) {
        if (currentCreature->isAlive() && currentCreature->distanceBetween(bestFood) > 1) {
          Point2D point = currentCreature->getPoint();
          Point2D foodPosition = bestFood.getPoint();
          Point2D directionToMove = point.getPointTo(foodPosition);
          currentCreature->advance(directionToMove, foodPosition);  
        }
      } 
    }
  }
}

void GameLoop::decrementHealths() {
  for (auto itr = creatures.begin(); itr != creatures.end(); itr++) {
    if (itr->isAlive()) itr->decrementHealth();
  }
}

bool GameLoop::allCreaturesDead() const {
  bool allDead = true;
  for (auto itr = creatures.begin(); itr != creatures.end(); itr++) {
    if (itr->isAlive()) return false;
  }
  return true;
}

const std::vector<Creature>& GameLoop::getCreatureInfo() const {
  return creatures;
}

maxHeap* GameLoop::getmaxHeap() const {
  return foodSpawned;
}