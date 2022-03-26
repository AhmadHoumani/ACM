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

int fun(int a, int b)
{
	cout << "\nFunction int was called\n";
	return a + b;
}
double fun(double a, double b)
{
	cout << "\nFunction double was called\n";

	return a + b;
}

int main()
{
	io;
	cout << fun(1, 1);
	cout << fun(1.1, 1.1);
}
