#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){
	int n; cin>>n;
	vector<int> a;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}

	int c0 = 0, c1 = 0, c2 = 0;
	int p = n / 3;
	for(auto el : a){
		if(el%3 == 0) c0++;
		if(el%3 == 1) c1++;
		if(el%3 == 2) c2++;
	}

	vector<vector<int>> elems({{c0, 0}, {c1, 1}, {c2, 2}});
	sort(elems.begin(), elems.end());
	reverse(elems.begin(), elems.end());
	for(int i=0;i<3;i++){
		int k = elems[i][0] - p;
		if(k < 0) continue;

		int i0 = elems[i][1];
		int c1 = -1, i2 = -1;
		for(auto el : elems){
			if(el[1] == (i0+1) % 3){
				c1 = el[0];
				break;
			}
		}

		if(c1 + k - p < 0) continue;
		int ans = k +  c1 + k - p;
		cout<<ans<<endl;
		return;
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