#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,m;
	cin>>n>>m;

	vector<ll> a, b;
	ll nn = n;
	ll mm = m;
	while(nn--){
		ll vl;
		cin>>vl;

		a.push_back(vl);
	}

	while(mm--){
		ll vl;
		cin>>vl;

		b.push_back(vl);
	}

	vector<ll> pos(n+1,0);
	for(ll i=0;i<n;i++){
		pos[a[i]] = i;
	}

	ll lst = -1;
	// ll maxPos = -1;
	ll totTime = 0;

	for(ll i=0;i<b.size();i++){

		if(pos[b[i]] > lst){
			totTime += (1 + 2*(pos[b[i]] - (i)));
		} else if(pos[b[i]] < lst){
			totTime += 1;
		}

		lst = max(pos[b[i]], lst);
	}

	cout<<totTime<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}