#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int a;
    cin>>a;
    int t;
    cin>>t;

    int total=0;
    int s;
    for(int i=1;i<=a;i++){
        cin>>s;

    total+=86400-s;
    
    if(total>=t){
        cout<<i<<endl;
        return;
    }
}
}
int main(){
    sami();

    ami();

    return 0;
}