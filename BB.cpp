#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
   ll n;
   cin>>n;

   vector<ll>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   vector<ll>c(n);
   for(int i=0;i<n;i++){
    cin>>c[i];
   }
   sort(v.begin(),v.end());
   sort(c.begin(),c.end());

   ll cnt=0;
   for(int i=0;i<n;i++){
    if(v[i]==c[i]){
        cnt++;
    }
   }
   cout<<cnt<<endl;

}

int main(){
    sami();

    ami();

    return 0;
}