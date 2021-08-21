//https://codeforces.com/contest/540/problem/C
#include <bits/stdc++.h>
using namespace std;
char b[505][505];
int X1,X2,Y1,Y2,n,m;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool dfs(int y,int x){
	if(b[y][x]!='.'){
		if(y==Y2 && x==X2)return 1;
		return 0;
	}
	b[y][x]='X';
	for(int i=0;i<4;++i)
		if(dfs(y+dy[i],x+dx[i]))return 1;
	return 0;
}
int main(){
	int i,j;cin>>n>>m;
	for(i=1;i<=n;++i)
		scanf("%s",b[i]+1);
	cin>>Y1>>X1>>Y2>>X2;
	b[Y1][X1]='.';
	if(dfs(Y1,X1))
		cout<<"YES\n";
	else
		cout<<"NO\n";
}
