#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define print(v)     \
    for (auto x : v) \
    cout << x << " "
#define io                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Function blue prints with templates
template<typename T>
// This code with tamplate function will not be excuted since it is not a real function.
// The compiler will look at the formate of the template function,
// and generate a new function with same formate

// One problem that will cause a compilation error is if the template has different args.

// To solve this we can use explicit args and template type deduction.

T mx(T a, T b) {
    return (a > b) ? a : b;
}

template<typename A>
A maximum(A a, A b) {
    return (a > b) ? a : b;
}

int main() {
    cout << mx(1, 2) << "\n";
    cout << mx(1.2, 1.3) << "\n";
    cout << mx("Cpp", "App") << "\n";
    auto res = maximum<double>(1.2, 1); // Explicit template arguments
    cout << res << "\n";
}
