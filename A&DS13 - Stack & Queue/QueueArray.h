#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include "Queue.h"
#include "QueueExceptions.h"

template <class T>
class QueueArray : public Queue<T>
{
public:
    QueueArray(int size = 100);
    ~QueueArray();
    virtual void enQueue(const T& e); // ���������� �������� � �������
    virtual T deQueue(); // �������� �������� �� �������
    virtual bool isQueueEmpty(); // �������� ������� �� �������
    void Print()
    {
        for (int i = 0; i < size_; i++) {
            std::cout << array_[i];
        }

    }
private:
    T* array_;
    int top_;
    int size_;
    int end_;
    int counter_;
};
#endif 

template<class T>
QueueArray<T>::QueueArray(int size) : //�����������
    top_(0),
    end_(0),
    size_(size),
    counter_(0)
{
    if (size_ <= 0)
        throw WrongQueueSize();
    array_ = new T[size];
};
template<class T>
QueueArray<T>::~QueueArray<T>() //����������
{
    delete array_;
};

template<class T>
void QueueArray<T>::enQueue(const T& e) //���������� ������ ���������� �������� � �������
{
    if (counter_ == size_)
        throw QueueOverflow();
    else
    {
        array_[end_] = e;
        end_ = ++end_ % size_;
        counter_++;
    }
}

template<class T>
T QueueArray<T>::deQueue() //���������� ������ �������� �������� �� �����
{
    if(counter_ == 0)
        throw QueueUnderflow();
    else
    {
        T popped = array_[top_];
        top_ = ++top_ % size_;
        counter_--;
        return popped;
    }
}

template<class T>
bool QueueArray<T>::isQueueEmpty() //���������� �������� �� ������� �������
{
    if (counter_ == 0)
        return true;
    else
        return false;
}
