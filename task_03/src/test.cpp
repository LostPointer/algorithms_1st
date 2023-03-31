
#include <gtest/gtest.h>

#include "sort.hpp"

TEST(SortTest, SimpleInt) {
  ASSERT_EQ(Sort<int>({}), std::vector<int>{});
  ASSERT_EQ(Sort<int>({1}), std::vector<int>{1});
  ASSERT_EQ(Sort<int>({1, 2, 3}), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(Sort<int>({3, 2, 1}), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(Sort<int>({3, 2, -1}), (std::vector<int>{-1, 2, 3}));
}

TEST(SortTest, EvenInt) {
  ASSERT_EQ(Sort<int>({1, 1}), (std::vector<int>{1, 1}));
  ASSERT_EQ(Sort<int>({1, 1, 2, 3}), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(Sort<int>({1, 2, 1, 3}), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(Sort<int>({1, 1, 2, 3, 2}), (std::vector<int>{1, 1, 2, 2, 3}));
}

TEST(SortTest, SimpleChar) {
  ASSERT_EQ(Sort<char>({'a', 'a'}), (std::vector<char>{'a', 'a'}));
  ASSERT_EQ(Sort<char>({'c', 'a', 'd', 'b'}), (std::vector<char>{'a', 'b', 'c', 'd'}));
  ASSERT_EQ(Sort<char>({'d', 'a', 'd', 'a'}), (std::vector<char>{'a', 'a', 'd', 'd'}));
}