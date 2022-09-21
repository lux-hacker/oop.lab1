#include "List.h"

template<class Type>
list::ListNode<Type>::ListNode(Type& data) {
    this->data = new Type(data);
    this->next = nullptr;
}

template<class Type>
Type& list::ListNode<Type>::getData() const {
    return *(this->data);
}

template<class Type>
void list::ListNode<Type>::setNext(list::ListNode<Type> *next) {
    this->next = next;
}

template<class Type>
list::ListNode<Type> *list::ListNode<Type>::getNext() {
    return this->next;
}

template<class Type>
list::ListNode<Type>::~ListNode() {
    delete this->data;
}

template<class Type>
list::List<Type>::List() {
    this->head = nullptr;
    this->tail = nullptr;
    this->buf = nullptr;
}

template<class Type>
list::List<Type>::~List() {
    this->buf = this->head;
    while(this->buf != nullptr){
        ListNode<Type>* t = this->buf;
        this->buf = this->buf->getNext();
        delete t;
    }
}

template<class Type>
void list::List<Type>::add(Type &data) {
    this->tail->setNext(new ListNode<Type>(data));
    this->tail = this->tail->getNext();
}

