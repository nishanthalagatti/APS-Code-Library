ll binomialCoeffDP(int n, int r, vector<vector<ll> &dp)
    {
        if(r>n) return 0;
        if(r==0 or r==n) return 1;
        
        for(int i=0; i<=r; i++)
            dp[0][i] = 0;
            
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
            
        for(int i=1; i<=n; i++){
            for(int j=1; j<=r; j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
        
        return dp[n][r];
    }

ll binomialCoeffNthRow(int n, int k)
{
    ll C[k + 1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1; // nC0 is 1
 
    for (int i = 1; i <= n; i++) {
        // Compute next row of pascal triangle using
        // the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}
