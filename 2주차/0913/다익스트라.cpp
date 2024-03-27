#include<iostream>
#include<queue>
using namespace std; 

/*
11
1 5 40
1 2 60
1 3 20
2 7 10
3 4 10
4 2 20
4 6 50
5 2 10
5 7 10
6 2 10
7 6 10
*/

// 다익스트라 
struct Edge {
	int node; 
	int edge_cost; 
};
struct Node {
	int node; 
	int acc_cost; // 누적된 거리
};

struct cmp {
	bool operator()(Node& left, Node& right)const {
		if (left.acc_cost > right.acc_cost) return true; 
		if (left.acc_cost < right.acc_cost) return false; 
		return false; 
	}
};
int N = 6; 
vector<Edge> adj[7]; 
void input() {
	int T; 
	cin >> T; 
	for (int i = 0; i < T; i++) {
		int a, b, c; 
		cin >> a >> b >> c;  // a->b c만큼 비용 
		adj[a].push_back({ b,c }); 
	}
}

int main() {
	input(); 
	
	int dist[7] = { 0 }; // pq 에 들어있는 거리중 제일 짧은 거리가 기록되어있다.
	for (int node = 1; node <= 6; node++) dist[node] = 1e9; 

	priority_queue<Node, vector<Node>, cmp> pq; 
	bool processed[7] = { 0 }; 

	dist[1] = 0; // 이후로는 pq에 얘보다 짧은 거리만 가치 있다! 
	pq.push({ 1, 0 }); 

	while (!pq.empty()) {
		Node now = pq.top(); pq.pop();
		if (processed[now.node])continue; 
		processed[now.node] = true; 

		// process 
		for (Edge next : adj[now.node]) { // now.acc_cost + next.edge_cost
			int new_dist = now.acc_cost + next.edge_cost; 
			if (dist[next.node] <= new_dist)continue;  // pq 에 넣을 가치가 있는가? 
			dist[next.node] = new_dist;  // 이후에 pq에는 얘보다 짧은거리만 가치있다
			pq.push({ next.node, new_dist }); 
		}
	}

	
	for (int node = 1; node <= 6; node++) {
		cout << 1 << "~~~~>" << node << ":" << dist[node] << endl; 
	}


	return 0; 
}
