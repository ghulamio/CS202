#ifndef CREATURE_H
#define CREATURE_H

class Creature{
    public:
        Creature(int id, double x, double y, int health);
        int getId() const;
        double getX() const;
        double getY() const;
        int getHealth() const;
        void setHealth(int health);
        void move(double dx, double dy);
        void attack(Creature& other);
        bool isAlive() const;
        
    private:
        int id;
        double x, y;
        int health;
};

#endif