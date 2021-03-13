#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

vector<int> bits(int x){
	vector<int> ans;
	for(int i=0;i<=30;i++){
		if(1 << i & x){
			ans.push_back(i);
		}
	}
	return ans;
}

void solve()
{
//   8 4 2 1
// 3 0 0 1 1
// 5 0 1 0 1

// u = 3
// u + v = 5
// v = 5 - u = 5 - 3 = 2

//    8 4 2 1
//u 7 0 1 1 1
//v 6 0 1 1 0
//13  1 1 0 1

//    8 4 2 1
//  1 0 0 0 1
//  2 0 0 1 0
//  4 0 1 0 0

// u = 1
// u + v = 4
// v = 4 - u = 4 - 1 = 3

//      8 4 2 1
//u  (1)0 0 0 1
//v  (3)0 0 1 1
//u+v(4)0 1 0 0 

	int q; cin>>q;
	while(q--){
		int initial,finalv; cin>>initial>>finalv;
		if(finalv < initial){
			cout<<"NO"<<endl;
		} else {
			// Lets count the set bits in finalv
			// If the finalv contains higher order bits
			// as compared to initial then, we can form
			// the answer. If finalv does not contain the
			// higher bits set, then we cannot form finalv - initial(which is (u + v) - u == v)
			// and no answer is possible

			vector<int> bitsI = bits(initial);
			vector<int> bitsF = bits(finalv);
			// if(bitsI.size() > bitsF.size()){
			// 	cout<<"NO"<<endl;
			// 	continue;
			// }
			int id = 0;
			bool isPos = true;
			for(int i=0;i<bitsF.size();i++){
				if(id < bitsI.size() && bitsF[i] >= bitsI[id]){
					id++;
				} else {
					isPos = false;
					break;
				}
			}
			if(isPos){
				cout<<"YES"<<endl;
			} else {
				cout<<"NO"<<endl;
			}
			
		}
	}
}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	// cin >> t;
	t = 1;

	while (t--)
	{
		solve();
	}
}
