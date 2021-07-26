//https://www.spoj.com/problems/BUGLIFE/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
vector<int> gp[2001];
int vis[2001];
int col[2001];

bool dfs(int node, int c) {

    vis[node] = 1;
    col[node] = c;
    for (int child:gp[node]) {
        if (vis[child] == 0) {
            bool res = dfs(child, c ^ 1);
            if (res == false)
                return false;
        } else {
            if (col[child] == col[node]) {
                return false;
            }
        }

    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, bugs, inter, a, b;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> bugs >> inter;
        int interr = inter;
        for (int i = 1; i <= bugs; ++i) {
            gp[i].clear(), vis[i] = 0;
        }
        for (int i = 1; i <= inter; ++i) {
            cin >> a >> b;
            gp[a].push_back(b), gp[b].push_back(a);
        }

        bool flag = true;
        for (int i = 1; i <= bugs; ++i) {
            if (vis[i] == 0) {
                bool isB = dfs(i, 0);
                if (!isB) {
                    flag = false;
                }
            }
        }
        cout << "Scenario #" << tc << ":" << "\n";
        if (flag == false) {

            cout << "Suspicious bugs found!" << "\n";
        } else {
            cout << "No suspicious bugs found!" << "\n";
        }

    }
}
