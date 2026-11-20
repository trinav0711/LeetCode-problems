class MyCircularQueue {
private:
    vector<int> v;
    int sz;
    int front, end;
public:
    MyCircularQueue(int k): sz{k}, front{0}, end{-1} {
        for(int i=0;i<k;++i)
            v.push_back(-1);
    }
    
    bool enQueue(int value) {
        if(end!=-1 && (end+1)%sz == front) return false;
        end=(end+1)%sz;
        v[end]=value;
        return true;
    }
    
    bool deQueue() {
        if(end==-1) return false;
        v[front]=-1;
        if(front==end) {
            end=-1;
            front=0;
        }
        else
            front=(front+1)%sz;
        return true;
    }
    
    int Front() {
        return end!=-1 && v[front]!=-1?v[front]:-1;
    }
    
    int Rear() {
        return end!=-1 && v[end]!=-1?v[end]:-1;
    }
    
    bool isEmpty() {
        return end==-1;
    }
    
    bool isFull() {
        return end!=-1 && (end+1)%sz == front;   
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */