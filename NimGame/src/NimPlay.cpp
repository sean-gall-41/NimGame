// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header
#include "simpio.h"
#include "NimGame.h"

void printInstructions(nimGame& game);
void announceResult(nimGame& game);

void playOneGame() {
    nimGame myGame;
    printInstructions(myGame);
    while (myGame.getNCoins() > 1) {
        std::cout << "There are " << myGame.getNCoins() << " coins in the pile." << std::endl;
        if (myGame.getWhoseTurn() == HUMAN) {
            myGame.setNCoins(myGame.getNCoins() - myGame.getMovePlayer(myGame.getWhoseTurn()));
        } else {
            int nTaken = myGame.getMovePlayer(myGame.getWhoseTurn());
            std::cout << "I'll take " << nTaken << "." << std::endl;
            myGame.setNCoins(myGame.getNCoins() - nTaken);
        }
        myGame.setWhoseTurn(opponent(myGame.getWhoseTurn()));
    }
    announceResult(myGame);
}

void printInstructions(nimGame &game) {
    std::cout << "Welcome to the game of Nim!" << std::endl;
    std::cout << "In this game, we will start with a pile of" << std::endl;
    std::cout << getN_COINS(game) << " coins on the table. On each turn, you" << std::endl;
    std::cout << "and I will alternately take between 1 and" << std::endl;
    std::cout << getMAX_MOVE(game) << " coins from the table. The player who" << std::endl;
    std::cout << "takes the last coin loses." << std::endl << std::endl;
    getLine("Press Enter to begin the game ... ");
}

void announceResult(nimGame& game) {
    if (game.getNCoins() == 0) {
        std::cout << "You took the last coin. You lose." << std::endl;
    } else {
        std::cout << "There is only one coin left." << std::endl;
        if (game.getWhoseTurn() == HUMAN) {
            std::cout << "I win." << std::endl;
        } else {
            std::cout << "I lose." << std::endl;
        }
    }
}
