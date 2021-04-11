#pragma once

#include "player.h"

class GameResult {
private:
    typedef enum {UNDEFINED, WON, DRAW} Result;
    Result result;
    Player::Id winnerPlayer;
public:
    GameResult():result(UNDEFINED), winnerPlayer(Player::INVALID_ID) { }
    bool isDraw() const { return result == DRAW; }
    bool isWon() const { return result == WON; }
    Player::Id getWinner() const { return winnerPlayer; }
    void setWinner(Player::Id id) {
        winnerPlayer = id;
        result = WON;
    }
    void setDraw() {
        winnerPlayer = Player::INVALID_ID;
        result = DRAW;
    }
};


