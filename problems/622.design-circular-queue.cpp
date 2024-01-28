/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class MyCircularQueue
{
public:
    MyCircularQueue(int k) :
        m_data(new int[k]),
        m_size(k),
        m_currentSize(0)
    {
    }

    ~MyCircularQueue()
    {
        delete[] m_data;
        m_data = nullptr;
    }

    bool enQueue(int value)
    {
        if (m_currentSize < m_size)
        {
            m_data[m_currentSize++] = value;
            return true;
        }
        return false;
    }

    bool deQueue()
    {
        if (!isEmpty())
        {
            for (int i = 0; i < m_currentSize - 1; ++i)
                m_data[i] = m_data[i + 1];
            --m_currentSize;
            return true;
        }
        return false;
    }

    int Front()
    {
        return isEmpty() ? -1 : m_data[0];
    }

    int Rear()
    {
        return isEmpty() ? -1 : m_data[m_currentSize - 1];
    }

    bool isEmpty()
    {
        return m_currentSize < 1;
    }

    bool isFull()
    {
        return m_currentSize == m_size;
    }

private:
    int* m_data;
    int m_size;
    int m_currentSize;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
