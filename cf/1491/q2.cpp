#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

bool check(int r, int c, vector<int> &a, int row, int col){
	int n = a.size();
	if(r - 1 >= 0){
		return a[r-1] != (c - 1) && a[r-1] != c && a[r-1] != (c+1);
	}
	if(r + 1 < n){
		return a[r+1] != c + 1 && a[r+1] != c - 1 && a[r+1] != c;
	}
}

int dfs(vector<int> &a, int i, int u, int v){
	int dr[5] = {-2,-1,0,1,2};
	int dc[5] = {-2,-1,0,1,2};
	int row = i, col = a[i];
	a[i] = -5;
	int ans = INT_MAX;
	for(int r=0;r<5;r++){
		for(int s=0;s<5;s++){
			int rr = row + dr[r]; int cc = col + dc[s];

			if(rr>=0 && rr < a.size() && cc >= 0 && cc <= 1000001 && a[rr]!=cc){
				// cout<<rr<<" "<<cc<<" "<<i<<" "<<col<<endl;		
				if(check(rr, cc, a, row, col)){
					// cout<<rr<<"--"<<cc<<endl;
					ans = min(ans, u * abs(rr - row) + v * abs(cc - col));
				}	
					
			}
		}
	}
	a[i] = col;

	return ans;
}

void solve()
{
	int n,u,v; cin>>n>>u>>v;
	vector<int> a;
	for(int i=0;i<n;i++){
		int u; cin>>u;
		a.push_back(u);
	}

	int ans = INT_MAX;
	for(int i=0;i<n;i++){
		ans = min(ans, dfs(a, i, u, v));
	}

	cout<<ans<<endl;

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
