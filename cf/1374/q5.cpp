#include <bits/stdc++.h>
#define int long long 

using namespace std;
// class Comparator {


void solve(){

	int n,k;
	cin>>n>>k;

	vector<int> alice, bob, both;
	int nn = n;
	while(nn--){
		int t,a,b;
		cin>>t>>a>>b;

		if(a == 0 && b == 0){
			continue;
		}

		if(a == 1 && b == 0){
			alice.push_back(t);
		} else if(a == 0 && b == 1){
			bob.push_back(t);
		} else {
			both.push_back(t);
		}

	}

	sort(alice.begin(), alice.end());
	sort(bob.begin(), bob.end());
	for(int i=0;i<min(alice.size(), bob.size());i++){
		both.push_back(alice[i]+bob[i]);
	}

	if(both.size() < k){
		cout<<-1<<endl;
		return;
	}
	sort(both.begin(), both.end());
	int sum = 0;
	for(int i=0;i<k;i++){
		sum += both[i];
	}

	cout<<sum<<endl;


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
