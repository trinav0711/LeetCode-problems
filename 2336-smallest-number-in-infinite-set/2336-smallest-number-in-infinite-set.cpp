class SmallestInfiniteSet {
    set<int> s;
    int lowest;
public:
    SmallestInfiniteSet(): lowest(1), s{} {}
    
    int popSmallest() {
        if(s.empty())
            return lowest++;
        int tmp=*s.begin();
        s.erase(s.begin());
        return tmp;
    }
    
    void addBack(int num) {
        if(num>=lowest || s.find(num)!=s.end())
            return;
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */