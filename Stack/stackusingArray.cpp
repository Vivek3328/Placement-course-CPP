#include <bits/stdc++.h>
using namespace std;

class stackusingArray{
    public:
        int *arr;
        int index;
        int size;

        stackusingArray(int size)
        {
            arr = new int[size];
            index=-1;
            this->size=size;
        }

        void push(int element)
        {
            if((size-index)>1)
            {
                index++;
                arr[index]=element;
            }
            else{
                cout<<"Stack Overflow"<<endl;
            }
        }

        void pop()
        {
            if(index>=0)
            {
                
                index--;
                
              
            }
            else{
                cout<<"Stack is Empty"<<endl;
            }
        }

        int top()
        {
            if(index>=0)
            {
                return arr[index];
            }
            else{
                return -1;
            }
        }

        bool isEmpty()
        {
            if(index>-1)
            {
                return false;
            }
            else{
                return true;
            }
        }
};

int main()
{
    stackusingArray st(3);

    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.isEmpty()<<endl;
    st.pop();
    cout<<st.isEmpty()<<endl;
    return 0;
}