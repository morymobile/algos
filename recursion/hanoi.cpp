#include <cassert>
#include <iostream>
#include <stack>


class Tower
{
public:
    Tower(int t)
    : t(t) {}

    void push(int v)
    {
        if (!s.empty() && s.top() <= v)
            assert(false);
        s.push(v);
    }
    int pop() 
    {
        int v = s.top();
        s.pop();
        return v;
    }
    bool empty()
    {
        return s.empty();
    }

    int tag()
    {
        return t;
    }

private:
    std::stack<int> s;
    int t;
};


void do_move(Tower &left, Tower &right, Tower &other, int n)
{
    if (n == 1) {
        int v = left.pop();
        std::cout << "from:" << left.tag()
                  << " to:" << right.tag()
                  << " value:" << v << std::endl;
        right.push(v);
        return;
    }
    do_move(left, other, right, n-1);
    do_move(left, right, other, 1);
    do_move(other, right, left, n-1);
}

void hanoi(int plates)
{
    Tower t1(1), t2(2), t3(3);
    for (int i = 0; i < plates; ++i) {
        t1.push(plates-i);
    }
    do_move(t1, t3, t2, plates);
    
    int n = 1;
    while (!t3.empty())
        assert(t3.pop() == n++);
    assert(n == plates+1);
}

int main()
{
    hanoi(3);
    hanoi(4);
    hanoi(64);
    return 0;
}
