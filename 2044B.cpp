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

        reverse(s.begin(),s.end());

        for(int i=0;i<s.size();i++){
            if(s[i]=='p'){
            s[i]='q';
        }
        else if(s[i]=='q'){
            s[i]='p';
        }

        }
      
    }
    cout<<s<<endl;
}

int main(){
    sami();

    ami();

    return 0;
}