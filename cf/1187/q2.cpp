#include <bits/stdc++.h>
#define int long long

using namespace std;

void fill(string s, vector< pair<int,int> > *chr){
	
	for(int i=0;i<26;i++){
		int ctr = 1;
		for(int j=0;j<s.length();j++){
			if(s[j] - 'a' == i){
				chr[i].push_back(make_pair(j, ctr++));
			}
		}
	}
}

int binSearch(vector< pair<int,int> >&arr, int target){

	int l = 0, r = arr.size()-1;
	while(l<=r){

		int m = l + (r - l) / 2;
		if(arr[m].second == target){
			return m;
		} else if(arr[m].second < target){
			l = m + 1;
		} else {
			r = m - 1;
		}

	}
	return -1;

}

void solve(){

	int n;
	cin>>n;
	string s;
	cin>>s;

	vector< pair<int,int> > cs[26]; //O(26n)
	fill(s, cs);
	int m;
	cin>>m;
	while(m--){//O(m)
		string t;
		cin>>t;

		vector<int> ct(26, 0); //O(26t)
		for(char c : t){
			ct[c-'a']+=1;
		}
		int max_ = 0;
		for(char c : t){
			if(cs[c-'a'].size() > 0){
				int count = ct[c-'a'];
				int ans = binSearch(cs[c-'a'], count);
				max_ = max(max_, cs[c-'a'][ans].first);
			}
		}


		cout<<(max_+1)<<endl;
	}


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
