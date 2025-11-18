class RandomizedSet {
public:
    unordered_map<int,int> m1;
    unordered_map<int,int> m2;
    int total;

    RandomizedSet() {
        total=0;
    }
    
    bool insert(int val) {
        if(m1.find(val)!=m1.end())
            return false;
        m1[val]=total;
        m2[total++]=val;
        return true;
    }
    
    bool remove(int val) {
        if(m1.find(val)==m1.end())
            return false;
        int idx=m1[val];
        m1.erase(val);
        total--;
        if(idx!=total){
            m2[idx]=m2[total];
            m1[m2[idx]]=idx;
        }
        m2.erase(total);
        return true;
    }
    
    int getRandom() {
        return m2[rand()%total];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */