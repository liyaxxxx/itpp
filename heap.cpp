#include <iostream>
using namespace std;
 
template<class type>

struct heap {
    type a[1000];
    int n;
    heap() {
        n = 0;
    }
 
    void _up(int i) {
        if(a[i]%2==0){
            if(a[i/2] < a[i]){
                swap(a[i], a[i/2]);
            }
        }
        if(a[i]%2==1){
            if(a[(i-1)/2] < a[i]){
                swap(a[i], a[(i-1)/2]);
            }
        }
    }
 
    void _down(int i) {
        if(a[i*2] < a[i*2 + 1]){
            swap(a[i*2 + 1], a[i]);
        }
        else{
            swap(a[i*2], a[i]);
        }
    }
 
    void push(type x) {
        n++;
        a[n] = x;
    }
 
    void pop() {
        swap(a[n], a[0]);
        n--;
    }
 
    void update(int i, type x){
        a[i] = x;
        while(a[i] <= a[(i-1)/2] || a[i] <= a[i/2]){
            _down(i);
        }
        
    }
 
    type top() {
        return a[0];
    }
 
    int size() {
        return n;
    }
 
    bool empty() {
        if(n==0){
            return true;
        }
        else{
            return false;
        }
    }
    
};
 
int main() {
    heap<int> hp;
    hp.push(10);
    hp.push(0);
    hp.push(20);
    hp.push(3);
    hp.push(7);
 
    while (!hp.empty()) {
        cout << hp.top() << ' ';
        hp.pop();
    }
    cout << endl;
    return 0;
}