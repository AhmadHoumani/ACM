//https://cses.fi/problemset/task/1192
#include <bits/stdc++.h>
 
using namespace std;
char roomConfig[1001][1001];
int vis[1001][1001];
int n, m;
 
bool isValid(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m)return false;
    if (vis[x][y] == true || roomConfig[x][y] == '#')return false;
    return true;
}
 
void dfs(int x, int y) {
    vis[x][y] = 1;
    if (isValid(x - 1, y)) {
        dfs(x - 1, y);
    }
    if (isValid(x, y + 1)) {
        dfs(x, y + 1);
    }
    if (isValid(x + 1, y)) {
        dfs(x + 1, y);
    }
    if (isValid(x, y - 1)) {
        dfs(x, y - 1);
    }
}
 
int main() {
    int rooms = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> roomConfig[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (roomConfig[i][j] == '.' && !vis[i][j]) {
                dfs(i, j), rooms++;
            }
        }
    }
    cout << rooms;
 
 
}
