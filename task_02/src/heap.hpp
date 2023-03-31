#pragma once

#include <cstddef>
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T>
class MinHeap {
 public:
  void Push(T value);
  T Pop();
  size_t Size();
  void ShiftDown(int index);
  void ShiftUp(int index);

 private:
  std::vector<T> data_;
};

template <typename T>
void MinHeap<T>::Push(T value) {
  data_.push_back(value);
  ShiftUp(data_.size() - 1);
}

template <typename T>
void MinHeap<T>::ShiftUp(int index) {
  if (index > 0 && data_[index] < data_[index / 2]) {
    std::swap(data_[index], data_[index / 2]);
    ShiftUp(index / 2);
  } else
    return;
}

template <typename T>
void MinHeap<T>::ShiftDown(int index) {
  if (2 * index + 1 > data_.size() - 1 || index > data_.size())
    return;
  else {
    if (data_[index] == data_[2 * index + 1] &&
        data_[2 * index + 1] == data_[2 * index + 2])
      return;
    else if (data_[index] > data_[2 * index + 1] &&
             data_[2 * index + 1] <= data_[2 * index + 2]) {
      std::swap(data_[2 * index + 1], data_[index]);
      ShiftDown(2 * index + 1);
    } else if (data_[index] > data_[2 * index + 2] &&
               data_[2 * index + 1] > data_[2 * index + 2]) {
      std::swap(data_[2 * index + 2], data_[index]);
      ShiftDown(2 * index + 2);
    }
  }
}

template <typename T>
T MinHeap<T>::Pop() {
  if (!data_.size()) throw std::out_of_range("Empty heap");
  T result = data_[0];
  if (data_.size() > 0) {
    data_[0] = data_.back();
    data_.pop_back();
    ShiftDown(0);
  }
  return result;
}

template <typename T>
size_t MinHeap<T>::Size() {
  return data_.size();
}