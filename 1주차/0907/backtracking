#include<iostream>
#include<vector>
using namespace std;

char items[] = "ABCDE";
// 5개 아이템 중 3개를 뽑아 나열한다. (중복 없이)

vector<char> nextPath(vector<char>path, int i) { // 만약 참조로 받으면 원상복구 해야 함
	path.push_back(items[i]);
	return path;
}

vector<bool> nextUsed(vector<bool>used, int i) {
	used[i] = true; // 이후 경로에서 i번째 아이템 선택 방지
	return used;
}

void print(vector<char>& v) {
	for (char ch : v) {
		cout << ch;
	}
	cout << endl;
}

bool isDup(vector<char> path, int i) {
	for (int i = 0; i < path.size(); i++) {
		if (path[i] == items[i]) return true;
	}
	return false;
}

void dfs(int level, vector<char>path, vector<bool> used) {
	if (level == 3) {
		print(path);
	}
	for (int i = 0; i < 5; i++) {
		// 가지치기
		if (isDup(path, i)) continue;
		if (used[i] == true) // i번째 아이템이 이전 경로에서 선택된 적 있는가
			continue;
		dfs(level + 1, nextPath(path, i), nextUsed(used, i));
	}
}



int main()
{
	dfs(0, vector<char>(), vector<bool>(5));
}
