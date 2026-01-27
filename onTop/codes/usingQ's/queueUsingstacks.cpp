// USING 1 STACK
class myQueue {
    stack<int>st1;
    
  public:
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        st1.push(x);
        // Implement enqueue operation
    }

    void dequeue() {
        if (st1.empty()) return;
        
        int temp = st1.top();
        st1.pop(); 
        
        if (st1.empty()) return;
        
        dequeue();
        
        st1.push(temp);
        // Implement dequeue operation
    }

    int front() {
       if (st1.empty()) return -1;
       
       int top = st1.top();
       st1.pop();
       
        if (st1.empty()) {
            // This is the front element
            st1.push(top);
            return top;
        }
        
       int res = front();
       
       st1.push(top);
       return res;
        // Implement front operation
    }

    int size() {
        return st1.size();
        // Implement size operation
    }
};



// USING 2 STACKS 
class myQueue {
    stack<int>st1;
    stack<int>st2;
  public:
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        st1.push(x);
        // Implement enqueue operation
    }

    void dequeue() {
        if (st1.empty() && st2.empty()) return;
        if(st2.empty()){
            while(!st1.empty()){
            st2.push(st1.top());  st1.pop();
            }
        }
        st2.pop(); 
        // Implement dequeue operation
    }

    int front() {
        if (st1.empty() && st2.empty()) return -1;

        if(st2.empty()){
            while(!st1.empty()){
            st2.push(st1.top());  st1.pop();
            }
        }
        return st2.top(); 
        // Implement front operation
    }

    int size() {
        return st1.size()+st2.size();
        // Implement size operation
    }
};
