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
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]>a[j]){
                    swap(a[i],a[j]);
                    swap(b[i],b[j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]<=k){
                k+=b[i];
        }
    }
    cout<<k<<endl;
   } 

}

int main(){
    sami();

    ami();

    return 0;
}