#Singly LL
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None
        self.size = 0

    # Push Front
    def push_front(self, value):

        new_node = Node(value)

        new_node.next = self.head

        self.head = new_node

        self.size += 1

    # Push Back
    def push_back(self, value):

        new_node = Node(value)

        if self.head is None:
            self.head = new_node
            self.size += 1
            return

        curr = self.head

        while curr.next:
            curr = curr.next

        curr.next = new_node

        self.size += 1

    # Pop Front
    def pop_front(self):

        if self.head is None:
            raise Exception("List is empty")

        self.head = self.head.next

        self.size -= 1


#Doubly LL
class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def push_front(self, value):
        new_node = Node(value)

        if self.head is None:
            self.head = self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

        self.size += 1

    def push_back(self, value):
        new_node = Node(value)

        if self.tail is None:
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node

        self.size += 1

    def pop_front(self):
        if self.head is None:
            raise Exception("List is empty")

        value = self.head.data

        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None

        self.size -= 1
        return value

    def pop_back(self):
        if self.tail is None:
            raise Exception("List is empty")

        value = self.tail.data

        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None

        self.size -= 1
        return value