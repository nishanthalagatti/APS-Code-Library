// get ith row of pascal triangle
vector<int> getRow(int rowIndex) {
        
        vector<int> pascal(rowIndex+1,0);
        pascal[0]=1;
        
        for(int i=1; i<=rowIndex; i++)
            for(int j=i; j>0; j--)
                pascal[j] = pascal[j] + pascal[j-1];
        
        return pascal;
}

// get whole pascal triangle till nth row

vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> pascal(numRows);

        for(int i=0; i<numRows; i++){
            for(int j=0; j<=i; j++)
                pascal[i].push_back(0);
            //cout<<pascal[i].size();
        }
        
        for(int i=0; i<numRows; i++){
            for(int j=0; j<=i; j++){
                if(j==0 || j==i)
                    pascal[i][j] = 1;
                else
                    pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
