#include "game-manager.h"

GameManager::GameManager(int N) : board(N), gameState(GameState::UNDEFINED),
        nextPlayer(-1) {
    srand((unsigned) time(0));

    players.push_back(Player());
    players.push_back(Player());

    players[0].init(0, 'X'); // player 1 have id 0
    players[1].init(1, 'O'); // player 2 have id 1
}

void GameManager::start() {
    board.reset();
    gameState = GameState::INPLAY;
    nextPlayer = rand() % players.size(); // randomly 0 or 1
}

bool GameManager::play() {
    while (gameState == GameState::INPLAY) {
        board.show(); // show board
        const Player &curPlayer = getNextPlayer();

        PlayerMove pMove = curPlayer.getMove();
        while (!board.applyMove(curPlayer, pMove)) {
            pMove = curPlayer.getMove();
        }

        setNextPlayer();

        // if current move makes any player win?
        if (board.possibleWin(pMove)) {
            gameState = GameState::FINISH;
            gameResult.setWinner(curPlayer.getId());
        } else if (board.isFull()) { // Draw if board is full and no winner yet
            gameState = GameState::FINISH;
            gameResult.setDraw();
        }
    }
    board.show();
    for (const Player &pl : players) {
        pl.showResult(gameResult);
    }

    return true;
}

