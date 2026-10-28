#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
        int n,m;
        cin>>n>>m;

        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());

    int sum=0;

    for(int i=0;i<n;i++){
        sum+=a[i];

        if(sum>=m){
            cout<<i+1<<endl;
            break;
        }
    }
}
int main(){
    sami();

    ami();

    return 0;
}