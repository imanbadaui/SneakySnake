#include "gamecontrol.h"
#include <iostream>
#include <windows.h>
#include <thread>
GameControl::GameControl()
{
    //ctor
}

void GameControl::key_directions(Directions &dir)
{


    if (GetAsyncKeyState(0x57) || GetAsyncKeyState(VK_UP))    //if press W
    {
        dir = Directions::UP;
    }
    else if (GetAsyncKeyState(0x53) || GetAsyncKeyState(VK_DOWN))    //if press S
    {
        dir = Directions::DOWN;
    }
    else if (GetAsyncKeyState(0x41) || GetAsyncKeyState(VK_LEFT))    //if press A
    {
        dir = Directions::LEFT;
    }
    else if (GetAsyncKeyState(0x44) || GetAsyncKeyState(VK_RIGHT))    //if press D
    {
        dir = Directions::RIGHT;
    }

}


void GameControl::main_grid (const Snake &snake,const Fruit &fruit, const Player_Info& player)
{
    std::cout<<"Player Name: " << player.getPlayerName() << "\t\tPlayer Score: " << player.getPlayerScore()<< std::endl;
//start from 1 to print player name and score in row 0.
    for (int row{1}; row < rows; ++row)
    {

        for (int col{0}; col < columns; ++col)
        {

            if (row == 1 || row == rows-1)
            {
                grid[row][col] = '#';
                std::cout <<grid[row][col];
            }
            else if(col == 0 || col == columns-1)
            {
                grid[row][col] = '#';
                std::cout <<grid[row][col];
            }

            else
            {
                if(snake.print(col,row) == snake.getHeadChar())
                {
                    grid[row][col] = snake.getHeadChar();
                    std::cout <<grid[row][col];
                }

                else if(fruit.print_fruit(col,row) == fruit.getFruitChar())
                {
                    grid[row][col] = fruit.getFruitChar();
                    std::cout <<grid[row][col];
                }
                else
                {
                    grid[row][col] = ' ';
                    std::cout <<grid[row][col];
                }


            }
        }
        std::cout << std::endl;
    }

}

void GameControl::edit_grid(Snake &snake,Fruit &fruit, Player_Info& player, Directions &dir)
{

    char head{snake.getHeadChar()};
    char tail{snake.getTailChar()};
    char fruitCh{fruit.getFruitChar()};
    char empty {' '};
    if (dir == Directions::STOP)
    {

        ;
    }
    else
    {
        setCursorPosition(0,0);
        std::cout<<"Player Name: " << player.getPlayerName() << "\t\tPlayer Score: " << player.getPlayerScore()<< std::endl;


        for(int row{0}; row < rows; ++row)
        {
            for(int col{0}; col < columns; ++col)
            {


                if(grid[row][col] == head)
                {
                    grid[row][col] = empty;
                    setCursorPosition(col, row);
                    std::cout<< empty;
                }
                else if(grid[row][col] == tail)
                {
                    grid[row][col] = empty;
                    setCursorPosition(col, row);
                    std::cout<< empty;
                }

                if (snake.print(col,row) == head)
                {
                    grid[row][col] = head;
                    setCursorPosition(col, row);
                    std::cout << grid[row][col];

                }
                else if(snake.print(col,row) == tail)
                {
                    grid[row][col] = tail;
                    setCursorPosition(col, row);
                    std::cout << grid[row][col];

                }
                else if(fruit.print_fruit(col,row) == fruitCh)
                {
                    grid[row][col] = fruitCh;
                    setCursorPosition(col, row);
                    std::cout << grid[row][col];

                }

            }
        }

    }
}

void GameControl::setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}


void GameControl::game_speed(Player_Info& player)
{


    if (player.getPlayerScore() >= 5)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds{ 50 });
    }
    else
    {
        std::this_thread::sleep_for(std::chrono::milliseconds{ 100 });
    }
}

GameControl::~GameControl()
{
    //dtor
}
