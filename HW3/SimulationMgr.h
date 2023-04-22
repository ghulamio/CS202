/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#ifndef _SIMULATIONMGR_H
#define _SIMULATIONMGR_H

#include<string>
#include <vector>

#include"GameLoop.h"

using namespace std;

class SimulationMgr {
  public:
    SimulationMgr(string data);
    ~SimulationMgr();
    void startSimulation();

  private:
    GameLoop* gameLoop;
};

#endif