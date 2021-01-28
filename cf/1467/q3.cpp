#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int a,b,c; cin>>a>>b>>c;
	vector< vector<int> > ar(3, vector<int>());
	
	// Sum of all elements of the bag
	int sumAll = 0;
	int s1 = 0, s2 = 0, s3 = 0;

	int nn = a;
	while(nn--){
		int u; cin>>u;
		sumAll +=u;
		s1 += u;
		ar[0].push_back(u);
	}
	nn = b;
	while(nn--){
		int u; cin>>u;
		sumAll +=u;
		s2 += u;
		ar[1].push_back(u);
	}
	nn = c;
	while(nn--){
		int u; cin>>u;
		sumAll +=u;
		s3 += u;
		ar[2].push_back(u);
	}

	sort(ar[0].begin(), ar[0].end());
	sort(ar[1].begin(), ar[1].end());	
	sort(ar[2].begin(), ar[2].end());

	// Negate all the elements of a bag
	int ans = 0;
	ans = max({ans, sumAll - 2*s1, sumAll - 2*s2, sumAll - 2*s3});

	for(int i=0;i<3;i++){
		for(int j=i+1;j<3;j++){
			ans = max({ans, sumAll - 2*ar[i].front() - 2*ar[j].front()});
		}
	}

	cout<<ans<<endl;

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
