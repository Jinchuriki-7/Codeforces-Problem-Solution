#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;
    int a,b,c;
    while(x--){
        cin>>a>>b>>c;

        int m=0;
        int i;
        int n[200005];
        for(i=0;i<a;i++){
         cin>>n[i];
         m=max(m,n[i]);

        }
           if(c>1){
                cout<<"Yes"<<endl;
                
            }
            else{
                if(n[b-1]==m){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
    }

}

int main(){
    sami();

    ami();

    return 0;
}