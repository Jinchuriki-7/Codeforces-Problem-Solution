#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void ami(){
    int n,d,r;

    while(cin>>n>>d>>r){
        if(n==0&&d==0&&r==0){
            break;
        }

        vector<int>a(n),b(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int ans=0;

        for(int i=0;i<n;i++){
            int total=a[i]+b[n-i-1];

            if(total>d){
                ans+=(total-d)*r;
            }
        }

        cout<<ans<<endl;
    }
}

int main(){
    sami();
    ami();
    return 0;
}