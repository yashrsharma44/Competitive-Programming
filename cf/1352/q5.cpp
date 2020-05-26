#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n0,n1,n2;
	cin>>n0>>n1>>n2;

	if(n0 == 0 && n2 == 0){
		string ans="0";
		int ct=  1;
		for(int i=0;i<n1;i++){
			ans += to_string(ct);
			ct = 1 - ct;
		}
		cout<<ans<<endl;
		return;
	}

	string ans="";

	if(n0 == 0 && n1 > 0){
		ans+="0";
	}

	if(n0 > 0){
		for(int i=0;i<=n0;i++){
			ans+="0";
		}
	}

	if(n2>0){
		for(int i=0;i<=n2;i++){
			ans+="1";
		}
	}

	if(n2 == 0 && n1 > 0){
		ans+="1";
	}

	if(n1 > 1){
		int ct=0;
		for(int i=1;i<n1;i++){
			ans+=to_string(ct);
			ct = 1 - ct;
		}
	}
	cout<<ans<<endl;
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