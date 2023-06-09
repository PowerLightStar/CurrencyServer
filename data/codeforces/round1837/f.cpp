#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cassert>
using namespace std;
int N,K;
int A[3<<17];
vector<int>f(long long MX)
{
	vector<int>ret(N+1,0);
	priority_queue<int>Q;
	for(int i=0;i<N;i++)
	{
		Q.push(A[i]);
		MX-=A[i];
		while(MX<0)
		{
			assert(!Q.empty());
			MX+=Q.top();
			Q.pop();
		}
		ret[i+1]=Q.size();
	}
	return ret;
}
bool ok(long long MX)
{
	vector<int>L=f(MX);
	reverse(A,A+N);
	vector<int>R=f(MX);
	reverse(A,A+N);
	reverse(R.begin(),R.end());
	for(int i=0;i<=N;i++)if(L[i]+R[i]>=K)return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)cin>>A[i];
		long long L=0,R=(long long)1e15;
		while(R-L>1)
		{
			long long mid=(L+R)/2;
			if(ok(mid))R=mid;
			else L=mid;
		}
		cout<<R<<"\n";
	}
}