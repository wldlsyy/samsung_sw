#include<iostream>
#include<string> 
#include<queue>

using namespace std; 

int main()
{
	string str; 
	cin >> str; 
	
	char target[2]; 
	cin >> target[0] >> target[1]; 

	int index[2] = { -1,-1 };
	for (int i = 0; i < 2; i++) {
		index[i] = str.find(target[i]); 
	}

	for (int i = 0; i < 2; i++) {
		auto it = str.begin();
		it = next(it, index[i]); // begin() + index[i]

		if (next(it, 1) != str.end()) { 
			*next(it, 1) = '#'; 
		}
		if (it != str.begin()) {
			*prev(it,1) = '#';
		}
	}
	cout << str; 
	return 0;
}
