//
// Created by More on 08/12/2022.
//

#ifndef GROUP_AK_VECTOR_H
#define GROUP_AK_VECTOR_H
#include <bits/stdc++.h>

using namespace std;
template <typename T> class AK_Vector;
template <typename T> ostream& operator<<(ostream& out, const AK_Vector<T>& vec);
template <class T>

class AK_Vector {
private:
    int sizeVector , capacityVector ;
    T *ptr_arr;
public:

    AK_Vector (int c = 3);
    AK_Vector (T*, int n );
    AK_Vector (const AK_Vector&);
    ~AK_Vector();
    AK_Vector<T> operator=(const AK_Vector&);
    AK_Vector<T> operator=(AK_Vector&&) noexcept ;
    T& operator[](int);
    void push_back(T);
    void pop_back();
    void erase(T* ptr);
    void erase(T* ptr1, T* ptr2);
    void clear();
    void insert(T* ptr, T element);
    T* begin();
    T* end();
    bool operator==(const AK_Vector<T>&);
    bool operator< (const AK_Vector<T>&) ;
    int size() const;
    int capacity() const ;
    void resize();
    bool empty();
    friend ostream& operator<< <T>(ostream& out, const AK_Vector<T>& vec);
    const T& operator*(T* it) const;
    void operator++();
    void operator+(int x);
};
template<class T>
AK_Vector<T>::AK_Vector(int c) {
    if(c<=0){
        cout << "error" << endl;
        return;
    }
    capacityVector = c;
    ptr_arr = new T[capacityVector];
    sizeVector = 0;
}

template<class T>
AK_Vector<T>::AK_Vector(T* ptr, int n) {
    capacityVector = n;
    ptr_arr = new T[capacityVector];
    sizeVector = n;
    for (int i = 0; i < n; ++i) {
        ptr_arr[i] = ptr[i];
    }
}

template<class T>
AK_Vector<T>::AK_Vector(const AK_Vector& anther) {
    this->capacityVector = anther.capacityVector;
    this->sizeVector = anther.sizeVector;
    this->ptr_arr = new T[capacityVector];
    for (int i = 0; i < sizeVector; ++i) {
        ptr_arr[i] = anther.ptr_arr[i];
    }
}

template<class T>
AK_Vector<T>::~AK_Vector() {
    delete[] ptr_arr;
}

template<class T>
AK_Vector<T> AK_Vector<T>::operator=(const AK_Vector& anther) {
    this->capacityVector = anther.capacityVector;
    this->sizeVector = anther.sizeVector;
    this->ptr_arr = new T[capacityVector];
    for (int i = 0; i < sizeVector; ++i) {
        ptr_arr[i] = anther.ptr_arr[i];
    }
    return * this;
}

template<class T>
AK_Vector<T> AK_Vector<T>::operator=(AK_Vector&& anther) noexcept {
    this->capacityVector = anther.capacityVector;
    this->sizeVector = anther.sizeVector;
    this->ptr_arr = new T[capacityVector];
    for (int i = 0; i < sizeVector; ++i) {
        ptr_arr[i] = anther.ptr_arr[i];
    }
    delete[] anther.ptr_arr;
    anther.sizeVector = 0;
    return * this;
}

template<class T>
T& AK_Vector<T>::operator[](int x) {
    if (x > sizeVector - 1) {
        cout << "Error , this out of scope !!" << endl;
        exit(-1);
    }
    return ptr_arr[x];
}

template<class T>
void AK_Vector<T>::push_back(T item) {
    if (sizeVector < capacityVector) {
        ptr_arr[sizeVector++] = item;
    }
    else {
        capacityVector *= 2;
        T* new_arr = new T[capacityVector];

        for (int i = 0; i < sizeVector; i++) {
            new_arr[i] = ptr_arr[i];
        }
        delete[] ptr_arr;
        ptr_arr = new_arr;
        new_arr = nullptr;
        ptr_arr[sizeVector++] = item;
    }

}

