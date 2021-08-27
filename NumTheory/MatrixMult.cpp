//https://www.spoj.com/problems/MPOW/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
#define N 52
ll a[N][N];
ll I[N][N];

void mul(ll B[][N], ll A[][N], int dim) {

    ll res[dim + 1][dim + 1];
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            res[i][j] = 0;
            for (int k = 0; k < dim; k++) {
                ll temp = ((A[i][k] * B[k][j]) % MOD);
                res[i][j] = (res[i][j] + temp) % MOD;
            }
        }
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            B[i][j] = res[i][j];
        }
    }
}

void power(ll A[][N], int di, int n) {

    for (int i = 0; i < di; i++) {
        for (int j = 0; j < di; j++) {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }
    while (n) {
        if (n % 2)
            mul(I, A, di), n--;
        else
            mul(A, A, di), n /= 2;


    }
    for (int i = 0; i < di; i++) {
        for (int j = 0; j < di; j++) {
            A[i][j] = I[i][j];
        }
    }
}


signed main() {


    int t;
    cin >> t;
    while (t--) {
        int di;
        cin >> di;
        int n;
        cin >> n;


        for (int i = 0; i < di; i++) {
            for (int j = 0; j < di; j++) {
                cin >> a[i][j];
            }
        }
        power(a, di, n);
        for (int i = 0; i < di; i++) {
            for (int j = 0; j < di; j++) {
                cout << a[i][j] % MOD << " ";
            }
            cout << "\n";
        }
    }
}








