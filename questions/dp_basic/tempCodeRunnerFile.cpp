if(dp[i][k]==-1)
            left = pali_part(s,i,k);
        else left = dp[i][j];
        if(dp[k+1][j]==-1)
            right = pali_part(s,k+1,j);
        else right = dp[i][j];
        int ans = left +right +1;