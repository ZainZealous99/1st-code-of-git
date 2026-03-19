#pragma once

template <typename t>
class abstractstack {
public:
    virtual void push(t value) = 0;
    virtual t pop() = 0;
    virtual t top() const = 0;
    virtual bool isempty() const = 0;
    virtual bool isfull() const = 0;
    virtual ~abstractstack() {}
};
