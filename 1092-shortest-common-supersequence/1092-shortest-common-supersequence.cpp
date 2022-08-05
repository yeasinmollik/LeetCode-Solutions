class Solution {
public:
    int dp[1010][1010] = {};
    int n, m;
    
    string shortestCommonSupersequence(string str1, string str2) {
        n = str1.size(), m = str2.size();
		vector<int> is, it;
        findLCS(str1, str2, is, it);
		is.push_back(-1);
		it.push_back(-1);
		reverse(is.begin(), is.end());
		reverse(it.begin(), it.end());
		is.push_back(n);
		it.push_back(m);
		
		string ans;
		for(int i = 1; i < is.size(); i++){
			//cout << is[i] << " " << it[i] << endl;
			if(is[i-1] + 1 <= is[i] - 1)
				ans += str1.substr(is[i-1] + 1, is[i] - is[i-1] - 1);
			if(it[i-1] + 1 <= it[i] - 1)
				ans += str2.substr(it[i-1] + 1, it[i] - it[i-1] - 1);
			if(is[i] < n)
				ans.push_back(str1[is[i]]);
		}
		return ans;
    }
    
    void findLCS(string &s, string &t, vector<int> &is, vector<int> &it){
        for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(s[i-1] == t[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		
		int i = n, j = m;
		while(i > 0 && j > 0){
			if(s[i - 1] == t[j - 1]) 
				is.push_back(i-1), it.push_back(j - 1), i--, j--;
			else {
				if(dp[i-1][j] > dp[i][j-1])
					i = i - 1;
				else
					j = j - 1;
			}
		}
    }
};
