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

int bfs(int start_row, int start_col, int end_row, int end_col) {
	int visited[3][5] = { 0 }; 
	int moveCnt[3][5] = { 0 }; // 몇회만에 최소 이동했는가
	
	queue<Node> qu;
	visited[start_row][start_col] = 1;
	moveCnt[start_row][start_col] = 0;
	qu.push({ start_row,start_col });

	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();

		// next 등록
		for (int t = 0; t < 4; t++) {
			int nr = now.row + dr[t];
			int nc = now.col + dc[t];
			if (nr < 0 || nc < 0 || nr >= 3 || nc >= 5) continue;
			if (MAP[nr][nc] < 0) continue; // 벽
			if (visited[nr][nc]==1) continue; // 이미 체크
			moveCnt[nr][nc] = moveCnt[now.row][now.col] + 1;
			visited[nr][nc] = 1;
			qu.push({ nr, nc });
		}
	}
	return moveCnt[end_row][end_col];
}

int main() {
	cin >> Y >> X;
	cin >> N >> M;

	cout << bfs(0, 0, Y, X) + bfs(Y, X, N, M);

	return 0;
}
