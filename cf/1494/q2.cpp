#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

void solve()
{
	int n; 
	vector<int> aa(4);
	cin>>n>>aa[0]>>aa[1]>>aa[2]>>aa[3];
	set<int> nm;
	for(int i=0;i<4;i++){
		nm.insert(aa[i]);	
	}

	if(nm.size() == 1){
		cout<<"YES"<<endl;
		return;
	}

	vector<int> a;
	for(int i=0;i<4;i++){
		if(aa[i] >= n-2){
			a.push_back(aa[i] - (n-2));
		} else {
			a.push_back(0);
		}
	}

	for(int i=0;i<4;i++){
		vector<int> b;
		int id = i;

		while(b.size() <= 4){
			b.push_back(a[id]);
			id++;
			id = id % 4;
		}
		bool isPos = true;
		for(int j=0;j<3;j++){
			id = (j+1) % 4;
			if(min(b[j], b[id]) >= 1 || (b[j] == 0 && b[id] == 0)){
				if(b[j] != 0 && b[id] != 0){
					b[j] -= 1;
					b[id] -= 1;
				}
				continue;
			} else {
				isPos = false;
				break;
			}
		}
		if(isPos){
			cout<<"YES"<<endl;
			return;
		}
	}

	int cnt = 0;
	for(int i=0;i<4;i++){
		if(a[i] <= n-2) cnt++;
	}

	if(cnt == 4){
		cout<<"YES"<<endl;
		return;
	}
	// for(int i=0;i<4;i++){
	// 	if(a[i] >= n-2){
	// 		a[i] = a[i] - (n-2);
	// 	} else {
	// 		a[i] = 0;
	// 	}
	// }

	// for(int i=0;i<4;i++){
	// 	vector<int> b;
	// 	int id = i;

	// 	while(b.size() <= 4){
	// 		b.push_back(a[id]);
	// 		id++;
	// 		id = id % 4;
	// 	}
	// 	bool isPos = true;
	// 	for(int j=0;j<3;j++){
	// 		id = (j+1) % 4;
	// 		if(min(b[j], b[id]) >= 1 || (b[j] == 0 && b[id] == 0)){
	// 			if(b[j] != 0 && b[id] != 0){
	// 				b[j] -= 1;
	// 				b[id] -= 1;
	// 			}
	// 			continue;
	// 		} else {
	// 			isPos = false;
	// 			break;
	// 		}
	// 	}
	// 	if(isPos){
	// 		cout<<"YES"<<endl;
	// 		return;
	// 	}
	// }

	cout<<"NO"<<endl;

	
}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	// t = 1;

	while (t--)
	{
		solve();
	}
}
