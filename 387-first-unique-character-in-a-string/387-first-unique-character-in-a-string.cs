public class Solution {
    public int FirstUniqChar(string s) {
        Dictionary<char, int> cnt = new Dictionary<char, int>();
        foreach(char c in s){
            if(cnt.ContainsKey(c))
                cnt[c]++;
            else
                cnt[c] = 1;
        }
        for(int i = 0; i < s.Length; i++)
            if(cnt[s[i]] == 1)
                return i;
        return -1;
    }
}