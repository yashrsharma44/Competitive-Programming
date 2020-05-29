#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll q,x;
	cin>>q>>x;
	set < pair<ll,ll> > st;
	vector<ll> count(x,0);
	for(ll i=0;i<x;i++){
		st.insert(make_pair(0, i));
	}

	for(ll i=0;i<q;i++){
		ll y;
		cin>>y;
		y = y % x;
		st.erase(make_pair(count[y], y));
		count[y]+=1;
		st.insert(make_pair(count[y], y));
		ll ans = (st.begin()->first * x) + st.begin()->second;
		cout<<ans<<endl;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
