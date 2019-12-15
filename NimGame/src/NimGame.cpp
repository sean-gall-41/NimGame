// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "NimGame.h"
#include <iostream>
#include "simpio.h"

Player opponent(Player player) {
    return (player == HUMAN) ? COMPUTER : HUMAN;
}

nimGame::nimGame() {
    nCoins = N_COINS;
    whoseTurn = STARTING_PLAYER;
}


int nimGame::findGoodMove(int nCoins) {
    int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
    for (int nTaken = 1; nTaken <= limit; nTaken++) {
        if (isBadPosition(nCoins - nTaken)) return nTaken;
    }
    return NO_GOOD_MOVE;
}

bool nimGame::isBadPosition(int nCoins) {
    if (nCoins == 1) return true;
    return findGoodMove(nCoins) == NO_GOOD_MOVE;
}

Player nimGame::getWhoseTurn() {
    return whoseTurn;
}

void nimGame::setWhoseTurn(Player currentTurn) {
    whoseTurn = currentTurn;
}

int nimGame::getNCoins() {
    return nCoins;
}

void nimGame::setNCoins(int nCoins) {
    this->nCoins = nCoins;
}

int nimGame::getMovePlayer(Player player) {
    if (player == HUMAN) return userMove();
    else return computerMove();
}

int nimGame::userMove() {
    while (true) {
        int nTaken = getInteger("How many would you like? ");
        int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
        if (nTaken > 0 && nTaken <= limit) return nTaken;
        std::cout << "That's cheating! Please choose a number";
        std::cout << " between 1 and " << limit << "." << std::endl;
        std::cout << "Ther are " << nCoins << " coins in the pile." << std::endl;
    }
}

int nimGame::computerMove() {
    int nTaken = findGoodMove(nCoins);
    return (nTaken == NO_GOOD_MOVE) ? 1 : nTaken;
}

int getN_COINS(nimGame game) {
    return game.N_COINS;
}

int getMAX_MOVE(nimGame game) {
    return game.MAX_MOVE;
}

