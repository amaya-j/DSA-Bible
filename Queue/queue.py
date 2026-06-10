# Basically a circular dynamic array

class Queue:
    def __init__(self):
        self.capacity = 4
        self.data = [None] * self.capacity

        self.front_idx = 0
        self.rear_idx = 0
        self.size = 0

    def resize(self):
        new_capacity = self.capacity * 2
        new_data = [None] * new_capacity

        for i in range(self.size):
            new_data[i] = self.data[(self.front_idx + i) % self.capacity]

        self.data = new_data
        self.capacity = new_capacity

        self.front_idx = 0
        self.rear_idx = self.size

    def enqueue(self, value):
        if self.size == self.capacity:
            self.resize()

        self.data[self.rear_idx] = value

        self.rear_idx = (self.rear_idx + 1) % self.capacity
        self.size += 1

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Queue is empty")

        value = self.data[self.front_idx]

        self.data[self.front_idx] = None

        self.front_idx = (self.front_idx + 1) % self.capacity
        self.size -= 1

        return value

    def front(self):
        if self.is_empty():
            raise IndexError("Queue is empty")

        return self.data[self.front_idx]

    def is_empty(self):
        return self.size == 0

    def get_size(self):
        return self.size