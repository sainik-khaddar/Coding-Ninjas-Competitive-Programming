/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input: s = "acdcb", p = "a*c?b"
Output: false
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

*/



class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        bool** dp = new bool*[m+1];
        for(int i=0;i<=m;i++){
            dp[i] = new bool[n+1];
            for(int j=0;j<=n;j++){
                dp[i][j] = false;
            }
        }
        
        dp[0][0] = true;
        
        for(int i=1;i<=n;i++){
            if(p[i-1] == '*'){
                dp[0][i] = dp[0][i-1];
            }
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == p[j-1]){ //check prev in str and pattern
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] == '*'){ // 1. '*' as null dp[i][j-1]   2. '*' as non empty string check for prev string and pattern match with '*' occurances (not dp[i-1][j-1] which shows '*' can be used only once)
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }else if(p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        
        return dp[m][n];
    }
};
