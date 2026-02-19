class Solution {
private:
    int findRow(vector<vector<int>>& m, int t, int s, int e) {
        if(t==m[s][0])
            return s;
        if(t>=m[e][0])
            return e;
        if(s>=e)
            return s;
        int mid=(s+e)/2;
        if(t==m[mid][0])
            return mid;
        if(t>m[mid][0])
            return findRow(m, t, mid, e-1);
        return findRow(m, t, s, mid-1);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target<matrix[0][0] || target>matrix[matrix.size()-1][matrix[0].size()-1])
            return false;
        auto& row=matrix[findRow(matrix, target, 0, matrix.size()-1)];
        auto itr=lower_bound(row.begin(), row.end(), target);
        if(itr==row.end())
            return false;
        return *itr==target;
    }
};