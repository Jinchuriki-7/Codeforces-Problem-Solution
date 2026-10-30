#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){

    int t;
    cin>>t;

    while(t--){
    
        int n,k;
        cin>>n>>k;

        vector<int>a(n),b(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
        }

        sort(b.begin(),b.end());

        if(k==1&&a!=b){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
} 

int main(){
    sami();

    ami();

    return 0;
}