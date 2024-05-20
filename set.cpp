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
            if (curr->value >= x) {
                if (curr->left == nullptr) {
                    curr->left = new node(x);
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    curr->right = new node(x);
                    break;
                }
                curr = curr->right;
            }
        }
    }

    void erase(type x){
        pair <node*, node*> tmp = find_with_parent(root, x);
        if (tmp.second == nullptr) return;
        sz--;
        if (tmp.second->right == nullptr) {
            if(tmp.first->left == tmp.second) {
                tmp.first->left = tmp.second->left;
            }
            else {
                tmp.first->right = tmp.second->left;
            }
            delete tmp.second;
            return;
        }

        pair <node*, node*> rl = find_lowest_node(tmp.second->right, tmp.second);
        tmp.second->value = rl.second->value;
        tmp = rl;
        if (tmp.second->right == nullptr) {
            if (tmp.first->left == tmp.second) {
                tmp.first->left = nullptr;
            }
            else {
                tmp.first->right = nullptr;
            }
            delete tmp.second;
            return;
        }

        if (tmp.first->left == tmp.second) {
            tmp.first->left = tmp.second->right;
        }
        else {
            tmp.first->right = tmp.second->right;
        }
        delete tmp.second;
        return;    
    }

    pair<node*, node*> find_with_parent(node* root, type x) {
        node* parent = nullptr;
        node* current = root;
        while (current != nullptr && current->value != x) {
            parent = current;
            if (x < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return {parent, current};
    }

    pair<node*, node*> find_lowest_node(node* root, node* parent) {
        node* current = root;
        node* prev = nullptr;
        while (current->left != nullptr) {
            prev = current;
            current = current->left;
        }
        return {prev, current};
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
            if (cur->value == x) {
                return true;
            } else if (x > cur->value) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return false;
    }
     
    size_t size() {
        return sz;
    }

    void print() {
        hhaprint(root);
        cout << endl;
    }

    void hhaprint(node* root) {
        if (root != nullptr) {
            hhaprint(root->left);
            cout << root->value << " ";
            hhaprint(root->right);
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
    bst.print();
    bst.erase(5);
    bst.print();
    
    return 0;
}
