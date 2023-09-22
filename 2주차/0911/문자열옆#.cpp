#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;

	char a ,b;
	cin >> a >> b;

	int prev_a=-1, next_a=-1;
	int prev_b=-1, next_b=-1;

	int idx = s.find(a, 0);
	prev_a = idx - 1;
	next_a = idx + 1;

	int idx2 = s.find(b, 0);
	prev_b = idx2 - 1;
	next_b = idx2 + 1;

	s[prev_a] = '#';
	s[next_a] = '#';
	s[prev_b] = '#';
	s[next_b] = '#';
	
	cout << s;

	return 0;
}
