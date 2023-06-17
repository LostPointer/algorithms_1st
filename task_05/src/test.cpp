
#include <gtest/gtest.h>

#include "tree.hpp"

TEST(AVL_Tree, Simple) {
  AVL_Tree data;
  data.Insert(3, 4);
  data.Insert(6, 1);
  data.Insert(2, 10);
  ASSERT_EQ(data.Find(2), 10);
  ASSERT_EQ(data.Find(6), 1);
  ASSERT_EQ(data.Find(3), 4);
  ASSERT_EQ(data.Size(), 3);
}

TEST(AVL_Tree, Medium) {
  AVL_Tree data;

  data.Insert(2, 4);
  data.Insert(4, 1);
  data.Insert(9, 10);
  data.Insert(8, 15);
  data.Insert(6, 3);
  ASSERT_EQ(data.Size(), 5);
  ASSERT_EQ(data.Find(4), 1);
  ASSERT_EQ(data.Find(2), 4);
  ASSERT_EQ(data.Find(8), 15);
  ASSERT_EQ(data.Find(6), 3);
  ASSERT_EQ(data.Find(9), 10);
  ASSERT_ANY_THROW(data.Find(24));
  ASSERT_ANY_THROW(data.Remove(5));
  data.Remove(4);
  ASSERT_EQ(data.Size(), 4);
  ASSERT_EQ(data.Find(2), 4);
  ASSERT_EQ(data.Find(8), 15);
  ASSERT_EQ(data.Find(6), 3);
  ASSERT_EQ(data.Find(9), 10);
}