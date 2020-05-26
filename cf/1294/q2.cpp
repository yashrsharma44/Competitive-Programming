#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool comp(pair<ll,ll> &p1, pair<ll,ll> &p2){

	if(p1.first != p2.first){
		return p1.first < p2.first;
	}

	return p1.second < p2.second;
}

void solve(){

	ll n;
	cin>>n;

	vector< pair <ll, ll> > coord;
	ll nn = n;
	while(nn--){
		ll u,v;
		cin>>u>>v;
		coord.push_back(make_pair(u, v));
	}

	sort(coord.begin(), coord.end(), comp);

	// for(pair<ll,ll> el : coord){
	// 	cout<<el.first<<" "<<el.second<<endl;
	// }

	bool isPossible = true;

	string ans = "";
	pair<ll,ll> prevPoint = coord[0];
	for(ll i=1;i<n;i++){

		if(coord[i].first != prevPoint.first){
			ll slope = (coord[i].first - prevPoint.first);
			ll slope2 = (coord[i].second - prevPoint.second);
			if(slope < 0 || slope2 < 0){
				isPossible = false;
				break;
			}

			ans += "R";
		} else {
			ll slope = (coord[i].second - prevPoint.second);
			ll slope2 = (coord[i].first - prevPoint.first);
			if(slope < 0 || slope2 < 0){
				isPossible = false;
				break;
			}

			ans += "U";			
		}
		prevPoint = coord[i];
	}

	if(isPossible){
		cout<<"YES"<<endl;
		string anss = "";
		for(ll i=0;i<coord[0].first;i++){
			anss += "R";
		}

		for(ll i=0;i<coord[0].second;i++){
			anss += "U";
		}		

		pair<ll,ll> prev = coord[0];
		
		for(ll i=1;i<n;i++){

			pair<ll,ll> el = coord[i];
			// cout<<el.first<<" "<<el.second<<" - "<<prev.first<<" "<<prev.second<<endl;
			
			for(ll i=0;i<abs(el.first - prev.first);i++){
				anss += "R";
				// cout<<"R";
			}

			for(ll i=0;i<abs(el.second - prev.second);i++){
				anss += "U";
				// cout<<"U";
			}

			// cout<<endl;

			prev = el;
			// cout<<el.first<<" "<<el.second<<endl;
		}


		cout<<anss<<endl;

	} else {
		cout<<"NO"<<endl;
	}
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}