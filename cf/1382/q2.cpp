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

	if(n == 1){
		cout<<"First"<<endl;
		return;
	}
	if(n == 2){
		if(a[0] == 1){
			cout<<"Second"<<endl;
		} else {
			cout<<"First"<<endl;
		}
		return;
	}

	// 1 winner, 0 loser
	int turn = 0;
	int itr = n-2;
	while(itr >= 0){
		if(turn == 0){
			if(a[itr] > 1){
				itr--;
			} else {
				itr--;
				turn = 1;
			}
		} else {
			turn = 0;
			itr--;
		}
	}
	if(turn == 0){
		cout<<"First"<<endl;
	} else {
		cout<<"Second"<<endl;
	}

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
