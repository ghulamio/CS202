#ifndef SIMULATION_MGR_H
#define SIMULATION_MGR_H

#include <vector>
#include <string>

#include "Creature.h"
#include "Food.h"

using namespace std;

class SimulationMgr {
public:
    SimulationMgr(const string& inputFile);
    void runSimulation();

private:
    void loadInputFile(const string& inputFile);
    void printCreatureLocations() const;
    void addNewFood();
    void resolveFights();
    void consumeFood();
    void moveCreatures();
    void decreaseHealth();
    
    vector<Creature> creatures;
    vector<Food> availableFood;
    vector<Food> futureFood;
};

#endif