#include <cstdlib>

#include <cassert>
#include <iostream>
#include <stack>


typedef std::stack<int> intstack;


void sort(intstack &s)
{
    intstack tmp;
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        while (!tmp.empty() && tmp.top() < v) {
            s.push(tmp.top());
            tmp.pop();
        }
        tmp.push(v);
    };
    while (!tmp.empty()) {
        s.push(tmp.top());
        tmp.pop();
    };
}

void verify(intstack &s)
{
    int prev = s.top();
    s.pop();
    while (!s.empty()) {
        assert(s.top() <= prev);
        prev = s.top();
        s.pop();
    }
}

void sortAndVerify(int num)
{
    intstack s;
    for (int i = 0; i < num; ++i) {
        s.push(random() % 1000);
    }

    sort(s);
    verify(s);
}

int main()
{
    srandom(1234);

    sortAndVerify(10);
    sortAndVerify(100);
    sortAndVerify(1000);

    return 0;
}
