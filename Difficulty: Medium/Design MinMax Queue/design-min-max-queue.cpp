class SpecialQueue {

  public:
    queue<int>q;
    deque<int>mini;
    deque<int>maxi;
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        while(!mini.empty() && mini.back()>x){
            mini.pop_back();
        }
        mini.push_back(x);
        
        while(!maxi.empty() && maxi.back()<x){
            maxi.pop_back();
        }
        maxi.push_back(x);
        
    }

    void dequeue() {
        // Remove element from the queue
        if(!q.empty()){
        int x=q.front();
        if(!mini.empty() && x==mini.front()) mini.pop_front();
        
        if(!maxi.empty() && x==maxi.front()) maxi.pop_front();
        q.pop();
        }
    }

    int getFront() {
        // Get front element
        if(!q.empty()){
        int x=q.front();
        return x;
        }
        return -1;
    }

    int getMin() {
        // Get minimum element
        return mini.empty() ? -1 : mini.front();
        
    }

    int getMax() {
        // Get maximum element
        return maxi.empty() ? -1 : maxi.front();
    }
};