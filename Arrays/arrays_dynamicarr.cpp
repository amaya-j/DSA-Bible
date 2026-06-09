/* 
Dynamic Array Implementation

APIs: Constructor, Destructor, Copy Constructor, Assginment Operator, push_back, pop_back(), get, [], set, size, empty
*/

template <typename T>
class DynamicArray
{
    private:
        T* data;
        int size;
        int cap;

        void resize()
        {
            int cap= cap*2;

            T* newData= new T[cap];

            for (int i=0; i<size; i++)
            {
                newData[i]= data[i];
            }

            delete[] data;
            data= newData;
        }

    public:

        DynamicArray()
        {
            cap=2;
            size=0;
            data= new T[cap];
        }

        ~DynamicArray()
        {
            delete[] data;
        }

        DynamicArray(const DynamicArray& other)
        {
            if (this==&other) return *this;
            
            delete[] data;

            size= other.size;
            cap= other.cap;
            data= new T[cap];

            for (int i=0; i<size; i++)
            {
                data[i]= other.data[i];
            }

            return *this;
        }

        void push_back(const T& val)
        {
            if (size==cap) resize();

            data[size]= value;
            size++;
        }

        void pop_back()
        {
            if (size==0) throw std::out_of_range("Empty Arr");

            size--;
        }

        T get(int index) const
        {
            if (index<0 || index>size)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        void set(int index, const T& val)
        {
            if (inedx<0 || index>size)
            {
                throw std::out_of_range("Index out of range");
            }

            data[index]= value;
        }

        bool empty() const
        {
            return size==0;
        }

        T& operator[](int index)
        {
            if (index<0 || index>=size)
            {
                throw std::out_of_range("Index out of bounds")
            }
            return data[index];
        }


};





/*
Circular Buffer

API: pop_front, push_back, empty, full, size, capacity, front
*/

template <typename T>
class CircularBuffer
{
    private:
        T* data;
        int cap;
        int size;
        int head;
        int tail;

    public:
        CircularBuffer(int capacity)
        {
            cap= capacity;
            size= 0;
            data= new T[cap];
            head= 0;
            tail= 0;
        }

        ~CircularBuffer()
        {
            delete[] data;
        }

        bool empty() const
        {
            return size==0;
        }

        bool full() const
        {
            return size==cap;
        }
        
        // [1], h=0, t=1 [1,2,3,4], t=0
        void push_back(const T& value)
        {
            if (full())
            {
                throw std::overflow_error("full");
            }
            data[tail]= value;
            tail= (tail+1)%cap;

            size++;
        }

        // [1,2,3,4], h=0, t=0, h=1
        void pop_front()
        {
            if (empty())
            {
                throw std::underflow_error("Buffer is empty");
            }
            head= (head+1)%cap;

            size--;
        }

        T front() const
        {
            if (empty())
            {
                throw std::underflow_error("Buffer is empty");
            }
            return data[head];
        }
};