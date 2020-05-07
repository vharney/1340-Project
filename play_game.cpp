#include <iostream>
#include <iomanip>
#include <fstream>
#include "random_letter.h"
#include "print_board.h"
#include "help.h"
#include "check_word.h"
#include "score_calculator.h"
#include "mistake_adder.h"
#include "set_empty.h"
#include "save_progress.h"
#include "quit.h"
using namespace std;

void play_game(int &score, int &mistake, char &letter, char *& row_1, char *& row_2, char *& row_3, char *& row_4, char *& row_5, int &counter_1, int &counter_2, int &counter_3, int &counter_4, int &counter_5, bool &exit_game){
    string input;
    int row_number;
    bool valid;
    int word_length;
    cout << right;
    cout << setw(42) << ">> Have fun playing! <<" << endl;
    print_board(row_1, row_2, row_3, row_4, row_5, score, mistake);
    while (true){
        cout << "Letter: " << letter << endl;
        cout << "Enter Command: ";
        cin >> input;
        if (input == "1"){
            if (counter_1 < 10){
                row_1[counter_1] = letter;
                ++counter_1;
                print_board(row_1, row_2, row_3, row_4, row_5, score, mistake);
            } else {
                cout << endl << "Sorry. The row is full!" << endl << endl;
                continue;
            }
        }
        else if (input == "2"){
            if (counter_2 < 10){
                row_2[counter_2] = letter;
                ++counter_2;
                print_board(row_1, row_2, row_3, row_4, row_5, score, mistake);
            } else {
                cout << endl << "Sorry. The row is full!" << endl << endl;
                continue;
            }
        }
        else if (input == "3"){
            if (counter_3 < 10){
                row_3[counter_3] = letter;
                ++counter_3;
                print_board(row_1, row_2, row_3, row_4, row_5, score, mistake);
            } else {
                cout << endl << "Sorry. The row is full!" << endl << endl;
                continue;
            }
        }
        else if (input == "4"){
            if (counter_4 < 10){
                row_4[counter_4] = letter;
                ++counter_4;
                print_board(row_1, row_2, row_3, row_4, row_5, score, mistake);
            } else {
                cout << endl << "Sorry. The row is full!" << endl << endl;
                continue;
            }
        }
        else if (input == "5"){
            if (counter_5 < 10){
                row_5[counter_5] = letter;
                ++counter_5;
                print_board(row_1, row_2, row_3, row_4, row_5, score, mistake);
            } else {
                cout << endl << "Sorry. The row is full!" << endl << endl;
                continue;
            }
        }
        else if (input == "quit"){
            cout << endl;
            string quit_game = quit();
            if (quit_game == "save"){
                save_progress(score, mistake, letter, row_1, row_2, row_3, row_4, row_5, counter_1, counter_2, counter_3, counter_4, counter_5);
            }
            else{
                ofstream fout;
                fout.open("progress.txt");
                fout << "";
                fout.close();
            }
            // delete [] row_1;
            // delete [] row_2;
            // delete [] row_3;
            // delete [] row_4;
            // delete [] row_5;
            // set_empty(row_1);
            // set_empty(row_2);
            // set_empty(row_3);
            // set_empty(row_4);
            // set_empty(row_4);
            // set_empty(row_5);
            exit_game = true;
            break;
        }
        else if (input == "submit"){
            cout << endl << "Which row would you like to submit? ";
            cin >> row_number;
            cout << endl;

            if (row_number == 1){
                if (counter_1 == 0){
                    cout << "Sorry. The row you are submitting is empty!" << endl << endl;
                    continue;
                }
                valid = check_word(row_1, counter_1);
                word_length = counter_1;
                counter_1 = 0;
                set_empty(row_1);
            } else if (row_number == 2){
                if (counter_2 == 0){
                    cout << "Sorry. The row you are submitting is empty!" << endl << endl;
                    continue;
                }
                valid = check_word(row_2, counter_2);
                word_length = counter_2;
                counter_2 = 0;
                set_empty(row_2);
            } else if (row_number == 3){
                if (counter_3 == 0){
                    cout << "Sorry. The row you are submitting is empty!" << endl << endl;
                    continue;
                }
                valid = check_word(row_3, counter_3);
                word_length = counter_3;
                counter_3 = 0;
                set_empty(row_3);
            } else if (row_number == 4){
                if (counter_4 == 0){
                    cout << "Sorry. The row you are submitting is empty!" << endl << endl;
                    continue;
                }
                valid = check_word(row_4, counter_4);
                word_length = counter_4;
                counter_4 = 0;
                set_empty(row_4);
            } else if (row_number == 5){
                if (counter_5 == 0){
                    cout << "Sorry. The row you are submitting is empty!" << endl << endl;
                    continue;
                }
                valid = check_word(row_5, counter_5);
                word_length = counter_5;
                counter_5 = 0;
                set_empty(row_5);
            } else{
                cout << endl;
                cout << "Sorry. Your input is invalid!" << endl << endl;
                continue;
            }

            if (valid){
                score_calculator(word_length, score);
                cout << "YAY YOU DID IT!!!" << endl;
                
            } else{
                mistake_adder(mistake);
                if (mistake > 10){
                    cout << endl;
                    // game_over(score);
                    // ofstream fout;
                    // fout.open("progress.txt");
                    // fout << "";
                    // fout.close();
                    // delete [] row_1;
                    // delete [] row_2;
                    // delete [] row_3;
                    // delete [] row_4;
                    // delete [] row_5;
                    exit_game = false;
                    break;
                }
            }
            print_board(row_1, row_2, row_3, row_4, row_5, score, mistake);
            continue;
        } else if (input == "help") {
            cout << endl;
            help();
            continue;
        }
        else{
            cout << endl;
            cout << "Sorry. Your input is invalid!" << endl << endl;
            continue;
        }
        letter = random_letter();
    }
}