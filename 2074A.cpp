#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;
    int a,b,c,d;
    while(n--){

        cin>>a>>b>>c>>d;

        if(a==b && b==c&& c==d&& d==a){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }

    }
}

int main(){
    sami();

    ami();

    return 0;
}