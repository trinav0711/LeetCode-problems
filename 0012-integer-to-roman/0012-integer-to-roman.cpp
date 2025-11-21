class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> m;
        m[1000]="M";
        m[900]="CM";
        m[500]="D";
        m[400]="CD";
        m[100]="C";
        m[90]="XC";
        m[50]="L";
        m[40]="XL";
        m[10]="X";
        m[9]="IX";
        m[5]="V";
        m[4]="IV";
        m[1]="I";

        vector<int> arr={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string s="";
        while(num>0){
            auto itr=upper_bound(arr.begin(),arr.end(),num)-1;
            s=s+m[*itr];
            num=num-*itr;
        }
        return s;
    }
};