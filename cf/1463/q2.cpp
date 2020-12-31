#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<int> arr;
	int nn = n;
	int i = 0;
	int sum1 = 0, sum2 = 0;
	while(nn--){
		int vl; cin>>vl;
		if(i%2==0){
			sum1+=vl;
		} else {
			sum2+=vl;
		}
		i++;
		arr.push_back(vl);
	}
	vector<int> ans;
	if(sum1 > sum2){
		for(int i=0;i<n;i++){
			if(i%2==0){
				ans.push_back(arr[i]);
			} else {
				ans.push_back(1);
			}
		}
	} else {
		for(int i=0;i<n;i++){
			if(i%2==1){
				ans.push_back(arr[i]);
			} else {
				ans.push_back(1);
			}
		}
	}

	for(int el : ans){
		cout<<el<<" ";
	}
	cout<<endl;
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
