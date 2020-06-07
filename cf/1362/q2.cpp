#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll>s;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		s.push_back(vl);
	}

	ll ans = 1;
	set<ll> elem;
	for(ll el : s){
		elem.insert(el);
	}
	for(ll i=1;i<=1024;i++){

		set<ll> elem2;
		for(ll el : s){
			elem2.insert((el^i));
		}

		bool isPos = elem.size() == elem2.size();
		for(ll el : elem){
			if(elem2.find(el) == elem2.end()){
				isPos = false;
				break;
			}
		}
		if(isPos){
			cout<<i<<endl;
			return;
		}

	}

	cout<<-1<<endl;

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
