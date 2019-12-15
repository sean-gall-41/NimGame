/*
 * CS 106B Boggle
 * This file contains the main program and user interface for running your
 * Boggle game.  We provide you a skeleton of this file that contains a shell
 * of the overall logic, but you must complete the playOneGame function.
 *
 * The playOneGame function talks to the Boggle class that you will write.
 * This file should contain all user interaction (cout / cin), while the Boggle
 * class should contain ALL game state such as the 16 letter cubes, the set of
 * words that have been formed, the algorithms for searching for words, etc.
 *
 * Please do not modify this provided file. Your turned-in files should work
 * with an unmodified version of all provided code files.
 *
 * Version: Sat 2014/02/05
 * Author : Marty Stepp
 */

#include <iostream>
//#include <string>
#include "console.h"
//#include "random.h"
#include "simpio.h"
//#include "strlib.h"

// function prototype declarations
void playOneGame();

int main() {
    // play games repeatedly until user decides to quit
    while (true) {
        playOneGame();
        std::cout << std::endl;
        if (!getYesOrNo("Play again (Y/N)? ")) {
            break;
        }
    }
    std::cout << "Have a nice day." << std::endl;
    //BoggleGUI::shutdown();
    return 0;
}


