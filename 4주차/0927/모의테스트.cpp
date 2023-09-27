#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> directory;
int N; // 디렉토리 개수
int Top; // 최상위 디렉토리 번호

int bfs(int node) {
    vector<bool> visited(N + 1, false);
    queue<int> q;
    // 시작 노드 큐에 넣고 방문 처리
    q.push(node);
    visited[node] = true;

    int cnt = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        // 현재 디렉토리에 연결된 하위 디렉토리 모두 탐색
        for (int i = 0; i < directory[curr].size(); ++i) {
            int next = directory[curr][i];
            if (visited[next]) continue; 
            q.push(next);
            visited[next] = true;
            if (next < node) { // 상위 디렉토리보다 하위 디렉토리 번호가 더 작은 경우
                cnt++; // 디렉토리 개수 증가
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cin >> N >> Top;

        // 초기화하고 사이즈 재설정
        directory.clear();
        directory.resize(N + 1);

        for (int n = 1; n <= N - 1; ++n) { // 상위, 하위 디렉토리 간 관계 입력받기
            int top, bottom;
            cin >> top >> bottom;
            directory[top].emplace_back(bottom);
        }

        // 각 상위 디렉토리로 bfs 돌려서 하위 디렉토리 개수 구하기
        int totalCnt = 0;
        for (int i = 1; i <= N; ++i) {
            if (directory[i].empty()) continue; // 상위 디렉토리 번호가 아니면 넘어감
            //cout << "노드 " << i << ":" << bfs(i) << "\n";
            totalCnt += bfs(i);
        }

        cout << "#" << t << " " << totalCnt << "\n";
    }

    return 0;
}
