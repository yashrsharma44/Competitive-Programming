#include <bits/stdc++.h>
#define ll long long int  

using namespace std;

#define max 4000000000

void bkt(ll x, set<ll> &visited){

	if(visited.find(x) != visited.end() || x > max){
		return;
	}
	if(x!=0)
	visited.insert(x);
	
	if(x == 0){
		for(ll i=1;i<=9;i++){
			bkt(i, visited);
		}
	} else {

		ll lastDigit = x%10;
		if(lastDigit > 0){
			bkt(10*x + lastDigit-1, visited);
		}
		bkt(10*x + lastDigit,visited);
		if(lastDigit < 9){
			bkt(10*x + lastDigit+1,visited);
		}
	}

}

void solve(){

	ll k;
	cin>>k;

	set<ll> visited;
	bkt(0, visited);

	ll ans = -1;
	ll i=1;
	// visited.erase(visited.begin());
	for(ll el : visited){
		if(i == k){
			ans = el;
			break;
		}
		i++;
	}
	cout<<ans<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}

}