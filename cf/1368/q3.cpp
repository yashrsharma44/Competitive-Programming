#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	int n;
	cin>>n;
	int k = 1;
	for(int i=1;i<=500;i++){
		if(i*i >= n){
			k = i;
			break;
		}
	}
	vector< pair<int,int> > ans;
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			ans.push_back(make_pair(i,j));
		}
	}

	int y = n / k;
	if(n % k!=0){
		y+=1;
	}
	int x = n % k;
	if(n == k*k){
		x = k;
	}


	for(int i=1;i<=y;i++){
		ans.push_back(make_pair(0, i));
	}
	for(int i=1;i<=(n/k);i++){
		ans.push_back(make_pair(k+1, i));
	}

	for(int i=1;i<=k;i++){
		ans.push_back(make_pair(i, k+1));
	}
	for(int i=1;i<=x;i++){
		ans.push_back(make_pair(i, 0));
	}
	cout<<ans.size()<<endl;
	for(auto el : ans){
		cout<<el.first<<" "<<el.second<<endl;
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
