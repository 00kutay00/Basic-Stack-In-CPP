#ifndef BASIC_STACK_HPP
#define BASIC_STACK_HPP

#include <stdexcept>  // out_of_range
#include <cstddef>    // size_t

template<typename T>
class BasicStack {
private:
    T* StartData;
    size_t MaxSize = 100;
    size_t CurrentIndex = 0;

public:
    BasicStack() {
        StartData = new T[MaxSize];
    }

    ~BasicStack() {
        delete[] StartData;
    }

    void push(T value) {
        if (CurrentIndex < MaxSize) {
            *(StartData + CurrentIndex) = value;
            CurrentIndex++;
        } else {
            throw std::out_of_range("Stack Out Of Range!");
        }
    }

    T pop() {
        if (CurrentIndex == 0) {
            throw std::out_of_range("Stack is empty!");
        }
        CurrentIndex--;
        return *(StartData + CurrentIndex);
    }

    T top() {
        if (CurrentIndex == 0) {
            throw std::out_of_range("Stack is empty!");
        }
        return *(StartData + (CurrentIndex - 1));
    }

    size_t size() const {
        return CurrentIndex;
    }

    void clear() {
        CurrentIndex = 0;
    }

    bool is_empty() const {
        return CurrentIndex == 0;
    }

    bool is_full() const {
        return CurrentIndex == MaxSize;
    }
};

#endif // BASIC_STACK_HPP
