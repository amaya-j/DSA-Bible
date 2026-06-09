//Singly LL

template <typename T>
class LinkedList {
private:

    struct Node {
        T data;
        Node* next;

        Node(const T& value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    int sz;

public:

    // Constructor
    LinkedList() {
        head = nullptr;
        sz = 0;
    }

    // Destructor
    ~LinkedList() {
        Node* curr = head;

        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    // Push Front
    void push_front(const T& value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        sz++;
    }

    // Push Back
    void push_back(const T& value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            sz++;
            return;
        }

        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;

        sz++;
    }

    // Pop Front
    void pop_front() {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        Node* temp = head;

        head = head->next;

        delete temp;

        sz--;
    }

    // Size
    int size() {
        return sz;
    }

    // Empty
    bool empty() {
        return sz == 0;
    }
};


//Doubly LL
template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) {
            data = value;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int sz;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    ~DoublyLinkedList() {
        Node* curr = head;

        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        sz++;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        sz++;
    }

    void pop_front() {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        sz--;
    }

    void pop_back() {
        if (tail == nullptr) {
            throw std::out_of_range("List is empty");
        }

        Node* temp = tail;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        sz--;
    }

    int size() const {
        return sz;
    }

    bool empty() const {
        return sz == 0;
    }
};
