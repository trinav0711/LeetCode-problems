// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    int bs(unsigned int start, unsigned int end) {
        if(start>=end)
            return start;
        if(isBadVersion(start)) return start;
        unsigned int mid=(start+end)/2;
        if(isBadVersion(mid))
            return bs(start+1, mid);
        return bs(mid+1, end);
    }
public:
    int firstBadVersion(int n) {
        return bs(1, n);
    }
};