#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void load_progress(int &score, int &mistake, char &letter, char *& row_1, char *& row_2, char *& row_3, char *& row_4, char *& row_5, int &counter_1, int &counter_2, int &counter_3, int &counter_4, int &counter_5){
    ifstream fin;
    int counter = 0;
    int row_counter = 0;
    string x;
    fin.open("progress.txt");
    while (getline(fin, x)){
        if (counter == 0){
            score = stoi(x);
        }
        else if (counter == 1){
            mistake = stoi(x);
        }
        else if (counter == 2){
            letter = x.c_str()[0];
        }
        else if (counter == 3){
            int j = 0;
            for (int i = 0; i < 10; ++i){
                row_1[i] = x[j];
                j+=2;
            }
        }
        else if (counter == 4){
            int j = 0;
            for (int i = 0; i < 10; ++i){
                row_2[i] = x[j];
                j+=2;
            }
        }
        else if (counter == 5){
            int j = 0;
            for (int i = 0; i < 10; ++i){
                row_3[i] = x[j];
                j+=2;
            }
        }
        else if (counter == 6){
            int j = 0;
            for (int i = 0; i < 10; ++i){
                row_4[i] = x[j];
                j+=2;
            }
        }
        else if (counter == 7){
            int j = 0;
            for (int i = 0; i < 10; ++i){
                row_5[i] = x[j];
                j+=2;
            }
        }
        else if (counter == 8){
            counter_1 = stoi(x);
        }
        else if (counter == 9){
            counter_2 = stoi(x);
        }
        else if (counter == 10){
            counter_3 = stoi(x);
        }
        else if (counter == 11){
            counter_4 = stoi(x);
        }
        else if (counter == 12){
            counter_5 = stoi(x);
        }
        ++counter;
    }
    fin.close();
}