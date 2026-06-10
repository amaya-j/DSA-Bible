template <typename T>
class Queue {
private:
    T* data;

    int capacity;
    int size;

    int frontIdx;
    int rearIdx;

    void resize() {
        int newCapacity = capacity * 2;

        T* newData = new T[newCapacity];

        // Copy elements in correct logical order
        for (int i = 0; i < size; i++) {
            newData[i] = data[(frontIdx + i) % capacity];
        }

        delete[] data;

        data = newData;
        capacity = newCapacity;

        frontIdx = 0;
        rearIdx = size;
    }

public:
    Queue() {
        capacity = 4;
        size = 0;

        data = new T[capacity];

        frontIdx = 0;
        rearIdx = 0;
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(const T& value) {
        if (size == capacity) {
            resize();
        }

        data[rearIdx] = value;

        rearIdx = (rearIdx + 1) % capacity;

        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }

        T value = data[frontIdx];

        frontIdx = (frontIdx + 1) % capacity;

        size--;

        return value;
    }

    T& front() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }

        return data[frontIdx];
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }
};
