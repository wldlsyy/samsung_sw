#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N; // 섬 개수
vector<long long> W; // 연료비
vector<vector<int>> canal; // 연결관계
vector<vector<int>> moveCnt; // 이동 횟수 저장

void input() {
	cin >> N;
	canal.resize(N + 1);
	W.resize(N + 1);
	moveCnt.resize(N + 1);

	for (int i = 0; i < N - 1; ++i) { // 운하 개수는 N-1
		int a, b;
		cin >> a >> b;
		canal[a].emplace_back(b);
		canal[b].emplace_back(a);
	}
	for (int n = 1; n <= N; ++n) { // 각 섬의 연료비, 인덱스가 섬 번호
		cin >> W[n];
	}
}

void dfs(int node, int parent, int depth) {
	moveCnt[node].push_back(depth);

	for (int neighbor : canal[node]) {
		if (neighbor != parent) {
			dfs(neighbor, node, depth + 1);
		}
	}
}

int main() {
	int TC; // 테스트케이스 수
	cin >> TC;
	for (int t = 0; t < TC; ++t) { // 각 케이스마다
		input();

		for (int n = 1;n <= N; ++n) {
			dfs(n,0,0); // n번 섬에서 모일 때 각각 이동 횟수 저장
		}

		//// 각 노드에서부터 루트 노드까지의 이동 횟수 출력
		//for (int i = 1; i <= N; ++i) {
		//	cout << "Node " << i << ": ";
		//	for (int j = 0; j < N; ++j) {
		//		cout << moveCnt[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		long long minFuel = INT_MAX;
		for (int i = 1; i <= N; ++i) {
			long long currFuel = 0;
			for (int j = 0; j < N; ++j) {
				currFuel += W[j+1] * moveCnt[i][j];
				if (currFuel > minFuel)
					break;
			}
			minFuel = min(minFuel, currFuel);
		}

		cout << minFuel << endl;

		// 벡터 초기화
		for (int i = 1; i <= N; ++i) {
			moveCnt[i].clear();
		}
		canal.clear();
		W.clear();
	}

	return 0;
}
