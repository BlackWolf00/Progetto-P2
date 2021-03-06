#ifndef CONTAINER_H
#define CONTAINER_H


#include <iostream>

template <class T>
class Container{

private:
    class nodo{
    public:
        T info;
        nodo* next;
        nodo(const T&, nodo* =nullptr);
        nodo(const nodo&);
        ~nodo();
    };

    nodo* first;

    static nodo* copy(const nodo*);

    static void destroy(nodo*);

    static bool search(nodo* ,const T&);

    static bool isEqual(const nodo*, const nodo*);


public:

    Container();
    Container(const T&);
    Container(const Container&);
    ~Container();

    void pushInOrder(const T&);
    bool removeOneItem(const T&);
    bool removeOneAtIndex(const unsigned int);
    bool searchIntoList(const T&) const;
    T searchAtIndex(unsigned int) const;
    unsigned int getIndex(const T&) const;

    Container<T> operator=(const Container<T>&);
    bool operator==(const Container<T>&) const;
    bool operator!=(const Container<T>&) const;

    void replaceAtIndex(const T&, unsigned int);
    nodo* getFirst() const;
    bool is_empty() const;
    unsigned int size() const;

    class Iterator{
        friend class Container<T>;
    private:
        nodo* pointed;
        bool pte;
        Iterator(nodo*, bool =false);
    public:
        Iterator(const Container<T>::Iterator&);
        Iterator &operator++();
        T& operator*() const;
        T* operator->() const;
        bool operator ==(const Iterator&) const;
        bool operator !=(const Iterator&) const;
        bool hasNext() const;
    };

    class Const_Iterator{
        friend class Container<T>;
    private:
        const nodo* pointed;
        bool pte;
        Const_Iterator(nodo*, bool =false);
    public:
        Const_Iterator(const Container<T>::Const_Iterator&);
        Const_Iterator &operator++();
        const T& operator*() const;
        const T* operator->() const;
        bool operator ==(const Const_Iterator&) const;
        bool operator !=(const Const_Iterator&) const;
        bool constHasNext() const;
    };

    Iterator begin() const;
    Iterator end() const;

    Const_Iterator constBegin() const;
    Const_Iterator constEnd() const;
};

template <class T>
Container<T>::nodo::nodo(const T& i, nodo* p): info(i), next(p){}

template <class T>
Container<T>::nodo::nodo(const nodo& n):info(n.info), next(n.next){}

template <class T>
Container<T>::nodo::~nodo(){
    if(next){
        delete next;
    }
}

template <class T>
typename Container<T>::nodo* Container<T>::copy(const nodo* n){
    if(!n) return nullptr;
    return new nodo(n->info, copy(n->next));
}

template <class T>
void Container<T>::destroy(nodo* n){
    if(n)
        delete n;
}

template <class T>
bool Container<T>::search(nodo* n, const T& itm){
    if(!n)
        return false;
    if(n->info == itm)
        return true;
    return search(n->next,itm);
}

template <class T>
bool Container<T>::isEqual(const nodo* nodol, const nodo* nodolfor){
    if(!nodol && !nodolfor)
        return true;
    if(!nodol || !nodolfor)
        return false;
    if(nodol->info==nodolfor->info)
        return equal(nodol->next, nodolfor->next);
    return false;
}

template <class T>
Container<T>::Container(): first(nullptr){}

template <class T>
Container<T>::Container(const T& itm): first(new nodo(itm)){}

template <class T>
Container<T>::Container(const Container& l1): first(copy(l1.first)){}

template <class T>
Container<T>::~Container<T>(){
    if(first)
        destroy(first);
}

template <class T>
void Container<T>::pushInOrder(const T& itm){
    nodo* current;
    nodo* new_nodo = new nodo(itm);

    if (first == nullptr || first->info > new_nodo->info){
        new_nodo->next = first;
        first = new_nodo;
    }
    else{
        current = first;
        while (current->next!=nullptr && current->next->info < new_nodo->info)
        {
            current = current->next;
        }
        new_nodo->next = current->next;
        current->next = new_nodo;
    }
}

template <class T>
bool Container<T>::removeOneItem(const T& itm){
    if(is_empty())
        return false;
    if(!first->next){
        if(first->info==itm){
            delete first;
            first=nullptr;
            return true;
        }
    }
    else{
        nodo* prev=first;
        nodo* att=first->next;

        if(prev->info==itm){
            first=first->next;
            prev->next=nullptr;
            delete prev;
            return true;
        }

        while(att->next!=nullptr && (att->info) != itm){
            prev=prev->next;
            att=att->next;
        }

        if(att->info==itm){
            prev->next=att->next;
            att->next=nullptr;
            delete att;
            return true;
        }
    }

    return false;
}

template <class T>
bool Container<T>::removeOneAtIndex(const unsigned int i){
    if(is_empty())
        return false;

    if(!first->next){
        if(i==0){
            delete first;
            first=nullptr;
            return true;
        }
    }
    else{
        nodo* prev=first;
        nodo* att=first->next;

        if(i==0){
            first=first->next;
            prev->next=nullptr;
            delete prev;
            return true;
        }

        for(unsigned int k=1; att->next && k<i; k++){
            prev=prev->next;
            att=att->next;
        }

        if(att){
            prev->next=att->next;
            att->next=nullptr;
            delete att;
            return true;
        }
    }

    return false;
}

