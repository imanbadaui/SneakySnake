#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H
#include <string>

class Player_Info
{
public:
    Player_Info(std::string player_name, int score=0);
    void setPlayerName(std::string player_name);

    std::string getPlayerName() const;
    void setPlayerScore(int player_score);
    int getPlayerScore() const;
    virtual ~Player_Info();

protected:
    std::string player_name;
    int score;
};

#endif // PLAYER_INFO_H
