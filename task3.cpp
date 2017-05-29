#include <iostream>

using namespace std;

class Stack
{
    const size_t mSize; //mSize - объем
    size_t mItemsCount; //mItemsCount - кол-во элементов
    int* mData; //указатель на следующий элемент списка (стека)
public:
    Stack(size_t size):mSize(size), mItemsCount(0) //низ стека (какое-то значение size), верх стека (0)
    {
        mData=new int[mSize]; // выделение нового участка памяти (массив)  для указателя
    }
    Stack(const Stack& obj /* ссылка на объект*/) : mSize(obj.mSize),mItemsCount(obj.mSize){
        mData=new int[mSize];
        for(int i=0;i<obj.mItemsCount;++i)
        {
            mData[i]=obj.mData[i];
        }
    }
    void push(int i)
    {
        if (mItemsCount==mSize)
            throw runtime_error("Stack polon");
        
        mData[mItemsCount]=i;
        ++mItemsCount;
        
    }
    
    int pop()
    {
        if ((mItemsCount) ==0)
            throw runtime_error("Stack pust");
        mItemsCount-=1;
        return mData[mItemsCount];
        
    }
    size_t getSize()
    {
        return mItemsCount;
    }
    ~Stack()
    {
        delete mData;
    }
};

int main() {
    try{
        Stack a(15);
        for (int i=0;i<10;++i)
            a.push(5);
        for (int i=0;i<5;++i)
            a.push(7);
        for (int i=0; i<10;++i)
            cout << a.pop() << endl;
        
        cout << "Stack 1" << endl;
        Stack b(a);
        int size_b=b.getSize();
        for (int i=0;i<size_b;++i)
            cout << b.pop() << endl;
        
    }
    catch (const exception& e)
    {cout << e.what() << endl;}
    return 0;
}
