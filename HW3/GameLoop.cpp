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
    int creatureId = std::stoi(data[0]);





    double x = std::stod(data[1]);
    double y = std::stod(data[2]);


    int health = std::stoi(data[3]);
    delete[] data;

    Creature temp(creatureId, x, y, health);
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
    int foodId = std::stoi(data[0]);
    double x = std::stod(data[1]);
    double y = std::stod(data[2]);
    int quality = std::stoi(data[3]);
    int spawnTime = std::stoi(data[4]);
    delete[] data;
    Food tempFood(foodId, x, y, quality, spawnTime);
    foodToSpawn->heapInsertItem(tempFood);
    index++;
  }
}


void GameLoop::printAllCreatures() {
  for (auto itr = creatures.begin(); itr != creatures.end(); itr++) {
    std::cout  << *itr << std::endl;
  }
}

void GameLoop::placeNewFood(const int spawnIteration) {
  Food& foodToPlace = const_cast<Food&>(foodToSpawn->peek());
  while (!foodToSpawn->heapIsEmpty() && foodToPlace.getSpawnTime() == spawnIteration) {
    Food temp;
    foodToSpawn->heapDelete(temp);
    foodSpawned->heapInsertItem(temp);
    if (!foodToSpawn->heapIsEmpty()) foodToPlace = const_cast<Food&>(foodToSpawn->peek());
  }
}

void GameLoop::resolveFights() {
  for (auto creatureInAction = creatures.begin(); creatureInAction != creatures.end(); creatureInAction++) {
    if (creatureInAction->isAlive()) {
      for (auto otherCreature = creatures.begin(); otherCreature != creatures.end(); otherCreature++) {
        if (otherCreature == creatureInAction) continue;
        double distanceBetween = creatureInAction->distanceFromCreature(*otherCreature);
        if (distanceBetween <= 2) {
          if (otherCreature->getHealth() <= creatureInAction->getHealth()) {
            otherCreature->die();
          }
        }
      }
    }
  }
}

void GameLoop::consumeFood() {
  if (!foodSpawned->heapIsEmpty()) {
    Food& bestFood = const_cast<Food&>(foodSpawned->peek());  
    for (auto currentCreature = creatures.begin(); currentCreature != creatures.end(); currentCreature++ ) {
      if (!foodSpawned->heapIsEmpty() && currentCreature->isAlive() && currentCreature->distanceFromFood(bestFood) <= 1) {
        Food temp;
        foodSpawned->heapDelete(temp);
        currentCreature->increaseHealth(temp.getFoodQuality());
        if (!foodSpawned->heapIsEmpty()) bestFood = const_cast<Food&>(foodSpawned->peek());
      }
    }
      
    if (!foodSpawned->heapIsEmpty()) {
      for (auto currentCreature = creatures.begin(); currentCreature != creatures.end(); currentCreature++) {
        if (currentCreature->isAlive() && currentCreature->distanceFromFood(bestFood) > 1) {
          Point2D origin = currentCreature->getCoordinate();
          Point2D foodPosition = bestFood.getCoordinate();
          Vector directionToMove = origin.getVectorTo(foodPosition);
          currentCreature->moveForGameLoop(directionToMove, foodPosition);  
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