#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

int score(vector<int> &A, int i){
	int n = A.size();
	if(i > 0 && i+1 < n && A[i-1] > A[i] && A[i+1] > A[i]) return 1;
	if(i > 0 && i+1 < n && A[i-1] < A[i] && A[i+1] < A[i]) return 1;
	return 0;
}

void solve(){

	int n; cin>>n;
	vector<int> A;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		A.push_back(u);
	}

	if(n <= 3){
		cout<<0<<endl;
		return;
	}

	// For each point, we try to modify its value, and check if the new value changes it's count and it's 
	// neighbour's count. If that happens, we change and adjust our count. Choose the min among all the 
	// possible values
	int ans = 0;
	for(int i=0;i<n;i++){
		ans += score(A, i);
	}
	int local = ans;
	for(int i=0;i<n;i++){
		int orig = A[i];
		set<int> elems;

		int without = local - score(A, i-1) - score(A, i) - score(A, i+1);

		if(i > 0){
			elems.insert(A[i-1] - 1);
			elems.insert(A[i-1] + 1);
			elems.insert(A[i-1]);			
		}

		if(i < n-1){
			elems.insert(A[i+1] + 1);
			elems.insert(A[i+1] - 1);
			elems.insert(A[i+1]);			
		}


		for(auto el : elems){
			A[i] = el;
			ans = min(ans, without + score(A, i) + score(A, i-1) + score(A, i+1));
		}			

		A[i] = orig;
	}

	cout<<ans<<endl;

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
