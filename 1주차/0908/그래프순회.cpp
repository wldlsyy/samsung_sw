#include <iostream>
using namespace std;

int N, K;
int Start;
int adj[101][101];

int visited[101];
void preorder(int now) {
	// A (preorder)
	cout << now << " ";
	for (int next = N; next >= 1; next--) {
		if (adj[now][next] == 0) continue;
		if (visited[next] == 1) continue;
		visited[next] = 1;
		preorder(next);
	}
	// B (postorder)
	return;
}

int visited2[101];
void postorder(int now) {
	// A (preorder)
	for (int next = N; next >= 1; next--) {
		if (adj[now][next] == 0) continue;
		if (visited2[next] == 1) continue;
		visited2[next] = 1;
		postorder(next);
	}
	// B (postorder)
	cout << now << " ";

	return;
}


int main() {
	cin >> N >> K;
	cin >> Start;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
	}

	visited[Start] = 1;
	preorder(Start);

	cout << endl;

	visited2[Start] = 1;
	postorder(Start);

	return 0;
}
