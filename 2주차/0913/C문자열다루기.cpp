#define _CRT_SECURE_NO_WARNINGS
#include<cstring> // string.h // c style 문자열 함수들이 있는 문자열 라이브러리
#include<string> // c++ string
#include<iostream>
using namespace std;

int main() {
	// 복사 
	/*
	{
		char dest[12];
		char src[12] = "hello world";
		strcpy(dest, src);
		cout << dest;
	}
	*/

	// strcmp 문자열 비교 함수 
	/*
	{
		char a[12] = "hello world";
		char b[12] = "Hello World";
		char c[12] = "hello world";

		if (!strcmp(a, b)) { // 같냐?
			cout << "A와 B가 같다";
		}
		if (!strcmp(a, c)) {
			cout << "A와 C는 같다";
		}

	}
	*/

	// string 을 c style 의 문자열로 str.c_str()
	string str = "hello world";
	char arr[12] = "";

	strcpy(arr, str.c_str());

	return 0;
}
