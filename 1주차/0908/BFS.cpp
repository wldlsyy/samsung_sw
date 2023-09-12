#include<iostream>
#include<queue>
using namespace std;

int arr[8][8];
int visited[8];

void init() {
	arr[0][1] = 1;
	arr[0][2] = 1;
	arr[0][3] = 1;
	arr[1][4] = 1;
	arr[1][5] = 1;
	arr[1][6] = 1;
	arr[3][7] = 1;
}

int main()
{
	init();
	string names = "ABCEFDQR";

	queue<int>qu;
	// 큐에 시작점 등록
	qu.push(0);
	visited[0] = 1;

	// BFS 진행
	while (!qu.empty()) {
		// 뽑고 (해당 정점 처리)
		int now = qu.front();
		qu.pop();
		cout << names[now] << " ";

		// next 큐 등록
		for (int next = 0; next < 8; next++) {
			if (arr[now][next] == 0) continue; // 연결관계 없으면 스킵
			if (visited[next] == 1) continue; // 한번 방문한 노드 스킵
			qu.push(next);
			visited[next] = 1;
		}
	}

	return 0;
}
