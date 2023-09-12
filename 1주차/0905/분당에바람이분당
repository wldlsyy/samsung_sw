#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> MAP[3][3];

int main() {
	int N; // 좌표의 수
	cin >> N;
	for (int n = 0; n < N;n++) {
		int y, x; // 농작물 좌표
		string str; // 작물 내구도
		cin >> y >> x >> str;
		for (int i = 0; i < str.length(); i++) {
			int ret = str[i] - '0';
			MAP[y][x].push_back(ret);
		}
	}
	int K; // 강풍 횟수
	cin >> K;
	for (int i = 0; i < K; i++) {
		int power;
		cin >> power;

		for (int row = 0; row < 3;row++) {
			for (int col = 0; col < 3; col++) {
				if (MAP[row][col].empty()) continue;
				// 각 칸마다 맨 마지막 원소를 -power
				vector<int>& ref = MAP[row][col];
				ref[ref.size() - 1] -= power;
				if (ref[ref.size()-1]<=0) ref.pop_back();

			}
		}
	}

	int cnt = 0;
	for (int row = 0; row < 3;row++) {
		for (int col = 0; col < 3; col++) {
			cnt += MAP[row][col].size();
		}
	}

	cout << cnt;

	return 0;
}
