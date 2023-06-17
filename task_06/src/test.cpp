
#include <gtest/gtest.h>

#include <vector>

#include "hashtable.hpp"

TEST(HashTable, Simple) {
  HashTable data;
  data.Insert("aaaa", 1);
  ASSERT_EQ(data.Find("aaaa"), 1);
  ASSERT_EQ(data.Size(), 1);
  data.Insert("aaaa", 2);
  ASSERT_EQ(data.Find("aaaa"), 2);
  ASSERT_EQ(data.Size(), 1);
}

TEST(HashTable, Medium) {
  HashTable data;
  data.Insert("ab", 4);
  data.Insert("ab", 7);
  data.Remove("ab");
  ASSERT_EQ(data.Size(), 0);
  data.Insert("c", 15);
  data.Insert("g", 26);
  data.Insert("a", 43);
  data.Insert("aaaa", 183);
  ASSERT_EQ(data.Find("c"), 15);
  ASSERT_EQ(data.Find("g"), 26);
  ASSERT_EQ(data.Find("a"), 43);
  ASSERT_EQ(data.Find("aaaa"), 183);
  data.Remove("a");
  ASSERT_ANY_THROW(data.Remove("a"));
  ASSERT_ANY_THROW(data.Find("a"));
  ASSERT_EQ(data.Find("aaaa"), 183);
  ASSERT_EQ(data.Size(), 3);
}