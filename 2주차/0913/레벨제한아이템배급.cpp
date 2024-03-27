#include<iostream>
#include <set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N, M; // 길드원 수, 아이템 수
	cin >> N >> M;

	vector<int> items(M); // 정렬된 상태 유지, 삭제/삽입 빈전
	vector<int> guild(N);

	for (int m = 0; m < M; m++) {
		cin >> items[m];
	}

	for (int n = 0; n < N; n++) {
		cin >> guild[n];
	}

	sort(items.begin(), items.end());
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int nowLevel = guild[i];
		// ele <= nowLevel의 제일 가까운 거
		auto ub = upper_bound(items.begin(), items.end(), nowLevel);
		if (ub == items.begin()) break;
		//prev(ub); ub--; // 이동 하기 전 유효한가?
		items.erase(prev(ub));
		answer++;
	}
	cout << answer;

}
