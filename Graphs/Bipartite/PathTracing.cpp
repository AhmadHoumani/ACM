//https://codeforces.com/contest/1144/problem/F
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> gp[200005];
ll color[200005];
bool flag = true;
vector<pair<int, int>> p;

void dfs(int node, int c) {
    color[node] = c;
    for (auto child:gp[node]) {
        if (color[child] == -1) {
            dfs(child, c ^ 1);
        } else if (color[child] == color[node]) {
            flag = false;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, a, b;

    cin >> n >> m;
    ll s = m;
    while (m--) {
        cin >> a >> b;
        gp[a].push_back(b), gp[b].push_back(a);
        p.push_back({a, b});
    }
    memset(color, -1, sizeof color);
    dfs(1, 0);
    if (!flag) {
        puts("NO");
    } else {
        cout << "YES" << "\n";
        for (int i = 0; i < s; ++i) {
            cout << (color[p[i].first] < color[p[i].second]);

        }
    }
}
