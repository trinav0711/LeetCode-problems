class Solution {
public:
    bool isHappy(int n) {
        set<int> m;
        while(n!=1 && m.find(n)==m.end()){
            m.insert(n);
            int sum=0;
            while(n){
                sum+=((n%10)*(n%10));
                n/=10;
            }
            n=sum;
        }
        return n==1;
    }
};