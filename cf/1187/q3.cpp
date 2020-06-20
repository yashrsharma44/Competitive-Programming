#include <bits/stdc++.h>
#define int long long

using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){

	if(p1.first!=p2.first){
		return p1.first < p2.first;
	}
	return p1.second < p2.second;

}

bool merge(vector< pair<int,int> > &arr, int l, int r){

	int ctr = 0;
	for(int i=0;i<arr.size();i++){

		// int el = arr[i];
		if(l >= arr[i].first && l <= arr[i].second && r > arr[i].second){
			arr[i].first = min(l, arr[i].first);
			arr[i].second = max(r, arr[i].second);
		} else if((l >= arr[i].first && l <= arr[i].second && r >= arr[i].first && r <= arr[i].second) || (l < arr[i].first && r > arr[i].second)){
			arr[i].first = min(l, arr[i].first);
			arr[i].second = max(r, arr[i].second);
		} else if(l < arr[i].first && r >= arr[i].first && r <= arr[i].second){
			arr[i].first = min(l, arr[i].first);
			arr[i].second = max(r, arr[i].second);
		} else {
			ctr+=1;
		}
	}

	return ctr != arr.size();

}

bool present(pair<int,int> p1, pair<int,int> p2){

	int l = p1.first, r = p1.second;

	if(l > p2.first && l < p2.second){
		return true;
	} else if(r > p2.first && r < p2.second){
		return true;
	} else if(l < p2.first && r > p2.second){
		return true;
	}

	return false;
}

void solve(){

	int n,m;
	cin>>n>>m;

	vector< pair<int,int> > con, dec;
	while(m--){

		int t;
		cin>>t;
		int l,r;
		cin>>l>>r;
		if(t == 1){
			if(!merge(con, l ,r)){
				con.push_back(make_pair(l,r));
			}
		} else {
			if(!merge(dec, l ,r)){
				dec.push_back(make_pair(l,r));
			}
		}

	}

	// Check invalid
	for(int i=0;i<con.size();i++){
		for(int j=0;j<dec.size();j++){
			if(present(con[i], dec[j]) || present(dec[j], con[i])){
				cout<<"NO"<<endl;
				return;
			}
		}
	}

	vector<int> b(n-1, 0);
	for(auto el : dec){
		for(int i=el.first;i<el.second;i++){
			b[i-1] = -1;
		}
	}

	vector<int> ans(n,0);
	ans[0] = n;
	for(int i=1;i<n;i++){
		ans[i] = ans[i-1] + b[i-1];
	}
	cout<<"YES"<<endl;
	for(int el : ans){
		cout<<el<<" ";
	}
	cout<<endl;
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
