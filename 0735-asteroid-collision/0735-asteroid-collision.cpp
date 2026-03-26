class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i:asteroids) {
            bool loop=false;
            while(!st.empty() && i<0 && st.top()>0) {
                if(-i>st.top())
                    st.pop();
                else {
                    if(-i==st.top())
                        st.pop();
                    loop=true;
                    break;
                }
            }
            if(!loop)
                st.push(i);
        }
        asteroids.clear();
        while(!st.empty()) {
            asteroids.push_back(st.top());
            st.pop();
        }
        reverse(asteroids.begin(), asteroids.end());
        return asteroids;
    }
};