#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

bool comp(vector<int> &p1, vector<int> &p2){
	double d1 = pow(p1[0] * p1[0] + p1[1] * p1[1], 0.5);
	double d2 = pow(p2[0] * p2[0] + p2[1] * p2[1], 0.5);

	return d1 < d2;
}

void solve(){	

	int n; cin>>n;
	vector<vector<int>> miners, diam;
	for(int i=0;i<2*n;i++){
		int u, v; cin>>u>>v;
		if(u == 0){
			// diam
			diam.push_back({u,v});
		} else {
			miners.push_back({u, v});
		}
	}

	sort(miners.begin(), miners.end(), comp);
	sort(diam.begin(), diam.end(), comp);
		
	double ans = 0;
	int p1 = 0, p2 = 0;
	while(p1 < miners.size()){
		double d = pow(abs(miners[p1][0] - diam[p2][0]) * abs(miners[p1][0] - diam[p2][0]) + abs(miners[p1][1] - diam[p2][1]) * abs(miners[p1][1] - diam[p2][1]), 0.5);
		ans += d;
		p1++; p2++;
	}

	printf("%0.15f\n", ans);
}	

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	// t = 1;

	while (t--)
	{
		solve();
	}
}
