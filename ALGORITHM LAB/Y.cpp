#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n,k;
    cin>>n>>k;

    while(k--){
        if(n%10==0){
            n=n/10;
        }
        else{
            n--;
        }
    }
    cout<<n<<endl;
}

int main(){
    sami();

    ami();

    return 0;
}