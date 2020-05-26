#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool comp(pair<ll,ll> p1, pair<ll,ll> p2){

	return p1.second < p2.second;
}

void solve(){

	ll n,a,b,k;
	cin>>n>>a>>b>>k;

	vector<ll> h;

	ll nn = n;
	while(nn--){

		ll vl;
		cin>>vl;

		h.push_back(vl);

	}

	ll minWin = 0;
	ll pow = a + b;

	vector< pair<ll,ll> > opp;

	for(ll i=0;i<n;i++){

		ll rem = h[i] % pow;

		if(rem == 0){
			opp.push_back(make_pair(h[i], b));
		} else {
			if(rem <= a){
				minWin +=1;
			} else {
				opp.push_back(make_pair(h[i], rem - a));
			}
		}

	}

	sort(opp.begin(), opp.end(), comp);

	for(ll i=0;i<opp.size();i++){

		
		
		ll diff = opp[i].second;
		ll times = ((diff % a == 0) ? (diff / a) : (diff / a + 1));

		if(times <= k){
			k -= times;
			minWin += 1;
		} else {
			break;
		}

		

	}

	cout<<minWin<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}