#include <iostream>
#include <stack>

using namespace std;

/* sort a stack so that the smallest element is on the top 
 * only one additional stack is allowed (push, pop, peek, isEmpty)
 * 
 * with unlimited stakcs, mergesort and quicksort can be implemented
 * mergesort:
 *  divide one current stack into 2 stacks util the stack size is 1
 *  merge them by sorting order
 * quicksort:
 *  with 2 additional stacks storing values > pivot point and values < the pivot
 *  then merge them back to the original stack
 *  sort until the range of highs and lows is 0
*/
void sortStack(stack<int>& st) {
    stack<int> st2;

    while (!st.empty()) {
        int top = st.top();
        st.pop();

        while (!st2.empty() && st2.top() > top) {
            st.push(st2.top());
            st2.pop();
        }

        st2.push(top);
    }

    // copy elements from st2 back to st (in reverse order)
    while (!st2.empty()) {
        st.push(st2.top());
        st2.pop();
    }
    
}

void printStack(stack<int> st) {
    for (stack<int> tmp = st; !tmp.empty(); tmp.pop()) {
        cout << tmp.top() << endl;
    }
}

int main() {
    stack<int> st;
    st.push(5);
    st.push(8);
    st.push(9);
    st.push(7);
    st.push(2);
    st.push(4);
    st.push(10);

    sortStack(st);
    printStack(st);

    return 0;
}