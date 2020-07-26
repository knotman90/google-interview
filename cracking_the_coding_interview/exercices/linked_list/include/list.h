#ifndef __LINKED_LIST
#define __LINKED_LIST

#include <cstddef>   // ptrdiff_t
#include <iostream>  // cout, endl
#include <iterator>  // iterator
#include <tuple>
#include <type_traits>  // remove_cv
#include <utility>      // swap
#include <unordered_set>      // unordered_set
//#define debug(STR) std::cout<<STR<<std::endl;
#define debug(STR) ;  // std::cout<<STR<<std::endl;

namespace {

template <typename T>
struct SinglyLinkedNode {
  SinglyLinkedNode(const T& t) : next(nullptr), value(t){};
  SinglyLinkedNode(T&& t) : next(nullptr), value(std::move(t)){};
  SinglyLinkedNode(const SinglyLinkedNode& t) = default;
  SinglyLinkedNode() : next(nullptr){};

  SinglyLinkedNode* next;
  T value;
};

template <typename T>
struct DoublyLinkedNode {
  DoublyLinkedNode(const T& t) : prev(nullptr), next(nullptr), value(t){};
  DoublyLinkedNode(T&& t) : prev(nullptr), next(nullptr), value(std::move(t)){};
  DoublyLinkedNode(const DoublyLinkedNode& t) = default;
  DoublyLinkedNode() : prev(nullptr), next(nullptr){};

  DoublyLinkedNode* prev;
  DoublyLinkedNode* next;
  T value;
};

}  // namespace

namespace ctci {

template <class Node>
Node* advance(size_t pos, Node* ptr) {
  pos = pos > 0 ? pos - 1 : 0;
  while (pos > 0) {
    ptr = ptr->next;
    pos--;
  }
  return ptr;
}

template <typename T, typename NodeType = SinglyLinkedNode<T> >
class List {
  using type = T;
  using node_type = NodeType;
  using node_ptr = node_type*;

 public:
  virtual void add_tail(T) = 0;
  virtual void add_front(T) = 0;
  virtual void remove_at(const size_t) = 0;
  virtual void remove(const T&) = 0;

  virtual void remove_front() { return remove_at(0); }
  virtual void remove_tail() { return remove_at(this->length); }

  virtual bool contains(const T& el) {
    auto [it, success] = this->find(el);
    return success;
  }

  virtual std::tuple<node_ptr, bool> find(const T& el) {
    node_ptr h = this->head;
    while (h) {
      if (h->value == el) return std::make_tuple(h, true);
    }
    return std::make_tuple(nullptr, false);
  }

  size_t size() const noexcept { return this->length; }

  void print(std::ostream& os = std::cout) const {
    debug(__PRETTY_FUNCTION__);
    node_ptr ptr = this->head;
    os << "[(size = " << this->length << ")\n\t";
    while (ptr) {
      os << ptr->value << ",";
      ptr = ptr->next;
    }
    os << std::endl << "]" << std::endl;
  }

  virtual ~List(){};
  List() : head(nullptr), tail(nullptr), length(0){};

  //-------EXERCICES---------

  /**************************************************
   *
   *Given a a list of size n return the middle element,
   *doing only one pass on the list
   *
   ***************************************************/
  T middle_element_in_one_pass() {
    node_ptr p1 = this->head;
    node_ptr p2 = p1->next;
    while (p2) {
      p1 = p1->next;

      p2 = p2->next;
      if (!p2) break;
      p2 = p2->next;
    }
    return p1->value;
  }

  void remove_duplicates_hash_map(){
    std::unordered_set<T> S;
    node_ptr p = this->head;
    unsigned pos = 0;
    while(p)
    {
      if(S.find(p->value) != S.end()){
        remove_at(pos);
        pos--;
      }
      else
        S.insert(p->value);

      p = p->next;
      pos++;    
    }
  }

  //--------------------------------
 protected:
  size_t length;
  NodeType* head;
  NodeType* tail;

  node_ptr advance(size_t pos) { return ctci::advance(pos, this->head); }
};

template <typename T>
class DoublyLinkedList : public List<T, DoublyLinkedNode<T> > {
  using node_type = DoublyLinkedNode<T>;
  using node_ptr = node_type*;

 public:
  DoublyLinkedList() : List<T, DoublyLinkedNode<T> >(){};
  ~DoublyLinkedList(){};

  inline void add_tail(T el) override {
    debug(__PRETTY_FUNCTION__);
    this->insert_after(std::move(el), this->length);
  }
  inline void add_front(T el) override {
    debug(__PRETTY_FUNCTION__);
    insert_before(el, 0);
  }

  void insert_after(T el, const size_t pos = 0) {
    node_ptr curr = this->advance(pos);
    node_ptr n = new node_type(std::move(el));
    if (!curr)
      this->head = this->tail = n;
    else {
      n->next = curr->next;
      if (!n->next) this->tail = n;
      n->prev = curr;
      curr->next = n;
    }
    this->length++;
  }

  void insert_before(T el, const size_t pos = 0) {
    node_ptr curr = this->advance(pos);
    node_ptr n = new node_type(std::move(el));
    if (!curr)
      this->head = this->tail = n;
    else {
      n->prev = curr->prev;
      if (!n->prev) this->head = n;
      n->next = curr;
      curr->prev = n;
    }
    this->length++;
  }

  void remove_at(const size_t index) override {
    debug(__PRETTY_FUNCTION__);
    node_ptr curr = this->advance(index);
    if (curr->prev)
      curr->prev->next = curr->next;
    else
      this->head = curr->next;

    if (curr->next)
      curr->next->prev = curr->prev;
    else
      this->tail = curr->prev;

    this->length--;
  };
  void remove(const T& el) override { debug(__PRETTY_FUNCTION__); };

 private:
};
/*
  template <typename T>
  class SinglyLinkedList : public List<T, SinglyLinkedNode<T> > {
    using node_type = SinglyLinkedNode<T>;
    using node_ptr = node_type*;

   public:
    SinglyLinkedList() : List<T, SinglyLinkedNode<T> >(){};
    ~SinglyLinkedList(){};

    void add_tail(T el) override {
      node_ptr n = new node_type(std::move(el));
      debug(__PRETTY_FUNCTION__);
      if (!this->head) {
        this->head = this->tail = n;
      } else {
        this->tail->next = n;
        this->tail = n;
      }
      this->length++;
    }


    void add_front(T el) override{};
    void remove(const size_t index) override{};
    void remove(const T& el) override{};

   protected:

  };
*/
}  // namespace ctci

#endif  //__LINKED_LIST