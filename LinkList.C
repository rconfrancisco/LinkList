#include <iostream>

template <typename T>
class LList_t {

private:

  struct Node_t {
    T data;
    Node_t* next;
    Node_t* prev;
    explicit Node_t (T value) : data(value), next(0), prev(0) {};
  };

  Node_t* head;
  Node_t* tail;
  
public:

  LList_t() : head(0), tail(0){};

  void add(T data) {
    Node_t* newNode = new Node_t(data);
    if(!newNode) return;
    if(!head) {
      head = newNode;
      tail = newNode;
    }
    else { 
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    return;
  }

  Node_t* find(T data) {
    if(!head) return 0;
    Node_t* currPtr = head;
    if(head->data == data) return head;
    while(currPtr->next) {
      currPtr = currPtr->next;
      if(currPtr->data == data) return currPtr;
    }
    return 0;
  }

  bool remove(T data) {

    Node_t *node = find(data);
    if(node == 0) return false;
    Node_t* prevNode = node->prev;
    Node_t* nextNode = node->next;
    if(!prevNode) {
      head = nextNode;
    }
    else {
      prevNode->next = nextNode;
    }
    if(!nextNode) {
      tail = prevNode;;
    }
    else {
      nextNode->prev = prevNode;
    }
    delete node;
    return true;
  }

  void print () {
    Node_t* currPtr = head;
    while(currPtr) {
      std::cout << currPtr->data << " ";
      currPtr = currPtr->next;
    }
    std::cout << std::endl
	      << " Head = " << ((head) ? head->data : 0 ) 
	      << " Tail = " << ((tail) ? tail->data : 0 ) 
	      << std::endl;
    return;
  };
};

int main() {

  LList_t<int> i;
  i.add(3);
    i.add(4);
  i.print();
  i.remove(3);
  i.print();
  i.remove(4);
  std::cout << "Should be empty" << std::endl;
  i.print();
  i.add(1);
  i.print();
  i.remove(1);
  std::cout << "Should be empty" << std::endl;
  i.print();
  i.add(2);
  i.print();
  i.add(3);
  i.print();
  i.add(4);
  i.print();
  i.add(5);
  i.print();
  i.add(6);
  std::cout << "should be 2 3 4 5 6 " << std::endl;
  i.print();
  std::cout << "removing 4" << std::endl;
  i.remove(4);
  i.print();

  LList_t<float> f;
  f.add(3.1);
  f.add(4.1);
  std::cout << "Now Float 3.1 4.1" << std::endl;
  f.print();
  f.remove(3.1);
  f.print();
  f.remove(4.1);
  std::cout << "Should be empty" << std::endl;
  f.print();
  f.add(1);
  f.print();
  f.remove(1);
  std::cout << "Should be empty" << std::endl;
  f.print();
  f.add(2);
  f.print();
  f.add(3.1);
  f.print();
  f.add(4.1);
  f.print();
  f.add(5);
  f.print();
  f.add(6);
  std::cout << "Should be 2 3.1 4.1 5 6 " << std::endl;
  f.print();
  std::cout << "removing 4.1" << std::endl;
  f.remove(4.1);
  f.print();
  return 0;
}

    
