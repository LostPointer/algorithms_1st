
#include <gtest/gtest.h>

#include "order_statistics.hpp"

TEST(OrderStatistics, Simple_int) {
  std::vector<int> data{1, 2, 5, 1, 7, 9, 11, 213, 12, 51, 17, 99};
  ASSERT_EQ(GetOrderStatistics<int>(data, 1), 1);
  ASSERT_EQ(GetOrderStatistics<int>(data, 2), 2);
  ASSERT_EQ(GetOrderStatistics<int>(data, 3), 5);
  ASSERT_EQ(GetOrderStatistics<int>(data, 4), 7);
  ASSERT_EQ(GetOrderStatistics<int>(data, 10), 99);
}

TEST(OrderStatistics, Simple_float) {
  std::vector<double> data{1.2,  2.3,  5.4,     1.2,  7.12, 9.23,
                           11.5, 213., 12.2376, 51.2, 17.1, 99.003};
  ASSERT_EQ(GetOrderStatistics<double>(data, 1), 1.2);
  ASSERT_EQ(GetOrderStatistics<double>(data, 2), 2.3);
  ASSERT_EQ(GetOrderStatistics<double>(data, 3), 5.4);
  ASSERT_EQ(GetOrderStatistics<double>(data, 4), 7.12);
  ASSERT_EQ(GetOrderStatistics<double>(data, 10), 99.003);
}

TEST(OrderStatistics, Simple_char) {
  std::vector<double> data{'b', 'c', 'd', 'a', 'f'};
  ASSERT_EQ(GetOrderStatistics<double>(data, 0), 'a');
  ASSERT_EQ(GetOrderStatistics<double>(data, 1), 'b');
  ASSERT_EQ(GetOrderStatistics<double>(data, 2), 'c');
  ASSERT_EQ(GetOrderStatistics<double>(data, 3), 'd');
  ASSERT_EQ(GetOrderStatistics<double>(data, 4), 'f');
}

TEST(OrderStatistics, Empty) {
  ASSERT_ANY_THROW(GetOrderStatistics<int>({}, 1));
}
