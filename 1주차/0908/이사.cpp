#include<iostream>
#include<queue>
using namespace std;

int N, M; // 지역 수, 관계 수
int arr[11][11];
int dest, K; // 직장 지역, 버스 탑승 횟수

void input() {
	cin >> N >> M;

	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	cin >> dest >> K;
}

int main() {
	input();

	int moveCnt[11] = { 1e9,1e9,1e9,1e9,1e9,1e9,1e9,1e9,1e9,1e9,1e9 };
	int visited[11] = { 0 };
	queue<int> qu;

	visited[dest] = 1;
	moveCnt[dest] = 0;
	qu.push(dest);

	while (!qu.empty()) {
		int now = qu.front();
		qu.pop();

		for (int next = 1; next <= N; next++) {
			if (arr[now][next] != 1)continue;
			if (visited[next] == 1)continue;
			visited[next] = 1;
			moveCnt[next] = moveCnt[now] + 1;
			qu.push(next);
		}
	}

	/*for (int i = 1; i <= N; i++) {
		cout << moveCnt[i] << " ";
	}*/


	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (moveCnt[i] <= K) 
			cnt++;
	}

	cout << cnt;

	return 0;
}
