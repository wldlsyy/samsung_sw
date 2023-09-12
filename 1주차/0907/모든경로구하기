#include <iostream>
#include<vector>
using namespace std;

int adj[4][4];
int visited[4];

void init() {
	adj[0][1] = 1;
	adj[0][2] = 1;
	adj[0][3] = 1;
	adj[1][0] = 1;
	adj[1][3] = 1;
	adj[2][1] = 1;
	adj[2][3] = 1;
}

vector<int> nextPath(vector<int> prevPath, int node) {
	prevPath.push_back(node);
	return prevPath;
}

void dfs(int now, vector<int> path) {
	if (now == 3) {
		for (int node : path) {
			cout << node << " ";
		}
		cout << "도착" << endl;
		return;
	}

	for (int next = 0; next < 4; next++) {
		if (adj[now][next] == 0) continue;
		if (visited[next] == 1) continue; // 이전 경로에서 등장
		visited[next] = 1; // 이후 경로에서 등장 방지
		dfs(next, nextPath(path, next));
		visited[next] = 0; // 원상복구
	}
	return;
}

int main() {
	init();

	int start = 0;
	visited[start] = 1; // 이후 경로에서 포함되지 못하도록
	vector<int> path = { start };
	dfs(start, path);

	return 0;
}
