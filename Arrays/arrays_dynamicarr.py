#Dynamic Array
class DynamicArray:
    def __init__(self):
        self.capacity= 2
        self.size= 0
        self.data= [None]*self.capacity
        
    def resize(self):
        self.capacity*= 2
        
        new_data= [None]* self.capacity
        
        
        for i in range(self.size):
            new_data[i]= self.data[i]
            
        self.data= new_data
        
    def push_back(self, value):
        if self.size==self.capacity:
            self.resize()
            
        self.data[self.size]= value
        self.size+= 1
        
    def pop_back(self):
        if self.size==0:
            raise IndexError("Array is empty")
        
        value= self.data[self.size-1]
        
        self.data[self.size-1]= None
        self.size-=1
        
        return value
    
    def get(self, index):
        if index<0 or index>=self.size:
            raise IndexError("Index out of bounds")
        
        return self.data[index]
    
    def set(self, index, value):
        if index<0 or index>=self.size:
            raise IndexError("Index out of bounds")
        
        self.data[index]= value
        
        
# Circular Buffer
class CircularBuffer:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size=0
        self.head=0
        self.tail=0
        self.data= [None]*self.capacity
        
    def empty(self):
        return self.size==0
    
    def full(self):
        return self.size==self.capacity
    
    def push_back(self,value):
        if self.full():
            raise OverflowError("Buffer full")
        
        self.data[self.tail]= value
        self.tail= (self.tail+1)%self.capacity
        
        self.size+=1
        
    def pop_front(self):
        if self.empty():
            raise IndexError("Buffer is empty")
        
        self.head= (self.head+1)% self.capacity
        self.size-=1
        
    def front(self):
        if self.empty():
            raise IndexError("Buffer is Empty")
        
        return self.data[self.head]