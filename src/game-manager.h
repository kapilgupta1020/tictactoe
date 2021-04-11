#pragma once

#include <vector>

#include "board.h"
#include "player.h"
#include "game-result.h"

using namespace std;

/**
 * A class representing game manager. This is responsible to run game.
 * Decides who should play next.
 * Updates game state on every player's move
**/
class GameManager {
private:
    enum class GameState {
        UNDEFINED = 0,
        INPLAY,
        FINISH,
    };
    Board board; // on this board game will be played
    Player::Id nextPlayer;
    vector<Player> players;
    GameState gameState;
    GameResult gameResult;
protected:
    const Player& getNextPlayer() const { return players[nextPlayer]; }
    void setNextPlayer() {
        nextPlayer++;
        nextPlayer %= players.size();
    }
public:
    GameManager(int N);
    GameManager() = delete;
    void start(); // starts game
    bool play();
    GameState getGameState() const { return gameState; }
    void showGameState();
};
