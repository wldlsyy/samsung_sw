#include<iostream>
#include <string>
using namespace std;

int N;

void print(string path) {
	string result;

	for (int i = 0; i < path.length(); i++) {
		result += path[i];
		if (i < path.length() - 1) {
			result += " ";
		}
	}

	cout << result << endl;
}

bool isAscending(string path) {
	for (int i = 0; i < path.size() - 1; i++) {
		// path[i] vs path[i + 1] 
		if (path[i] <= path[i + 1]) continue;
		return false;
	}
	return true;
}

bool isDuplicate(string path) {
	bool dat[200] = { 0 };
	for (char ch : path) {
		if (dat[ch] == true) {
			return true;
		}
		dat[ch] = true;
	}
	return false;
}

void dfs1(int level, string path) {
	if (level == N) {
		//cout << path << "\n";
		print(path);
		return;
	}
	for (int i = 1; i <= 6; i++) {
		dfs1(level + 1, path + to_string(i));
	}
	return;
}

void dfs2(int level, string path) {
	if (level == N) {
		//cout << path << "\n";
		print(path);
		return;
	}
	for (int i = 1; i <= 6; i++) {
		if (isAscending(path + to_string(i)) == false)continue; // 가지치기 
		dfs2(level + 1, path + to_string(i));
	}
	return;
}

void dfs3(int level, string path) {
	if (level == N) {
		//cout << path << "\n";
		print(path);
		return;
	}
	for (int i = 1; i <= 6; i++) {
		if (isDuplicate(path + to_string(i))) continue;
		dfs3(level + 1, path + to_string(i));
	}
	return;
}
int main()
{
	int M;
	cin >> N >> M;
	if (M == 1) dfs1(0, "");
	if (M == 2) dfs2(0, "");
	if (M == 3) dfs3(0, "");
	return 0;
}
