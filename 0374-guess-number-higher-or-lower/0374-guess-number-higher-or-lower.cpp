/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
private:
    int find(uint64_t low, uint64_t high) {
        if(!guess(low))
            return low;
        if(!guess(high))
            return high;
        uint64_t mid=(low+high)/2;
        uint64_t tmp=guess(mid);
        if(!tmp)
            return mid;
        if(tmp==1)
            return find(mid+1, high);
        return find(low, mid);
    }
public:
    int guessNumber(int n) {
        return find(1, n);
    }
};