#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

ll mod_pow(ll num, ll idx){

	ll ans = 1;

	
	while(idx>0){

		if(idx%2==1){
			ans=(ans*num)%MOD;
		}

		num = (num*num)%MOD;
		idx/=2;
	}

	return ans%MOD;

}

void solve(){

	ll n,m;
	cin>>n>>m;

	cout<<mod_pow(mod_pow(2,m)-1, n)<<endl;
	
}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}

}