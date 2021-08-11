//DSU find max in each set using path compression!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
int gp[100001];
int find(int a) {
    if (gp[a] < 0) return a;

    return gp[a] = find(gp[a]);
}

void Union(int a, int b) {
    gp[a] = min(gp[a], gp[b]);
    gp[b] = a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q, a, b, x, y;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        gp[i] = -i;

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if (a != b) Union(a, b);
    }

    cin >> q;
    while (q--) {
        cin >> a >> b;
        x = a, y = b;
        a = find(a), b = find(b);
        if (a == b)
            cout << "TIE\n";

        else {
            if (gp[a] < gp[b])
                cout << x << endl;
            else
                cout << y << endl;
        }
    }
}


