#include <iostream>
#include <string>
#include <random>
#include <cctype>
#include <windows.h>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int row, col;

    bool endgame = true;
    bool start = true;
    string alpha[6] = { "a","b","c","d","e","f" };
    string number[6] = { "1","2","3","4","5","6" };





    while (start) {
        std::cout << "row, col(3~6) : ";
        std::cin >> row >> col;

        if ((row < 3 || row > 6) || (col < 3 || col > 6)) {
            std::cout << "3~6중에서 골라주세요." << endl;
        }
        else {
            start = false;
        }
    }


    int CxR = col * row;
    vector<string> alphabet = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r" };
    vector<string> card;

    if (CxR % 2 == 0) {
        for (int i = 0; i < CxR / 2; ++i) {
            card.push_back(alphabet[i]);
            card.push_back(alphabet[i]);
        }
    }
    else {
        card.push_back("@");
        for (int i = 0; i < (CxR - 1) / 2; ++i) {
            card.push_back(alphabet[i]);
            card.push_back(alphabet[i]);
        }
    }
    random_device rd;
    mt19937 gen(rd());
    shuffle(card.begin(), card.end(), gen);


    string index[6][6];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            index[i][j] = card[i * col + j];
        }
    }









    bool matched[6][6] = { false };
    int score_count = 0;
    std::cout << " ";
    for (int i = 0; i < col; ++i) {
        std::cout << "  " << alpha[i];
    }
    std::cout << endl;


    for (int i = 0; i < row; ++i) {
        std::cout << number[i] << " ";

        for (int j = 0; j < col; ++j) {
            if (matched[i][j]) {
                std::cout << " " << index[i][j] << " ";
            }
            else {
                std::cout << " * ";
            }
        }
        std::cout << endl;
    }

    while (endgame) {



        string pos1, pos2;
        std::cout << endl;
        std::cout << "두 개의 카드(ex : a1 a3) :  ";
        std::cin >> pos1 >> pos2;

        ++score_count;

        if (pos1 == "q" || pos1 == "Q" || pos2 == "q" || pos2 == "Q") {
            break;
        }


        // 0 = 1&a | 1 = 2&b | 2 = 3&c | 3 = 4&d ...
        int col1 = pos1[0] - 'a';
        int col2 = pos2[0] - 'a';
        int row1, row2;

        try {
            row1 = stoi(pos1.substr(1)) - 1;
            row2 = stoi(pos2.substr(1)) - 1;
        }
        catch (...) {
            cout << "다시 입력해주세요." << endl;
            continue;
        }

        if (col1 < 0 || col1 >= col || col2 < 0 || col2 >= col || row1 < 0 || row1 >= row || row2 < 0 || row2 >= row) {
            cout << "다시 입력해주세요." << endl;
            continue;
        }




        bool joker1 = (index[row1][col1] == "@");
        bool joker2 = (index[row2][col2] == "@");

        int origin_row = -1, origin_col = -1;   // 내가 입력한 나머지 한 장 위치
        int find_joker_row = -1, find_joker_col = -1;   // 조커가 찾아준 카드 위치


        bool jokerFound = false;

        if (joker1 || joker2) {
            if (joker1) { 
                origin_row = row2; 
                origin_col = col2; 
            }
            else { 
                origin_row = row1; 
                origin_col = col1;
            }


            std::cout << "조커를 찾았습니다! ";
            std::cout << endl;


            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (index[i][j] == index[origin_row][origin_col] && !(i == origin_row && j == origin_col)) {
                        find_joker_row = i;
                        find_joker_col = j;
                        jokerFound = true;
                    }
                }
            }
        }


        std::cout << " ";
        for (int i = 0; i < col; ++i) {
            std::cout << "  " << alpha[i];
        }
        std::cout << endl;



        for (int i = 0; i < row; ++i) {
            std::cout << number[i] << " ";
            for (int j = 0; j < col; ++j) {
                if (matched[i][j]) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    std::cout << " " << (char)toupper(index[i][j][0]) << " ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else if (jokerFound && i == find_joker_row && j == find_joker_col) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    std::cout << " " << index[i][j][0] << " ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else if (i == row2 && j == col2) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                    std::cout << " " << index[i][j][0] << " ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else if (i == row1 && j == col1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    std::cout << " " << index[i][j][0] << " ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else {
                    std::cout << " * ";
                }
            }
            std::cout << endl;
        }
        std::cout << endl;



        if (jokerFound) {
            matched[origin_row][origin_col] = true;
            matched[find_joker_row][find_joker_col] = true;

            if (joker1)
                matched[row1][col1] = true;
            else
                matched[row2][col2] = true;
        }
        else if (index[row1][col1] == index[row2][col2]) {
            matched[row1][col1] = true;
            matched[row2][col2] = true;
        }
        else {
            std::cout << "다시하세요." << endl;
        }

        bool allMatched = true;
        for (int i = 0; i < row && allMatched; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!matched[i][j]) {
                    allMatched = false;
                    break;
                }
            }
        }
        if (allMatched) {
            std::cout << "카드를 다 찾았습니다!" << endl;

            int tempscore;
            if (CxR % 2 == 0) {
                tempscore = CxR / 2 + 1;
            }
            else {
                tempscore = (CxR - 1) / 2;
            }

            int score;
            if (score_count <= tempscore)
                score = 100;
            else if (score_count <= tempscore * 1.5)
                score = 75;
            else if (score_count <= tempscore * 2)
                score = 50;
            else
                score = 25;

            std::cout << "점수 : " << score << "점" << endl;
            break;
        }
    }
}