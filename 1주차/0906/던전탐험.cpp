#include<iostream>
#include<string>
using namespace std;

int N;

void dfs(int level, string s) {
	if (level == N) {
		cout << s << endl;
		return;
	}

	dfs(level+1, s+"L"); // 왼쪽
	dfs(level+1, s+"R"); // 오른쪽
}

int main() {
	cin >> N;
	string str = "";

	dfs(0, str);

	return 0;
}
