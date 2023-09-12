#include<iostream>
using namespace std;

int main() {
	int coins[4] = { 500, 100, 50, 10 };

	int price;
	cin >> price;
	
	int cnt = 0;

	for (int val : coins) {
		cnt += price / val;
		price %= val;
	}

	cout << cnt << endl;
}
