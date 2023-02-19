#pragma once

#include <vector>

template <typename T>
struct Dot{
  public:
    Dot *back;
    Dot *next;
    T value;
    Dot(Dot *finish1, T value1){
      next = nullptr;
      back = finish1;
      value = value1;
    }
    Dot(T value1){
      back = nullptr;
      next = nullptr;
      value = value1;
    }
};

template <typename T>
class Stack {
  public:
    void Push(T value);
    T Pop();
    int Size();
    ~Stack(){
      delete start_;
      delete finish_;
    }
  
  private:
    Dot<T> *start_ = nullptr;
    Dot<T> *finish_ = nullptr;
    int size_;
};

template <typename T>
void Stack<T>::Push(T value) { 
  if (not start_){
    Dot<T> *new_Dot = new Dot(value);
    start_ = new_Dot;
    finish_ = new_Dot;
  }
  else{
    Dot<T> *new_Dot = new Dot(finish_, value);
    finish_->next = new_Dot;
    finish_ = new_Dot;
  }
  size_ += 1;
}

template <typename T>
T Stack<T>::Pop() {
  if (size_ > 1) {
    T value = finish_->value;
    Dot<T> *temp = finish_;
    finish_->back->next = nullptr;
    finish_ = finish_->back;
    delete temp;
    size_ -= 1;
    return value;
  }
  else if (size_ == 1){
    T value = finish_->value;
    Dot<T> *temp = finish_;
    start_ = nullptr;
    finish_ = nullptr;
    delete temp;
    size_ -= 1;
    return value;
  }
  else return T();
}


template <typename T>
int Stack<T>::Size(){
  return size_;
}

template <typename T>
struct DotWithMin{
  public:
    DotWithMin *back;
    DotWithMin *next;
    T value;
    T min_value;
    DotWithMin(DotWithMin *finish1, T value1, T value2){
      next = nullptr;
      back = finish1;
      value = value1;
      min_value = value2;
    }
    DotWithMin(T value1){
      back = nullptr;
      next = nullptr;
      value = value1;
      min_value = value1;
    }
};


template <typename T>
class MinStack {
  public:
    void Push(T value);
    T Pop();
    T GetMin();
  ~MinStack(){
      delete start_;
      delete finish_;
    }
  
  private:
    DotWithMin<T> *start_ = nullptr;
    DotWithMin<T> *finish_ = nullptr;
    int size_;
    
};

template <typename T>
void MinStack<T>::Push(T value) { 
  if (not start_){
    DotWithMin<T> *new_Dot = new DotWithMin(value);
    start_ = new_Dot;
    finish_ = new_Dot;
  }
  else{
    T min_value = (finish_->min_value < value) ? finish_->min_value : value;
    DotWithMin<T> *new_Dot = new DotWithMin<T>(finish_, value, min_value);
    finish_->next = new_Dot;
    finish_ = new_Dot;
  }
  size_ += 1;
}

template <typename T>
T MinStack<T>::Pop() {
  if (size_ > 1) {
    T value = finish_->value;
    DotWithMin<T> *temp = finish_;
    finish_->back->next = nullptr;
    finish_ = finish_->back;
    delete temp;
    size_ -= 1;
    return value;
  }
  else if (size_ == 1){
    T value = finish_->value;
    DotWithMin<T> *temp = finish_;
    start_ = nullptr;
    finish_ = nullptr;
    delete temp;
    size_ -= 1;
    return value;
  }
  else return T();
}


template <typename T>
T MinStack<T>::GetMin() {
  if (size_ > 0) return finish_->min_value;
  else return T();
}