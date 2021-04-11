#include "player.h"
#include "player-move.h"
#include "game-result.h"

#include <iostream>
#include <sstream>
using namespace std;


void Player::init(int id, char symbol, string name) {
    this->id = id;
    this->symbol = symbol;
    this->name = name;
}

PlayerMove Player::getMove() const {
    PlayerMove pMove;
    cout <<"Player '"<< symbol << "'  move ROW COL: ";
    string str;
    getline(cin, str);
    stringstream ss(str);
    ss >> pMove.x >> pMove.y;
    // board's index starts from 0 hence, adjust for board
    pMove.x--;
    pMove.y--;
    return pMove;
}

void Player::showResult(const GameResult &result) const {
    if (result.isDraw()) {
        cout << "\nGame DRAW\n";
        return;
    }
    cout << "\nPlayer " << name << "('" << symbol << "') ";
    if (result.getWinner() == id) {
        cout << "WON";
    } else {
        cout << "LOSE";
    }
    cout << " this match!!\n";
}
