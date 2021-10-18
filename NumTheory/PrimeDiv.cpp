//https://codeforces.com/contest/1025/problem/B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> prime;
void addPrime(ll n)
{
	for(ll i=2;i*i<=n;i++)
	if(n % i == 0)
	{
		prime.push_back(i);
//		cout<<i<<" ";
		while(n % i == 0)
		n /= i;
	}
	
	if(n > 1)
	prime.push_back(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
    	cin>>a[i]>>b[i];
	}
	addPrime(a[0]);
	addPrime(b[0]);
	for(auto p:prime){
		bool hap=true;
		for(int i=1;i<n;i++){
			if((a[i]%p!=0) && (b[i]%p!=0)){
				hap=false;
				break;
			}
		}
		if(hap==true){
			cout<<p;
			return 0;
	}
		
	}
	cout<<-1;
}
 
