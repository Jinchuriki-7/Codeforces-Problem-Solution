#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;

    while(cin>>n){
        int a[1005];
        int cnt=0;

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    cnt++;
                }
            }
        }

        cout<<"Minimum exchange operations : "<<cnt<<endl;
    }

}


int main(){
    sami();

    ami();

    return 0;
}