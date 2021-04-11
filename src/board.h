#pragma once

#include <vector>
using namespace std;

// forward declaration
class PlayerMove;
class Player;

/**
 * A class to represent a game board of size NxN
 */
class Board {
private:
    vector<vector<char>> b; // 2-D array to represent board
    int N; // dimension of board
    int moveCounter;
public:
    Board() = delete;
    Board(int n);
    void reset(); // reset game board
    int getSize(); // returns dimension of board
    bool applyMove(const Player &pl, const PlayerMove &plMove); // applies player's move on board
    bool isValidCell(const PlayerMove &pMove);
    bool isEmptyCell(const PlayerMove &pMove);
    bool isFull();
    bool possibleWin(const PlayerMove &pMove);
    void show();
};
