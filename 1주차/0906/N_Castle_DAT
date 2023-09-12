#include<iostream>
#include<vector>
using namespace std; 

int N; 
bool used[10]; 
bool isUnpromising(int col) {
	return used[col]; 
}

int answer; 
void dfs(int row) {
	if (row == N) {
		answer++; 
		return;
	}
	for (int col = 0; col < N; col++) {
		if (isUnpromising(col))continue; // 가지치기 
		used[col] = true;  // 상태 바꾸기 
		dfs(row + 1); 
		used[col] = false; // 상태 원상복구 
	}
}
int main()
{
	cin >> N; 
	dfs(0); 
	cout << answer; 

	return 0; 
}
