#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int Y, X; // 치즈 위치
int N, M; // 친구 좌표

int MAP[3][5] = {
	0,0,0,0,-1,
	-1,0,-1,0,0,
	0,0,0,0,-1,
};

void input() {
	cin >> Y >> X;
	cin >> N >> M;
}

int visited[3][5];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int moveCnt[3][5] = { 0 }; // 몇회만에 최소 이동했는가

void bfs(int start_row, int start_col, int result[3][5]) {
	int visited[3][5] = { 0 };
	queue<Node> qu;
	visited[start_row][start_col] = 1;
	result[start_row][start_col] = 0;
	qu.push({ start_row, start_col });

	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();

		for (int t = 0;t < 4;t++) {
			int nr = now.row + dr[t];
			int nc = now.col + dc[t];
			if (nr < 0 || nc < 0 || nr >= 3 || nc >= 5) continue;
			if (MAP[nr][nc] < 0) continue;
			if (visited[nr][nc]) continue;
			visited[nr][nc] = 1;
			result[nr][nc] = result[now.row][now.col] + 1;
			qu.push({ nr, nc });
		}
	}
	return;
}

int main() {
	int moveCnt[3][5] = { 0 }; // 몇회만에 최소 이동했는가

	cin >> Y >> X;
	cin >> N >> M;

	bfs(Y, X, moveCnt); // 치즈 ~~> 쥐 + 치즈 ~~> 친구

	cout << moveCnt[0][0] + moveCnt[N][M];

	return 0;
}
