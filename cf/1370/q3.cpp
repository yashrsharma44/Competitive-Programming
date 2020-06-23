#include <bits/stdc++.h>
#define int long long

using namespace std;


void solve(){

	int n;
	cin>>n;

	// if(n%2 == 0){
	// 	cout<<"Ashishgup"<<endl;
	// } else {
	// 	cout<<"FastestFinger"<<endl;
	// }

	int turn = 0;
	while(true){

		if(n % 2 == 0){
			set<int> fact;
			for(int i=2;i*i<=n;i++){
				if(n%i==0){
					fact.insert(i);
					fact.insert(n / i);
				}
			}
			bool odd = false;
			for(auto el : fact){
				if(el % 2 == 1){
					n = n / el;
					odd = true;
					break;
				}
			}

			
			
		} else {
			break;
		}
		turn+=1;

	}
	if(turn%2 == 1){
		cout<<"Ashishgup"<<endl;
	} else {
		cout<<"FastestFinger"<<endl;
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
