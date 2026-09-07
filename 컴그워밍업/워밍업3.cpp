#include <iostream>
#include <cmath>
using namespace std;

struct Pos {
	int x, y, z;
};

int findTop(bool exist[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		if (exist[i]) {
			return i;
		}
	}
	return -1;
}

int findBottom(bool exist[], int size) {
	for (int i = 0; i < size; i++) {
		if (exist[i]) {
			return i;
		}
	}
	return -1;
}

int main() {
	const int MAX_SIZE = 10;

	Pos posList[MAX_SIZE];   
	bool exist[MAX_SIZE];    
	int pointCount = 0;   
	bool sort_onoff = false; 

	for (int i = 0; i < MAX_SIZE; i++) {
		exist[i] = false;
	}

	char cmd;

	while (true) {
		cout << endl << "명령어 입력 (+, -, e, d, a, b, c, f, g, q) : ";
		cin >> cmd;

		if (cmd == '+') {
			int x, y, z;
			cin >> x >> y >> z;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "숫자만 입력해주세요." << endl;
				continue;
			}


			if (pointCount >= MAX_SIZE) {
				cout << "리스트가 가득 찼습니다." << endl;
			}
			else {
				int target;
				if (pointCount == 0) {
					target = 0;
				}
				else {
					int top = findTop(exist, MAX_SIZE);
					if (top == MAX_SIZE - 1) {
						int gap = -1;
						for (int i = 0; i < MAX_SIZE; i++) {
							if (!exist[i]) {
								gap = i;
								break;
							}
						}
						target = gap;
					}
					else {
						target = top + 1;
					}
				}
				posList[target].x = x;
				posList[target].y = y;
				posList[target].z = z;
				exist[target] = true;
				pointCount++;
			}
		}
		else if (cmd == '-') {
			if (pointCount <= 0) {
				cout << "리스트가 비어있습니다." << endl;
			}
			else {
				int top = findTop(exist, MAX_SIZE);
				exist[top] = false;
				pointCount--;
			}
		}
		else if (cmd == 'e') {
			int x, y, z;
			cin >> x >> y >> z;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "숫자만 입력해주세요." << endl;
				continue;
			}

			if (pointCount >= MAX_SIZE) {
				cout << "리스트가 가득 찼습니다." << endl;
			}
			else {
				int target;
				if (pointCount == 0) {
					target = 0;
				}
				else if (!exist[0]) {
					target = 0;  
				}
				else {
					int gap = -1;
					for (int i = 1; i < MAX_SIZE; i++) {
						if (!exist[i]) {
							gap = i;
							break;
						}
					}
					for (int i = gap; i > 0; i--) {
						posList[i] = posList[i - 1];
						exist[i] = true;
					}

					target = 0;   
				}
				posList[target].x = x;
				posList[target].y = y;
				posList[target].z = z;
				exist[target] = true;
				pointCount++;
			}
		}

		else if (cmd == 'd') {
			if (pointCount <= 0) {
				cout << "리스트가 비어있습니다." << endl;
			}
			else {
				int bottom = findBottom(exist, MAX_SIZE);
				exist[bottom] = false;
				pointCount--;
			}
		}
		else if (cmd == 'a') {
			cout << "저장된 점의 개수 : " << pointCount << endl;
		}
		else if (cmd == 'b') {
			Pos tempList[MAX_SIZE];
			bool tempexist[MAX_SIZE];

			for (int i = 0; i < MAX_SIZE; i++) {
				int newIndex = (i - 1 + MAX_SIZE) % MAX_SIZE;
				tempList[newIndex] = posList[i];
				tempexist[newIndex] = exist[i];
			}
			for (int i = 0; i < MAX_SIZE; i++) {
				posList[i] = tempList[i];
				exist[i] = tempexist[i];
			}
		}
		else if (cmd == 'c') {
			for (int i = 0; i < MAX_SIZE; i++) {
				exist[i] = false;
			}
			pointCount = 0;
		}
		else if (cmd == 'f') {
			if (sort_onoff) {
				sort_onoff = false;
			}
			else {
				sort_onoff = true;
			}
		}
		else if (cmd == 'g') {
			Pos points[MAX_SIZE];
			int n = 0;
			for (int i = 0; i < MAX_SIZE; i++) {
				if (exist[i]) {
					points[n] = posList[i];
					n++;
				}
			}

			if (n < 2) {
				cout << "점이 2개가 필요합니다." << endl;
			}
			else {
				double maxDist = -1;
				double minDist = -1;
				int maxA = 0, maxB = 0, minA = 0, minB = 0;

				for (int i = 0; i < n - 1; i++) {
					for (int j = i + 1; j < n; j++) {
						int dx = points[i].x - points[j].x;
						int dy = points[i].y - points[j].y;
						int dz = points[i].z - points[j].z;
						double dist = sqrt((double)(dx * dx + dy * dy + dz * dz));

						if (maxDist < 0 || dist > maxDist) {
							maxDist = dist;
							maxA = i;
							maxB = j;
						}
						if (minDist < 0 || dist < minDist) {
							minDist = dist;
							minA = i;
							minB = j;
						}
					}
				}

				cout << "가장 먼 두 점 : (" << points[maxA].x << "," << points[maxA].y << "," << points[maxA].z << ") , (" << points[maxB].x << "," << points[maxB].y << "," << points[maxB].z << ")  거리 : " << maxDist << endl;
				cout << "가장 가까운 두 점 : (" << points[minA].x << "," << points[minA].y << "," << points[minA].z << ") , (" << points[minB].x << "," << points[minB].y << "," << points[minB].z << ")  거리 : " << minDist << endl;
			}
		}
		else if (cmd == 'q') {
			break;
		}
		else {
			cout << "알 수 없는 명령어 입니다." << endl;
			continue; 
		}

		if (cmd != 'a' && cmd != 'g') {
			if (sort_onoff) {
				Pos temp[MAX_SIZE];
				int n = 0;
				for (int i = 0; i < MAX_SIZE; i++) {
					if (exist[i]) {
						temp[n] = posList[i];
						n++;
					}
				}

				for (int i = 0; i < n - 1; i++) {
					for (int j = 0; j < n - 1 - i; j++) {
						double d1 = sqrt((double)(temp[j].x * temp[j].x + temp[j].y * temp[j].y + temp[j].z * temp[j].z));
						double d2 = sqrt((double)(temp[j + 1].x * temp[j + 1].x + temp[j + 1].y * temp[j + 1].y + temp[j + 1].z * temp[j + 1].z));
						if (d1 > d2) {
							Pos t = temp[j];
							temp[j] = temp[j + 1];
							temp[j + 1] = t;
						}
					}
				}

				for (int i = 0; i < n; i++) {
					double dist = sqrt((double)(temp[i].x * temp[i].x + temp[i].y * temp[i].y + temp[i].z * temp[i].z));
					cout << i << " : (" << temp[i].x << ", " << temp[i].y << ", " << temp[i].z << ")  거리 : " << dist << endl;
				}
				for (int i = n; i < MAX_SIZE; i++) {
					cout << i << " : " << endl;
				}
			}
			else {
				for (int i = MAX_SIZE - 1; i >= 0; i--) {
					if (exist[i]) {
						cout << i << " : (" << posList[i].x << ", " << posList[i].y << ", " << posList[i].z << ")" << endl;
					}
					else {
						cout << i << " : " << endl;
					}
				}
			}
		}
	}

	return 0;
}
