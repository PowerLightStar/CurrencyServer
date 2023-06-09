//People who believe in miracles are as amazing as miracles themselves.
#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*f;
}
 
const int N=2e5+10;
int n,a[N],ans[N],now;
 
signed main(){
    for(int T=read();T;--T){
        n=read(),now=0;
        for(int i=1;i<=n;++i) a[i]=read();
        if(a[n]){puts("NO");continue;}
        for(int i=n;i>=1;--i){
            if(i==1){ans[i]=0;break;}
            if(a[i-1]^now) ans[i]=i-1,now^=1;
            else ans[i]=i-2,now^=1,a[i-1]=now;
        }
        puts("YES");
        for(int i=1;i<=n;++i) printf("%d ",ans[i]); puts("");
    }
    return 0;
}