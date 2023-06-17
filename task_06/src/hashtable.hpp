#pragma once

#include <cstddef>
#include <string>
#include <vector>

struct HashElement {
  HashElement(std::string &&key, int value) : key_(key), value_(value) {}
  std::string key_;
  int value_;
  HashElement *next_ = nullptr;
};

class HashTable {
public:
  HashTable();
  void Insert(std::string &&key, int value);
  void Remove(const std::string &key);
  int Find(const std::string &key) const;
  size_t Size() const;

private:
  bool FirstInsert(std::string &&key, int value);
  std::vector<HashElement *> data_{};
  size_t size_ = 0;
};