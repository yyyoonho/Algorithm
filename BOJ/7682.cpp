#include <iostream>
#include <string>
using namespace std;

string tiktak;
char map[3][3];

bool checkBingo(char mark) {
	bool flag = false;

	//���� ����Ȯ��
	for (int i = 0; i < 3; i++) {
		if (map[i][0] != mark) continue;
		if (map[i][0] == map[i][1] && map[i][0] == map[i][2]) {
			flag = true;
			break;
		}
	}

	//���� ����Ȯ��
	for (int i = 0; i < 3; i++) {
		if (map[0][i] != mark) continue;
		if (map[0][i] == map[1][i] && map[0][i] == map[2][i]) {
			flag = true;
			break;
		}
	}

	//�밢�� ����Ȯ��
	if (!flag && map[0][0] == mark) {
		if (map[0][0] == map[1][1] && map[0][0] == map[2][2]) flag = true;
	}

	if (!flag && map[2][0] == mark) {
		if (map[0][2] == map[1][1] && map[0][2] == map[2][0]) flag = true;
	}

	return flag;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	while (true) {
		cin >> tiktak;
		if (tiktak == "end") break;

		//map �ʱ�ȭ �� X,O ī��Ʈ
		int xCount = 0;
		int oCount = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				map[i][j] = tiktak[i * 3 + j];
				if (map[i][j] == 'X') xCount++;
				else if (map[i][j] == 'O') oCount++;
			}
		}

		bool xState = checkBingo('X');
		bool oState = checkBingo('O');

		// xCount==oCount+1 �� ���
		if (xCount == oCount + 1) {
			//1. X���� ���� & O���� ����
			if (xState == true && oState == false) {
				cout << "valid" << '\n';
				continue;
			}

			//2. X���� ���� & X���� ����
			if (xState == false && oState == false && xCount+oCount==9) {
				cout << "valid" << '\n';
				continue;
			}
		}

		// xCount==oCount �� ���
		else if (xCount == oCount) {
			//3. X���� ���� & O���� ����
			if (xState == false && oState == true) {
				cout << "valid" << '\n';
				continue;
			}
		}

		cout << "invalid" << '\n';
	}

	return 0;
}
