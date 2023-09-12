#include<iostream>
#include<vector>
using namespace std;


void RecursiveFunc(vector<int> arr, int start, int end) {
	if (start >= end) {
		cout << arr[end] << " ";
		return;
	}


	cout << arr[start] << " ";
	RecursiveFunc(arr, start+1, end);
	cout << arr[start] << " ";

	return;
}


int main() {
	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int start, end;
	cin >> start >> end;

	RecursiveFunc(arr, start, end);
}
