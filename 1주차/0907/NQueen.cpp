#include<iostream>
#include<vector>
using namespace std;

// 각 좌표에 그룹 번호를 붙여준다. 

// 우하방향 그룹 
int group1[13][13];
int N;
void SetGroup1() { // 우하 방향으로 그룹 setting
	int dr = 1; // 방향
	int dc = 1; // 방향 

	int gn = 1;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			if (group1[row][col] != 0)continue; //이미 그룹이 set 된 좌표
			int next_row = row;
			int next_col = col;
			while (next_row < N && next_col < N) {
				group1[next_row][next_col] = gn;
				next_row += dr;
				next_col += dc;
			}
			gn++;
		}
	}
}



// 좌하방향 그룹 
int group2[13][13];

void SetGroup2() { // 좌하 방향으로 그룹 setting 
	int dr = 1; // 방향
	int dc = -1; // 방향 

	int gn = 1;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			if (group2[row][col] != 0)continue; //이미 그룹이 set 된 좌표
			int next_row = row;
			int next_col = col;
			while (next_row < N && next_col >= 0) {
				group2[next_row][next_col] = gn;
				next_row += dr;
				next_col += dc;
			}
			gn++;
		}
	}
}

bool used_1[26]; // [3][2] 의 대각선1 그룹이 사용되었는가? -> used_1[group1[3][2]] == true
bool used_2[26]; // [3][2] 의 대각선2 그룹이 사용되었는가? -> used_2[group2[3][2]] == true
bool used_col[13];

int cnt;
void dfs(int row) {
	if (row == N) {
		cnt++;
		return;
	}
	for (int col = 0; col < N; col++) {
		// 이전 경로에서 선택되었으면 
		if (used_col[col])continue;
		if (used_1[group1[row][col]])continue;
		if (used_2[group2[row][col]])continue;

		// 이후 경로에서 선택 방지
		used_col[col] = true;
		used_1[group1[row][col]] = true;
		used_2[group2[row][col]] = true;

		dfs(row + 1);

		// 원상복구 
		used_col[col] = false;
		used_1[group1[row][col]] = false;
		used_2[group2[row][col]] = false;
	}
}
int main() {
	cin >> N;
	SetGroup1();
	SetGroup2();
	dfs(0);
	cout << cnt;
	return 0;
}
