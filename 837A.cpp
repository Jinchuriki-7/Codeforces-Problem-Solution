#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
      int n,k;
    cin>>n>>k;

    int tm=240-k;
    int cnt=0;

    for(int i=1;i<=n;i++){
        tm-=5*i;

        if(tm>=0){
            cnt++;
        }
        else{
            break;
        }
    }

    cout<<cnt<<endl;

}

int main(){
    sami();

    ami();

    return 0;
}