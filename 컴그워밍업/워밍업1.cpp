#include <iostream>
#include <time.h>

#define line 4
using namespace std;

void find_min(int matrix[line][line], int min0[line][line]) {
	int min[4] = {10, 10, 10, 10};
	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < line; ++j) {
			if (min[i] > matrix[i][j]) {
				min[i] = matrix[i][j];
			}
		}
	}
	
	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < line; ++j) {
			min0[i][j] = matrix[i][j] - min[i];
		}
	}
}
void find_max(int matrix[line][line], int max0[line][line]) {
	int max[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < line; ++j) {
			if (max[i] < matrix[j][i]) {
				max[i] = matrix[j][i];
			}
		}
	}

	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < line; ++j) {
			max0[i][j] = matrix[i][j] + max[j];
		}
	}
}

int main() {

	srand((unsigned)time(NULL));
	int one_matrix[line][line];
	int two_matrix[line][line];

	bool endgame = true;
	
	int min1[line][line];
	int min2[line][line];
	int max1[line][line];
	int max2[line][line];

	int count_e = 0;
	int count_f = 0;

	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < line; ++j) {
			one_matrix[i][j] = rand() % 9 + 1;
			two_matrix[i][j] = rand() % 9 + 1;
		}
	}

	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < line; ++j) {
			cout << one_matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < line; ++j) {
			cout << two_matrix[i][j] << " ";
		}
		cout << endl;
	}


		
	string cmd;
		

	

	while (endgame) {
			
		cout << endl;
		cout << "명령어(m곱셈, a덧셈, d뺄셈, r, t, e, f, +/-, s, q) : ";
		cin >> cmd;


		if (cmd == "M" || cmd == "m")
		{
			int multi[line][line];
			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					multi[i][j] = one_matrix[i][0] * two_matrix[0][j]
						+ one_matrix[i][1] * two_matrix[1][j]
						+ one_matrix[i][2] * two_matrix[2][j]
						+ one_matrix[i][3] * two_matrix[3][j];
				}
			}

			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					cout << multi[i][j] << " ";
				}
				cout << endl;
			}
			continue;
		}



		else if (cmd == "A" || cmd == "a") {
			int plus[line][line];

			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					plus[i][j] = one_matrix[i][j] + two_matrix[i][j];
				}
			}

			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					cout << plus[i][j] << " ";
				}
				cout << endl;
			}
			continue;
		}



		else if (cmd ==  "D" || cmd == "d") {
			int minus[line][line];

			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					minus[i][j] = one_matrix[i][j] - two_matrix[i][j];
				}
			}

			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					cout << minus[i][j] << " ";
				}
				cout << endl;
			}
			continue;
		}



		else if (cmd == "R" || cmd == "r") {
			int det1[line];
			int det2[line];
			int temp[2];
				
			det1[0] = one_matrix[0][0] *
				((one_matrix[1][1] * one_matrix[2][2] * one_matrix[3][3] +
					one_matrix[1][2] * one_matrix[2][3] * one_matrix[3][1] +
					one_matrix[1][3] * one_matrix[2][1] * one_matrix[3][2])
					-
					(one_matrix[1][3] * one_matrix[2][2] * one_matrix[3][1] +
						one_matrix[1][1] * one_matrix[2][3] * one_matrix[3][2] +
						one_matrix[1][2] * one_matrix[2][1] * one_matrix[3][3]));

			det1[1] = -one_matrix[0][1] *
				((one_matrix[1][0] * one_matrix[2][2] * one_matrix[3][3] +
					one_matrix[1][2] * one_matrix[2][3] * one_matrix[3][0] +
					one_matrix[1][3] * one_matrix[2][0] * one_matrix[3][2])
					-
					(one_matrix[1][3] * one_matrix[2][2] * one_matrix[3][0] +
						one_matrix[1][0] * one_matrix[2][3] * one_matrix[3][2] +
						one_matrix[1][2] * one_matrix[2][0] * one_matrix[3][3]));

			det1[2] = one_matrix[0][2] *
				((one_matrix[1][0] * one_matrix[2][1] * one_matrix[3][3] +
					one_matrix[1][1] * one_matrix[2][3] * one_matrix[3][0] +
					one_matrix[1][3] * one_matrix[2][0] * one_matrix[3][1])
					-
					(one_matrix[1][3] * one_matrix[2][1] * one_matrix[3][0] +
						one_matrix[1][0] * one_matrix[2][3] * one_matrix[3][1] +
						one_matrix[1][1] * one_matrix[2][0] * one_matrix[3][3]));

			det1[3] = -one_matrix[0][3] *
				((one_matrix[1][0] * one_matrix[2][1] * one_matrix[3][2] +
					one_matrix[1][1] * one_matrix[2][2] * one_matrix[3][0] +
					one_matrix[1][2] * one_matrix[2][0] * one_matrix[3][1])
					-
					(one_matrix[1][2] * one_matrix[2][1] * one_matrix[3][0] +
						one_matrix[1][0] * one_matrix[2][2] * one_matrix[3][1] +
						one_matrix[1][1] * one_matrix[2][0] * one_matrix[3][2]));
			temp[0] = det1[0] + det1[1] + det1[2] + det1[3];

			det2[0] = two_matrix[0][0] *
				((two_matrix[1][1] * two_matrix[2][2] * two_matrix[3][3] +
					two_matrix[1][2] * two_matrix[2][3] * two_matrix[3][1] +
					two_matrix[1][3] * two_matrix[2][1] * two_matrix[3][2])
				-
				(two_matrix[1][3] * two_matrix[2][2] * two_matrix[3][1] +
					two_matrix[1][1] * two_matrix[2][3] * two_matrix[3][2] +
					two_matrix[1][2] * two_matrix[2][1] * two_matrix[3][3]));
			det2[1] = -two_matrix[0][1] *
				((two_matrix[1][0] * two_matrix[2][2] * two_matrix[3][3] +
					two_matrix[1][2] * two_matrix[2][3] * two_matrix[3][0] +
					two_matrix[1][3] * two_matrix[2][0] * two_matrix[3][2]) 
					-
					(two_matrix[1][3] * two_matrix[2][2] * two_matrix[3][0] +
						two_matrix[1][0] * two_matrix[2][3] * two_matrix[3][2] +
						two_matrix[1][2] * two_matrix[2][0] * two_matrix[3][3]));
			det2[2] = two_matrix[0][2] *
				((two_matrix[1][0] * two_matrix[2][1] * two_matrix[3][3] +
					two_matrix[1][1] * two_matrix[2][3] * two_matrix[3][0] +
					two_matrix[1][3] * two_matrix[2][0] * two_matrix[3][1])
					-
					(two_matrix[1][3] * two_matrix[2][1] * two_matrix[3][0] +
						two_matrix[1][0] * two_matrix[2][3] * two_matrix[3][1] +
						two_matrix[1][1] * two_matrix[2][0] * two_matrix[3][3]));
			det2[3] = -two_matrix[0][3] *
				((two_matrix[1][0] * two_matrix[2][1] * two_matrix[3][2] +
					two_matrix[1][1] * two_matrix[2][2] * two_matrix[3][0] +
					two_matrix[1][2] * two_matrix[2][0] * two_matrix[3][1])
					-
					(two_matrix[1][2] * two_matrix[2][1] * two_matrix[3][0] +
						two_matrix[1][0] * two_matrix[2][2] * two_matrix[3][1] +
						two_matrix[1][1] * two_matrix[2][0] * two_matrix[3][2]));
			temp[1] = det2[0] + det2[1] + det2[2] + det2[3];

			cout << "첫번째 행렬식의 값 : " << temp[0] << "   " << "두번째 행렬식의 값 : " << temp[1] << endl;
			continue;
}


		else if (cmd == "T" || cmd == "t") {
			int transFir[line][line];
			int transSec[line][line];

			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					transFir[i][j] = one_matrix[j][i];
					transSec[i][j] = two_matrix[j][i];
				}
			}
			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					cout << transFir[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					cout << transSec[i][j] << " ";
				}
				cout << endl;
			}
			continue;
		}
		else if (cmd == "E" || cmd == "e") {
			if (count_e >= 1) {
				for (int i = 0; i < line; ++i) {
					for (int j = 0; j < line; ++j) {
						cout << one_matrix[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				for (int i = 0; i < line; ++i) {
					for (int j = 0; j < line; ++j) {
						cout << two_matrix[i][j] << " ";
					}
					cout << endl;
				}
				count_e = 0;
			}
			else {
				find_min(one_matrix, min1);
				find_min(two_matrix, min2);

				for (int i = 0; i < line; ++i) {
					for (int j = 0; j < line; ++j) {
						cout << min1[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				for (int i = 0; i < line; ++i) {
					for (int j = 0; j < line; ++j) {
						cout << min2[i][j] << " ";
					}
					cout << endl;
				}
				count_e = 1;
			}
			continue;
		}
		else if (cmd == "F" || cmd == "f") {
			if (count_f >= 1) {
				for (int i = 0; i < line; ++i) {
					for (int j = 0; j < line; ++j) {
						cout << one_matrix[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				for (int i = 0; i < line; ++i) {
					for (int j = 0; j < line; ++j) {
						cout << two_matrix[i][j] << " ";
					}
					cout << endl;
				}
				count_f = 0;
			}
			else {
				find_max(one_matrix, max1);
				find_max(two_matrix, max2);

				for (int i = 0; i < line; ++i) {
					for (int j = 0; j < line; ++j) {
						cout << max1[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				for (int i = 0; i < line; ++i) {
					for (int j = 0; j < line; ++j) {
						cout << max2[i][j] << " ";
					}
					cout << endl;
				}
				count_f = 1;
			}
			continue;
		}
		else if (cmd == "+" || cmd == "=") {
			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					if (one_matrix[i][j] + 1 == 10) {
						one_matrix[i][j] = 0;
					}
					else {
						one_matrix[i][j] = one_matrix[i][j] + 1;
					}
					if (two_matrix[i][j] + 1 == 10) {
						two_matrix[i][j] = 0;
					}
					else {
						two_matrix[i][j] = two_matrix[i][j] + 1;
					}
				}
			}
			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					cout << one_matrix[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					cout << two_matrix[i][j] << " ";
				}
				cout << endl;
			}
			continue;
		}
		else if (cmd == "-" || cmd == "_") {
			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					if (one_matrix[i][j] - 1 == -1) {
						one_matrix[i][j] = 9;
					}
					else {
						one_matrix[i][j] = one_matrix[i][j] - 1;
					}
					if (two_matrix[i][j] - 1 == -1) {
						two_matrix[i][j] = 9;
					}
					else {
						two_matrix[i][j] = two_matrix[i][j] - 1;
					}
				}
			}
			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					cout << one_matrix[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					cout << two_matrix[i][j] << " ";
				}
				cout << endl;
			}
			continue;
		}
		else if (cmd == "S" || cmd == "s") {
			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					one_matrix[i][j] = rand() % 9 + 1;
					two_matrix[i][j] = rand() % 9 + 1;
				}
			}

			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					cout << one_matrix[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < line; ++i) {
				for (int j = 0; j < line; ++j) {
					cout << two_matrix[i][j] << " ";
				}
				cout << endl;
			}
			continue;
		}
		else if (cmd == "Q" || cmd == "q") {
			break;
		}
		else {
			cout << "명령어를 다시 입력해 주세요";
			continue;
		}
	}
}