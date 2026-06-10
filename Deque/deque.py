class Deque:
    def __init__(self):
        self.cap=4
        self.size=0
        self.front=0
        self.data=[None]*self.cap
        
    def resize(self):
        self.cap*=2
        newData= [None]*self.cap
        
        for i in range(self.size):
            newData[i]= self.data[(i+self.cap)%self.cap]
            
        self.front=0
        
    def push_back(self, val):
        if self.size==self.cap:
            self.resize()
        rear= (self.front+self.size)%self.cap
        self.data[rear]= val
        
        self.size+=1
        
    def push_front(self, val):
        if self.size==self.cap:
            self.resize()
        self.front= (self.front-1+self.cap)%self.cap
        self.data[self.front]= val
        
        self.size+=1
        
    def pop_back(self):
        if self.empty():
            raise IndexError("Empty deque")
        rear= (self.front+self.size-1)%self.cap
        val= self.data[rear]
        self.data[rear]= None
        self.size-=1
        
        return val
    
    def pop_front(self):
        if self.empty():
            raise IndexError("Empty deque")
        self.front= (self.front-1)%self.cap
        val = self.data[self.front]
        self.data[self.front]= None
        self.size-=1
        
        return val
    
    def empty(self):
        return self.size==0
    
    
        
            