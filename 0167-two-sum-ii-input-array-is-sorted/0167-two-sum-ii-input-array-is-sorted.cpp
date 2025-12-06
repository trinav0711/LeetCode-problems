class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first=0, last=numbers.size()-1;
        # define sum numbers[first]+numbers[last]
        while(first<last){
            if(sum == target)
                break;
            else if(sum < target)
                first++;
            else
                last--;
        }
        return {first+1, last+1};
    }
};