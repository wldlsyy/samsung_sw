#include<iostream>
#include<string>
using namespace std;

int main() {
	string name; // 민철이 영어 이름
	cin >> name;

	int n; // 검사할 문자열 수
	cin >> n;

	string s; // 맛집 이름
	for (int i = 0; i < n; i++) {
		cin >> s;
		
		if (s.find(name) == -1) {
			cout << 'X' << "\n";
		}
		else {
			cout << 'O' << "\n";
		}
	}

	return 0;
}
