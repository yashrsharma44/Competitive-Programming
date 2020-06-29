#include <bits/stdc++.h>
#define int long long 

using namespace std;

class Comparator {
public:
	bool operator()(vector<int> v1, vector<int> v2){
		return v1[0] > v2[0];
	}

};

void solve(){

	int n,k;
	cin>>n>>k;

	priority_queue < vector<int>, vector< vector<int> >, Comparator > pq1, pq2, pq3;

	int nn = n;
	while(nn--){
		vector<int> tt(3, 0);
		cin>>tt[0]>>tt[1]>>tt[2];
		if(tt[1] == 0 && tt[2] == 0){
			continue;			
		}

		if(tt[1] == 1 && tt[2] == 1){
			pq1.push(tt);
		} else if(tt[1] == 1 && tt[2] == 0){
			pq2.push(tt);
		} else if(tt[1] == 0 && tt[2] == 1){
			pq3.push(tt);
		}
	}
	int sum = 0;
	int kk = 0;
	int p1 = pq2.size(), p2 = pq3.size();
	while(kk < k && pq2.size() > 0 && pq3.size() > 0){

		vector<int> el2 = pq2.top(), el3 = pq3.top();
		if(el2[0] + el3[0] <= pq1.top()[0]){
			sum += el2[0] + el3[0];
			pq2.pop();
			pq3.pop();
		} else {
			sum += pq1.top()[0];
			pq1.pop();
		}
		kk+=2;
	}

	if(kk >= k){
		cout<<sum<<endl;
		return;
	}

	while(pq1.size() > 0 && kk < k){
		sum += pq1.top()[0];
		kk+=2;
	}
	if(kk >= k){
		cout<<sum<<endl;
		return;
	}

	while(pq2.size() > 0 && kk < k){
		sum += pq2.top()[0];
		pq2.pop();
		kk+=1;
	}


	if(kk >= k){
		cout<<sum<<endl;
		return;
	}

	while(pq3.size() > 0 && kk < k){
		sum += pq3.top()[0];
		pq3.pop();
		kk+=1;
	}

	
	if(kk >= k){
		cout<<sum<<endl;
		return;
	}
	cout<<-1<<endl;
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
