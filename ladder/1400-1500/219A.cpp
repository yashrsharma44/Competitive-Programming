#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int k; cin>>k;
	string s; cin>>s;

	map<char,int> chr;
	for(char c : s) chr[c]++;

	string ans = "";
	for(auto el : chr){
		if(el.second % k == 0){
			int cnt = el.second / k;
			for(int i=0;i<cnt;i++)ans+=el.first;
		} else {
			cout<<-1<<endl;
			return;
		}
	}
	string aa = "";
	for(int i=0;i<k;i++) aa += ans;

	cout<<aa<<endl;
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
