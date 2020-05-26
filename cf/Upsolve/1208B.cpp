
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;
	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	set<ll> st;
	
	ll ans = 1e9;
	for(ll i=0;i<n;i++){


		set<ll> st;
		bool isPrefix = true;
		for(ll p1=0;p1<i;p1++){
			if(st.find(a[p1]) != st.end()){
				isPrefix = false;
				break;
			} else {
				st.insert(a[p1]);
			}
		}

		ll minSuffix = n;
		for(ll p2=n-1;p2>=i;p2--){

			if(st.find(a[p2]) != st.end()){
				break;
			} else {
				st.insert(a[p2]);
				minSuffix = p2;
			}
		}

		if(isPrefix){
			ans = min(ans, minSuffix - i);
		}

	}

	cout<<ans<<endl;
}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}