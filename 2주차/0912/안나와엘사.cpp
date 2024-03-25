#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int N; // 맵 크기
string MAP[5];
// #: 빙하

// 시작 노드
int anna_r, anna_c; // 안나 좌표
int elsa_r, elsa_c; // 엘사 좌표

int visited_anna[5][5];
int visited_elsa[5][5];

void input() {
	cin >> N;

	for (int row = 0; row < N; row++) {
		cin >> MAP[row];
	}

	cin >> anna_r >> anna_c >> elsa_r >> elsa_c;

}

int dr[] = { 0,-1,1,0,0 };
int dc[] = { 0,0,0,-1,1 };


void bfs(int start_row, int start_col, int visited[5][5]) {
	queue<Node> qu;
	visited[start_row][start_col] = 1; // 체크 안된건 0으로 되어있기 때문에 1로 시작함.
	qu.push({ start_row, start_col });

	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();

		for (int t = 0;t < 5;t++) {
			int nr = now.row + dr[t];
			int nc = now.col + dc[t];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (MAP[nr][nc] == '#') continue; // 빙하
			if (visited[nr][nc] > 0) continue;
			
			visited[nr][nc] = 1;
			visited[nr][nc] = visited[now.row][now.col] + 1;
			qu.push({ nr, nc });
		}
	}

}


int main() {

	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();

	bfs(anna_r, anna_c, visited_anna);

	bfs(elsa_r, elsa_c, visited_elsa);

	int result[5][5];

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			result[row][col] = max(visited_anna[row][col], visited_elsa[row][col]);
		}
	}

	int minTime = 1e9;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			minTime = min(minTime, result[row][col]);
		}
	}

	cout << minTime;

	return 0;
}
