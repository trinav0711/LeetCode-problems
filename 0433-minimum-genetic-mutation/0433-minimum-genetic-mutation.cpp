class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene==endGene)
            return 1;
        unordered_set<string> visit;
        for(string str:bank)
            visit.insert(str);
        if(visit.find(endGene)==visit.end())
            return -1;
        queue<string> q;
        q.push(startGene);
        int steps=0;
        vector mute{'A', 'C', 'G', 'T'};
        while(!q.empty()) {
            ++steps;
            int s=q.size();
            auto str=q.front();
            for(int i=0;i<s;++i) {
                for(int idx=0;idx<8;++idx) {
                    for(char c:mute) {
                        if(c==str[idx])
                            continue;
                        char tmp=str[idx];
                        str[idx]=c;
                        if(str==endGene)
                            return steps;
                        if(visit.find(str)!=visit.end()) {
                            visit.erase(str);
                            q.push(str);
                        }
                        str[idx]=tmp;
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};