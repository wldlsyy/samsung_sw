#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
	int num;
	char ch;
};

bool compare(const Node& left, const Node& right) {
	// left와 right 중 누가 더 왼쪽으로 가는지
	if (left.num % 2 == 0 && right.num % 2 != 0) {
		return true;
	}
	else if (left.num % 2 != 0 && right.num % 2 == 0) {
		return false;
	}
	else if (left.num != right.num) {
		return left.num < right.num;
	}
	else {
		return left.ch < right.ch;
	}
}

int main() {
	int N;
	cin >> N;
	
	vector<int> arr(N);
	vector<char> arr2(N);

	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}

	for (int n = 0; n < N; n++) {
		cin >> arr2[n];
	}

	vector<Node> nodes; // 구조체 Node를 저장할 vector

	for (int n = 0; n < N; n++) {
		nodes.push_back({ arr[n], arr2[n] });
	}
	
	// Type 1
	sort(arr.begin(), arr.end(), less<int>()); // 오름차순 정렬
	for (int n = 0; n < N; n++) {
		cout << arr[n] << " "; // 정렬된 배열 출력
	}
	cout << "\n";

	// Type 2
	sort(arr.begin(), arr.end(), greater<int>()); // 내림차순 정렬
	for (int n = 0; n < N; n++) {
		cout << arr[n] << " "; // 정렬된 배열 출력
	}
	cout << "\n";

	// Type 3
	sort(nodes.begin(), nodes.end(), compare);
	for (Node val : nodes) {
		cout << val.num << " ";
	}
	cout << "\n";
	for (Node val : nodes) {
		cout << val.ch << " ";
	}


	return 0;
}
