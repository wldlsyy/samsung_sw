#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int adj[100][100];
int visited[100];
int N;
int dest;
int minCost, maxCost;

void dfs(int now, int cost) {
	if (now == dest) {
		minCost = min(cost, minCost);
		maxCost = max(cost, maxCost);
		return;
	}

	for (int next = 0; next < N; next++) {
		if (adj[now][next] == 0) continue;
		if (visited[next] == 1) continue;
		visited[next] == 1;
		dfs(next, cost + adj[now][next]);
		visited[next] = 0;
	}
	return;
}

int main() {
	minCost = 1e9;
	maxCost = -1e9;

	cin >> N;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> adj[row][col];
		}
	}

	int start;
	cin >> start >> dest;

	visited[start] = 1;
	dfs(start, 0);

	cout << minCost << endl;
	cout << maxCost << endl;


	return 0;
}
