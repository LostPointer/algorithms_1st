#pragma once

#include <vector>

template <typename T>
void Merge(std::vector<T> &data, int p, int q, int r){
  std::vector <T> aboba;
  int i = p, j = q;
  while (i < q && j < r){
   if (data[i] <= data[j]){
    aboba.push_back(data[i]);
    i++;
   }
   else if (data[i] > data[j]){
    aboba.push_back(data[j]);
    j++;
   }
  }
  while(i < q){
    aboba.push_back(data[i]);
    i++;
  }
  while(j < r){
    aboba.push_back(data[j]);
    j++;
  }
  for (int k = 0; k < aboba.size(); k++){
    data[p +k] = aboba[k];
  }
}

template <typename T>
void MergeVector(std::vector<T> &data, int r, int p){
  if (p - r <= 1) {
    return;
  }
  int q = (p + r) / 2;
  MergeVector(data, r, q);
  MergeVector(data, q, p);
  Merge(data, r, q, p);
}




template <typename T>
std::vector<T> Sort(const std::vector<T>& data) {
  std::vector<T> result = data;
    MergeVector(result, 0, result.size());
  return result;
}