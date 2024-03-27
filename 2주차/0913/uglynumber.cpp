#include<iostream>
#include<set>
#include<queue>

using namespace std;

int main()
{
	using ll = long long; 
	
	priority_queue<ll, vector<ll>, greater<ll>> pq; // 작은 값부터 뽑는다.
	set<ll> exist;

	int mul[3] = { 2,3,5 };
	exist.insert(1);
	pq.push(1);

	int order[1501]; 
	int th = 1; 
	while (th <= 1500) {
		// 뽑고 
		int now = pq.top(); pq.pop();
		order[th] = now; 
		th++; 

		// process x2, x3, x5 
		for (int i = 0; i < 3; i++) {
			if (exist.count(now * mul[i]) == 1)continue;
			exist.insert(now * (ll)mul[i]);
			pq.push(now * (ll)mul[i]);
		}
	}

	int Q; 
	cin >> Q; 
	for (int i = 0; i < Q; i++) {
		int q; cin >> q; 
		cout << order[q] << " "; 
	}

	return 0;
}
