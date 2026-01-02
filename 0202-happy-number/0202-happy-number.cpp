class Solution {
public:
    bool isHappy(int n) {
        int ctr=0;
        while(n!=1 && ctr<10){
            ctr++;
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