#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

bool check(int val, int d){
	while(val > 0){
		int las = val % 10;
		if(las == d) return true;
		val/=10;
	}

	return false;
}

void solve(){

	int q,d; cin>>q>>d;
	vector<int> a;
	int nn = q;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}

	if(d == 1){
		while(q--){
			cout<<"YES"<<endl;
			
		}return;
	}

	if(d == 2){
		for(auto el : a){
			if(el%2==0){
				cout<<"YES"<<endl;
			} else if(el >= 21) {
				cout<<"YES"<<endl;
			} else {
				cout<<"NO"<<endl;
			}
		}
		return;
	}

	map<int,vector<int>> mp;
	mp[3] = {12,21};
	mp[4] = {-1,-1,-1};
	mp[5] = {-1,-1,-1,-1};
	mp[6] = {-1, 24, -1, 12, -1};
	mp[7] = {56, 35, 14,63,42,21};
	mp[8] = {-1,16,-1,24,-1,32,-1};
	mp[9] = {18,27,36,45,54,63,72, 81};

	for(auto el : a){
		int div = el / d;
		int rem = el % d;
		if(rem == 0 || check(el, d)){
			cout<<"YES"<<endl;
			continue;
		}
		int val = mp[d][rem-1];
		if(val != -1 && val <= el - rem){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}

	}

	
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}

