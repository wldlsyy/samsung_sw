#include<iostream>
using namespace std;

int N;
int adj[13][13];
void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> adj[r][c];
		}
	}
}
int visited[13];
int minCost = 1e9;
void dfs(int now, int visitCnt, int cost) {
	if (cost >= minCost) {
		return;
	}
	if (visitCnt == N) {
		if (adj[now][1]) {
			minCost = min(minCost, cost + adj[now][1]);
		}
		return;
	}
	for (int next = 0; next < N; next++) {
		if (adj[now][next] == 0)continue;
		if (visited[next] == 1)continue;
		visited[next] = 1;
		dfs(next, visitCnt + 1, cost + adj[now][next]);
		visited[next] = 0;
	}
}
int main()
{
	input();
	int cnt = 1;
	visited[1] = 1;
	dfs(1, cnt, 0);
	cout << minCost;
	return 0;
}
