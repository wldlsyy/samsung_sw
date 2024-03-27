#include<queue>
#include<utility>
#include<iostream>
using namespace std; 

struct Node {
	int num;
	char ch;
};
struct cmp {
	bool operator()(const int& left, const int& right) const {
		return left < right; 
	}
	bool operator()(const Node& left, const Node& right) const {
		if (left.num % 2 == 1 && right.num % 2 == 0) {
			return true; 
		}
		if (left.num % 2 == 0 && right.num % 2 == 1) {
			return false; 
		}
		if (left.num < right.num) {
			return true; 
		}
		if (left.num > right.num) {
			return false; 
		}
		return left.ch > right.ch; 
	}
};


int main()
{

	//freopen_s(new FILE*, "텍스트.txt", "r", stdin); 
	less<int>; 
	priority_queue<Node,vector<Node>, cmp> pq;
	
	pq.push({2,'z'});
	pq.push({4,'b'});
	pq.push({1,'a'});
	pq.push({1,'b'});
	pq.push({1,'c'});
	pq.push({3,'e'});
	pq.push({5,'q'});

	while (!pq.empty()) {
		Node now = pq.top(); pq.pop(); 

		cout << now.num << " " << now.ch << "\n";
	}

	return 0; 
}
