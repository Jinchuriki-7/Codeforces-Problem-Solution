#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;

    double ans=0;
    double credit=0;
    while(n--){
        double a,b;
        cin>>a>>b;


        ans+=a*b;
        credit+=b;
       
    }
  cout<<fixed<<setprecision(2)<<ans/credit<<endl;
}

int main(){
    sami();

    ami();

    return 0;
}