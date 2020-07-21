#include <bits/stdc++.h>
#define int long long 

using namespace std;


void solve(){

	int n;
	cin>>n;
	
	vector<int> a;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}
	
	set<int> res, cur, cur2;
	for (int i: a) {
        cur2 = {i};
        for (int j: cur) cur2.insert(i|j);
        for (int j: cur = cur2) res.insert(j);
    }
	// cout<<res.size()<<endl;
	
	int sz = res.size();
	int pr = n*(n+1)/2;
	if(sz!=pr){
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
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
