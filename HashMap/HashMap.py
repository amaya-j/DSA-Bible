class Node:
    def __init__(self, key, val):
        self.key=key
        self.val=val
        self.next= None
        
class HashMap:
    def __init__(self, capacity=8):
        self.cap= capacity
        self.size=0
        self.buckets= [None]*self.cap
        
    def _hash(self, key):
        return hash(key)%self.cap
    
    def put(self,key,val):
        idx= self._hash(key)
        
        head= self.buckets[idx]
        
        curr=head
        
        while curr:
            if curr.key==key:
                curr.val= val
                return
            curr= curr.next
            
        new_node= Node(key, val)
        
        new_node.next= head
        self.buckets[idx]= new_node
        self.size+=1
        
    def get(self,key, res):
        idx= self.hashKey(key)
        curr= self.buckets[idx]
        
        while curr:
            if curr.key==key:
                res= curr.val
                return True
            curr= curr.next
        return False
    
    def remove(self, key, val):
        idx= self.hashKey(key)
        curr= self.buckets[idx]
        prev= None
        
        while curr:
            if curr.key==key:
                if prev:
                    prev.next=curr.next
                else:
                    self.buckets[idx]= curr.next
                
                self.size-=1
                return
            
            prev= curr
            curr= curr.next
            
    def loadFactor(self):
        return self.size/self.cap