#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
   int n;
   cin>>n;
   string s;
   while(n--){
    cin>>s;
    string temp=s;
    sort(temp.begin(),temp.end());
    if(temp==s){
        reverse(temp.begin(),temp.end());
        
    }
    if(temp==s){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<temp<<endl;
        }
   }
}

int main(){
    sami();

    ami();
    return 0;
}



