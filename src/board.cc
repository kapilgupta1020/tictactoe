#include "board.h"
#include "player.h"
#include "player-move.h"

#include <iostream>
using namespace std;

Board::Board(int n) {
    N = n;
    moveCounter = 0;
    for (int i=0; i < N; i++) {
        b.push_back(vector<char>(N));
        for (int j=0; j< N; j++) {
            b[i][j] = ' ';
        }
    }
}

void Board::reset() {
    moveCounter = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            b[i][j]=' ';
        }
    }
}

void Board::show() {
    cout << endl;
    cout << " |";
    // 1|2|3|
    for (int i=1; i<=N; i++) {  cout << " " << i << " |"; }
    cout <<endl;
    // ------
    cout << "-+";
    for (int i=1; i<=N; i++) {  cout << "---+"; }
    cout << endl;

    for (int i=0; i<N; i++) {
        cout << i+1 << "|";
        for (int j=0; j<N; j++) {
            cout << " " << b[i][j] << " |";
        }
        cout << endl;

        cout << "-+";
        for (int i=1; i<=N; i++) {  cout << "---+"; }
        cout << endl;
    }
    cout << endl;
}

int Board::getSize() {
    return N;
}

bool Board::isFull() {
    return (moveCounter >= N*N);
}

bool Board::isValidCell(const PlayerMove &pMove) {
    if (pMove.x >= 0 && pMove.x < N &&
        pMove.y >= 0 && pMove.y < N) {
        return true;
    }
    return false;
}

bool Board::isEmptyCell(const PlayerMove &pMove) {
   return (isValidCell(pMove) && b[pMove.x][pMove.y] == ' ');
}

bool Board::applyMove(const Player &p, const PlayerMove &pMove) {
    if (isEmptyCell(pMove)) {
        b[pMove.x][pMove.y] = p.getSymbol();
        moveCounter++;
        return true;
    }
    return false;
}

bool Board::possibleWin(const PlayerMove &pMove) {
    if (isEmptyCell(pMove)) return false;

    char symbol = b[pMove.x][pMove.y];

    bool winFlag = false;

    int i=0;
    // check if row is complete
    for (i = 0; i < N; i++) {
        if (b[pMove.x][i] != symbol) {
            break;
        }
    }
    if (i == N) { return true; }

    // check if col is complete
    for (i = 0; i < N; i++) {
        if (b[i][pMove.y] != symbol) {
            break;
        }
    }
    if (i == N) { return true; }

    // check if main diagonal is complete
    for (i = 0; i < N; i++) {
        if (b[i][i] != symbol) {
            break;
        }
    }
    if (i == N) { return true; }

    // check if secondary diagonal is complete
    for (i = 0; i < N; i++) {
        if (b[i][N-i-1] != symbol) {
            break;
        }
    }
    if (i == N) { return true; }

    return false;
}

