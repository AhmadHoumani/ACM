//https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
vector<int> gp[100001];
int vis[100001];

void dfs(int node) {
    vis[node] = 1;
    for (int child:gp[node]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, e, a, b, count = 0;
    cin >> n >> e;
    while (e--) {
        cin >> a >> b;
        gp[a].push_back(b), gp[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            count++;
            dfs(i);
        }
    }
    cout << count;
}

