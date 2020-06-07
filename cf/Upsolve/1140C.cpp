#include <bits/stdc++.h>
#define int long long 

using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){

	if(p1.second != p2.second){
		return p1.second > p2.second;
	}

	return p1.first > p2.first;

}

void solve(){

	int n,k;
	cin>>n>>k;

	vector <pair<int,int> >vv;
	for(int i=0;i<n;i++){
		int t,b;
		cin>>t>>b;
		vv.push_back({t,b});
	}
	sort(vv.begin(), vv.end(), comp);
	

	
	int ans = -1;
	int sum = 0;
	int p1 = 0, p2 = 0;
	set < pair<int,int> >st;
	for(int i=0;i<n;i++){

		sum += vv[i].first;
		st.insert({vv[i].first, i});

		while(st.size() > k){
			auto it = st.begin();
			sum -=  it->first;
			st.erase(it);
		}

		ans = max(ans, sum * vv[i].second);

	}


	cout<<ans<<endl;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
