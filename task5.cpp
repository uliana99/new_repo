#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Class1 {
public:
    vector<int> vec;
    int value;
    
    Class1(): value(0) {}
    
    void add(int val) {
        ++value;
        vec.push_back(val);
    }
    void del() {
        if(value > 0) {
            int min = vec[0];
            int place = 0;
            for(int i = 0; i < value; ++i) {
                if(min > vec[i]) {
                    min = vec[i];
                    place = i;
                }
            }
            --value;
            vec.erase(vec.begin() + place);
        } else {
            throw runtime_error("ERROR1: delete");
        }
    }
    void get() {
        if(value > 0) {
            int min = INT_MAX;
            for(int i = 0; i < value; ++i) {
                if(min > vec[i]) {
                    min = vec[i];
                }
            }
            cout << "min: " << min << endl;
        } else {
            throw runtime_error("ERROR2: get");
        }
        
    }
};

void call(const Class1& A) {
    if(A.value < 1) {throw runtime_error("ERROR: function call");}
    for(int i = 0; i < A.vec.size(); ++i) {
        cout << A.vec[i] << " ";
    }
    cout << endl;
}

int main() {
    try {
        Class1 c;
        
        c.add(3);
        c.add(4);
        c.add(1);
        c.add(-5);
        
        
        call(c);
        
        c.get();
        
        c.del();
        c.del();
        
        call(c);
        
        c.get();
        
    } catch(const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
