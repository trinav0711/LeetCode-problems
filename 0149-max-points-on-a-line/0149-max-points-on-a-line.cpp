class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2)
            return points.size();
        int ctr=0;
        for(int i=0;i<points.size();i++) {
            for(int j=i+1;j<points.size();j++) {
                double m;
                if(points[j][0]!=points[i][0])
                    m=double(points[j][1]-points[i][1])/double(points[j][0]-points[i][0]);
                int ctrtmp=2;
                cout<<"m="<<m<<endl;
                for(int k=0;k<points.size();k++) {
                    if(k==i || k==j)
                        continue;
                    if(points[i][0]==points[j][0]) {
                        if(points[k][0]==points[i][0])
                            ctrtmp++;
                    }
                    else if(double(points[k][1]-points[i][1])/double(points[k][0]-points[i][0])==m)
                        ctrtmp++;
                }
                ctr=max(ctr, ctrtmp);
            }
        }
        return ctr;
    }
};