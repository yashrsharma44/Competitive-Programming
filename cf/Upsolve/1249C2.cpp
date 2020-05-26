#include <bits/stdc++.h>
#define ll long long int

using namespace std;


void solve(){

	ll n;
	cin>>n;

	vector<ll> dig;
	ll nn = n;
	
	ll pos2 = -1;
	while(nn>0){
		dig.push_back(nn%3);
		if(nn%3 == 2){
			pos2 = dig.size()-1;
		}
		nn/=3;
	}

	dig.push_back(0);
	ll pos0 = dig.size()-1;

	if(pos2!=-1){
		for(ll i=pos2+1;i<dig.size();i++){
			if(dig[i] == 0){
				pos0 = i;
				break;
			}
		}

		dig[pos0] = 1;
		for(ll i=0;i<pos0;i++){
			dig[i] = 0;
		}
	}
	ll ans = 0;
	ll pw = 1;
	for(ll i=0;i<dig.size();i++){
		ans = ans + (dig[i]*pw);
		pw*=3;
	}
	cout<<ans<<endl;


}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	// t=1;

	while(t--){
		solve();
	}

}