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
    
    
    
    bool find(type x){
        node *cur = root;
        while(true){
            if(cur == nullptr){
                return false;
            }
            if(cur -> value == x){
                return true;
            }
            if(x > cur -> value){
                cur = cur -> right;
            }
            else if(x < cur -> value){
                cur = cur -> left;
            }
    
        }
        return false;
    }
    void print(){
        
    }
     
    size_t size() {
        return sz;
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
    cout << bst.find(5) << endl;
    
    cout << bst.size() << endl;
    return 0;
}