#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> gp[1000001];
int par[1000001];
int lvl[1000001];
vector<pair<ll, ll> > v(300001);
#define ff first
#define ss second

int find(int a) {
    if (par[a] == a) {
        return a;
    }
    return par[a] = find(par[a]);
}

void initialize(ll n) {
    for (ll i = 1; i <= n; i++) {
        v[i] = {i, i};
    }
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
        return;
    }
    if (lvl[a] > lvl[b]) {
        par[b] = a;
        lvl[a] += lvl[b];
        v[a].first = max(v[a].first, v[b].first);
        v[a].second = min(v[a].second, v[b].second);
    } else {
        par[a] = b;
        lvl[b] += lvl[a];
        v[b].first = max(v[a].first, v[b].first);
        v[b].second = min(v[a].second, v[b].second);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    string query;
    cin >> n >> m;
    initialize(n);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        lvl[i] = 1;
    }
    while (m--) {
        cin >> query;
        if (query == "union") {
            cin >> a >> b;
            merge(find(a), find(b));

        } else {
            cin >> a;
            ll k = find(a);
            cout << v[k].ss << " " << v[k].ff << " " << lvl[k] << "\n";
        }

    }

}



