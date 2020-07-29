#include <bits/stdc++.h>
#define int long long 

using namespace std;

int smallCycle(vector<int> *adj, int st, int n){

	int ans = INT_MAX;

	queue<int> q;
	vector<int> dist(n, -1);
	vector<int> par(n, -1);
	dist[st] = 0;
	q.push(st);

	while(!q.empty()){

		int root = q.front();
		q.pop();

		for(auto child : adj[root]){

			if(child == par[root]){
				continue;
			}
			if(dist[child] == -1){
				par[child] = root;
				dist[child] = dist[root] + 1;
				q.push(child);
			} else {
				ans = min(ans, dist[child] + dist[root] + 1);
			}
		}
	}

	return ans;
}

void solve(){
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	vector<int> bits[60];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<60;j++){
			int el = a[i];
			if((el >> j) & 1){
				bits[j].push_back(i);
				if(bits[j].size() > 2){
					cout<<3<<endl;
					return;
				}
			}
		}
	}
	vector<int> b;
	for(int el : a){
		if(el){
			b.push_back(el);
		}
	}
	n = b.size();
	a = b;
	vector<int> adj[n];

	// Out here we have atmost 2 diff numbers for a given bit
	// So atmost we can have 60*2 numbers with each of the bit
	// set as 2.

	// So we can consider pairs of numbers.
	// 16 8 4 2 1
	//  0 0 0 1 1
	//  0 0 1 1 0
	//  0 1 1 0 0
	//  1 1 0 0 0

	// If this is not true, we have another number, which increases the bit
	// count > 2, which would be handled by the above loop
	// Hence the invariant holds true :P

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i] & a[j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	// cout<<"L"<<endl;
	int ans = INT_MAX;
	for(int i=0;i<n;i++){
		ans = min(ans, smallCycle(adj, i, n));
	}
	if(ans == INT_MAX){
		cout<<-1<<endl;
		return;
	}
	cout<<ans<<endl;
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
