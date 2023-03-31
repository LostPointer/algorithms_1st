#pragma once

#include <vector>

template <typename T>
void Merge(std::vector<T> &data, int start, int center, int finish) {
  std::vector<T> array;
  int i = start, j = center;
  while (i < center && j < finish) {
    if (data[i] <= data[j]) {
      array.push_back(data[i]);
      i++;
    } else if (data[i] > data[j]) {
      array.push_back(data[j]);
      j++;
    }
  }
  while (i < center) {
    array.push_back(data[i]);
    i++;
  }
  while (j < finish) {
    array.push_back(data[j]);
    j++;
  }
  for (int k = 0; k < array.size(); k++) {
    data[start + k] = array[k];
  }
}

template <typename T>
void MergeVector(std::vector<T> &data, int start, int finish) {
  if (finish - start <= 1) {
    return;
  }
  int center = (finish + start) / 2;
  MergeVector(data, start, center);
  MergeVector(data, center, finish);
  Merge(data, start, center, finish);
}

template <typename T>
std::vector<T> Sort(const std::vector<T> &data) {
  std::vector<T> result = data;
  MergeVector(result, 0, result.size());
  return result;
}