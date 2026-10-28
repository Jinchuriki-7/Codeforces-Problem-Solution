#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
	  int n;

    while(cin>>n){
        if(n==0){
            break;
        }

        int cnt[100]={0};

        for(int i=0;i<n;i++){
            int age;
            cin>>age;
            cnt[age]++;
        }

        for(int i=1;i<100;i++){
            for(int j=0;j<cnt[i];j++){
                cout<<i<<" ";
            }
        }

        cout<<endl;
    }
}

int main(){
	sami();

	ami();

	return 0;
}