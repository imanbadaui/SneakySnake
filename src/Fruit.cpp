#include <iostream>
#include <random>
#include <thread>
#include "Fruit.h"

using namespace std;

default_random_engine engine{ static_cast<unsigned int>(time(NULL))};

Fruit::Fruit(int rows, int columns)
    : fruit{'F'}
{
    xyGenerator(rows, columns);
}

int Fruit::get_fruitX()const
{
    return fruitX;
}

int Fruit::get_fruitY()const
{
    return fruitY;
}

char Fruit::getFruitChar() const
{
    return fruit;

}

void Fruit::xyGenerator(int rows, int columns)
{
    uniform_int_distribution<int> random{2,rows-2};
    fruitX = random(engine);
    fruitY = random(engine);
}

char Fruit::print_fruit (int current_x, int current_y) const
{

    if (current_x == fruitX && current_y == fruitY)
        return getFruitChar();

}
