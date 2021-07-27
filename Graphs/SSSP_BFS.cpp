//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<ll> gp[100005];
ll vis[100005];
ll dis[100005];

void bfs(ll node) {
    vis[node] = 1;
    //dis[node] = 0;
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        ll curr = q.front();
        q.pop();
        for (ll child:gp[curr]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = 1;
                dis[child] = dis[curr] + 1;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t, n, m, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            gp[i].clear();
            vis[i] = 0;
        }
        while (m--) {
            cin >> a >> b;
            gp[a].push_back(b), gp[b].push_back(a);
        }
        bfs(1);
        cout << dis[n] << "\n";
    }
}
