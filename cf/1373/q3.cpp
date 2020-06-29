#include <bits/stdc++.h>
#define int long long 

using namespace std;

int binSearch(vector<int> &a, int target){

	int l = 0, r = a.size();
	while(l < r){
		int m = l + (r - l) / 2;
		if(a[m] > target){
			r = m;
		} else {
			l = m + 1;
		}
	}

	return l;
}

void solve(){

	string s;
	cin>>s;
	vector<int> a;
	int cnt = 0;
	for(char c : s){
		if(c == '+'){
			cnt--;
		} else {
			cnt++;
		}
		a.push_back(cnt);
	}
	a.push_back(s.length());

	int rnmax = a[0];
	for(int i=1;i<a.size();i++){
		rnmax = max(rnmax, a[i]);
		a[i] = rnmax;
	}
	
	int ans = 0;
	for(int i=0;i<=1000010;i++){

		
	

	}

	cout<<ans<<endl;

	

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
