#include <bits/stdc++.h>
#define int long long 

using namespace std;

pair<int,int> get(vector< vector<int> > &mat){

	int dr[4] = {-1, 1, 0, 0};
	int dc[4] = {0, 0, -1, 1};

	int n = mat.size(), m = mat[0].size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

			bool isPos = true;
			if(mat[i][j] == 0){

				for(int k=0;k<n;k++){
					
					if(mat[k][j] == 1){
						isPos = false;
						break;
					}

				}

				for(int k=0;k<m;k++){
					if(mat[i][k] == 1){
						isPos = false;
						break;
					}
				}

				if(isPos){
					return make_pair(i,j);
				}

			}
			

		}
	}

	return make_pair(-1,-1);

}

void solve(){

	int n,m;
	cin>>n>>m;
	vector< vector<int> >mat(n,vector<int>(m, 0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a;
			cin>>a;
			mat[i][j] = a;
		}
	}

	int i = 0;
	while(true){

		pair<int,int> pos = get(mat);
		if(pos.first == -1 && pos.second == -1){
			break;
		}
		i+=1;
		mat[pos.first][pos.second] = 1;
	}

	if(i%2 == 1){
		cout<<"Ashish"<<endl;
	} else {
		cout<<"Vivek"<<endl;
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
