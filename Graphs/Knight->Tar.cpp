//https://www.codechef.com/problems/PRGCUP01
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
ll vis[10][10];
ll dis[10][10];
int fta, ftb;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int cor1, int cor2) {
    if (cor1 < 1 || cor1 > 8 || cor2 < 1 || cor2 > 8) {
        return false;
    }
    if (vis[cor1][cor2]) {
        return false;
    }
    return true;
}

int BFS(int x, int y) {
    vis[x][y] = 1;
    dis[x][y] = 0;
    queue<pair<int, int>> qp;
    qp.push({x, y});
    if (x == fta && y == ftb) {
        return dis[x][y];
    }
    while (!qp.empty()) {
        int cx = qp.front().first;
        int cy = qp.front().second;
        qp.pop();
        for (int i = 0; i < 8; ++i) {
            if (isValid(cx + dx[i], cy + dy[i])) {
                x = cx + dx[i];
                y = cy + dy[i];
                dis[x][y] = dis[cx][cy] + 1;
                vis[x][y] = 1;
                qp.push({x, y});
                if (x == fta && y == ftb) {
                    return dis[x][y];
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        char ia, ib, ta, tb;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++)
                vis[i][j] = 0;
        }
        cin >> ia >> ib;//index
        cin >> ta >> tb;//target
        int fia = ia - 'a' + 1;
        fta = ta - 'a' + 1;
        int fib = ib - '0';
        ftb = tb - '0';
        cout << BFS(fia, fib) << "\n";

    }

}
