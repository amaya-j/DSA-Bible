template <typename T>
class Stack
{
    private:
        T* data;
        int cap;
        int count;
    
        void resize()
        {
            int cap= cap*2;
            T* newData= new T[cap];

            for (int i=0; i<count; i++)
            {
                newData[i]= data[i];
            }

            delete[] data;
            data= newData;
        }
    public:
        Stack()
        {
            cap= 4;
            count=0;
            data= new T[cap];
        }

        ~Stack()
        {
            delete[] data;
        }

        void push(const T& val)
        {
            if (count==cap)
            {
                resize();
            }
            data[count]= value;
            count++;
        }

        void pop()
        {
            if (count==0)
            {
                throw std::runtime_error("Empty Stack");
            }
            count--;
        }

        T& top()
        {
            if (count==0)
            {
                throw std::runtime_error("Empty Stack");
            } 
            return data[count-1];
        }

        bool empty()
        {
            return (count==0);
        }

};
