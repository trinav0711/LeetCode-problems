class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        bool carry=0;
        string ans="";
        for(int i=0;i<max(a.length(), b.length())||carry; i++){
            bool a1= (i<a.length()&&a[i]=='1');
            bool b1= (i<b.length()&&b[i]=='1');
            ans+=(a1^b1^carry?"1":"0");
            int ctr=0;
            if(a1)
                ctr++;
            if(b1)
                ctr++;
            if(carry)
                ctr++;
            carry=ctr>=2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};