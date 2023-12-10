#include "list.h"
#include<iostream>

List::List() : first{nullptr},listSize{0} {}
List::Node:: Node():element{0}, next{nullptr} {} 
List::Node::Node(int value):element{value},next{nullptr}  {}

List::~List(){
    while( first ) {
        Node * temp{ first };
        first = first -> next;
        delete temp;
    }
}



List::List(const List& other):first{nullptr} , listSize{other.listSize}{    //copy constructor

    Node * newCurrentVal{ other.first };
    Node * current{ nullptr };
    while(newCurrentVal){

        Node * newNode{ new Node(newCurrentVal -> element) };

        if(!first){
            first = newNode;
            current = first;
        } else{
            current -> next = newNode;
            current = current -> next;
        }
        newCurrentVal = newCurrentVal -> next;
    }

}

List::List(List&& other) : first(other.first), listSize(other.listSize) {
    other.first = nullptr;
    other.listSize = 0;
}

bool List::is_empty() const{
    return(first==nullptr);
}

List& List::operator=(const List& other) {
    if (this == &other) {  //self-assignment
        return *this;
    }

    List temp(other);

    // Swapping the contents of the temporary list with the current list
    std::swap(first, temp.first);
    std::swap(listSize, temp.listSize);

    return *this;
}

List& List::operator=(List&& other) noexcept {

    if (this != &other) {
    
        // Transferring ownership by moving the 'other' list's resources
        std::swap(first, other.first);
        std::swap(listSize, other.listSize);

    }
    return *this;
}

int List::size() const{

    return listSize;

}

void List::insert( int value ) 
{
    Node * tmp{ new Node( value )};
    if(!first || value < first->element){
        tmp -> next = first;
        first = tmp;
    } else{
        Node * current{ first };
        while(current -> next && value > current -> next -> element){
            current = current -> next;
        }
        tmp -> next = current -> next;
        current -> next = tmp;
    }

     listSize++;
}

void List::remove( int value ){

    Node * current{ first };
    Node * prev{ nullptr };
    while( current ){
        if( current -> element == value ){
            if( prev ){
                prev -> next = current -> next;
            }else{
                first = current -> next;
            }
            delete current;
            listSize--;
            return;
        }
        prev = current;
        current =  current -> next;
    }

}

int List::get_element_by_index(int index) const{
    return get_element_recursive( first , index );
}

int List::get_element_recursive( Node * current,int index ) const {

    if(index < 0){    //Handling negative index here

        return -1;
    }

    if(index == 0 && current){
        return current -> element;
    }
    if(!current){

        return -1; //Handling invalid Index

    }

    return get_element_recursive(current -> next,index - 1);
}

void List::remove_by_index(int index){
    if(index < 0 || index >= listSize || !first){

        return;

    }

    Node * current{ first };
    Node * prev{ nullptr };
    int currentIndex{ 0 };
    
    while(current && currentIndex < index){
        prev = current;
        current = current -> next;
        currentIndex++;
    }
    if(prev){
        prev -> next = current -> next;
    }else{
        first = current -> next;
    }
    delete current;
    listSize--;
}

void List::print() const{

    Node * current{ first };
    while(current){
        std::cout << current -> element << " ";
        current = current -> next;
    }

    std::cout << std::endl;

};
