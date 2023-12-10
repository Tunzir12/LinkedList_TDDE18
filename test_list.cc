#include "catch.hpp"
#include "list.h"


//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) {
  List list{};

  REQUIRE( list.is_empty() == true );
  REQUIRE( list.size() == 0 );
  REQUIRE(list.get_element_by_index(0) == -1);
  REQUIRE(list.get_element_by_index(1) == -1);
  list.remove_by_index(0);
  REQUIRE( list.is_empty());
  REQUIRE( list.size() == 0);
  list.print();
}

TEST_CASE("Test remove_by_index on an empty list") {
  List emptyList{};

  emptyList.remove_by_index(0); 
  emptyList.remove_by_index(1); 

    
  REQUIRE(emptyList.size() == 0);
  REQUIRE(emptyList.is_empty() == true);
}

TEST_CASE("Testing copy and move constructor on empty list")
{
 List list1{};
 List copiedList = list1;
 REQUIRE( copiedList.size() == 0);
 List movedList = std::move(list1);
 REQUIRE( movedList.size() == 0);

}

TEST_CASE("Testing copy and move assignment operator on empty list")
{
  List list{};
  List copyOp = list;
  REQUIRE( copyOp.size() == 0);
  List moveOp = std::move(list);
  REQUIRE( moveOp.size() == 0);

}

TEST_CASE( "Insertion and deletion" ){
  List list1{};
  list1.insert(5);
  list1.insert(3);
  list1.insert(9);
  list1.insert(7);
  REQUIRE(list1.is_empty() == false);

  list1.print();
  list1.remove(5);
  list1.remove(3);
  list1.remove(9);
  list1.remove(7);
  REQUIRE(list1.is_empty() == true);


  list1.print();

  }

TEST_CASE("Insert new elements"){
  List list1{};
  list1.insert(6);
  list1.insert(2);
  list1.insert(8);
  list1.print();
  REQUIRE(list1.size() == 3);
  list1.insert(9);
  list1.insert(4);
  list1.print();
  REQUIRE(list1.size() == 5);

 REQUIRE(list1.get_element_by_index(0) == 2);
 REQUIRE(list1.get_element_by_index(4) == 9);
 REQUIRE(list1.get_element_by_index(-1) == -1);
 REQUIRE(list1.get_element_by_index(5) == -1);
 
}

TEST_CASE("Getting and Removing element by index"){
  List list2{};
  list2.insert(8);
  list2.insert(2);
  list2.insert(5);
  list2.insert(10);
  list2.print();

  list2.remove_by_index(3);
  list2.print();
  list2.remove_by_index(-1);

  list2.print();
  REQUIRE(list2.get_element_by_index(3) == -1);
  REQUIRE(list2.get_element_by_index(100) == -1);

}

TEST_CASE("Copy constructor"){

  List list4{};

  list4.insert(8);
  list4.insert(20);
  list4.insert(30);
  list4.insert(16);
  list4.insert(22);
  list4.print();

  List copiedList{list4};
  copiedList.print();

  list4.remove(20);
  list4.print();
  copiedList.print();

  REQUIRE(list4.size() == 4);
  REQUIRE(copiedList.size() == 5);

  copiedList.insert(42);
  REQUIRE(copiedList.size() == 6);
  copiedList.print();



}

TEST_CASE("move constructor"){
  
  List list5{};

  list5.insert(5);
  list5.insert(15);
  list5.insert(42);
  list5.insert(8);
  list5.insert(17);
  list5.print();

  List movedFrom{std::move(list5)};
  movedFrom.print();
  
  REQUIRE(list5.size() == 0);
  REQUIRE(movedFrom.size() == 5);
  movedFrom.insert(-12);
  movedFrom.print();
  REQUIRE(movedFrom.size() == 6);
  

}

TEST_CASE("Copy Assignment operator"){

  List list1{};
  List list2{};
  list2=list1;
  REQUIRE(list2.size() == 0);

  list1.insert(3);
  list1.insert(8);
  list1=list1;   ///self-assignment
  list2=list1;
  REQUIRE(list1.size() == 2);
  REQUIRE(list2.size() == 2);
  REQUIRE(list1.size() == 2);
  list1.remove(8);
  REQUIRE(list2.size() == 2);
  REQUIRE(list1.size() == 1);
  list2.insert(5);
  list2.insert(9);
  list2=list1;
  REQUIRE(list2.size() == 1);
  REQUIRE(list1.size() == 1);
  List list4{};
  List list5{};
  List list6{};

  list4.insert(12);
  list5.insert(13);
  list6.insert(15);

  list6=list5=list4;

  REQUIRE(list4.get_element_by_index(0) == 12);
  REQUIRE(list4.get_element_by_index(0) == 12);
  REQUIRE(list4.get_element_by_index(0) == 12);

}


TEST_CASE("Move assignment operator"){

   List list1{};
   list1.insert(8);
   list1.insert(10);
   list1 = std::move(list1);//self-assignment
   REQUIRE(list1.size() == 2); 
   List list2{};
   list2 = std::move(list1);
   REQUIRE(list2.size() == 2);
   List list3{};
   list2 = std::move(list3);
   REQUIRE(list2.size() == 0);
   list1.insert(6);
   list1.insert(26);

   list2.insert(99);
   list2.insert(9);

   list2=std::move(list1);
   REQUIRE(list2.size() == 2);
   list1.insert(10);
   list3.insert(20);

   list3=std::move(list2=std::move(list1));
   

   REQUIRE(list3.size() == 3);
   REQUIRE(list3.get_element_by_index(0) == 9);

}
