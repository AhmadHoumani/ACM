#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define vl vector<ll>
#define mp make_pair
#define pb push_back
#define fi  first
#define se second
const ll inf=1e18;
const ll MOD=1e9+7;
const ll ZERO=0;
const ll LOG=32;

struct project
{
	string name;
	int duration;
	int score;
	int best_before;
	map<string , ll> skill;
};

map<string, map< string , ll > > con;

vector<project> prj;

void input()
{
	ll c,p;
	cin>>c>>p;
	
	for(ll i=0;i<c;i++)
	{
		string name;
		ll skill_count;
		cin >> name >> skill_count;
		for(ll j=0;j<skill_count;j++)
		{
			string skill_name;
			ll skill_level;
			cin>>skill_name>>skill_level;
			con[name][skill_name]=skill_level;
		}
	}
	
	for(ll i=0;i<p;i++)
	{
		string project_name;
		ll duration, score, best_before, skill_count;
		cin>> project_name >> duration >> best_before >> skill_count;
		prj[i].name = project_name;
		prj[i].score=score;
		prj[i].best_before = best_before; 
		for(ll j=0;j<skill_count;j++)
		{
			string skill_name;
			ll skill_required;
			prj[i].skill[skill_name] = skill_required;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//	ifstream cin("")
//	ofstream cout("");
	
}
