#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;

    int ans=0;
    int cnt=0;
    int tot=0;
 while(n--){
     int b,d;
     cin>>b>>d;

      cnt+=b;

      ans+=d;

      tot=cnt-ans;
        
    }

    int a;
    cin>>a;
    
    int final=a-tot;

    vector<int>v={1,2,4,8,16,32,64};

    

}

int main(){
    sami();

    ami();

    return 0;
}