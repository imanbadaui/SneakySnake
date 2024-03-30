#include "Snake.h"
#include "Fruit.h"
#include"player_info.h"
#include<list>
#include<iostream>
using namespace std;

Snake::Snake(int x,int y)
{
    head= 'O';
    tail= 'o';
    snakeXY.push_front(make_pair(x,y));
    snake_length = 1;
}

// takes new x,y head snake location and put in in the list
void Snake::setXY(int x, int y)
{
    snakeXY.push_front(make_pair(x,y));
    snakeXY.pop_back();

}

void Snake::getHead(int headX,int headY) const
{

    headX = snakeXY.front().first;
    headY = snakeXY.front().second;
}

char Snake::getHeadChar() const
{
    return head;
}
char Snake::getTailChar() const
{
    return tail;
}
void Snake::snake_dir (const Directions & dir,int rows, int columns)
{
    if (dir != Directions::STOP)
    {
        int headX = snakeXY.front().first;
        int headY = snakeXY.front().second;

        if (dir == Directions::RIGHT)
        {
            ++headX;
        }
        else if (dir == Directions::LEFT)
        {
            --headX;
        }
        else if (dir == Directions::UP)
        {
            --headY;
        }
        else if (dir == Directions::DOWN)
        {
            ++headY;
        }



        if (headX == 0)
        {
            headX = columns-2;
        }
//1 because grid starts from row 1, row 0 for player name and score.
        else if (headY == 1)
        {
            headY = rows-2;
        }
        else if (headX == columns-1)
        {
            headX = 1;
        }
        else if (headY == rows-1)
        {
            headY = 2;
        }

        setXY(headX, headY);
    }
}


bool Snake::eat ( Fruit &fruit,Player_Info &player)
{

    if(snakeXY.front().first == fruit.fruitX && snakeXY.front().second == fruit.fruitY)
    {
        snakeXY.push_front(make_pair(fruit.fruitX,fruit.fruitY));
        snake_length++;
        player.setPlayerScore(player.getPlayerScore() + 1);
        return true;

    }
    return false;
}

//when x and y of head will be the same numbers as x and Y for any of tail positions
bool Snake::dead()
{
    bool dead = false;
    auto itr_tail  = snakeXY.begin();
    //iterator to first tail element if no tail, points to end
    ++itr_tail;
    pair<int,int> tail_element;

    while(itr_tail != snakeXY.end() && !dead)
    {

        tail_element = *itr_tail;
        if(snakeXY.front().first == tail_element.first && snakeXY.front().second == tail_element.second)
        {
            dead = true;
        }

        ++itr_tail;

    }

    return dead;
}

char Snake::print(int current_x,int current_y) const
{
    auto itr_snake =snakeXY.begin();

    if(current_x == snakeXY.front().first && current_y == snakeXY.front().second)
    {

        return getHeadChar();
    }
    else
    {
        ++itr_snake;
        for(; itr_snake != snakeXY.end() ; ++itr_snake)
        {
            pair<int,int> tailXY = *itr_snake;
            if(current_x == tailXY.first && current_y == tailXY.second)
            {
                return getTailChar();
            }
        }
    }
    return 'f';
}
