#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

template <typename T>
class unique_ptr {
 public:
  unique_ptr() : ptr(nullptr){};
  unique_ptr(const T* const ip) : ptr(ip){};
  unique_ptr(const unique_ptr& obj) = delete;
  unique_ptr& operator=(const unique_ptr& src) = delete;
  unique_ptr(unique_ptr&& ip) noexcept
  {
  	this->ptr = ip->ptr;
  	ip->ptr = nullptr;
  }
  unique_ptr& operator=(unique_ptr&& obj)
  {
  	this->ptr = obj->ptr;
  	obj->ptr = nullptr;
  	return this;
  }
  bool operator bool(){
  	return (ptr != nullptr);
  }
  ~unique_ptr() {
    delete ptr;
    ptr = nullptr;
  }

 private:
  T* ptr;

}

int main()
{
  unique_ptr<int> ptr1();
  unique_ptr<int> ptr2();
  unique_ptr<int> ptr3();
  ptr1 = ptr2 = ptr3;
}

#endif
