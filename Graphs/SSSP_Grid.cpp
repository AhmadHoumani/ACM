//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/jungle-run/
#include <bits/stdc++.h>
using namespace std;
char forest[31][31];
int vis[31][31];
int dis[31][31];
queue<pair<int, int>> qp;
int n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n)return false;
    if (vis[x][y] == true || forest[x][y] == 'T')return false;
    return true;
}

void bfs(int x, int y) {
    vis[x][y] = 1;
    dis[x][y] = 0;
    qp.push({x, y});
    while (!qp.empty()) {
        int x = qp.front().first;
        int y = qp.front().second;
        int d = dis[x][y];

        qp.pop();
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY)) {
                dis[newX][newY] = d + 1;
                vis[newX][newY] = 1;
                qp.push({newX, newY});
            }
        }


    }
}


int main() {
    int startX = 0, startY = 0, endX = 0, endY = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> forest[i][j];
            if (forest[i][j] == 'S') {
                startX = i, startY = j;
            }
            if (forest[i][j] == 'E') {
                endX = i, endY = j;
            }
        }

    }

    bfs(startX, startY);
    cout << dis[endX][endY];


}

