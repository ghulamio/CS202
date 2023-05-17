/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#include<iostream>
#include<fstream>

#include"SimulationMgr.h"

using namespace std;

SimulationMgr::SimulationMgr(string data) {
  ifstream dataStream;
  dataStream.open(data);
  vector<string> creatures;
  vector<string> foods;
  
  // Load the creatures into a string vector
  string line1;
  getline(dataStream, line1);
  int N = stoi(line1);
  for (int i = 0; i < N; i++) {
    string creatureData;
    getline(dataStream, creatureData);
    creatures.push_back(creatureData);
  }

  // Load the foods into a string vector
  while (dataStream) {
    string foodData;
    getline(dataStream, foodData);
    if (foodData.find(",") != string::npos) { 
      foods.push_back(foodData);
    }
  }

  gameLoop = new GameLoop(foods.size(), creatures, foods);
}

SimulationMgr::~SimulationMgr() {
  delete gameLoop;
}

void SimulationMgr::startSimulation() {
  int loop = 0;
  while (gameLoop->aliveCreatures()) {
    gameLoop->creaturesOutput();    
    gameLoop->spawnFood(loop);
    gameLoop->fight();
    gameLoop->eat();
    gameLoop->loseHealth();
    loop++;
  }  
}

int main(int argc, const char** argv) {
  SimulationMgr s(argv[1]);
  s.startSimulation();
  return 0;
}