#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

template <typename Type>
class Class1 {
public:
    vector<Type> vec;
    int value;
    
    Class1(): value(0) {}
    
    void add(int val) {
        ++value;
        vec.push_back(val);
    }
    void del() {
        if(value > 0) {
            Type min = vec[0];
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
            Type min = INT_MAX;
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
    void call() {
        if(value > 0) {
            for(int i = 0; i < value; ++i) {
                cout << vec[i] << "\t";
            }
            cout << endl;
        } else {
            throw runtime_error("ERROR3: function call");
        }
    }
};


int main() {
    try {
        Class1 <double> c1;
        
        c1.add(4.3);
        c1.add(5.2);
        c1.add(4.5);
        c1.add(5.1);
        
        c1.call();
        
        c1.get();
        c1.del();
        c1.del();
        
        c1.call();
        c1.get();
        
        Class1 <int> c2;
        
        c2.add(4);
        c2.add(5);
        c2.add(4);
        c2.add(-5);
        
        c2.call();
        
        c2.get();
        c2.del();
        c2.del();
        
        c2.call();
        c2.get();

        
    } catch(const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
