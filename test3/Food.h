#ifndef FOOD_H
#define FOOD_H

class Food {
public:
    Food(int id, int spawnTime, double x, double y, int quality);
    int getId() const;
    int getSpawnTime() const;
    double getX() const;
    double getY() const;
    int getQuality() const;

private:
    int id, spawnTime;
    double x, y;
    int quality;
};

#endif