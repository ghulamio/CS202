/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#ifndef _GAMELOOP_H
#define _GAMELOOP_H

#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>

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
    void moveCreatureTowardsFood(vector<Creature>::iterator c, Food& f);
    void loseHealth(); 


  private:
    vector<Creature> creatures;
    minHeap* foodToSpawn;
    maxHeap* foodSpawned;
};

#endif