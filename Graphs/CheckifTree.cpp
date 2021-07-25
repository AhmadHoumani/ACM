//https://www.spoj.com/problems/PT07Y/
#include<bits/stdc++.h>

using namespace std;
vector<int> gp[10001];
int vis[10001];

void dfs(int node) {
    vis[node] = 1;
    for (int child:gp[node]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

int main() {
    int n, m, a, b, count = 0;
    cin >> n >> m;
    int mm = m;
    while (mm--) {
        cin >> a >> b;
        gp[a].push_back(b), gp[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            count++;
            dfs(i);
        }
    }
    //cout << count;
    if (count == 1 && m == n - 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }


}

