#include "hashtable.hpp"

#include <stdexcept>

HashTable::HashTable() { data_.resize(10000); }

bool HashTable::FirstInsert(std::string &&key, int value) {
  size_t index = (std::hash<std::string>{}(key)) % data_.size();
  if (data_[index] != nullptr)
    return false;
  data_[index] = new HashElement(std::move(key), value);
  return true;
}

void HashTable::Insert(std::string &&key, int value) {
  ++size_;
  if (FirstInsert(std::move(key), value))
    return;
  size_t index = (std::hash<std::string>{}(key)) % data_.size();
  HashElement *current_elem = data_[index];
  while (current_elem->next_ != nullptr || current_elem->key_ == key) {
    if (current_elem->key_ == key) {
      --size_;
      current_elem->value_ = value;
      return;
    }
    current_elem = current_elem->next_;
  }
  current_elem->next_ = new HashElement(std::move(key), value);
}

void HashTable::Remove(const std::string &key) {
  if (size_ == 0)
    throw std::out_of_range("Empty hashtable");

  size_t index = (std::hash<std::string>{}(key)) % data_.size();
  if (data_[index] == nullptr)
    throw std::out_of_range("Wrong key");

  HashElement *current_elem = data_[index];
  if (current_elem->key_ == key) {
    --size_;
    data_[index] = current_elem->next_;
    delete current_elem;
    return;
  }
  while (current_elem->next_->key_ != key) {
    if (current_elem->next_ == nullptr)
      throw std::out_of_range("Wrong key");
    current_elem = current_elem->next_;
  }
  --size_;
  HashElement *new_next = current_elem->next_->next_;
  delete current_elem->next_;
  current_elem->next_ = new_next;
}

int HashTable::Find(const std::string &key) const {
  if (size_ == 0)
    throw std::out_of_range("Empty hashtable");

  size_t index = (std::hash<std::string>{}(key)) % data_.size();
  if (data_[index] == nullptr)
    throw std::out_of_range("Wrong key");

  if (data_[index]->key_ == key)
    return data_[index]->value_;

  HashElement *current_elem = data_[index];
  while (current_elem->next_->key_ != key) {
    if (current_elem->next_ == nullptr)
      throw std::out_of_range("Wrong key");
    current_elem = current_elem->next_;
  }
  return current_elem->next_->value_;
}

size_t HashTable::Size() const { return size_; }