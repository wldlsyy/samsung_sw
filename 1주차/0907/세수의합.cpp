#include<iostream>
#include<vector>
using namespace std;

int N, K; // 배열 크기와 만족해야 하는 값
vector<int> arr; // {5,2,1,4}
int exist[100001] = { false };
int index[100001]; // [5]=0, [2]=1, [1]=2, [4]=3

int main() {
	cin >> N >> K;
	arr = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		exist[arr[i]] = true;
	}

	int cnt = 0;
	for (int a = 0;a < N;a++) {
		for (int b = a + 1; b < N; b++) {
			int twoSum = arr[a] + arr[b];
			int target = K - twoSum;
			if (target<0 || target > 100000) continue;
			if (!exist[target]) continue;
			if (arr[a] == target || arr[b] == target) continue;
			cnt++;
		}
	}
	cout << cnt / 3; // c<a<b / a<c<b / a<c<b

	return 0;
}
