#include<iostream>
#include<queue>
using namespace std;

int N, M;
int adj[11][11];
int Fire;
void input() {
	cin >> N >> M;
	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	cin >> Fire;
}

int main()
{
	input();
	int moveCnt[11] = { 1e9,1e9,1e9,1e9,1e9,1e9,1e9,1e9,1e9,1e9,1e9 };

	bool visited[11] = { 0 };
	queue<int> qu;
	int start = 1;
	visited[start] = true;
	moveCnt[start] = 0;
	qu.push(start);

	while (!qu.empty()) {
		int now = qu.front(); qu.pop();

		for (int next = 1; next <= N; next++) {
			if (adj[now][next] == 0)continue;
			if (next == Fire)continue;
			if (visited[next] == 1)continue;
			visited[next] = 1;
			moveCnt[next] = moveCnt[now] + 1;
			qu.push(next);
		}
	}

	// moveCnt 
	if (moveCnt[N] == 1e9) {
		cout << -1; 
	}
	else 
	cout << moveCnt[N]; 

	return 0; 
}
