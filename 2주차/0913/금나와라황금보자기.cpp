#include<queue>
#include<functional>
#include<iostream>
using namespace std; 

struct Node {
	int weight; 
	bool isGold; 
};

struct cmp {
	bool operator()(const Node& left, const Node& right) const {
		if (left.weight > right.weight) {
			return true; 
		}
		if (left.weight < right.weight) {
			return false;
		}
		if (left.isGold == false && right.isGold == true) {
			return true; 
		}
		return false;  
	}
};

int main()
{
	//freopen_s(new FILE*, "text.txt", "r", stdin);
	priority_queue<Node, vector<Node>, cmp> pq; 
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int val; 
		cin >> val; 
		pq.push({ val, true }); 
	}
	int cnt = 0; 
	while (!pq.empty()) {
		
		Node first = pq.top(); pq.pop(); 
		if (first.isGold == false) break; 
		cnt++; 
		
		if (pq.empty())break; 

		Node second = pq.top(); pq.pop(); 
		if (second.isGold == false) break;
		cnt++; 

		pq.push({ second.weight * 2, false }); 
	}
	cout << cnt; 
	return 0; 
}
