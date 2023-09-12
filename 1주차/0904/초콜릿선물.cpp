#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N = 100000;
	string S;

	cin >> S; // 문자열 입력받기

	vector<char> uniqueChars;

	for (int i = 0;i < S.length(); i++) {
		char curr = S[i];
		bool isDup = false;

		for (int j = 0;j < i;j++) {
			if (curr == S[j]) {
				isDup = true;
				break;
			}
		}
		if (!isDup) {
			uniqueChars.push_back(curr);
		}
	}
	// 중복을 제외한 문자를 알파벳 순서대로 정렬
	sort(uniqueChars.begin(), uniqueChars.end());

	// 정렬된 문자 출력
	for (char ch : uniqueChars) {
		cout << ch;
	}

	return 0;
}
