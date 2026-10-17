class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size()<=1) return true;
        int arr[26];
        for(int i=0;i<26;++i)
            arr[order[i]-'a']=i;
        for(int i=1;i<words.size();++i) {
            int j;
            for(j=0;j<min(words[i].length(), words[i-1].length());++j) {
                if(arr[words[i][j]-'a'] > arr[words[i-1][j]-'a'])
                    break;
                if(arr[words[i][j]-'a'] < arr[words[i-1][j]-'a'])
                    return false;
            }
            if(j>=min(words[i].length(), words[i-1].length()) && words[i].length()<words[i-1].length())
                return false;
        }
        return true;
    }
};