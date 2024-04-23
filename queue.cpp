#include <iostream>
using namespace std;

template <class type>
struct queue {
    struct node {
        type data;
        node* next;
        node* prev;
    };

    node* front;
    node* back;

    queue() {
        front = back = nullptr;
    }

    void push_front(type x) {
        node* p = new node;
        p->data = x;
        p->next = front;
        p->prev = nullptr;

        if (front != nullptr) {
            front->prev = p;
        }

        front = p;

        if (back == nullptr) {
            back = p;
        }
    }

    void pop_front() {
        if (front == nullptr) {
            return;
        }

        node* p = front;
        front = front->next;

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
            back->next = p;
        }

        back = p;

        if (front == nullptr) {
            front = p;
        }
    }

    void pop_back() {
        if (back == nullptr) {
            return;
        }

        node* p = back;
        back = back->prev;

        if (back != nullptr) {
            back->next = nullptr;
        } else {
            front = nullptr;
        }

        delete p;
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
    queue<int> q;
    q.push_front(3);
    cout << q.front_value() << endl;
    cout << q.back_value() << endl;
    q.pop_front();
    q.push_back(55);
    cout << q.front_value() << endl;
    cout << q.back_value() << endl;
    q.pop_back();
    cout << q.empty() << endl;
    return 0;
}
