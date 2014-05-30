/* 
 * File:   main.cpp
 * Author: Toshiki Arita
 *
 * Created on May 28, 2014, 4:11 AM
 */

#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>


using namespace std;

/*
 *      Usage : mastermind enable1.txt
 */

int main(int argc, char** argv) {


    string pick; // Game Difficulty
    vector<string> wordBank; // Usable words
    vector<string> possible; // 0-9 are possible answers. 10 is the correct answer.

    //---- Pick difficulty----
    cout << "HI THERE WELCOME TO A GAME OF FALLOUT'S HACKING GAME!\n" << //Pick difficulty
            "DIFFICULTY? (1-5)?\n";
    cin >> pick;

    while (pick < "1" || pick > "5") { // No chars plz
        cout << "TRY AGAIN PLEASE\n";
        cin >> pick;
    }

    //----Open File----
    ifstream readBank;
    string file = argv[1];
    while (!readBank.is_open()) { // Keep asking for file name if not open
        try {
            readBank.open(file.c_str());
            if (!readBank.good())
                throw 1;
        } catch (int x) {
            cout << "BAD FILE NAME! Please re enter.\n";
            cin >> file;
        }
    }
    //----Fill Word Bank----
    while (readBank.good()) {
        string line;
        getline(readBank, line);
        wordBank.push_back(line);
    }
    //----Pick Possibles & Correct Word----
    int count;
    srand(time(NULL)); // Set seed for rand())
    while (true) {
        int randomIndex = rand() % wordBank.size() + 1; // Random integer from 1 to wordBank size
        try {
            //            cout << randomIndex << " " << wordBank[randomIndex].length() - 1 << " " << wordBank[randomIndex] << endl;     DEBUG
            //            cout << wordBank[randomIndex].length() - 1 << " " << atoi(pick.c_str()) * 3 << endl;                          DEBUG
            if (wordBank[randomIndex].length() - 1 == atoi(pick.c_str()) * 3) { // Found (difficulty * 3) length word
                //                cout << randomIndex << "  Picked Word Is            " << wordBank[randomIndex] << endl;               DEBUG
                possible.push_back(wordBank[randomIndex]);

                count++;
                if (count == 10) {
                    possible.push_back(possible[rand() % possible.size() + 1]);
                    break;
                }
            }
        } catch (const std::out_of_range& oor) {
            cerr << "Out of Range error: " << oor.what() << '\n';
        }

    }

    //----Print Possible Words----
    for (int i = 0; i < 10; i++) //                                                                                                     DEBUG
        cout << "Possible word #" << i << " " << possible[i] << endl;

    //----Get Guess----
    int cc = 0; // Correct Count
    string guess;

    for (int i = 0; i < 4; i++) {

        //---Get Valid Guess---
        while (guess.length() != atoi(pick.c_str()) * 3) {
            cout << "Guess (" << 4 - i << " left) ?\n";
            cin >> guess;
            if (guess.length() != atoi(pick.c_str()) * 3)
                cout << "Length needs to be " << atoi(pick.c_str()) * 3 << " letters long. re enter\n";
        } // while. get one guess

        //--- Count # Correct---
        for (int j = 0; j < atoi(pick.c_str()) * 3; j++) {
            if (guess[j] == possible[10][j]) {
                cc++;
            }
        }// for. count correct

        //---Show Result---
        if (cc == atoi(pick.c_str()) * 3) {
            cout << "CONGRATS YOU WON THE GAME!!!\n";
            return 0;
        } else
            cout << cc << "/" << atoi(pick.c_str()) * 3 << " correct\n";

        //---Reset for next turn---
        cc = 0;
        guess = "";
    }// for. pick four guesses

    cout << "\nGood try!\n";

    return 0;
}

