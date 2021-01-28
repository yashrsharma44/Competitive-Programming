#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n,m; cin>>n>>m;
	string s; cin>>s;

	vector<vector<int>> q;
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		q.push_back({u, v});
	}

	vector<int> preMax, preMin, postMax, postMin, sm;
	int min_ = 0, max_ = 0;
	int sum = 0;
	preMin.push_back(0); preMax.push_back(0);sm.push_back(0);
	for(int i=0;i<n;i++){
		if(s[i] == '+'){
			sum+=1;
		} else {
			sum-=1;
		}
		sm.push_back(sum);
		min_ = min(min_, sum);
		max_ = max(max_, sum);

		preMin.push_back(min_);
		preMax.push_back(max_);
	}
	
	postMin.push_back(sum);
	postMax.push_back(sum);
	min_ = max_ = sum;
	for(int i=n-1;i>=0;i--){
		if(s[i] == '+'){
			sum -=1;
		} else {
			sum += 1;
		}
		min_ = min(min_, sum);
		max_ = max(max_, sum);

		postMax.push_back(max_);
		postMin.push_back(min_);
	}

	reverse(postMin.begin(), postMin.end());
	reverse(postMax.begin(), postMax.end());

	for(auto qq : q){
		// if(qq[1] - qq[0] == n - 1){
		// 	cout<<1<<endl;
		// 	continue;
		// }

		int prMin = preMin[qq[0]-1];
		int prMax = preMax[qq[0]-1];

		int diff = sm[qq[1]] - sm[qq[0]-1];

		int poMin = postMin[qq[1]] - diff;
		int poMax = postMax[qq[1]] - diff;
		// cout<<"prMin"<<prMin<<"prMax"<<prMax<<"poMin"<<poMin<<"poMax"<<poMax<<endl;
		int ans = max(poMax, prMax) - min(poMin, prMin) + 1;
		cout<<ans<<endl;
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
