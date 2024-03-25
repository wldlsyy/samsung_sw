#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int N; // 맵 크기
string MAP[20];
// #: 벽, A: 소화기, $: 불, _: 빈공간

// 시작 노드
int mr, mc; // 민철 좌표
int fr, fc;

int visited_mc[20][20];
int visited_fire[20][20];

void input() {
	cin >> N;

	for (int row = 0; row < N; row++) {
		cin >> MAP[row];
	}

	cin >> mr >> mc;

}

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };


void bfs(int start_row, int start_col, int visited[20][20]) {
	// 소화기 ~~> 민철
	queue<Node> qu;
	visited[start_row][start_col] = 1; // 체크 안된건 0으로 되어있기 때문에 1로 시작함.
	qu.push({ start_row, start_col });

	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();

		for (int t = 0;t < 4;t++) {
			int nr = now.row + dr[t];
			int nc = now.col + dc[t];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (MAP[nr][nc] == '#') continue; // 벽
			if (MAP[nr][nc] == '$') continue; // 불
			if (visited[nr][nc] > 0) continue;
			visited[nr][nc] = 1;
			visited[nr][nc] = visited[now.row][now.col] + 1;
			qu.push({ nr, nc });
		}
	}

}


int main() {

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	input();

	bfs(mr, mc, visited_mc);


	// 불 좌표 찾기
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (MAP[row][col] == '$') {
				fr = row;
				fc = col;
			}
		}
	}

	bfs(fr, fc, visited_fire);

	// 소화기 좌표
	int minTime = 1e9;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (MAP[row][col] == 'A') {
				int time = visited_mc[row][col] - 1 + visited_fire[row][col] - 1;
				minTime = min(time, minTime);
			}
		}
	}
	cout << minTime;

	return 0;
}
