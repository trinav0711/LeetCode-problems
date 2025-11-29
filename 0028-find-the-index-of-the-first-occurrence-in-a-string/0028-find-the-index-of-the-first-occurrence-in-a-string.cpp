class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> psum; psum.reserve(haystack.size());
        if(needle.size() > haystack.size()) return -1;
        int sum=0;
        for(int i=0;i<needle.size();i++)
            sum+=(int)(needle[i]-'a');
        psum.push_back((int)(haystack[0]-'a'));
        for(int i=1;i<haystack.size();i++)
            psum.push_back(psum[i-1]+(int)(haystack[i]-'a'));
        int idx=-1;
        for(int i=0;i<=haystack.size()-needle.size();i++){
            if(i==0 && psum[i+needle.size()-1]!=sum) continue;
            if(i && (psum[i+needle.size()-1]-psum[i-1])!=sum) continue;
            int j=0;
            for(j;j<needle.size();j++){
                if(haystack[i+j]!=needle[j]) break;
            }
            if(j>=needle.size()){
                idx=i; break;
            }
        }
        return idx;
    }
};