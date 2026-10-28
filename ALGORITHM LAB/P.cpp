#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int Y,P;

    while(cin>>Y){
        cin>>P;

        vector<int> a(P);

        for(int i=0;i<P;i++){
            cin>>a[i];
        }

        int l=0;
        int ans=0;
        int first=0,last=0;

        for(int r=0;r<P;r++){
            while(a[r]-a[l]>=Y){
                l++;
            }

            if(r-l+1>ans){
                ans=r-l+1;
                first=a[l];
                last=a[r];
            }
        }

        cout<<ans<<" "<<first<<" "<<last<<endl;
    }
}

int main(){
    sami();
    ami();
    return 0;
}