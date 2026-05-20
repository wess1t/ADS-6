// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
  struct N {
    T data;
    N* next;
    N(const T& val) : data(val), next(nullptr) {}
  };
  N* head;
public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (head != nullptr)
      pop();
  }
  void push(const T& item) {
    N* newN = new N(item);
    if (head == nullptr || item.prior > head->data.prior) {
      newN->next = head;
      head = newN;
      return;
    }
    N* current = head;
    while (current -> next != nullptr && current->next->data.prior >= item.prior)
      current = current->next;
    newN->next = current->next;
    current->next = newN;
  }
  T pop() {
    N* temp = head;
    T res = temp->data;
    head = head->next;
    delete temp;
    return res;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
