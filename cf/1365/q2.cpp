#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;

	vector<int>a;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}
	vector<int> b;
	nn=n;
	int countOne = 0, countZero = 0;
	while(nn--){
		int vl;
		cin>>vl;
		if(vl==1){
			countOne +=1;
		} else{
			countZero +=1;
		}
		b.push_back(vl);
	}

	bool isInc = true;
	// chkc sorted
	for(int i=1;i<n;i++){
		if(a[i] < a[i-1]){
			isInc = false;
			break;
		}
	}

	if(isInc){
		cout<<"Yes"<<endl;
		return;
	}

	if(countOne == n ||countZero ==n){
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;



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
