#include <iostream>
#include <cassert>

template<class T>
class Stacks {
public:
    virtual void push(int i, const T &v) = 0;
    virtual void pop(int i) = 0;
    virtual T &top(int i) = 0;
    virtual size_t size(int i) = 0;
    virtual bool empty(int i) = 0;
    virtual size_t stackCount() = 0;
};

template<class T>
class FixedLengthStacks : public Stacks<T> {
public:
    FixedLengthStacks(size_t stackDepth, size_t stackCount = 3)
        : m_stackDepth(stackDepth)
        , m_stackCount(stackCount)
    {
        m_values = (T *)malloc(sizeof(T) * stackCount * stackDepth);
        m_offsets = (int *)malloc(sizeof(int) * stackCount);
        for (int i = 0; i < stackCount; ++i) {
            m_offsets[i] = -1;
        }
    }
    ~FixedLengthStacks()
    {
        free((void *) m_values);
        free((void *) m_offsets);
    }
    virtual void push(int i, const T &v)
    {
        assert(i >= 0 && i < m_stackCount);
        assert(m_offsets[i] < (int)(m_stackDepth-1));
        int offset = ++(m_offsets[i]);
        m_values[i*m_stackDepth + offset] = v;
    }
    virtual void pop(int i)
    {
        assert(i >= 0 && i < m_stackCount);
        assert(m_offsets[i] >= 0);
        --m_offsets[i];
    }
    virtual T &top(int i)
    {
        assert(i >= 0 && i < m_stackCount);
        assert(m_offsets[i] >= 0);
        return m_values[i*m_stackDepth + m_offsets[i]];
    }
    virtual size_t size(int i)
    {
        assert(i >= 0 && i < m_stackCount);
        return m_offsets[i]+1;
    }
    virtual bool empty(int i)
    {
        return size(i) == 0;
    }
    virtual size_t stackCount()
    {
        return m_stackCount;
    }

    size_t m_stackDepth;
    size_t m_stackCount;
    T *m_values;
    int *m_offsets;
};

template<class T>
class DynamicLengthStacks : public Stacks<T> {
public:
    struct Element {
        T value;
        Element *next;
    };
    DynamicLengthStacks(size_t stackDepth, size_t stackCount = 3)
        : m_stackDepth(stackDepth)
        , m_stackCount(stackCount)
    {
        m_head = (Element *)malloc(sizeof(Element) * stackCount * stackDepth);
        for (int i = 0; i < stackCount * stackDepth; ++i) {
            if (i+1 < stackCount * stackDepth) {
                m_head[i].next = &m_head[i+1];
            } else {
                m_head[i].next = NULL;
            }
        }
        m_freeElements = m_head;

        m_topElements = (Element **)malloc(sizeof(Element *) * stackCount);
        for (int i = 0; i < stackCount; ++i) {
            m_topElements[i] = NULL;
        }
    }
    ~DynamicLengthStacks()
    {
        free((void *) m_head);
        free((void *) m_topElements);
    }
    virtual void push(int i, const T &v)
    {
        assert(i >= 0 && i < m_stackCount);
        assert(m_freeElements != NULL);
        Element *e = m_freeElements;
        m_freeElements = m_freeElements->next;
        e->value = v;
        if (m_topElements[i] == NULL) {
            e->next = NULL;
            m_topElements[i] = e;
        } else {
            e->next = m_topElements[i];
            m_topElements[i] = e;
        }
    }
    virtual void pop(int i)
    {
        assert(i >= 0 && i < m_stackCount);
        assert(m_topElements != NULL);
        Element *e = m_topElements[i];
        m_topElements[i] = e->next;
        e->next = m_freeElements;
        m_freeElements = e;
    }
    virtual T &top(int i)
    {
        assert(i >= 0 && i < m_stackCount);
        assert(m_topElements != NULL);
        return m_topElements[i]->value;
    }
    virtual size_t size(int i)
    {
        assert(i >= 0 && i < m_stackCount);
        Element *e = m_topElements[i];
        size_t count = 0;
        while (e != NULL) {
            e = e->next;
            ++count;
        };
        return count;
    }
    virtual bool empty(int i)
    {
        return size(i) == 0;
    }
    virtual size_t stackCount()
    {
        return m_stackCount;
    }
    T v;
    size_t m_stackDepth;
    size_t m_stackCount;
    Element *m_head;
    Element *m_freeElements;
    Element **m_topElements;
};

void func(Stacks<int> &s)
{
    std::cout << "s.empty " << s.empty(2) << std::endl;
}

int main()
{
    FixedLengthStacks<int> s1(3, 3);
    func(s1);
    s1.push(2, 1);
    func(s1);
    s1.push(2, 1);
    s1.push(2, 1);

    DynamicLengthStacks<int> s2(3, 3);
    func(s2);
    s2.push(2, 1);
    s2.push(2, 2);
    s2.push(2, 3);
    s2.push(2, 4);
    s2.push(2, 5);
    s2.push(2, 6);
    s2.push(2, 7);
    s2.push(2, 8);
    s2.push(2, 9);
    s2.pop(2);
    s2.push(2, 9);
    s2.pop(2);
    s2.push(1, 9);
    return 0;
}
