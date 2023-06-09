#include <iostream>
using namespace std;
const int MN = 1<<20;
int as[MN];
bool used[MN];
int main() {
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0;i<n;++i)cin>>as[i],--as[i],used[i]=0;
		int co=0,cc=0;
		for(int i=0;i<n;++i)if(!used[i]){
			int x=i;
			int p=x;
			int pp=x;
			while(!used[x]) {
				used[x]=1;
				int y = as[x];
				pp=p;
				p=x;
				x=y;
			}
			if (x==pp) {
				++co;
			} else if (x==i) {
				++cc;
			} else {
			}
		}
		cout<<cc+!!co<<' '<<cc+co<<'\n';
	}
}