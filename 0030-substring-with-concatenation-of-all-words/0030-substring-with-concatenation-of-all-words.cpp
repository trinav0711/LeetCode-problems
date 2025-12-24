class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = words[0].length();
        int start=0, end=words.size()*n;
        unordered_map<string, int> wordm;
        for(string tmp:words){
            if(wordm.find(tmp)==wordm.end())
                wordm[tmp]=1;
            else
                wordm[tmp]++;
        }
        if(wordm.size()==1 && wordm.find("a")!=wordm.end() && count(s.begin(),s.end(),'a')==s.length()){
            if(words.size()>s.length())
                return ans;
            for(int i=0;i<=s.length()-words.size();i++)
                ans.push_back(i);
            return ans;
        }
        while(end<=s.length()){
            unordered_map<string, int> m(wordm);
            int curstart=start;
            for(start;start<end;start+=n){
                if(m.find(s.substr(start,n))!=m.end()){
                    m[s.substr(start,n)]--;
                    if(m[s.substr(start,n)]==0)
                        m.erase(s.substr(start,n));
                }
                else
                    break;
            }
            if(start>=end)
                ans.push_back(curstart);
            start=curstart+1;
            end=start+words.size()*n;
        }
        return ans;
    }
};