#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;

	// int pos = 0, neg = 0, zero = 0;
	vector<int> pos, neg, zero;
	for(int i=0;i<n;i++){
		int vl;
		cin>>vl;
		if(vl>0){
			// pos++;
			pos.push_back(vl);
		} else if(vl==0){
			// zero++;
			zero.push_back(vl);
		} else {
			// neg++;
			neg.push_back(vl);
		}
	}
	int k = 0;

	cout<<1<<" ";
	cout<<neg[0]<<endl;
	neg.erase(neg.begin());
	k++;
	if(pos.size() == 0){
		k+=2;
		cout<<2<<" ";
		cout<<neg[0]<<" "<<neg[1];
		cout<<endl;
		neg.erase(neg.begin());
		neg.erase(neg.begin());
	} else {
		k+=1;
		cout<<1<<" ";
		cout<<pos[0]<<endl;
		pos.erase(pos.begin());
		// cout<<endl;
	}
	int sz = pos.size() + neg.size() + zero.size();
	cout<<sz<<" ";
	for(int el : zero){
		cout<<el<<" ";
	}
	for(int el : neg){
		cout<<el<<" ";
	}
	for(int el : pos){
		cout<<el<<" ";
	}
	cout<<endl;


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
