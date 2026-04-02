#ifndef GENERIC_QUEUE_H
#define GENERIC_QUEUE_H

template <typename T>
class Queue {
private:
    struct Node {
        T val;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    ~Queue() {
        while (!is_empty()) dequeue();
    }

    void enqueue(T val) {
        Node* temp = new Node();
        temp->val = val;
        temp->next = nullptr;
        if (tail == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void dequeue() {
        if (head == nullptr) return;
        Node* temp = head;
        if (head->next == nullptr) {
            head = nullptr;
            tail = nullptr;
            delete temp;
            return;
        }
        head = head->next;
        delete temp;
    }

    T front() const {
        return head->val;
    }

    bool is_empty() const {
        return head == nullptr;
    }
};

#endif