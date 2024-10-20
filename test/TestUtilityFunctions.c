#include "unity.h"
#include "integer_toolkit.h"

void test_concat() {
  TEST_ASSERT_EQUAL(123, intk_concat(3, 1, 2, 3));
  TEST_ASSERT_EQUAL(9650, intk_concat(4, 9, 6, 5, 0));
}

void test_with_zeros() {
  TEST_ASSERT_EQUAL(1, intk_with_zeros(1, 0));
  TEST_ASSERT_EQUAL(10, intk_with_zeros(1, 1));
  TEST_ASSERT_EQUAL(100, intk_with_zeros(1, 2));
  TEST_ASSERT_EQUAL(1000, intk_with_zeros(1, 3));
  TEST_ASSERT_EQUAL(10000, intk_with_zeros(1, 4));
  TEST_ASSERT_EQUAL(100000, intk_with_zeros(1, 5));
  TEST_ASSERT_EQUAL(1000000, intk_with_zeros(1, 6));
  TEST_ASSERT_EQUAL(10000000, intk_with_zeros(1, 7));
}

void test_set_digit() {
  int number;

  // number = 990;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(90, number);
  // number = 990;
  // intk_set_digit(&number, 1, 0);
  // TEST_ASSERT_EQUAL(900, number);

  // number = 9;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(0, number);
  // number = 90;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(0, number);
  // number = 900;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(0, number);
  // number = 9000;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(0, number);
  // number = 90000;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(0, number);
  // number = 900000;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(0, number);

  // number = 19;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(9, number);
  // number = 10;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(9, number);
  // number = 1009;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(9, number);
  // number = 10009;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(9, number);
  // number = 100009;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(9, number);
  // number = 1000009;
  // intk_set_digit(&number, 0, 0);
  // TEST_ASSERT_EQUAL(9, number);

  // number = 200000;
  // intk_set_digit(&number, 0, 1);
  // // printf("\nThe number is: %i\n", number);
  // intk_set_digit(&number, 1, 2);
  // // printf("\nThe number is: %i\n", number);
  // intk_set_digit(&number, 2, 3);
  // // printf("\nThe number is: %i\n", number);
  // intk_set_digit(&number, 3, 4);
  // // printf("\nThe number is: %i\n", number);
  // intk_set_digit(&number, 4, 5);
  // // printf("\nThe number is: %i\n", number);
  // intk_set_digit(&number, 5, 6);
  // // printf("\nThe number is: %i\n", number);
  // // TEST_ASSERT_EQUAL(123456, number);
}

void test_swap() {
  // int number;

  // number = 13;
  // intk_swap(&number, 0, 1);
  // TEST_ASSERT_EQUAL(31, number);
  // number = 100;
  // intk_swap(&number, 0, 1);
  // TEST_ASSERT_EQUAL(10, number);
  // number = 102;
  // intk_swap(&number, 0, 2);
  // TEST_ASSERT_EQUAL(201, number);
}

void test_clamp() {
  for (int i = 2; i < 13; ++i) {
    TEST_ASSERT_TRUE(
      intk_in_range(intk_clamp(i, i - 1, i + 1), i - 1, i + 1)
    );
    TEST_ASSERT_TRUE(
      intk_in_range(intk_clamp(i, i + 1, i + 2), i + 1, i + 2)
    );
    TEST_ASSERT_TRUE(
      intk_in_range(intk_clamp(i, i - 1, i - 2), i - 2, i - 1)
    );
  }
}