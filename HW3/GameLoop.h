#ifndef _GAMELOOP_H
#define _GAMELOOP_H

#include<vector>
#include<string>

#include"Creature.h"
#include"minHeap.h"
#include"maxHeap.h"

using namespace std;

class GameLoop{
  public:
    GameLoop(int capacity, const vector<string>& c, const vector<string>& f);
    ~GameLoop();

    bool aliveCreatures() const;

    void creaturesOutput();
    void spawnFood(const int);
    void fight();
    void eat();
    void loseHealth(); 


  private:
    vector<Creature> creatures;
    minHeap* foodToSpawn;
    maxHeap* foodSpawned;
};

#endif