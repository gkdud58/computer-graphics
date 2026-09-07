#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {

    string data_name;
    bool endgame = true;
    bool eee = true;
    bool ggg = true;
    bool hhh = true;
    bool ccc = true;
    bool iii = true;
    int j_count = 1;


    std::cout << "파일명(data.txt) : ";
    std::cin >> data_name;

    ifstream file(data_name);

    if (!file.is_open()) {
        std::cout << "파일을 열 수 없습니다." << endl;
        return 1;
    }


    // 문장
    vector<string> lines;
    string line;
    while (getline(file, line)) {

        lines.push_back(line);
    }
    file.close();


    for (int i = 0; i < lines.size(); ++i) {
        std::cout << lines[i] << endl;
    }


    while (endgame) {


        string cmd;
        std::cout << endl;
        std::cout << "명령어(a,b,c,d,e,f,g,h,i,j,q) : ";
        std::cin >> cmd;

        int linecount = lines.size();


        vector<vector<string>> words;
        for (int i = 0; i < linecount; ++i) {
            stringstream ss(lines[i]);
            string word;
            vector<string> keep_words;

            while (ss >> word) {
                keep_words.push_back(word);
            }

            words.push_back(keep_words);
        }

        if (cmd == "a" || cmd == "A") {
            for (int i = 0; i < linecount; ++i) {
                for (int j = 0; j < lines[i].size(); ++j) {
                    if (isupper(lines[i][j])) {
                        lines[i][j] = tolower(lines[i][j]);
                    }
                    else if (islower(lines[i][j])) {
                        lines[i][j] = toupper(lines[i][j]);
                    }
                }
            }
            for (int i = 0; i < lines.size(); ++i) {
                std::cout << lines[i] << endl;
            }
        }


        else if (cmd == "b" || cmd == "B") {
            for (int i = 0; i < lines.size(); ++i) {
                lines[i] += " " + to_string(words[i].size());
            }
            for (int i = 0; i < lines.size(); ++i) {
                std::cout << lines[i] << endl;
            }
        }


        else if (cmd == "c" || cmd == "C") {
            if (ccc) {
                int count = 0;
                for (int i = 0; i < linecount; ++i) {
                    vector<int> colors(lines[i].size(), 7);
                    int find_word = 0;
                    for (int j = 0; j < words[i].size(); ++j) {
                        string w = words[i][j];
                        int start = lines[i].find(w, find_word);
                        find_word = start + w.size();

                        if (isupper(w[0])) {
                            count++;
                            for (int k = start; k < start + w.size(); ++k) {
                                colors[k] = 2;
                            }
                        }
                    }

                    for (int j = 0; j < lines[i].size(); ++j) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[j]);
                        std::cout << lines[i][j];
                    }
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    std::cout << endl;
                }
                ccc = false;
            }
            else {
                for (int i = 0; i < linecount; ++i) {
                    std::cout << lines[i] << endl;
                }
                ccc = true;
            }
        }

        else if (cmd == "d" || cmd == "D") {
            for (int i = 0; i < linecount; ++i) {
                reverse(lines[i].begin(), lines[i].end());
            }
            for (int i = 0; i < linecount; ++i) {
                std::cout << lines[i] << endl;
            }
        }


        else if (cmd == "e" || cmd == "E") {
            if (eee) {
                for (int i = 0; i < linecount; ++i) {
                    for (int j = 0; j < lines[i].size(); ++j) {
                        if (isspace(lines[i][j])) {
                            lines[i][j] = '*';
                        }
                    }
                }
                eee = false;
            }
            else {
                for (int i = 0; i < linecount; ++i) {
                    for (int j = 0; j < lines[i].size(); ++j) {
                        if (lines[i][j] == '*') {
                            lines[i][j] = ' ';
                        }
                    }
                }
                eee = true;
            }


            for (int i = 0; i < linecount; ++i) {
                std::cout << lines[i] << endl;
            }
        }


        else if (cmd == "f" || cmd == "F") {
            int count = 0;
            for (int i = 0; i < linecount; ++i) {
                int find_word = 0;
                for (int j = 0; j < words[i].size(); ++j) {
                    string w = words[i][j];
                    int start = lines[i].find(w, find_word);
                    find_word = start + w.size();
                    
                    reverse(w.begin(), w.end());
                    lines[i].replace(start, w.size(), w);
                }
            }

            for (int i = 0; i < linecount; ++i) {
                std::cout << lines[i] << endl;
            }
        }


        else if (cmd == "g" || cmd == "G") {
            char origin, nnew;

            if (ggg) {
                bool found = false;

                std::cout << "바꿀 문자 : ";
                std::cin >> origin;
                std::cout << "새로운 문자 : ";
                std::cin >> nnew;

                for (int i = 0; i < linecount; ++i) {
                    for (int j = 0; j < lines[i].size(); ++j) {
                        if (lines[i][j] == origin) {
                            lines[i][j] = nnew;
                            found = true;
                        }
                    }
                }
                if (!found) {
                    std::cout << "찾을 수 없습니다. 다시 입력해주세요" << endl;
                    continue;
                }

                for (int i = 0; i < linecount; ++i) {
                    std::cout << lines[i] << endl;
                }
                char temp = origin;
                origin = nnew;
                nnew = temp;
                ggg = false;
            }
            else {
                for (int i = 0; i < linecount; ++i) {
                    for (int j = 0; j < lines[i].size(); ++j) {
                        if (lines[i][j] == origin) {
                            lines[i][j] = nnew;
                        }
                    }
                }
                for (int i = 0; i < linecount; ++i) {
                    std::cout << lines[i] << endl;
                }
                ggg = true;
            }

        }


        else if (cmd == "h" || cmd == "H") {
            if (hhh) {
                for (int i = 0; i < linecount; ++i) {
                    for (int j = 0; j < lines[i].size(); ++j) {
                        if (isdigit(lines[i][j])) {
                            lines[i].insert(j + 1, "\n");
                            ++j;
                        }
                    }
                }
                hhh = false;
            }
            else {
                for (int i = 0; i < linecount; i++) {
                    lines[i].erase(remove(lines[i].begin(), lines[i].end(), '\n'), lines[i].end());
                }
                hhh = true;
            }


            for (int i = 0; i < linecount; ++i) {
                std::cout << lines[i] << endl;
            }
        }

        // 명령어와 단어를 입력하면, 문장들을 모두 출력하면서 입력 받은 단어를 찾아 다른 색으로 출력하고, 몇 개 있는지를 계산하여 출력한다.  (대소문자 구분하지 않는다)

        else if (cmd == "i" || cmd == "I") {
            if (iii) {
                string ctrlf;

                std::cout << "찾는 단어 : ";
                std::cin >> ctrlf;

                int count = 0;
                for (int i = 0; i < linecount; ++i) {
                    vector<int> colors(lines[i].size(), 7);
                    int find_word = 0;
                    for (int j = 0; j < words[i].size(); ++j) {
                        string w = words[i][j];
                        int start = lines[i].find(w, find_word);
                        find_word = start + w.size();
                        
                        if (_stricmp(w.c_str(), ctrlf.c_str()) == 0) {
                            count++;
                            for (int k = start; k < start + w.size(); ++k) {
                                colors[k] = 2;
                            }
                        }
                    }

                    for (int j = 0; j < lines[i].size(); ++j) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[j]);
                        std::cout << lines[i][j];
                    }
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    std::cout << endl;
                }
                std::cout << ctrlf << "은 " << count << "개 있습니다." << endl;
                iii = false;
            }
            else {
                for (int i = 0; i < linecount; ++i) {
                    std::cout << lines[i] << endl;
                }
                iii = true;
            }


        }


        else if (cmd == "j" || cmd == "J") {
            for (int i = j_count; i < linecount; ++i) {
                for (int j = 0; j < lines[i].size(); ++j) {
                    std::cout << lines[i][j];
                }
                std::cout << endl;
            }
            for (int i = 0; i < j_count; ++i) {
                for (int j = 0; j < lines[i].size(); ++j) {
                    std::cout << lines[i][j];
                }
                std::cout << endl;
            }

            ++j_count;
        }


        else if (cmd == "q" || cmd == "Q") {
            break;
        }


        else {
            std::cout << "명령어를 다시 입력해주세요" << endl;
            continue;
        }

    }

    return 0;

}