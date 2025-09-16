#include "unity.h"
#include "integer_toolkit.h"

void test_divisible_by_2() {
  for (int i = 0; i < 1000; i += 2) {
    TEST_ASSERT_TRUE(intk_divisible_by_2(i));
  }
}

void test_divisible_by_3() {
  for (int i = 0; i < 1000; i += 3) {
    TEST_ASSERT_TRUE(intk_divisible_by_3(i));
  }
}

void test_divisible_by_4() {
  for (int i = 0; i < 1000; i += 4) {
    TEST_ASSERT_TRUE(intk_divisible_by_4(i));
  }
}

void test_divisible_by_5() {
  for (int i = 0; i < 1000; i += 5) {
    TEST_ASSERT_TRUE(intk_divisible_by_5(i));
  }
}