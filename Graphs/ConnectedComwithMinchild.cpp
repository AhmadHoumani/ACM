//https://codeforces.com/problemset/problem/893/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<ll> gp[100005];
ll vis[100005];
ll prices[100005];
ll p = 0;

ll dfs(ll node) {
    vis[node] = 1;
    ll mn = prices[node];
    for (ll child:gp[node]) {
        if (!vis[child]) {
            mn = min(mn, dfs(child));
        }
    }
    return mn;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, a, b;
    cin >> n >> m;
    //ll prices[n];
    for (int i = 1; i <= n; ++i) {
        cin >> prices[i];
    }
    while (m--) {
        cin >> a >> b;
        gp[a].push_back(b), gp[b].push_back(a);
    }
    ll p = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {

            p += dfs(i);
//            cout << prices[i] << " ";
//            cout << i << " ";

        }
    }
    cout << p;
}
