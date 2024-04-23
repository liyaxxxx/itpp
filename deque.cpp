#include <iostream>
using namespace std;

template <class type>
struct deque {
    struct node {
        type data;
        node* next;
        node* prev;
    };

    node* front;
    node* back;

    deque() {
        front = back = nullptr;
    }

    void pop_front() {
        if (front == nullptr) {
            return;
        }

        node* p = front;
        front = front -> next;

        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            back = nullptr;
        }

        delete p;
    }

    void push_back(type x) {
        node* p = new node;
        p->data = x;
        p->next = nullptr;
        p->prev = back;

        if (back != nullptr) {
            back -> next = p;
        }

        back = p;

        if (front == nullptr) {
            front = p;
        }
    }

    type front_value() {
        return front->data;
    }

    type back_value() {
        return back->data;
    }

    bool empty() {
        return (front == nullptr);
    }
};

int main() {
    deque<int> dq;
    dq.push_back(3);
    cout << dq.front_value() << endl;
    cout << dq.back_value() << endl;
    dq.pop_front();
    dq.push_back(5);
    cout << dq.front_value() << endl;
    cout << dq.back_value() << endl;
    dq.pop_front();
    cout << dq.empty() << endl;
    return 0;
}
