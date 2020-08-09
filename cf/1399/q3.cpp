#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){

	int n;
	cin>>n;
	vector<int> a(n);
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}

	sort(a.begin(), a.end());
	if(n == 1){
		cout<<0<<endl;
		return;
	}
	if(n <=3){
		cout<<1<<endl;
		return;
	}
	int minS = a[0] + a[1];
	int maxS = a[0] + a.back();

	int maxK = 0;
	for(int i=1;i<=150;i++){

		int count = 0;
		map<int,int> cmp(mp);
		for(int el : a){
			if(i -el != el){
				count += min(cmp[i-el], cmp[el]);	
			} else {
				count += (cmp[el] / 2);
			}
			
			cmp[el] = 0; cmp[i-el] = 0;
		}
		maxK = max(maxK, count);
	}

	cout<<maxK<<endl;



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
