public class Solution {
    public int FirstUniqChar(string s) {
        int[] cnt = new int[26];
        foreach(char c in s){
            cnt[c - 'a']++;
        }
        for(int i = 0; i < s.Length; i++)
            if(cnt[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
}