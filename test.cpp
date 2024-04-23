#include <iostream>
using namespace std;

template <class type>
struct stack{
    struct node{
        type data;
        node *next;
    };
    node *root;
    stack(){
        root = nullptr;
    }
    void push(type x){
        node *p = new node;
        p -> data = x;
        p -> next = root;
        root = p;
    }
    void pop(){
        node *p = root;
        root = root -> next;
        delete p;
    }
    type top(){
        return root -> data;
    }
    bool empty(){
        if(root == nullptr) return true;
        else return false;
    }
};

int main(){
    stack <int> s;
    s.push(30);
    cout << s.top() << endl << s.empty() << endl;
    s.pop();
    cout << s.empty();
}
