#include <bits/stdc++.h>
#define int long long 

using namespace std;

int LIS(vector<int> b){

	vector<int>res;
	for(int i=0;i<b.size();i++){
		auto it = lower_bound(res.begin(), res.end(), b[i]);
		if(it == res.end()){
			res.push_back(b[i]);
		} else {
			*it = b[i];
		}
	}

	return res.size();

}

void solve(){

	int n;
	cin>>n;

	vector<int> a, b;
	int nn =n;
	while(nn--){
		int aa;
		cin>>aa;
		a.push_back(aa);
	}

	nn = n;
	while(nn--){
		int bb;
		cin>>bb;
		b.push_back(bb);
	}
	vector<int>bb(b);
	sort(bb.begin(),bb.end());
	reverse(bb.begin(), bb.end());

	bool isSame = true;
	for(int i=0;i<n;i++){
		if(a[i] != bb[i]){
			isSame = false;
		}
	}

	if(isSame){
		cout<<1<<endl;
		return;
	}

	for(int i=0;i<n;i++){
		b.push_back(b[i]);
	}
		
	map<int,int>mp;
	for(int i=0;i<n;i++){
		mp[a[i]]=i;
	}
	for(int i=0;i<b.size();i++){
		b[i] = mp[b[i]];
	}
	int maxR=0;
	
	int curr=1;
	int prev = b[0];
	for(int i=1;i<b.size();i++){

		if(prev + 1 == b[i] || (prev == 0 && b[i] == n-1) || (prev == n-1 && b[i] == 0)){
			curr+=1;
			prev = b[i];
		} else {
			maxR=max(maxR,curr);
			curr=1;
			prev = b[i];
		}

	}

	//  curr=1;
	//  prev = b[0];
	// for(int i=1;i<b.size();i++){

	// 	if(prev - 1 == b[i]){
	// 		curr+=1;
	// 		prev = b[i];
	// 	} else {
	// 		maxR=max(maxR,curr);
	// 		curr=1;
	// 		prev = b[i];
	// 	}

	// }

	maxR = max(maxR, curr);
	if(maxR > n){
		maxR = maxR / 2;
	}
	cout<<maxR<<endl;


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
