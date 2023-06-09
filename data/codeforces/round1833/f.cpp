#include<bits/stdc++.h>
using namespace std;
#define N 505050
#define int long long
const int p=1e9+7;
map<int,int>cnt;
int n,m,phi[N],a[N];
int power(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int k=0;
		cnt.clear();
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];cnt[a[i]]++;
		}
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		phi[0]=1;
		for(int i=1;i<=n;i++)phi[i]=phi[i-1]*cnt[a[i]]%p;
		int ans=0;
		for(int i=m;i<=n;i++){
			if(a[i-m+1]==a[i]-m+1){
				ans=(ans+phi[i]*power(phi[i-m],p-2)%p)%p;
			}
		}
		cout<<ans%p<<"\n";
	} 
} 
