//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=945
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> gp[201];
int vis[201];
int col[201];

bool dfs(int par, int c) {
    vis[par] = 1;
    col[par] = c;
    for (int child : gp[par]) {
        if (!vis[child]) {
            bool res = dfs(child, c ^ 1);
            if (res == false) {
                return false;
            }
        } else {
            if (col[child] == col[par]) {
                return false;
            }
        }
    }
    return true;
}

signed main() {

    int tt, n, l, a, b, s;
    while (1) {
        cin >> n;
        if (n == 0)break;
        cin >> l;
        for (int i = 0; i < n; ++i) {
            gp[i].clear(), vis[i] = 0;
        }
        for (int i = 0; i < l; i++) {
            cin >> a >> b;
            gp[a].push_back(b), gp[b].push_back(a);
        }
        bool flag = true;

        bool isB = dfs(0, 0);
        if (!isB) {
            flag = false;
        }
        if (flag == false) {

            cout << "NOT BICOLORABLE." << "\n";
        } else {
            cout << "BICOLORABLE." << "\n";
        }

    }
}
