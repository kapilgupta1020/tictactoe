#pragma once

#include "player-move.h"

#include <string>
using namespace std;

class GameResult;

/**
 * A class represent player of the game
 **/

class Player {
public:
    typedef int Id;
    static const Id INVALID_ID = -1;
    Player() : id(INVALID_ID), symbol(0) { }
    void init(int n, char symbol, string name = "");
    PlayerMove getMove() const; // get player's move input
    void showResult(const GameResult &result) const; // show game of result to player
    Player::Id getId() const { return id; }
    const char getSymbol() const { return symbol; }
    const string& getName() const { return name; }
private:
    Id id; // player id uniq for this player
    char symbol;
    string name;
};
