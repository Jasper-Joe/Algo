//
//  main.cpp
//  regularExpressionMatching
//
//  Created by Jinglun Zhou on 2020/2/16.
//  Copyright © 2020 Jinglun Zhou. All rights reserved.
//

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=p.size();
        int n=s.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        if(p.size()>=2 && p[1]=='*'){
            dp[2][0]=true;
        }
        for(int i=2;i<m;i++){
            if(p[i]=='*'){
            //DP initialization, * can let us ignore the last element
            //sub-strings of p might match empty string
                dp[i+1][0]=dp[i-1][0];
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[i-1]==s[j-1] ||p[i-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                if(p[i-1]=='*'){
                    if(p[i-2]==s[j-1] || p[i-2]=='.'){
                        dp[i][j]=( dp[i-2][j-1] || dp[i][j-1] || dp[i-2][j]);
                        //dp[i-2][j-1] means we are not using *
                        //dp[i-2][j] means using * to ignore the last element
                        //dp[i][j-1] means using * to repeat the last element
                    }
                    else if(p[i-2]!=s[j-1]){
                        dp[i][j]=dp[i-2][j];
                    }
                }
            }
        }




        return dp[m][n];

    }
};
