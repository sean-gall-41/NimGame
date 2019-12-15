// This is a .h file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#ifndef _NIM_GAME_H
#define _NIM_GAME_H

enum Player {HUMAN, COMPUTER};

Player opponent(Player player);

class nimGame {

public:

    nimGame(); //only need to initialize nCoins and whoseTurn
    int findGoodMove(int nCoins);
    bool isBadPosition(int nCoins);
    Player getWhoseTurn();
    void setWhoseTurn(Player currentTurn);
    int getNCoins();
    void setNCoins(int nCoins);
    int getMovePlayer(Player player);
    friend int getN_COINS(nimGame game);
    friend int getMAX_MOVE(nimGame game);

private:

    const int N_COINS = 13;
    const int MAX_MOVE = 3;
    const int NO_GOOD_MOVE = -1;
    const Player STARTING_PLAYER = HUMAN;
    int nCoins;
    Player whoseTurn;
    int userMove();
    int computerMove();

};

int getN_COINS(nimGame game);
int getMAX_MOVE(nimGame game);


#endif // _NIM_GAME_H
