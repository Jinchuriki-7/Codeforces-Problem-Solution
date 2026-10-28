#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<string>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<4;j++){
                if(a[i][j]=='#'){
                    cout<<j+1<<" ";
                }
            }
        }

        cout<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}