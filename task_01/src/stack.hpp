#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
 public:
  void Push(T value);
  T Pop();
  T Back();
  size_t Size();
  void Clear();

 private:
  std::vector<T> data_;
};

template <typename T>
void Stack<T>::Push(T value) {
  data_.push_back(value);
}

template <typename T>
T Stack<T>::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty stack");
  T result = data_.back();
  data_.pop_back();
  return result;
}

template <typename T>
T Stack<T>::Back() {
  if (data_.empty()) throw std::out_of_range("Empty stack");
  return data_.back();
}

template <typename T>
size_t Stack<T>::Size() {
  return data_.size();
}

template <typename T>
void Stack<T>::Clear() {
  data_.clear();
}

template <typename T>
class MinStack {
 public:
  void Push(T value);
  T Pop();
  T GetMin();
  T Back();
  int Size();
  void Clear();

 private:
  std::vector<T> min_values_;
  std::vector<T> data_;
};

template <typename T>
void MinStack<T>::Push(T value) {
  if (data_.empty() || min_values_.back() >= value)
    min_values_.push_back(value);
  data_.push_back(value);
}

template <typename T>
T MinStack<T>::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty stack");
  T result = data_.back();
  data_.pop_back();

  if (result == min_values_.back()) min_values_.pop_back();
  return result;
}

template <typename T>
T MinStack<T>::GetMin() {
  if (data_.empty()) throw std::out_of_range("Empty stack");
  return min_values_.back();
}

template <typename T>
T MinStack<T>::Back() {
  if (data_.empty()) throw std::out_of_range("Empty stack");
  return data_.back();
}

template <typename T>
int MinStack<T>::Size() {
  return data_.size();
}

template <typename T>
void MinStack<T>::Clear() {
  data_.clear();
}
