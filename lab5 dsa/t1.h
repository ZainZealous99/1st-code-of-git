#ifndef T1_H
#define T1_H

template <typename t>
class abstractqueue 
{
public:
    virtual void enqueue(t value) = 0;
    virtual t dequeue() = 0;
    virtual t front() const = 0;
    virtual bool isempty() const = 0;

    virtual bool isfull() const = 0;

    virtual ~abstractqueue() {}
};

#endif