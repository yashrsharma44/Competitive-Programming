#include <bits/stdc++.h>
#define MOD 998244353
#define int long long 

using namespace std;

bool valid(map<int,int> mp){

	int count = -1;
	for(auto el : mp){
		if(count == -1){
			count = el.second;
		} else {
			if(count != el.second){
				return false;
			}
		}
	}

	return true;

}

bool checkValid(map<int,int> mp){

	set<int> count;
	for(auto el :  mp){
		count.insert(el.second);
	}
	if(count.size() == 2){
		return true;
	}

	return false;
}


void solve(){

	int n;
	cin>>n;

	vector<int> u;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		u.push_back(vl);
	}

	int maxLen = -1;
	map<int,int>mp;
	for(int i=0;i<n;i++){
		mp[u[i]]+=1;

		if(valid(mp)){
			maxLen = i+1;
		}

		if(!valid(mp) && checkValid(mp)){
			maxLen = i-1;
		}
	}

	cout<<maxLen<<endl;

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
