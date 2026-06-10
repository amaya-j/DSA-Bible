template <typename T>
class Deque
{
    private:
        T* data;
        int cap;
        int size;
        int front;

        void resize()
        {
            cap*=2;
            T* newData= new T[cap];

            for (int i=0; i<size; i++)
            {
                newData[i]= data[(front+i)%cap];
            }

            delete[] data;
            data= newData;

            front= 0;
        }

    public:
        Deque()
        {
            cap= 4;
            size=0;
            data= new T[cap];
            frot=0;
        }

        ~Deque()
        {
            delete[] data;
        }

        void push_back(const T& val)
        {
            if (size==cap)
            {
                resize();
            }
            int rear= (front+size)%cap;
            data[rear]= val;
            size++;
        }

        void push_front(const T& val)
        {
            if (size==cap)
            {
                resize();
            }
            front= (front-1+cap)%cap;
            data[front]= val;
            size++;
        }

        T pop_back()
        {
            if (empty())
            {
                throw std::index_error("Empty queue")
            }
            int rear= (front+size-1)%cap;
            T val= data[rear];
            size--;

            return val;
        }

        T pop_front()
        {
            if (empty())
            {
                throw std::index_error("Empty queue")
            }
            front= (front+1)%cap;
            T val= data[front];
            size--;

            return val;
        }

        bool empty()
        {
            return (size==0);
        }

};