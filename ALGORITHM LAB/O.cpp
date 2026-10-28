#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;

    while(cin>>n){
        vector<int>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int m;
        cin>>m;

        sort(a.begin(),a.end());

        int f=0,l=n-1;
        int x=0,y=0;
        
        while(f<l){
            if(a[f]+a[l]==m){
                x=a[f];
                y=a[l];
                f++;
                l--;
            }
            else if(a[f]+a[l]<m){
                f++;
            }
            else{
                l--;
            }
        }
        cout<<"Peter should buy books whose prices are "<<x<<" and "<<y<<"."<<endl<<endl;
    }
}

int main(){
    sami();
    ami();
    return 0;
}