#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tree {
public:
    vector<int> list;
    int value;
};

Tree t[10];

int getValue(int* a, int size) {
    int v;
    for(int i = 0; i < size; ++i) {
        if(a[i] == -1) { v = i; }
    }
    return v;
}

void func_tree(int* a, int size, int base, int place) {
    for(int j = 0; j < size; ++j) {
        if(a[j] == place) {
            t[j].value = j;
            if(place >= 0) {t[base].list.push_back(j); }
            func_tree(a, size, j, j);
        }
    }
}

void tabulation(int tab) {
    for(int i = 0; i < tab; ++i) {
        cout << " ";
    }
}

void call_func(const Tree& A, int tab = 0) {
    tabulation(tab);
    cout << A.value << endl;
    for(vector<int>::const_iterator iter = A.list.begin(); iter != A.list.end(); ++iter) {
        call_func(t[*iter], (tab + 1));
        //
        for(vector<int>::const_iterator iter1 = A.list.begin(); iter1 != A.list.end(); ++iter1) {
            call_func(t[*iter1], (tab + 1));
        }
        tabulation(tab);
        cout << A.value << endl;
        //
        vector<int>::const_iterator iter2 = A.list.begin();
        if (iter != A.list.end())
            call_func(t[*iter2], (tab + 1));
        tabulation(tab);
        cout << A.value << endl;
        for(; iter2 != A.list.end(); ++iter2) {
           call_func(t[*iter2], (tab + 1));
    }
    }
}

int main() {
    int array[] = {-1, 0, 0, 0, 1, 2, 3, 1, 2, 3};
    int size = sizeof(array)/sizeof(int);
    int value = getValue(array, size);
    
    func_tree(array, size, value, -1);
    
    call_func(t[value]);
    cout << endl;
    
    return 0;
}
