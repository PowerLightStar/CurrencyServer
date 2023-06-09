#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll in(){
	ll x;
	scanf("%lld",&x);
	return x;
}
const int N=305;
int n,sum,a[N],mark[N];
int f[N*N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)a[i]=in(),sum+=a[i];
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=a[i];j--)
			if(!f[j]&&f[j-a[i]])f[j]=i;
	}
	if((sum&1)||!f[sum>>1]){
		cout<<"First"<<endl;
		while(1){
			int x,y;
			for(int i=1;i<=n;i++)
				if(a[i]){x=i;break;}
			cout<<x<<endl;
			cin>>y;
			if(y<=0)return 0;
			int v=min(a[x],a[y]);
			a[x]-=v,a[y]-=v;
		}
	}else{
		for(int i=sum>>1;i;)
			mark[f[i]]=1,i-=a[f[i]];
		cout<<"Second"<<endl;
		while(1){
			int x,y;
			cin>>x;
			if(x<=0)return 0;
			for(int i=1;i<=n;i++)
				if(a[i]&&mark[i]!=mark[x]){y=i;break;}
			int v=min(a[x],a[y]);
			a[x]-=v,a[y]-=v;
			cout<<y<<endl;
		}
	}
	return 0;
}