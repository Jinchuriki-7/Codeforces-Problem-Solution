#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;

    string s;
    while(x--){
        cin>>s;

        int cnt=0;
       for(int i=0;i<s.size()-1;i++){
           
        if(s[i]==s[i+1]){
            cnt++;
        }
       }
       if(cnt>0){
        cout<<1<<endl;
       }
       else{
        cout<<s.size()<<endl;
       }
    }
}

int main(){
    sami();

    ami();

    return 0;
}