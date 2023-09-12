#include<iostream>
#include<vector>
using namespace std;

int N;
int cnt;

void dfs(int num) {
	if (num > N) {
		return;
	} 
	if (num == N) {
		cnt++;
		return;
	}

	dfs(num + 1); // num + 1 ~~> N
	dfs(num + 2); // num + 2 ~~> N
	dfs(num + 3); // num + 3 ~~> N
}

int main() {
	cin >> N;
	dfs(0);
	cout << cnt;

	return 0;
}
