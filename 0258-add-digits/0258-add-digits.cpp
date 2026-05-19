class Solution {
public:
    int addDigits(int num) {
        if(!num) return num;
        vector<int> v;
        while(num) {
            v.push_back(num%10);
            num/=10;
        }
        while(v.size()>1) {
            num=0;
            while(!v.empty()) {
                num+=v.back();
                v.pop_back();
            }
            while(num) {
                v.push_back(num%10);
                num/=10;
            }
        }
        return v.back();
    }
};