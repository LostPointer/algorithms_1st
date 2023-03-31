#pragma once

#include <memory>
#include <stdexcept>

template <typename T>
struct Dot {
 private:
  Dot<T> *back = nullptr;
  Dot<T> *next = nullptr;
  T value = T();

 public:
  Dot<T>(Dot *finish1, T value1) : back(finish1), value(value1) {}
  Dot<T>(T value1) : value(value1) {}
  Dot<T>() {}
  Dot<T> *GetBack() { return this->back; }
  Dot<T> *GetNext() { return this->next; }
  T GetValue() { return this->value; }
};

template <typename T>
class Stack {
 public:
  void Push(T value);
  T Pop();
  int Size();
  ~Stack() {
    if (start_) delete start_;
    if (finish_) delete finish_;
  }

 private:
  Dot<T> *start_ = nullptr;
  Dot<T> *finish_ = nullptr;
  int size_ = 0;
};

template <typename T>
void Stack<T>::Push(T  /*value*/) {
  if (!start_) {
    Dot<T> *new_Dot = nullptr = new Dot(value);
    start_ = new_Dot;
    finish_ = new_Dot;
  } else {
    Dot<T> *new_Dot = nullptr = new Dot(finish_, value);
    auto tmp = finish_->GetNext();
    tmp = new_Dot;
    finish_ = new_Dot;
  }
  size_ += 1;
}

template <typename T>
T Stack<T>::Pop() {
  if (size_ > 1) {
    T value = finish_->GetValue();
    auto temp = std::unique_ptr<Dot<T>>(finish_);
    auto tmp = finish_->GetBack()->GetNext();
    tmp = nullptr;
    finish_ = finish_->GetBack();
    size_ -= 1;
    return value;
  } else if (size_ == 1) {
    T value = finish_->GetValue();
    auto temp = std::unique_ptr<Dot<T>>(finish_);
    start_ = nullptr;
    finish_ = nullptr;
    size_ -= 1;
    return value;
  } else
    throw std::out_of_range("Empty Stack");
}

template <typename T>
int Stack<T>::Size() {
  return size_;
}

template <typename T>
struct DotWithMin {
 public:
  DotWithMin<T> *back;
  DotWithMin<T> *next;
  T value;
  T min_value;
  DotWithMin<T>(DotWithMin<T> *finish1, T value1, T value2)
      : next(nullptr), back(finish1), value(value1), min_value(value2) {
    // value = value1;
    // min_value = value2;
  }
  DotWithMin<T>(T value1)
      : back(nullptr), next(nullptr), value(value1), min_value(value1) {
    // back = nullptr;
    // next = nullptr;
    // value = value1;
    // min_value = value1;
  }
};

template <typename T>
class MinStack {
 public:
  void Push(T value);
  T Pop();
  T GetMin();
  ~MinStack() {
    if (start_) delete start_;
    if (finish_) delete finish_;
  }

 private:
  DotWithMin<T> *start_ = nullptr;
  DotWithMin<T> *finish_ = nullptr;
  int size_ = 0;
};

template <typename T>
void MinStack<T>::Push(T value) {
  if (!start_) {
    DotWithMin<T> *new_Dot = new DotWithMin<T>(value);
    start_ = new_Dot;
    finish_ = new_Dot;
  } else {
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
    auto temp = std::unique_ptr<DotWithMin<T>>(finish_);
    finish_->back->next = nullptr;
    finish_ = finish_->back;
    size_ -= 1;
    return value;
  } else if (size_ == 1) {
    T value = finish_->value;
    auto temp = std::unique_ptr<DotWithMin<T>>(finish_);
    start_ = nullptr;
    finish_ = nullptr;
    size_ = 0;
    return value;
  } else
    throw std::out_of_range("Empty MinStack");
}

template <typename T>
T MinStack<T>::GetMin() {
  if (size_ > 0)
    return finish_->min_value;
  else
    throw std::out_of_range("Empty MinStack");
}