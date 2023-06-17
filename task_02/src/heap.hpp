#pragma once

#include <cstddef>
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T> class MinHeap {
public:
  void Push(T value);
  T Pop();
  size_t Size();
  void Clear();
  T GetMin();
  T GetMax();

private:
  void SiftUp(T value);
  void SiftDown();
  std::vector<T> data_;
};

template <typename T> void MinHeap<T>::SiftUp(T value) {
  int index = data_.size() - 1;
  int swap_index = (index - 1) / 2;
  while (value < data_[swap_index]) {
    if (index == 0)
      break;
    data_[index] = data_[swap_index];
    data_[swap_index] = value;
    index = swap_index;
    swap_index = (index - 1) / 2;
  }
  if (data_.size() > 1 && data_[data_.size() - 2] > data_[data_.size() - 1])
    std::swap(data_[data_.size() - 2], data_[data_.size() - 1]);
}

template <typename T> void MinHeap<T>::SiftDown() {
  int index = 0, left_child_index = 2 * index + 1,
      right_child_index = 2 * index + 2;
  while ((data_[index] >= data_[left_child_index] &&
          left_child_index < data_.size()) ||
         (data_[index] >= data_[right_child_index] &&
          right_child_index < data_.size())) {
    if (data_[left_child_index] < data_[right_child_index] ||
        right_child_index >= data_.size()) {
      std::swap(data_[index], data_[left_child_index]);
      index = left_child_index;
      left_child_index = 2 * index + 1;
    } else {
      std::swap(data_[index], data_[right_child_index]);
      index = right_child_index;
      right_child_index = 2 * index + 2;
    }
    if (data_.size() >= index) {
      break;
    }
  }
  if (data_.size() > 1 && data_[data_.size() - 2] > data_[data_.size() - 1])
    std::swap(data_[data_.size() - 2], data_[data_.size() - 1]);
}

template <typename T> void MinHeap<T>::Push(T value) {
  data_.push_back(value);
  SiftUp(value);
}

template <typename T> T MinHeap<T>::Pop() {
  if (data_.empty())
    throw std::out_of_range("Empty heap");
  T result = data_.front();
  data_.front() = data_.back();
  data_.pop_back();
  SiftDown();
  return result;
}

template <typename T> size_t MinHeap<T>::Size() { return data_.size(); }

template <typename T> void MinHeap<T>::Clear() { return data_.clear(); }

template <typename T> T MinHeap<T>::GetMin() {
  if (data_.empty())
    throw std::out_of_range("Empty heap");
  return data_.front();
}

template <typename T> T MinHeap<T>::GetMax() {
  if (data_.empty())
    throw std::out_of_range("Empty heap");
  return data_.back();
}
