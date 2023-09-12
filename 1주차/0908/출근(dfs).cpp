#include <iostream>
#include<vector>
using namespace std;

int N, M; // 지역 수, 관계 수
int adj[11][11];
int Fire; // 화재가 발생한 지역
int visited[11];

int minCnt = 1e9;
void dfs(int now, int moveCnt) {
	if (now == N) {
		minCnt = min(minCnt, moveCnt);
		
		return;
	}

	for (int next = 1; next <= N; next++) {
		if (adj[now][next] == 0) continue; // 연결 관계 없음
		if (visited[next] == 1) continue; // 이전에 방문했음
		if (next == Fire) continue;
		visited[next] = 1;
		dfs(next, moveCnt+1);
		visited[next] = 0;
	}
	
	return;
}


int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	cin >> Fire;

	visited[1] = 1;
	dfs(1, 0); // 시작, 몇번 이동했는가

	if (minCnt == 1e9) {
		cout << -1;
	}
	else {
		cout << minCnt;
	}

	return 0;
}
