class myStack {
  public:
    int * arr;
    int r;
    int n;
    myStack(int n) {
        arr = new int[n];
        r=0; this->n=n;
        // Define Data Structures
    }
    
    bool isEmpty() {
        if(r==0) return true;
        return false;
        // check if the stack is empty
    }

    bool isFull() {
        if(r==n) return true;
        return false;
        // check if the stack is full
    }

    void push(int x) {
        if(isFull()){
            return ;
        }
        arr[r++]=x;
        // inserts x at the top of the stack
    }

    void pop() {
        if(isEmpty()){
            return ;
        }
        arr[r--]=-1;
        // removes an element from the top of the stack
    }

    int peek() {
        if(isEmpty()){
            return -1;
        }
        return arr[r-1];
        // Returns the top element of the stack
    }
};