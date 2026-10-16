class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> rec;
        for(const auto& str:operations) {
            if(str=="C")
                rec.pop_back();
            else if(str=="D")
                rec.push_back(2*rec.back());
            else if(str=="+" && rec.size()>1) {
                int tmp=rec[rec.size()-2];
                rec.push_back(rec.back()+tmp);
            }
            else {
                rec.push_back(stoi(str));
            }
        }
        int sum=0;
        while(!rec.empty()) {
            sum+=rec.back(); rec.pop_back();
        }
        return sum;
    }
};