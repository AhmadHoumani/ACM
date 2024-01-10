//https://www.spoj.com/problems/FACTCG2/
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e7 + 7;

vector<int> LPF(MAX_N, 0);

void computeLPF() {
    for (int i = 2; i < MAX_N; ++i) {
        if (LPF[i] == 0) {
            for (int j = i; j < MAX_N; j += i) {
                if (LPF[j] == 0) {
                    LPF[j] = i;
                }
            }
        }
    }
}

void primeFactorization(int x) {
    cout << "1";
    while (x > 1) {
        cout << " x " << LPF[x];
        x /= LPF[x];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    computeLPF();

    int x;
    while (cin >> x) {
        primeFactorization(x);
    }

    return 0;
}
