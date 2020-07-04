#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	if(a.size() == 1){
		cout<<-1<<endl;
		return;
	}
	if(a.size() == 2){
		if(a[0] == a[1]){
			cout<<-1<<endl;
		} else {
			cout<<1<<endl;
			if(a[0] < a[1]){
				cout<<1<<endl;
			} else {
				cout<<2<<endl;
			}
		}
		return;
	}
	
	int min_ = INT_MAX;
	int minIdx = -1;
	for(int i=0;i<n;i++){
		
		if(a[i] < min_){
			min_ = a[i];
			minIdx = i+1;
		}
	}
	cout<<1<<endl;
	cout<<minIdx<<endl;

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
