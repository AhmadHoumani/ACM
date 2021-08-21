//https://codeforces.com/contest/246/problem/D
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
#define N 100005
int n, m, a[N];
vector<int> adj[N];
set<int> col[N];

void dfs(int k) {

    for (int i: adj[k]) {
        if (a[i] != a[k])
            col[a[k]].insert(a[i]);
    }
}

signed main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        dfs(i);

    sort(a + 1, a + n + 1);
    int ans = 0, idx = a[1];

    for (int i = 1; i <= n; i++) {
        int size = col[a[i]].size();
        if (ans < size) {
            ans = size;
            idx = a[i];
        }
    }

    cout << idx << endl;
}
