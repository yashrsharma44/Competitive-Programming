#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void space(int i){
	for(int ii=0;ii<i;ii++) cout<<"  ";
}

void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++){
		if(i == arr.size()-1) cout<<arr[i];
		else cout<<arr[i]<<" ";
	}
}

vector<int> get(int i){
	vector<int> ans;
	for(int j=0;j<=i;j++) ans.push_back(j);
	for(int j=i-1;j>=0;j--) ans.push_back(j);

	return ans;
}

void solve(){

	int n; cin>>n;
	vector<vector<int>> ans;
	for(int i=0;i<=n;i++){
		ans.push_back(get(i));
	}
	for(int i=n-1;i>=0;i--){
		ans.push_back(get(i));
	}
	for(int i=0;i<=n;i++){
		space(n - i);
		print(ans[i]);cout<<endl;
		// space(n - i);
	}
	for(int i=n-1;i>=0;i--){
		space(n - i);
		print(ans[i]);cout<<endl;
		// space(n - i);cout<<endl;
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
