#include <gtest/gtest.h>
#include <list.h>


constexpr unsigned SIZE = 10;
template<class List>
void initialize_linked_list(List& l , const unsigned S){
for (int i = 0; i < S; ++i)
 	l.add_tail(i);
}

/*
TEST(SinglyLinkedList, add_tail) {
  ctci::SinglyLinkedList<int> single_list;

  for (int i = 0; i < 10; ++i) {
    ASSERT_EQ(single_list.size(), i);
    single_list.add_tail(i);
    ASSERT_EQ(single_list.size(), i + 1);
  }
}
*/
TEST(DoublyLinkedList, add_tail){
 ctci::DoublyLinkedList<int> doubly_list;  

 for (int i = 0; i < 10; ++i)
 {
 	ASSERT_EQ(doubly_list.size(), i);
 	doubly_list.add_tail(i);
 	ASSERT_EQ(doubly_list.size(), i+1);
 doubly_list.print();
 }
 
 }


 TEST(DoublyLinkedList, add_front){
 ctci::DoublyLinkedList<int> doubly_list;  

 for (int i = 0; i < 10; ++i)
 {
 	ASSERT_EQ(doubly_list.size(), i);
 	doubly_list.add_front(i);
 	ASSERT_EQ(doubly_list.size(), i+1);
 	//doubly_list.print();
 }
 
 }

TEST(DoublyLinkedList, remove_front){
 ctci::DoublyLinkedList<int> doubly_list;  

initialize_linked_list(doubly_list , SIZE);
 while(doubly_list.size() > 0)
 {
 	doubly_list.remove_front();
 	//doubly_list.print();
 }
 
 }


TEST(DoublyLinkedList, remove_tail){
 ctci::DoublyLinkedList<int> doubly_list;  
initialize_linked_list(doubly_list , SIZE);

 while(doubly_list.size() > 0)
 {
 	doubly_list.remove_tail();
 	//doubly_list.print();
 }
 
 }


TEST(DoublyLinkedList, find_middle_element_in_one_pass_even){
 ctci::DoublyLinkedList<int> doubly_list;  
 initialize_linked_list(doubly_list , SIZE);
 doubly_list.print();
 ASSERT_EQ(doubly_list.middle_element_in_one_pass() , (SIZE)/2);

 }


TEST(DoublyLinkedList, find_middle_element_in_one_pass_odd){
 ctci::DoublyLinkedList<int> doubly_list;  
 initialize_linked_list(doubly_list , SIZE+1);
 doubly_list.print();
 ASSERT_EQ(doubly_list.middle_element_in_one_pass() , (SIZE)/2);

 }



 TEST(DoublyLinkedList, remove_duplicates_hash_map){
 ctci::DoublyLinkedList<int> doubly_list;  
 initialize_linked_list(doubly_list , SIZE*3+1);
 initialize_linked_list(doubly_list , SIZE*2+1);
 initialize_linked_list(doubly_list , SIZE*2+1);
 doubly_list.print();

doubly_list.remove_duplicates_hash_map();
doubly_list.print();
 }



int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}