//https://assessment.hackerearth.com/challenges/college/nits-local-10/algorithm/84888e824aa04fc793c3beefca02b5a7/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
vector<int> gp[1001];
int dis[1001];
int vis[1001];

void dfs(int node, int d) {
    vis[node] = 1;
    dis[node] = d;
    for (int child:gp[node]) {
        if (!vis[child]) {
            dfs(child, dis[node] + 1);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int edges, a, b, q, g;
    cin >> edges;
    edges--;
    while (edges--) {
        cin >> a >> b;
        gp[a].push_back(b), gp[b].push_back(a);

    }
    dfs(1, 0);
    int ans = -1;
    int min_dis = 99999999;
    cin >> q;
    while (q--) {
        int gc;
        cin >> gc;
        if (dis[gc] < min_dis) {
            min_dis = dis[gc];
            ans = gc;
        } else {
            if (dis[gc] == min_dis && gc < ans) {
                ans = gc;
            }
        }
    }
    cout << ans;
}
