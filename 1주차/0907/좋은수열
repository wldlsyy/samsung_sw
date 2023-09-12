#include<iostream>
#include<string>
using namespace std;

int N;

bool isGood(string s) {
	// [a]~[b] -> size = b-a+1
	// [a, a+size/2-1] vs [a+size/2, b] -> 동일하면 나쁜수열
	for (int a = 0;a < s.size(); a++) {
		for (int b = a + 1; b < s.size(); b++) {
			int size = b - a + 1;
			if (size % 2 != 0)continue;
			if(s.substr(a, size/2) == s.substr(a+size/2, size/2)) return false; // [a~몇개]
		}
	}
	return true;
}

bool EXIT;
void dfs(int level, string s) {
	if (level == N) {
		EXIT = true;
		cout << s << endl;
		return;
	}

	for (char ch = '1'; ch <= '3'; ch++) {
		string new_s = s + ch;
		if (isGood(new_s)) {
			dfs(level + 1, new_s);
		}

		if (EXIT) return; // 빠른종료
	}

}


int main() {
	cin >> N;

	dfs(0, "");
	
	return 0;
}
