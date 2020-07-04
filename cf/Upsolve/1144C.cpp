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

	sort(a.begin(), a.end());
	set<int> elem, el2;
	elem.insert(a[0]);
	for(int i=1;i<n;i++){
		if(a[i] > *elem.rbegin()){
			elem.insert(a[i]);
		} else {
			if(el2.find(a[i]) != el2.end()){
				cout<<"NO"<<endl;
				return;
			}
			el2.insert(a[i]);
		}
	}
	cout<<"YES"<<endl;
	cout<<elem.size()<<endl;
	for(int el : elem){
		cout<<el<<" ";
	}
	cout<<endl;
	cout<<el2.size()<<endl;
	for(auto it=el2.rbegin();it!=el2.rend();it++){
		cout<<*it<<" ";
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
