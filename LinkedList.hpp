#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

template <class T>
class List
{
    template <class T1>
    struct Node
    {
        T data;
        Node <T> * p_next;
        Node( int data, Node * p_next = nullptr ): data( data ), p_next( p_next ) {};
    };

    int size {}; // что бы считать сколько Node - ов
    Node <T> * p_head; // начало узла, тоже указатель так как все элементы из динамич. памяти

public:
    List();
    ~List();

    int get_size() { return size; }; // возвращает кол-во элементов

    T & operator[] ( int index ); // выводит элементы
    void push_front( T data ); // добавляет элем. в начале
    void push_back( T data ); // добавляет элем. в конце
    void pop_front(); // удаляет элем. в начале
    void pop_back(); // удаляет элем. в конце
    void insert( T data, int index ); // вставляет новый элемент
    void remove_at( int index ); // удаляет элемент
    void clear(); // очищает память
}; // class Link

#endif