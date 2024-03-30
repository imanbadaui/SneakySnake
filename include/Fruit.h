#ifndef FRUIT_H
#define FRUIT_H

#include "Snake.h"
class Snake;
class Fruit
{
public:
    friend class Snake;
    Fruit(int rows, int columns);
    void xyGenerator(int rows, int columns);
    char print_fruit (int current_x, int current_y) const;
    int get_fruitX() const;
    int get_fruitY() const;
    char getFruitChar() const;


private:
    char fruit;
    int fruitX,fruitY;
};

#endif // FRUIT_H
