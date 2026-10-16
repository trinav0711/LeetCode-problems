class MyHashMap {
private:
    int arr1[500'000];
    int arr2[500'000];
public:
    MyHashMap() {
        for(int i=0;i<500'000;++i) {
            arr1[i]=arr2[i]=-1;
        }
    }
    
    void put(int key, int value) {
        if(key>=500'000)
            arr1[key%500'000]=value;
        else
            arr2[key]=value;
    }
    
    int get(int key) {
        if(key>=500'000)
            return arr1[key%500'000];
        return arr2[key]; 
    }
    
    void remove(int key) {
        if(key>=500'000)
            arr1[key%500'000]-1;
        else
           arr2[key]=-1; 
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */