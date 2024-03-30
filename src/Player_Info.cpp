#include "Player_Info.h"

Player_Info::Player_Info(std::string player_name, int score): player_name{player_name}, score{score}
{
    //ctor
}

void Player_Info::setPlayerName(std::string player_name)
{
    player_name=player_name;
}
std::string Player_Info::getPlayerName() const
{
    return player_name;
}

void Player_Info::setPlayerScore(int player_score)
{
    score= player_score;
}
int Player_Info::getPlayerScore() const
{
    return score;
}

Player_Info::~Player_Info()
{
    //dtor
}
