#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;

	bool isPos = false;

	ll strt = a-b;
	ll end=a+b;
	
	for(ll i=strt;i<=end;i++){
		if((i * n <= (c + d)) && (i * n >= (c - d))){
			cout<<"Yes"<<endl;
			return;
		}
	}


	cout<<"No"<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;

	

	while(t--){
		solve();
	}
}