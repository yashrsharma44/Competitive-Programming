#include <bits/stdc++.h>
#define int long long 

using namespace std;

// int dp

int func(vector<int> &a, int i, int k, int z, bool mleft){

	// base cases
	if(k == 0){
		return a[i];
	}

	int score = 0;

	// Two cases : We can move left or we cannot
	if(z == 0){
		// move right only

		// if at last
		if(i == a.size()-1){
			return a[i];
		}
		score = func(a, i+1, k-1, z, true);
	} else {
		// we can move left and right

		// edge case: i == 0 || i == n-1
		if(i == 0){
			// move right
			score = func(a, i+1, k-1, z, true);
		} else if(i == a.size()-1){
			// move left
			if(mleft){
				score = func(a, i-1,k-1,z-1,false);	
			}
		} else {
			// move left or right
			int leftS = 0, rightS = 0;
			if(mleft){
				leftS = func(a, i-1, k-1, z-1, false);
			} 
			rightS = func(a, i+1, k-1,z,true);
			score = max(leftS, rightS);
		}
	}

	return score + a[i];

}

void solve(){
	
	int n,k,z;
	cin>>n>>k>>z;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int ans = 0;
	// k--;
	vector<int> pre(n-1, 0);
	pre[0] = a[1];
	for(int i=1;i<n-1;i++){
		pre[i] = pre[i-1] + a[i+1];
	}


	vector<int> doub;
	for(int i=1;i<n;i++){
		doub.push_back(a[i]+a[i-1]);
	}

	for(int i=0;i<doub.size();i++){
		int k1 = k / 2;
		int sum = a[0] + pre[i] - a[1];
		if(k1 > z){
			sum += z * doub[i];
			int remK = k - (2*z);
			sum += pre[min(i+remK,n-1)] - pre[i];	
			ans = max(ans, sum);
		} else {
			sum += k1 * doub[i];
			int remK = k - (2*k);
			if(remK == 1){
				sum += a[i+1];
			}
			ans = max(ans, sum);
		}
		k--;
	}


	cout<<ans<<endl;

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
