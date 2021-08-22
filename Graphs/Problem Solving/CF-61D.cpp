//https://codeforces.com/contest/61/problem/D
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<pair<int, int>> gp[1000001];
int vis[1000001];
ll leafsum = 0;

void dfs(ll root, ll sum) {
    vis[root] = 1;
    for (auto child:gp[root]) {
        if (!vis[child.first]) {
            dfs(child.first, sum + child.second);
        } else if (gp[root].size() == 1) {
            leafsum = max(leafsum, sum);
        }
    }
}

signed main() {

    ll n, a, b, w, sum = 0;
    cin >> n;
    n--;
    while (n--) {
        cin >> a >> b >> w;
        gp[a].push_back({b, w}), gp[b].push_back({a, w});
        sum += w * 2;
    }
    dfs(1, 0);
    ll ans = sum - leafsum;
    cout << ans;
}
