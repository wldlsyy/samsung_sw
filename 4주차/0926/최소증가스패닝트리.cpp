#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, long long> p;

int N, M; // 노드 수, 간선 수
vector<p> graph[100001]; // 인덱스 이용해서 해당 노드가 몇번 노드와 어떤 가중치로 연결되었는지 저장
vector<int> parent(100001, 0); // 각 노드의 부모 노드를 저장
vector<long> weight(100001, 0); // 각 노드의 가중치를 저장

struct cmp {
    bool operator()(p a, p b) {
        return a.second > b.second;
    }
};

long long bfs() {
    priority_queue<p, vector<p>, cmp> pq;
    vector<bool> visited(N + 1, false);

    // 1번 정점부터 시작하니까, 1번과 연결된 간선 모두 큐에 삽입
    for (int i = 0; i < graph[1].size(); ++i) {
        pq.push(graph[1][i]);
        visited[1] = true; // 1번 노드 방문 처리
    }

    int cnt = 0;
    while (cnt < N - 1) { // 모든 노드 잇는 최소 간선 수는 (노드 수 - 1) 이니까
        p edge = pq.top();
        pq.pop();

        int node = edge.first;
        long long w = edge.second;

        if (visited[node]) continue; // 간선이 노드를 이미 방문했으면 넘어감
        visited[node] = true; // 방문 처리
        parent[node] = 1; // 노드의 부모를 1로 설정
        weight[node] = w; // 노드의 가중치 설정
        cnt++;

        for (int i = 0; i < graph[node].size(); ++i) { // 노드와 연결된 간선 모두 삽입
            int nextNode = graph[node][i].first;
            long long nextWeight = graph[node][i].second;
            if (visited[nextNode]) continue; // 만약 그 노드가 이미 방문한거면 스킵
            if (nextWeight < weight[nextNode]) continue; // 부모보다 자식 간선의 가중치가 더 작으면 스킵
            pq.push(graph[node][i]);
            weight[nextNode] = nextWeight;
            parent[nextNode] = node;
        }
    }

    // 최소 증가 스패닝 트리를 구성할 수 없는 경우 -1 반환
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) { // 연결 안된거 하나라도 있으면
            return -1;
        }
    }

    // 최소 간선의 총합 반환
    long long totalWeight = 0;
    for (int i = 2; i <= N; ++i) {
        totalWeight += weight[i];
    }
    return totalWeight;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cin >> N >> M;

        for (int i = 0; i < M; ++i) {
            int n1, n2;
            long long w;
            cin >> n1 >> n2 >> w;
            graph[n1].push_back({ n2,w });
            graph[n2].push_back({ n1,w });
        }

        long long result;
        result = bfs();

        cout << "#" << t << " " << result << "\n";

        // 초기화
        for (int i = 1; i <= N; ++i) {
            graph[i].clear();
            parent[i] = 0;
            weight[i] = 0;
        }

    }

    return 0;
}
