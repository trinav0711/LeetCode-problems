class SnapshotArray {
private:
    unordered_map<int, map<int,int>> m;
    unordered_map<int,int> todo;
    int cur;
public:
    SnapshotArray(int length): todo{}, cur{0} {
        for(int i=0;i<length;++i) {
            m[i][-1]=0;
        }
    }
    
    void set(int index, int val) {
        todo[index]=val;
    }
    
    int snap() {
        for(auto& [idx,val]:todo) {
            m[idx][cur]=val;
        }
        ++cur;
        todo.clear();
        return cur-1;
    }
    
    int get(int index, int snap_id) {
        auto itr=m[index].upper_bound(snap_id);
        --itr;
        return itr->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */