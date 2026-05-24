class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i=sqrt(area);
        while(i) {
            if(area%i==0)
                return {area/i, i};
            --i;
        }
        return {area, 1};
    }
};