template <class T>
bool Container<T>::searchIntoList(const T& itm)const{
    return search(first, itm);
}

template <class T>
T Container<T>::searchAtIndex(unsigned int i) const{
    if(i>= size())
        return nullptr;
    nodo* att = first;
    for(unsigned int k=0; k<i; k++)
        att=att->next;
    return att->info;
}

template<class T>
unsigned int Container<T>::getIndex(const T& itm)const{
    nodo * curr=first;
    unsigned int counter=0;
    while(curr && curr->info!=itm){
        curr=curr->next;
        counter++;
    }
    return counter;
}

template <class T>
Container<T> Container<T>::operator=(const Container<T>& cl){
    if(this!=&cl){
        delete first;
        first = copy(cl.getFirst());
    }
    return *this;
}

template <class T>
bool Container<T>::operator==(const Container<T>& c) const{
    return equal(first, c.first);
}

template <class T>
bool Container<T>::operator!=(const Container<T>& c) const{
    return !(equal(first, c.first));
}

template<class T>
void Container<T>::replaceAtIndex(const T& itm, unsigned int i){
    removeOneAtIndex(i);
    pushInOrder(itm);
}

template <class T>
typename Container<T>::nodo* Container<T>::getFirst() const{
    return first;
}

template <class T>
bool Container<T>::is_empty() const{
    return !first;
}

template<class T>
unsigned int Container<T>::size() const{
    unsigned int counter=0;
    nodo* tmp=first;
    while(tmp){
        counter++;
        tmp=tmp->next;
    }
    return counter;
}

template<class T>
Container<T>::Iterator::Iterator(Container::nodo *n, bool passed): pointed(n), pte(passed){}

template <class T>
Container<T>::Iterator::Iterator(const Container<T>::Iterator& it): pointed(it.pointed){
    if(!pointed && !pointed->next)
        pte=true;
    else
        pte=false;
}

template<class T>
typename Container<T>::Iterator Container<T>::begin() const{
    return Iterator(first);
}

template<class T>
typename Container<T>::Iterator Container<T>::end() const{
    nodo *p=first;
    while(p&&p->next)
        p=p->next;
    return Iterator(p+1,true);
}

template<class T>
typename Container<T>::Iterator &Container<T>::Iterator::operator++(){
    if(!pte && pointed){
        if(pointed->next==nullptr){
            pointed=pointed+1;
            pte=true;
        }
        else
            pointed=pointed->next;
    }
    return *this;
}

template<class T>
T &Container<T>::Iterator::operator*() const{
    return pointed->info;
}

template<class T>
T *Container<T>::Iterator::operator->() const{
    return &(pointed->info);
}

template<class T>
bool Container<T>::Iterator::operator ==(const Container<T>::Iterator & i) const{
    return pointed==i.pointed;
}

template<class T>
bool Container<T>::Iterator::operator !=(const Container<T>::Iterator & i) const{
    return pointed!=i.pointed;
}

template <class T>
bool Container<T>::Iterator::hasNext() const{
    if(pointed->next)
        return true;
    else
        return false;
}

template<class T>
Container<T>::Const_Iterator::Const_Iterator(Container::nodo *n, bool passed): pointed(n), pte(passed){}

template <class T>
Container<T>::Const_Iterator::Const_Iterator(const Container<T>::Const_Iterator& cit): pointed(cit.pointed){
    if(!pointed && !pointed->next)
        pte=true;
    else
        pte=false;
}

template<class T>
typename Container<T>::Const_Iterator Container<T>::constBegin() const{
    return Const_Iterator(first) ;
}

template<class T>
typename Container<T>::Const_Iterator Container<T>::constEnd() const{
    nodo *p=first;
    while(p&&p->next)
        p=p->next;
    return Const_Iterator(p+1,true);
}

template<class T>
typename Container<T>::Const_Iterator &Container<T>::Const_Iterator::operator++(){
    if(!pte && pointed){
        if(pointed->next==nullptr){
            pointed=pointed->next;
            pte=true;
        }
        else pointed=pointed->next;
    }
    return *this;
}

template<class T>
const T &Container<T>::Const_Iterator::operator*() const{
    return pointed->info;
}

template<class T>
const T *Container<T>::Const_Iterator::operator->() const{
    return &(pointed->info);
}

template<class T>
bool Container<T>::Const_Iterator::operator ==(const Container<T>::Const_Iterator & i) const{
    return pointed==i.pointed;
}

template<class T>
bool Container<T>::Const_Iterator::operator !=(const Container<T>::Const_Iterator & i) const{
    return pointed!=i.pointed;
}

template <class T>
bool Container<T>::Const_Iterator::constHasNext() const{
    if(pointed->next)
        return true;
    else
        return false;
}

#endif // CONTAINER_H
