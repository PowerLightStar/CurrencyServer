#include<bits/stdc++.h>
using namespace std;
 
void SV()
{
	int n;
	cin>>n;
	vector<vector<int> >E;
	E.resize(n+1);
	map<pair<int,int>,int>mp;
	for(int i=1;i<n;++i)
	{
		int u,v;
		cin>>u>>v;
		mp[{u,v}]=mp[{v,u}]=i;
		E[u].push_back(v) , E[v].push_back(u);
	}
	
	vector<int>ans;
	
	vector<int>sz(n+1,0);
	function<bool(int,int)> dfs=[&](int u,int fa)
	{
		sz[u]=1;
		for(int v:E[u])
			if(v!=fa)
			{
				dfs(v,u);
				if(sz[v]==3)
				{
					sz[v]-=3;
					ans.push_back(mp[{u,v}]);
				}
				sz[u]+=sz[v];
			}
		return sz[u]<=3;
	};
	
	if(dfs(1,-1) && sz[1]==3)
	{
		cout<<ans.size()<<"\n";
		for(int id:ans)cout<<id<<' ';
		cout<<"\n";
	}
	else cout<<"-1\n";
}
int main()
{
	ios::sync_with_stdio(0);
	int TTT;cin>>TTT;while(TTT--)SV();
	return 0;
}
