#include<iostream>
#include<vector>
using namespace std;

int adj[11][11];
int id[11] = { 1004, 1680, 9941, 3367,3261,2976,4889,1234,6461,7329,5518 };
// id[0] == 1004 ...

void init() {
	adj[0][1] = 1;
	adj[0][2] = 1;
	adj[1][3] = 1;
	adj[1][4] = 1;
	adj[2][5] = 1;
	adj[2][6] = 1;
	adj[4][7] = 1;
	adj[4][8] = 1;
	adj[5][9] = 1;
	adj[5][10] = 1;
}

int main() {
	init();

	int num;
	cin >> num;
	
	// 입력받은 사원번호가 존재하는 지 체크
	int index = -1;
	for (int i = 0; i < 11; i++) {
		if (num == id[i]) {
			index = i;
		}
	}
	if (index == -1) {
		cout << "no person";
		return 0;
	}

	// boss 찾기
	int boss = -1;
	for (int from = 0; from < 11; from++) { // from -> to
		if (adj[from][index]) {
			boss = from;
		}
	}
	if (boss == -1) {
		cout << "no boss" << "\n";
	}
	else {
		cout << id[boss] << "\n";
	}

	// 동료 찾기
	if (boss == -1) {
		cout << "no company" << "\n";
	}
	else{
		int flag = 0;
		for (int to = 0; to < 11; to++) {
			if (adj[boss][to] && id[to] != num) {
				cout << id[to] << "\n";
				flag = 1;
			}
		}
		if (flag == 0) {
			cout << "no company" << "\n";
		}
	}

	// junior 찾기
	int junior = -1;
	for (int to = 0; to < 11; to++) { // from -> to
		if (adj[index][to]) {
			junior = to;
			cout << id[junior] << " ";
		}
	}
	if (junior == -1) {
		cout << "no junior";
	}

	return 0;
}
