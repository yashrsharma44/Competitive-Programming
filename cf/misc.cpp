int ans = 0, rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> horizontalSubMatrices = vector<vector<int>>(rows,vector<int>(cols,0));
    for(int i=0; i<rows;++i){
        for(int j=cols-1; j>=0; --j){
            if(matrix[i][j] == 0)
                continue;
            if(j != cols-1)
                horizontalSubMatrices[i][j] += horizontalSubMatrices[i][j+1];
            horizontalSubMatrices[i][j] += matrix[i][j];            
        }
    }
    
    for(int j=0; j<cols; ++j){
        int i=rows-1;
        stack<pair<int,int>> s;
        int runningSum = 0;
        while(i >= 0){
            int c = 0;
            while(!s.empty() && s.top().first > horizontalSubMatrices[i][j]){
                runningSum -= ((s.top().second+1)*(s.top().first - horizontalSubMatrices[i][j]));
                c += s.top().second+1;
                s.pop();
            }
            runningSum += horizontalSubMatrices[i][j];
            ans += runningSum;
            s.push(make_pair(horizontalSubMatrices[i][j],c));
            --i;
        }
    }
    return ans;