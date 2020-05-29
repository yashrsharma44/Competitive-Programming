#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	

	ll n,m,x,y;
	cin>>n>>m>>x>>y;

	if((2*x) > y){

		ll ans = 0;
		for(ll i=0;i<n;i++){
			string s;
			cin>>s;
			ll cz=0;
			for(ll j=0;j<m;j++){
				if(s[j] == '.'){
					cz+=1;
				} else {
					ll z = cz / 2;
					ans += ((z) * y) + ((cz - (2*z)) * x); 
					cz=0;
				}
			}
			if(cz!=0){
				ll z = cz / 2;
				ans += ((z) * y) + ((cz - (2*z)) * x); 
					
			}
		}
		cout<<ans<<endl;

	} else {
		ll ans = 0;
		for(ll i=0;i<n;i++){
			string s;
			cin>>s;
			for(char c : s){
				if(c == '.'){
					ans+=x;
				}
			}
		}
		cout<<ans<<endl;
		return;
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
