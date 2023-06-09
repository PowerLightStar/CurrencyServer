#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstring>
#include<set>
#include<iomanip>
#include<cmath>
#include<stack>
using namespace std;
#define se second
#define fi first
#define INIT ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
inline ll Norm(ll x){return (x % MOD + MOD) % MOD;}
inline ll Add(ll u, ll v){return Norm(Norm(u) + Norm(v));} //加
inline ll Sub(ll u, ll v){return Norm(Norm(u) - Norm(v));} //减
inline ll Mul(ll u, ll v){return Norm(Norm(u) * Norm(v));} //乘
ll Ksm(ll x, ll e) //快速幂
{
	ll res = 1;
	x = Norm(x);
	while (e)
	{
		if (e & 1)
			res = Mul(res, x);
		x = Mul(x, x);
		e >>= 1;
	}
	return res;
}
ll Ksc(ll a,ll b) //快速乘
{
	ll ans = 0;
	while(b)
	{
		if(b & 1)
		{
			--b;
			ans = Add(ans,a)%MOD;
		}
		a = Add(a,a) % MOD;
		b >>= 1;
	}
	return ans;
}
inline ll Inv(ll x){return Ksm(x, MOD - 2);}//逆元
inline ll Div(ll u, ll v){return Mul(u, Inv(v));}
void Ex_gcd(ll a,ll b,ll &x,ll &y) //拓展欧几里得
{
	if(!b)
	{
		x=1;
		y=0;
		return;
	}
	Ex_gcd(b,a%b,x,y);
	ll k=x;
	x=y;
	y=k-a/b*y;
}
ll gcd(ll a,ll b){return b>0 ? gcd(b,a%b):a;}//gcd
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}//lcm
double jiao(double a2,double a1,double b2,double b1)//向量计算两边夹角
{
	double ab,a11,b11,cosr;
    ab=a1*b1+a2*b2;
    a11=sqrt(a1*a1+a2*a2);
    b11=sqrt(b1*b1+b2*b2);
    cosr=ab/a11/b11;
    return cosr;
}
ll CRT(ll a[],ll b[],ll n)//中国剩余定理
{
	ll ans=0,x,y,M=1,N;
	for(int i=1;i<=n;i++) M*=a[i];
	for(int i=1;i<=n;i++)
	{
		N=M/a[i]; //其余元素的lcm
		Ex_gcd(N,a[i],x,y); //拓展欧几里得
		ans=(ans + N * x * b[i]) % MOD;
	}
	return ans;
}
 // 在[1, top]的范围内，和n互质的数的个数----容斥
ll calc(ll n, ll top)
{
     vector<pair<ll,ll> > divisors;
     for(ll i = 2; i * i <= n ; i ++ ) {
         if(n % i == 0) {
             int s = 0;
             while(n % i == 0) n /= i, s ++ ;
             divisors.push_back({i, s});
         }
     }
     if(n > 1) divisors.push_back({n, 1});
 
     ll res = 0, m = divisors.size();
     for (ll i = 1; i < 1 << m; i ++ )
     {
         ll t = 1, s = 0;
         for (ll j = 0; j < m; j ++ )
             if (i >> j & 1)
             {
                 if (t * divisors[j].first > top) {
                     t = -1;
                     break;
                 }
                 t *= divisors[j].first;
                 s ++ ;
             }
         if (t != -1) {
             if (s % 2) res += top / t;
             else res -= top / t;
         }
     }
     return top - res;
}
void Ks_zhishu() // 1 到 1e9
{
	const int C = 32000;
	bool p[C];
    ll d[C],k = 0;
	for (int i = 2; i < C; i++)
		p[i] = 1;
	for (int i = 2; i < C; i++)
	if (p[i])
	{
		d[++k] = i;
		for (int j = 2 * i; j < C; j += i)
			p[j] = 0;
	}
}
/*void pre_MOD() //组合数预处理
{
    ll f[nn],invf[nn],p[nn];
    p[0] = 1;
    for(int i=1;i<=1e7;++i) p[i] = p[i-1] * 2 % MOD;
    f[0]=f[1]=invf[0]=invf[1]=1;
    for(int i=2;i<=nn-1;++i)
    {
       f[i]=f[i-1]*i%MOD;
        invf[i]=(MOD-MOD/i)*invf[MOD%i]%MOD;
    }
    for(int i=2;i<=nn-1;++i) invf[i]=invf[i-1]*invf[i]%MOD;
}
ll C(ll n,ll m) //大前，小后，组合数
{
    if(n<m) return 0;
    return f[n]*invf[m]%MOD*invf[n-m]%MOD;
}*/
/*struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll get(ll x)//hash
{
	x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    return x;
}*/
 
int read() {
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}
void write(ll x) {
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
 
ll T,n;
struct node
{
	ll a,b;
}x[200005];
bool cmp(node x,node y)
{
	if(x.a == y.a) return x.b > y.b;
	return x.a < y.a;
}
int main()
{
	INIT;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;++i) cin>>x[i].a>>x[i].b;
		sort(x+1,x+1+n,cmp);
		
		ll ans = 0;
		ll tmp = 0,re = 0;
		for(int i=1;i<=n;++i)
		{
			if(tmp != x[i].a)
			{
				tmp = x[i].a;
				re = x[i].a;
			}
			if(re)
			{
				--re;
				ans += x[i].b;
			}
		}
		cout<<ans<<'\n';
		
	}
	return 0;
}
/*
//去除前导0
reverse(a.begin(),a.end());
while(a.size()>1 && a.back() == '0') a.pop_back();
reverse(a.begin(),a.end());
 
cout<<fixed<<setprecision(5)<<a;
*/