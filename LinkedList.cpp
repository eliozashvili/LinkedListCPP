#include "LinkedList.hpp"

template <class T>
List <T>::List(): size ( 0 ), p_head ( nullptr ) {};

template <class T>
List <T>::~List() { clear(); };

template <class T>
void List <T>::clear()
{
    while ( size )
    {
        pop_front();
    }
}

template <class T>
void List <T>::remove_at( int index )
{
    if ( index == 0 )
    {
        pop_front();
    }
    else
        {
            Node <T> * p_previous = this->p_head;

            for (int i {0}; i < index - 1; i++)
            {
                p_previous = p_previous->p_next;
            }

            Node <T> * p_to_delete = p_previous->p_next;
            p_previous->p_next = p_to_delete->p_next;

            delete p_to_delete;

            size--;
        }
}

template <class T>
void List <T>::pop_front()
{
    Node <T> * p_temp = p_head;
    p_head = p_head->p_next;

    delete p_temp;

    size--;
}

template <class T>
void List <T>::pop_back()
{
    remove_at( size - 1 );
}

template <class T>
void List <T>::push_front( T data )
{
    p_head = new Node( data, p_head );
    size++;
}

template <class T>
void List <T>::push_back( T data )
{
    if (p_head == nullptr)
    {
        p_head = new Node <T>( data );
    }
    else
        {
            Node <T> * p_current = this->p_head;

            while (p_current->p_next != nullptr)
            {
                p_current = p_current->p_next;
            }
            p_current->p_next = new Node <T>( data );
        }
        size++;
}

template <class T>
void List <T>::insert( T data, int index )
{
    if (index == 0)
    {
        push_front( data );
    }
    else
        {
            Node <T> * p_previous = this->p_head;

            for (int i {0}; i < index - 1; i++)
            {
                p_previous = p_previous->p_next;
            }
            p_previous->p_next = new Node <T>( data, p_previous->p_next );
        }
}

template <class T>
T & List <T>::operator[] ( const int index )
{
    int count {};

    Node <T> * p_current = this->p_head;

    while ( p_current != nullptr )
    {
        if ( count == index )
        {
            return p_current->data;
        }
        p_current = p_current->p_next;
        count++;
    }
}