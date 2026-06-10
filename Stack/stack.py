class Stack:
    def __init__(self):
        self.cap=4
        self.count=0
        self.data= [None]*self.cap
        
    def resize(self):
        self.cap*=2
        newData= [None]*self.cap
        for i in range (self.count):
            newData[i]= self.data[i]
            
        self.data= newData
        
    def push(self, val):
        if self.cap==self.count:
            self.resize()
        self.data[self.count]= val
        self.count+=1
        
    def pop(self):
        if self.empty():
            raise IndexError("Empty Stack")
        
        val= self.data[self.count-1]
        self.data[self.count-1]= None
        
        return val
    
    def top(self):
        if self.empty():
            raise IndexError("Empty Stack")
        
        return self.data[self.count-1]
    
    def empty(self):
        return (self.count==0)