template<class T>
void AK_Vector<T>::pop_back() {
    if (sizeVector >= 1)
        sizeVector--;
    else
        cout << "Error The Vector Is Empty\n";
}

template<class T>
void AK_Vector<T>::erase(T* ptr) {
    int pos = ptr - ptr_arr;
    if (pos < sizeVector && pos >= 0 )
    {
        sizeVector--;
        for (int i = pos; i < sizeVector ; ++i) {
            ptr_arr[i] = ptr_arr[i+1];
        }
    }
    else
        cout << "error pointer out of scope\n";
}

template<class T>
void AK_Vector<T>::erase(T* ptr1, T* ptr2) {
    int pos1 , pos2;
    pos1 = ptr1 - ptr_arr;
    pos2 = ptr2 - ptr_arr;
    if (pos1 < sizeVector && pos1 >= 0 && pos2 < sizeVector && pos2 >= 0 && pos2 >= pos1)
    {
        sizeVector = sizeVector + pos1 - pos2 - 1;
        for (int i = pos1; i < sizeVector ; ++i) {
            ptr_arr[i] = ptr_arr[pos2 - pos1 + 1];
        }
    }
    else
        cout << "error pointer out of scope or first pointer after second\n";
}

template<class T>
void AK_Vector<T>::clear() {
    sizeVector = 0;
}

template<class T>
void AK_Vector<T>::insert(T* ptr, T element) {
    int pos = ptr - ptr_arr;
    if (pos >= 0 && pos < sizeVector)
    {
        if (sizeVector == capacityVector) {
            capacityVector *= 2;
            T* new_arr = new T[capacityVector];

            for (int i = 0; i < sizeVector; i++) {
                new_arr[i] = ptr_arr[i];
            }
            delete[] ptr_arr;
            ptr_arr = new_arr;
            new_arr = nullptr;
        }
        sizeVector++;
        for (int i = sizeVector-1; i > pos ; i--)
        {
            ptr_arr[i] = ptr_arr[i-1];
        }
        ptr_arr[pos] = element;
    }
    else
        cout << "error pointer out of scope\n";

}

template<class T>
T* AK_Vector<T>::begin() {
    return ptr_arr;
}

template<class T>
T* AK_Vector<T>::end() {
    return &ptr_arr[sizeVector-1];
}

template<class T>
bool AK_Vector<T>::operator==(const AK_Vector<T>&another) {
    if (sizeVector != another.sizeVector)
        return false;
    for (int i = 0; i < sizeVector; i++)
    {
        if (ptr_arr[i] != another.ptr_arr[i])
            return false;
    }
    return true;
}

template<class T>
bool AK_Vector<T>::operator<(const AK_Vector<T>&another) {
    for (int i = 0; i < min(sizeVector,another.sizeVector) ; i++)
    {
        if (ptr_arr[i] == another.ptr_arr[i])
            continue;
        else if (ptr_arr[i] > another.ptr_arr[i])
            return false;
        else if (ptr_arr[i] < another.ptr_arr[i])
            return true;
    }
    return false;
}

template<class T>
int AK_Vector<T>::size() const {
    return sizeVector;
}

template<class T>
int AK_Vector<T>::capacity() const {
    return capacityVector;
}

template<class T>
void AK_Vector<T>::resize() {
    T* new_arr = new T[sizeVector];
    for (int i = 0; i < sizeVector; i++) {
        new_arr[i] = ptr_arr[i];
    }
    delete[] ptr_arr;
    ptr_arr = new_arr;
    delete[] new_arr;
}

template<class T>
bool AK_Vector<T>::empty() {
    if (sizeVector == 0)
        return true;
    else
        return false;
}

template<typename T>
inline ostream& operator<<(ostream& out,const AK_Vector<T>& vec) {
    for (int i = 0; i < vec.sizeVector; ++i) {
        out << vec.ptr_arr[i] << "  ";
    }
    cout << endl;
    return out;
}

template<class T>
const T &AK_Vector<T>::operator*(T* it) const {
    return *it;
}

#endif //GROUP_AK_VECTOR_H
