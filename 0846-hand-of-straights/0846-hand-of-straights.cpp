class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(groupSize==1) return true;
        if(hand.size() % groupSize) return false;
        multiset<int> s;
        for(int x:hand)
            s.insert(x);
        while(!s.empty()) {
            int low=*s.begin();
            for (int i=1;i<groupSize;++i) {
                if(s.find(low+i)==s.end())
                    return false;
            }
            for(int i=1;i<groupSize;++i)
                s.erase(s.find(i+low));
            s.erase(s.begin());
        }
        return true;
    }
};