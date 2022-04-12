ll Catalan(int n)
    {
        ll dp[n+1];
        dp[0]=1;
        
        for(int i = 1;i < n+1 ; ++ i) 
            dp[i] = (((2*i)*(2*i-1)*dp[i-1])/(i*(i+1))); 

        return dp[n];
    }

ll Catalan(int n) 
    {
        //code here
        ll catalan[n+1];
        catalan[0] = 1;
        catalan[1] = 1;
        
        for(int i=2; i<=n; i++){
            catalan[i]=0;
            for(int j=0; j<i; j++)
                catalan[i] += catalan[j]*catalan[i-j-1];
        }
        
        // for(int i=0; i<=n; i++)
        //     cout<<catalan[i]<<" ";
        
        return catalan[n];
    }
