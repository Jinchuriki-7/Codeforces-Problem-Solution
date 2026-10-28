#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin >> n;
    int x;
    cin >> x;

    int mx=x;
    int mn=x;
    int amazing=0;
    for(int i=1;i<n;i++){
        cin >> x;

        if(x>mx){
            amazing++;
            mx=x;
        }
        else if(x<mn){
            amazing++;
            mn=x;
        }
    }

    cout << amazing << endl;

}

int main(){
    sami();

    ami();

    return 0;
}