class DetectSquares {
private:
    map<pair<int,int>, int> pts;
public:
    DetectSquares(): pts{} {}
    
    void add(vector<int> point) {
        ++pts[{point[0], point[1]}];
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x1 = point[0];
        int y1 = point[1];
        
        // Iterate through all stored points, treating them as the diagonal opposite (x2, y2)
        for (auto& [p, cnt] : pts) {
            int x2 = p.first;
            int y2 = p.second;
            
            // 1. Must have positive area (x1 != x2 or y1 != y2)
            // 2. Must form a square (width == height)
            if (x1 == x2 || abs(x1 - x2) != abs(y1 - y2)) {
                continue;
            }
            
            // Check if the other two corners exist
            if (pts.count({x1, y2}) && pts.count({x2, y1})) {
                // Multiply the frequencies of the three points
                ans += cnt * pts[{x1, y2}] * pts[{x2, y1}];
            }
        }
        
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */