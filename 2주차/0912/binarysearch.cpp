#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool bst(vector<int>& arr, int target) {
	int s = 0;
	int e = arr.size() - 1;

	while (s <= e) {
		int mid = (s + e) / 2;
		// 다음 탐색 범위를 줄인다
		if (target == arr[mid]) {
			return true;
		}
		else if (arr[mid] < target) {
			s = mid + 1;
		}
		else if (target < arr[mid]) {
			e = mid - 1;
		}
	}

	return false;
}


int main() {
	int n; // 배열 크기
	int k; // 찾아야 하는 수
	
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> k;
	vector<int> arr2(k); // 찾아야 하는 배열
	for (int i = 0; i < k; i++) {
		cin >> arr2[i];
	}

	sort(arr.begin(), arr.end()); // O(nlogn)

	for (int i = 0; i < k; i++) {
		int target = arr2[i];
		if (bst(arr, target)) {
			cout << 'O';
		}
		else {
			cout << 'X';
		}
	}

	return 0;
}
