#include<iostream>
#include<vector>
using namespace std;

int N, M;
int computer[101][101];

void init(int a, int b) {
	computer[a][b] = 1;
	computer[b][a] = 1;
}

int visited[101];

void dfs(int now) {
	for (int next = 1; next <= N; next++) {
		if (computer[now][next]) { //  now -> next
			if (!computer[now][next]) continue;
			if (visited[next] == 1) continue;
			visited[next] = 1;
			dfs(next);
		}
	}

	return;
}

int main() {
	cin >> N >> M;
	computer[N][N];

	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		init(a, b);
	}

	int start = 1;
	visited[start] == 1;
	dfs(start);

	int cnt = 0;
	for (int n = 2; n <= N; n++) {
		if (visited[n]) cnt++;
	}

	cout << cnt;

	return 0;
}
