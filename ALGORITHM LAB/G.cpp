#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;

    vector<int> h(n),a(n);
    for(int i=0;i<n;i++){
        cin>>h[i]>>a[i];
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j&&h[i]==a[j]){
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
}

int main(){
    sami();
    ami();
    return 0;
}