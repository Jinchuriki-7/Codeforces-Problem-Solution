#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;
    int l1,b1,l2,b2,l3,b3;
    while(n--){
        cin>>l1>>b1>>l2>>b2>>l3>>b3;

        int a=l2+b2;
        int c=l3+b3;

        if((a-c)<2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

}

int main(){
    sami();

    ami();

    return 0;
}