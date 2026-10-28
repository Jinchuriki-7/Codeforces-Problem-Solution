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

        vector<int>a(n),b(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        if(a[n-1]>b[n-1]){
            swap(a[n-1],b[n-1]);
        }

        int flag=1;

        for(int i=0;i<n-1;i++){
            if(a[i]>b[i]){
                swap(a[i],b[i]);
            }

            if(a[i]>a[n-1]||b[i]>b[n-1]){
                flag=0;
                break;
            }
        }

        if(flag){
            cout<<"Yes"<<endl;
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