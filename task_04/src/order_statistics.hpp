#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>

template <typename T>
int RandomizedPartition(std::vector<T> &tmp, size_t left, size_t right) {
  size_t pivot = left + std::rand() % (right - left + 1);
  int less = left - 1;
  T pivot_value = tmp[pivot];
  std::swap(tmp[pivot], tmp[right]);
  for (size_t i = left; i < right; ++i) {
    if (tmp[i] <= pivot_value) {
      std::swap(tmp[++less], tmp[i]);
    }
  }
  std::swap(tmp[++less], tmp[right]);
  return less;
}

template <typename T>
T GetOrderStatistics(const std::vector<T> &data, size_t n) {
  if (data.empty())
    throw std::out_of_range("Empty vector");
  std::vector<T> tmp = data;
  size_t left = 0, right = tmp.size() - 1;
  int pivot = RandomizedPartition(tmp, left, right);
  while (pivot != n) {
    pivot = RandomizedPartition(tmp, left, right);
    if (pivot > n)
      right = pivot;
    else if (pivot < n)
      left = pivot + 1;
  }
  return tmp[n];
}