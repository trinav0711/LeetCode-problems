class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string tmp;
        if(str1.length()<str2.length())
            swap(str1, str2);
        while(!str2.empty()) {
            int idx=str1.find(str2);
            if(idx==std::string::npos || idx>0)
                return "";
            tmp=str1;
            str1=str2;
            str2=tmp.substr(idx+str2.length(), tmp.length()-str2.length());
            if(str1.length()<str2.length())
                swap(str1, str2);
            cout<<"str1="<<str1<<" and str2="<<str2<<endl;
        }
        return str1;
    }
};