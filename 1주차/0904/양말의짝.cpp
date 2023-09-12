#include <iostream>
using namespace std;

int dat[100001] = { 0 };
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N;i++) {
		int socks;
		cin >> socks;
		dat[socks]++;
	}

	int cnt = 0;
	for (int i = 1; i < 100000;i++) {
		cnt += dat[i] / 2;
	}

	cout << cnt << endl;

	return 0;
}
