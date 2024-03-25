#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int main() {
	int h, w;
	cin >> h >> w;

	int MAP[101][101] = { 0 };

	Node first;
	Node second;
	cin >> first.row >> first.col;
	cin >> second.row >> second.col;

	int visited[100][100] = { 0 }; // 시작점으로부터 거리
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };

	queue<Node> qu;

	visited[first.row][first.col] = 1;
	visited[second.row][second.col] = 1;
	qu.push(first);
	qu.push(second);

	int maxDay = -1e9;
	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();
		maxDay = max(maxDay, visited[now.row][now.col]);

		// next 등록
		for (int t = 0; t < 4; t++) {
			int nr = now.row + dr[t];
			int nc = now.col + dc[t];
			if (nr < 0 || nc < 0 || nr>=h || nc>=w) continue;
			if (visited[nr][nc]>0) continue;
			visited[nr][nc] = visited[now.row][now.col] + 1;
			qu.push({ nr, nc });
			}
		}

	cout << maxDay;

	return 0;
}
