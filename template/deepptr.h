#ifndef DEEPPTR_H
#define DEEPPTR_H

#include <iostream>

template <class T>
class DeepPtr{
private:
    T* pted;
public:
    DeepPtr(T* =nullptr);
    DeepPtr(const DeepPtr&);
    DeepPtr& operator=(const DeepPtr&);
    T* operator->() const;
    T& operator*() const;
    ~DeepPtr();
    bool operator==(const DeepPtr&) const;
    bool operator!=(const DeepPtr&) const;
    bool operator>(const DeepPtr&) const;
    bool operator<(const DeepPtr&) const;
};

template <class T>
DeepPtr<T>::DeepPtr(T* itm): pted(itm){}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr& dptr){
      if(dptr== nullptr)
          pted=nullptr;
      else
          pted=dptr.pted->clone();
}

template <class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr& dptr){
        if(this != &dptr){
            if(pted)
                delete pted;
            pted = dptr.pted->clone();
    }
    return *this;
}

template <class T>
T* DeepPtr<T>::operator->() const{
       return pted;
}

template <class T>
T& DeepPtr<T>::operator*() const{
        return *pted;
}

template <class T>
DeepPtr<T>::~DeepPtr(){
    if(pted)
        delete pted;
}

template <class T>
bool DeepPtr<T>::operator==(const DeepPtr& dptr) const{
    return *pted==*(dptr.pted);
}

template <class T>
bool DeepPtr<T>::operator!=(const DeepPtr& dptr) const{
    return *pted!=*(dptr.pted);
}

template<class T>
bool DeepPtr<T>::operator<(const DeepPtr& dptr) const{
    return *pted<*(dptr.pted);
}

template<class T>
bool DeepPtr<T>::operator>(const DeepPtr& dptr) const{
    return *pted>*(dptr.pted);
}

#endif // DEEPPTR_H
