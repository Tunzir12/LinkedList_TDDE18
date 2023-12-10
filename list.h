#ifndef LIST_H
#define LIST_H

class List
{
   private:
       struct Node{
        
         int element;
         Node* next;

         Node();

         Node(int value);
    };

   

     Node * first;

     int listSize;
     int get_element_recursive(Node*current,int index) const;

   public:

    List(const List& other);//copy constructor
    List(List&& other); //Move constructor
    int size() const;
  
    void insert(int value);
    void print() const;
    void remove(int value);
    int get_element_by_index(int index) const;
    bool is_empty() const;
    void remove_by_index(int index);
    List& operator = (const List& other);//copy assignment operator
    List& operator = (List&& other) noexcept;//move assignment operator
    
     List();
    ~List();
};

#endif
