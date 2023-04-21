#ifndef __SIMULATIONMGR_H
#define __SIMULATIONMGR_H

#include<string>

#include"GameLoop.h"

class SimulationMgr {
  public:
    SimulationMgr(std::string filename);
    ~SimulationMgr();
    void begin();

  private:
    GameLoop* gameLoop;
};

#endif