#include <stack>
#include <iostream>

struct Element {
    int a;
    double b;
};

int main()
{
    std::stack<int> s;
    s.push(1);
    int &a = s.top();
    std::cout << a << std::endl;

    std::stack<Element> s1;
    //s1.push(Element(1, 1.0));

    return 0;
}

