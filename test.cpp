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



#include <iostream>
using namespace std;

template <class type>
struct bst {
    struct node {
        int data;
        node* left;
        node* right;
    };
    node* root;
    bst() {
        root = nullptr;
    }
    void insert(int x) {
        if (root == nullptr) {
            root = new node;
            root->data = x;
            root->left = nullptr;
            root->right = nullptr;
        }
        else {
            node* cur = root;
            node* parent = nullptr;
            while (cur != nullptr) {
                parent = cur;
                if (x < cur->data) {
                    cur = cur->left;
                }
                else {
                    cur = cur->right;
                }
            }
            if (x < parent->data) {
                parent->left = new node;
                parent->left->data = x;
                parent->left->left = nullptr;
                parent->left->right = nullptr;
            }
            else {
                parent->right = new node;
                parent->right->data = x;
                parent->right->left = nullptr;
                parent->right->right = nullptr;
            }
        }
    }

    bool find(int x) {
        return hha(root, x);
    }

    bool hha(node* root, int x) {
        if (root == nullptr) {
            return false;
        }
        if (root->data == x) {
            return true;
        }
        if (x < root->data) {
            return hha(root->left, x);
        } else {
            return hha(root->right, x);
        }
    }

    void print() {
        hhe(root);
    }
    void hhe (node *root){
        if(root != nullptr) {
            hhe(root -> left);
            cout << root-> data << " ";
            hhe(root -> right);
        }
    }
};

int main() {
    bst<int> tree;
    tree.insert(5);
    tree.insert(30);
    tree.insert(777);
    tree.insert(20);
    tree.insert(489);
    tree.insert(4);
    tree.insert(60);
    tree.insert(8);
    tree.insert(2);
    tree.insert(1);

    tree.print();
    cout << endl;
    
    if(tree.find(50)){
        cout << "1" << endl;
    }
    else{
        cout << "0" << endl;
    }
    
    return 0;
}

