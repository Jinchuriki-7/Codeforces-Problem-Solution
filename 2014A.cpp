#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
     int t;
    cin >> t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int gold=0;
        int ans=0;

        for(int i=0;i<n;i++){

            if(a[i]>=k){
                gold+=a[i];
            }
            else if(a[i]==0&&gold>0){
                gold--;
                ans++;
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