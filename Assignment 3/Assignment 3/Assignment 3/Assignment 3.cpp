#include <iostream>
#include <vector>
using namespace std;

template <typename   T>
class Queue {
private:
    vector<T> data;
    int frontIdx;  // front element index
    int rearIdx;   // rear element index
    int currSize;  // the current size
    int capacity;  // max

public:
    // constructor, to make a vector and such
    Queue(int cap) : capacity(cap), frontIdx(0), rearIdx(0), currSize(0) {
        data.resize(capacity);
    }

    // element is pushed into queue, prototype without menu. Checks if full too incase
    void push(T value) {
        if (currSize == capacity) {
            cout << "Queue at max capacity." << endl;
            return;
        }
        data[rearIdx] = value;
        rearIdx = (rearIdx + 1) % capacity;
        currSize++;
    }

    // pops element and checks if empty
    void pop() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        frontIdx = (frontIdx + 1) % capacity;
        currSize--;
    }

    // front element is returned
    T front() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return T(); 
        }
        return data[frontIdx];
    }

    // returns current size of the queue
    int size() {
        return currSize;
    }

    // return if current size is empty
    bool empty() {
        return currSize == 0;
    }

    // the command to move the front to the rear
    void move_to_rear() {
        if (empty() || currSize == 1) {
            return;  // checks if empty or 1, as either option would not require it to be moved
        }
        T frontElement = front();  // temporary front element
        pop();  // pops the front element
        push(frontElement);  // push temp into the back
    }

    // command to display queue, or report empty if empty
    void display() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int idx = frontIdx;
        for (int i = 0; i < currSize; ++i) {
            cout << data[idx] << " ";
            idx = (idx + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    // makes Queue into int and also 10 integers to put in
    Queue<int> q(10);

    // fluff added to those 10 spots
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    // elements are displayed
    cout << "Elements in Queue: ";
    q.display();

    // calls to move front element to back
    q.move_to_rear();

    // displaying the results after moving to rear
    cout << "Elements after front has been moved to rear: ";
    q.display();

    return 0;
}

