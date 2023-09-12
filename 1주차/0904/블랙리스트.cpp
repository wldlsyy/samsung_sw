#include <iostream>
using namespace std;

int main() {
	int apt[100001] = { 0, };
	int check[100001] = { 0, };

	int c, r;
	cin >> c >> r;
	for (int row = 0; row < r;row++) {
		for (int col = 0;col < c;col++) {
			int val;
			cin >> val;
			apt[val] += 1; // 아파트에 해당 번호 얼마나 있는지 체크
		}
	}


	int blackCnt = 0;
	int bc, br;
	cin >> br >> bc;
	for (int row = 0; row < br; row++) {
		for (int col = 0; col < bc;col++) {
			int n;
			cin >> n; // 블랙리스트 번호
			if (check[n] == 0) {
				blackCnt += apt[n];
				check[n] = 1; 
			}
		}
	}

	cout << blackCnt << "\n" << (r * c) - blackCnt;

	return 0;
}
