#ifndef LAB1_1_LIST_H
#define LAB1_1_LIST_H

namespace list {
    template<class Type>
    class ListNode {
    protected:
        Type *data;
        ListNode *next;
    public:
        explicit ListNode(Type &);

        ~ListNode();

        Type &getData() const;

        ListNode *getNext();

        void setNext(ListNode *);
    };

    template<class Type>
    class List {
        ListNode<Type> *head;
        ListNode<Type> *tail;
        ListNode<Type> *buf;
    public:
        List();

        ~List();

        void add(Type &);
    };

}

#endif //LAB1_1_LIST_H
