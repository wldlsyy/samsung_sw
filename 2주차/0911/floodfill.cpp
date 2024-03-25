#include<iostream>
#include<queue>
using namespace std; 

struct Node {
	int row;
	int col;
}; 

int main()
{
	Node start;
	cin >> start.row >> start.col;

	int visited[5][5] = { 0 }; 
	int dr[] = { -1,1,0,0 }; 
	int dc[] = { 0,0,-1,1 }; 
	
	queue<Node> qu; 
	visited[start.row][start.col] = 1;
	qu.push(start); 

	while (!qu.empty()) {
		Node now = qu.front(); 
		qu.pop(); 

		// next 등록 
		for (int t = 0; t < 4; t++) {
			int nr = now.row + dr[t];
			int nc = now.col + dc[t];
			if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5)
				continue; 
			if (visited[nr][nc] > 0)
				continue; 
			visited[nr][nc] = visited[now.row][now.col] + 1; 
			qu.push({ nr,nc });
		}
	}

	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++) {
			cout << visited[row][col] << " ";
		}
		cout << "\n";
	}
	return 0;
}
