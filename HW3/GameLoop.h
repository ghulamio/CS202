#ifndef __GameLoop_H
#define __GameLoop_H

#include<vector>
#include<string>
#include"Creature.h"
#include"minHeap.h"
#include"maxHeap.h"

class GameLoop{
  private:
  std::vector<Creature> creatures;
  minHeap* foodToSpawn;
  maxHeap* foodSpawned;


  public:
  GameLoop(int);
  ~GameLoop();

  void initCreatures(const std::vector<std::string>&);
  void initSpawnHeap(const std::vector<std::string>&);

  void printAllCreatures();
  void placeNewFood(const int);
  void resolveFights();
  void consumeFood();
  void decrementHealths(); 

  bool allCreaturesDead() const;
  
  const std::vector<Creature>& getCreatureInfo() const;
  maxHeap* getmaxHeap() const;

};

#endif