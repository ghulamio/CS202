#include<iostream>
#include<fstream>
#include<vector>
#include<string>


#include"Point2D.h"
#include"GameLoop.h"
#include"SimulationMgr.h"

using namespace std;


SimulationMgr::SimulationMgr(string filename) {
  ifstream inputStream;
  inputStream.open(filename);
  vector<string> creatures;
  vector<string> foods;
  
  // Process the creatures
  string line1;
  getline(inputStream, line1);
  int N = stoi(line1);
  for (int i = 0; i < N; i++) {
    string inputCreature;
    getline(inputStream, inputCreature);
    creatures.push_back(inputCreature);
  }

  // Process the foods
  while (inputStream) {
    string inputFoods;
    getline(inputStream, inputFoods);
    if (inputFoods.find(",") != string::npos)
      foods.push_back(inputFoods);
  }

  gameLoop = new GameLoop(foods.size());
  gameLoop->initCreatures(creatures);
  gameLoop->initSpawnHeap(foods);
}

SimulationMgr::~SimulationMgr() {
  delete gameLoop;
}

void SimulationMgr::begin() {
  int GameLoopIteration = 0;
  while (!gameLoop->allCreaturesDead()) {
    gameLoop->printAllCreatures();    
    gameLoop->placeNewFood(GameLoopIteration);
    gameLoop->resolveFights();
    gameLoop->consumeFood();
    gameLoop->decrementHealths();
    GameLoopIteration++;
  }  
}

int main(int argc, const char** argv) {
  SimulationMgr mgr(argv[1]);
  mgr.begin();
}