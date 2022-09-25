class MyCircularQueue {
public:
    int size, l, r;
    vector<int> v;
    
    MyCircularQueue(int k) {
        size = k;
        l = 0;
        r = -1;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        v.push_back(value);
        r++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        l++;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return v[l];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return v[r];
    }
    
    bool isEmpty() {
        return l > r || v.empty();
    }
    
    bool isFull() {
        return r - l + 1 == size;
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