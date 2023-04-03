#pragma once
#include <algorithm>
template <typename TElem>

class DynamicVector {
private:
    int size;
    int capacity;
    TElem* elements;

public:
    DynamicVector() {
        size = 0;
        capacity = 20;
        elements = new TElem[capacity];
    }
    DynamicVector(const DynamicVector& v) {
        size = v.size;
        capacity = v.capacity;
        elements = new TElem[capacity];
        for (int i = 0; i < v.getSize(); i++)
            elements[i] = v.getElemsOnPosition(i);
    }
    ~DynamicVector() {
        delete[] elements;
    }
    void add(TElem& e) {
        if (size == capacity)
            resize();
        elements[size] = e;
        size++;
    }
    void remove(int pos) {
        if(!(pos<this->size))
            return;
        for (int i = pos; i < size - 1; i++)
            elements[i] = elements[i + 1];
        size--;
    }

    int getSize() const {
        return size;
    }
    TElem* getAllElems() const {
        return elements;
    }
    TElem& getElemsOnPosition(int pos) const {
        return elements[pos];
    }
    void setElemsOnPosition(int pos, TElem e) {
        elements[pos] = e;
    }
private:
    void resize() {
        capacity = capacity * 2;
        TElem* newElements = new TElem[capacity];
        std::copy(elements, elements + size, newElements);
        delete[] elements;
        elements = newElements;
    }
};