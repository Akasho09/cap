class myQueue {
    vector<int> v;
    int front, rear, n;

public:
    myQueue(int n) {
        v.assign(n, -1);
        front = 0;
        rear = 0;
        this->n = n;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % n == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        v[rear] = x;
        rear = (rear + 1) % n;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        v[front] = -1;
        front = (front + 1) % n;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return v[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return v[(rear - 1 + n) % n];
    }
};
