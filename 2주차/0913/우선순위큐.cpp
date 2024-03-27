#include<queue>
#include<iostream>
using namespace std;

int main() {

	int N;
	cin >> N;

	string s;
	int num;
	priority_queue<int> pq; // max heap 동작, int가 큰값이 먼저 나옴

	for (int i = 0; i < N; i++) {
		cin >> s >> num;

		if (s == "push") {
			pq.push(num);
		}

		if (s == "pop") {
			for (int n = 0; n < num; n++) {
				int ret = pq.top();
				pq.pop();
				cout << ret << " ";
			}
			cout << endl;
		}

		if (s == "add") {
			int ret = pq.top();
			pq.pop();
			ret += num;
			pq.push(ret);
		}
	}


	return 0;
}
