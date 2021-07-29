//https://www.spoj.com/problems/PPATH/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<ll> gp[10000];
ll vis[10000];
ll dis[10000];
vector<int> primes;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(int(n)); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isValid(int a, int b) {
    int cnt = 0;
    while (a > 0) {
        if (a % 10 != b % 10) {
            cnt++;
        }
        a = a / 10, b = b / 10;
    }
    if (cnt == 1) {
        return true;
    }
    return false;
}

void BuildGraph() {
    for (int i = 1000; i <= 9999; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i + 1; j < primes.size(); ++j) {
            if (isValid(primes[i], primes[j])) {
                gp[primes[i]].push_back(primes[j]), gp[primes[j]].push_back(primes[i]);
            }
        }
    }
}

void bfs(int node) {
    dis[node] = 0;
    vis[node] = 1;
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        int peak = q.front();
        q.pop();
        for (int child:gp[peak]) {
            if (!vis[child]) {
                q.push(child);
                dis[child] = dis[peak] + 1;
                vis[child] = 1;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t, a, b;
    BuildGraph();

    cin >> t;
    while (t--) {
        cin >> a >> b;
        memset(dis, -1, sizeof dis);
        memset(vis, 0, sizeof vis);
        bfs(a);
        if (dis[b] == -1) {
            cout << "Impossible" << "\n";
        } else {
            cout << dis[b] << "\n";
        }


    }
}
