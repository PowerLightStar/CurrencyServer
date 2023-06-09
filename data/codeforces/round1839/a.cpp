// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a=ceil((n*1.0)/k);
        if((n-1)%k!=0){
            a+=1;
        }
        cout<<a<<endl;
    }
 
    return 0;
}