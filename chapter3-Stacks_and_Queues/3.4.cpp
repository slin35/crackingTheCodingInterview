#include <iostream>
#include <stack>

using namespace std;

/* queue implementation using two stacks */
class Queue {
    public:
        Queue() {}

        int size() {
            return s;
        }

        void push_back(int x) {
            s1.push(x);
            s++;
        }

        int pop_front() {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            if (s2.empty())
                throw "empty stack";
            
            s--;
            int res = s2.top();
            s2.pop();
            return res;
        }

        int front() {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            return s2.top();
        }

        int empty() {
            return s == 0;
        }

    private:
        stack<int> s1;  // for enqueue
        stack<int> s2;  // for dequeue
        int s{0};       // size
    
};


int main() {
    Queue q;

    q.push_back(1);
    q.push_back(2);
    q.push_back(3);

    cout << q.front() << endl;
    cout << q.pop_front() << endl;

    cout << q.front() << endl;


    return 0;
}
