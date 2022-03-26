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

// //    Lambda function signature :
// [capture list](parameters) -> return type
// {
// 	// Function body
// }

int main()
{
	io;
	// Lambda function with name;
	auto func = []()
	{
		cout << "Hello with naming\n";
	};
	func();
	// Lambda function without a name by adding () before(;);
	[]()
	{
		cout << "Hello without naming\n";
	}();

	// Lambda Function with parameters;
	[](int a, int b)
	{
		cout << "Lambda Function with parameters and direct calling\n";
		cout << "Sum of " << a << " and " << b << " = " << a + b << "\n";
	}(1, 2);

	// Lambda Function with return;
	auto res = [](int a, int b) -> int // No need to add int unless I want to force the return to be as int or double
	{
		return a + b;
	}(1, 2);
	cout << "Result of return in Lambda = " << sizeof(res) << "\n";
}
