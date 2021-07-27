//https://codeforces.com/gym/317667/problem/C
#include<bits/stdc++.h>
using namespace std;
vector<int> gp[500005];
int vis[500005];
vector<int> all;
int arr[500005];

void bfs(int node) {
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (!vis[x]) {
            all.push_back(x);
            vis[x] = 1;
            for (int child:gp[x]) {
                if (!vis[child]) {
                    q.push(child);
                }
            }
        }
    }
    for (int q:all) {
        arr[q] = all.size();
    }
    all.clear();
}

int main() {
    int n, m, k, a, b, count = 0;
    cin >> n >> m;

    while (m--) {
        cin >> k;
        while (k--) {
            cin >> a;
            if (count == 1) {
                gp[a].push_back(b), gp[b].push_back(a);
            }
            count = 1;
            b = a;
        }
        count = 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            bfs(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << arr[i] << " ";
    }
}


