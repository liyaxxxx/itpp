#include <iostream>
using namespace std;

template<class type>
struct BST {
    struct node {
        type value;
        node *left;
        node *right;
        node(type x) {
            value = x;
            left = nullptr;
            right = nullptr;
        }
    };
    size_t sz;
    node *root;
    BST() {
        root = nullptr;
        sz = 0;
    }

    void insert(type x) {
        sz++;
        if (root == nullptr) {
            root = new node(x);
            return;
        }
        node *curr = root;
        while (true) {
            if (curr -> value >= x) {
                if (curr -> left == nullptr) {
                    curr -> left = new node(x);
                    break;
                }
                curr = curr -> left;
            } else { 
                if (curr -> right == nullptr) {
                    curr -> right = new node(x);
                    break;
                }
                curr = curr -> right;
            }
        }
    }
    
    void erase(type x) {
        root = eraseHelper(root, x);
    }

    node* eraseHelper(node* root, type x) {
        if (root == nullptr) return root;
        if (x < root->value) {
            root->left = eraseHelper(root->left, x);
        } else if (x > root->value) {
            root->right = eraseHelper(root->right, x);
        } else {
            if (root->left == nullptr) {
                node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                node* temp = root->left;
                delete root;
                return temp;
            }
            node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = eraseHelper(root->right, temp->value);
        }
        return root;
    }

    node* minValueNode(node* root) {
        node* current = root;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    
    bool find(type x) {
        node *cur = root;
        while (cur != nullptr) {
            if (cur -> value == x) {
                return true;
            } else if (x > cur -> value) {
                cur = cur -> right;
            } else {
                cur = cur -> left;
            }
        }
        return false;
    }
     
    size_t size() {
        return sz;
    }

    void print() {
        printInOrder(root);
        cout << endl;
    }

    void printInOrder(node* root) {
        if (root != nullptr) {
            printInOrder(root->left);
            cout << root->value << " ";
            printInOrder(root->right);
        }
    }
};

int main() {
    BST<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(0);
    bst.insert(7);
    bst.insert(15);
    bst.insert(30);
    bst.insert(6);
    bst.insert(40);
    bst.insert(35);
    
    cout << "Before erase: ";
    bst.print();
    bst.erase(5);
    cout << "After erase 5: ";
    bst.print();
    
    cout << "Find 5: " << bst.find(5) << endl;
    
    cout << "Size of BST: " << bst.size() << endl;
    
    return 0;
}
