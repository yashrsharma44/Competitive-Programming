#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> a;
	set<ll> st;
	map<ll,ll> mp;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;

		mp[vl] +=1;

		st.insert(vl);
		a.push_back(vl);
	}

	ll maxEl = -1, maxCount = -1;
	for(auto el : mp){
		if(el.second > maxCount){
			maxCount = el.second;
			maxEl = el.first;
		}
	}

	st.erase(maxEl);
	ll diffCount = st.size();

	if(abs(maxCount - diffCount) == 1){
		cout<<min(maxCount, diffCount)<<endl;
		return;
	}

	if(maxCount > diffCount){
		cout<<diffCount+1<<endl;
	} else {
		cout<<maxCount<<endl;
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}