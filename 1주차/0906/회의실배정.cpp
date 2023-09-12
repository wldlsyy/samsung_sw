#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Time {
	int start;
	int end;
};

bool cmp(Time left, Time right) {
	return left.end < right.end;
}


int main() {
	int N;
	cin >> N;
	vector<Time> time(N);

	for (int n = 0; n < N; n++) {
		cin >> time[n].start >> time[n].end;
	}

	sort(time.begin(), time.end(), cmp);

	int cnt = 0;
	int prev = 0;
	for (int n = 0; n < time.size(); n++) {
		if (time[n].start<prev) continue;
		cnt++;
		prev = time[n].end;
	}

	cout << cnt;

	return 0;
}
