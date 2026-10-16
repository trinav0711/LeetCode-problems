class MyHashSet {
private:
    int arr1[500'000];
    int arr2[500'000];
public:
    MyHashSet() {
        for(int i=0;i<sizeof(arr1)/sizeof(int);++i) {
            arr1[i]=false;
            arr2[i]=false;
        }
    }
    
    void add(int key) {
        if(key>500'000)
            arr2[key%500'000]=true;
        else
            arr1[key%500'000]=true;
    }
    
    void remove(int key) {
        if(key>500'000)
            arr2[key%500'000]=false;
        else
            arr1[key%500'000]=false;
    }
    
    bool contains(int key) {
        if(key>500'000)
            return arr2[key%500'000];
        return arr1[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */