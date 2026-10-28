#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        string x,y;
        cin>>x>>y;

        int a[4]={0},b[4]={0};
        int j=0;

        for(char c:x){
            if(c=='.'){
                j++;
            }else{
                a[j]=a[j]*10+(c-'0');
            }
        }
        j=0;
        for(char c:y){
            if(c=='.'){
                j++;
            }
            else{
                b[j]=b[j]*2+(c-'0');
            }
        }

        if(a[0]==b[0] && a[1]==b[1] && a[2]==b[2] && a[3]==b[3]){
            cout<<"Case "<<i<<": Yes"<<endl;
        }else{
            cout<<"Case "<<i<<": No"<<endl;
        }
    }
}

int main(){
    sami();
    ami();
    return 0;
}