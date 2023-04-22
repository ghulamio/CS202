#ifndef _SIMULATIONMGR_H
#define _SIMULATIONMGR_H

#include<string>

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