//https://codeforces.com/problemset/problem/1176/E
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> gp[2000001];
int vis[2000001];
int dis[2000001];

void bfs(int par) {
    queue<int> q;
    vis[par] = 1;
    q.push(par);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int child:gp[x]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = 1;
                dis[child] = dis[x] + 1;
            }
        }
    }

}

signed main() {

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
        int cnte = 0, cnto = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] % 2 == 0) {
                cnte++;
            } else {
                cnto++;
            }
        }
        if (cnte < cnto) {
            cout << cnte << "\n";
            for (int i = 1; i <= n; i++) {
                if (dis[i] % 2 == 0) {
                    cout << i << " ";
                }
            }
        } else {
            cout << cnto << "\n";
            for (int i = 1; i <= n; i++) {
                if (dis[i] % 2) {
                    cout << i << " ";
                }
            }
        }

        cout << "\n";
    }


}









