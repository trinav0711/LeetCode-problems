class Solution {
    map<pair<double, int>, double> m;
public:
    double myPow(double x, int n) {
        cout<<"x="<<x<<" and n="<<n<<"\n";
        if(x==0)
            return 0;
        if(x==1)
            return 1;
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n<0) {
            if(n%2)
                return 1/x*1/myPow(x,abs(n/2))*1/myPow(x,abs(n/2));
            else
                return 1/myPow(x,abs(n/2))*1/myPow(x,abs(n/2));
        }
        if(m.find({x, n})!=m.end())
            return m[{x,n}];
        if(n%2)
            m[{x,n}]=myPow(x, n/2)*myPow(x, n/2)*x;
        else
            m[{x,n}]=myPow(x, n/2)*myPow(x, n/2);
        return m[{x,n}];
    }
};