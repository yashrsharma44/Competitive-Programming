#include <bits/stdc++.h>
#define int long long 

using namespace std;


void solve(){

	int n;
	cin>>n;
	int nn = n;
	vector<int> a;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}
	vector<int> pre(n-1, 0);
	for(int i=0;i<n-1;i++){
		pre[i] = a[i+1] - a[i];
	}
	int pos = 0, neg  = 0;
	for(int el : pre){
		if(el > 0){
			pos++;
		} else if(el < 0){
			neg++;
		}
	}
	if(pos == neg){
		for(int el : a){
			cout<<el<<" ";
		}
		cout<<endl;
		return;
	}

	if(pos > neg){
		int k = pos - (n/2);
		for(int i=0;k>0 && i<n-1;i++){
			if(pre[i] > 0){
				a[i] = -a[i];
				k--;
				i++;
			}
		}
	} else {
		int k = neg - (n/2);
		
		for(int i=0;k>0 && i<n-1;i++){
			if(pre[i] < 0){
				a[i] = -a[i];
				k--;
				i++
			}
		}

	}


	for(int el : a){
		cout<<el<<" ";
	}
	cout<<endl;
	return;


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
