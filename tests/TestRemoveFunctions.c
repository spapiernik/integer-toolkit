#include "unity.h"
#include "integer_toolkit.h"

void test_remove_first_of() {
  int number;

  number = 312143;
  intk_remove_first_of(&number, 3);
  TEST_ASSERT_EQUAL(12143, number);
  number = 312143;
  intk_remove_first_of(&number, 1);
  TEST_ASSERT_EQUAL(32143, number);
  number = 312143;
  intk_remove_first_of(&number, 2);
  TEST_ASSERT_EQUAL(31143, number);
  number = 312143;
  intk_remove_first_of(&number, 121);
  TEST_ASSERT_EQUAL(343, number);
  number = 123132;
  intk_remove_first_of(&number, 123);
  TEST_ASSERT_EQUAL(132, number);
  number = 123132;
  intk_remove_first_of(&number, 132);
  TEST_ASSERT_EQUAL(123, number);
}

void test_remove_last_of() {
  int number;

  number = 312143;
  intk_remove_last_of(&number, 3);
  TEST_ASSERT_EQUAL(31214, number);
  number = 312143;
  intk_remove_last_of(&number, 1);
  TEST_ASSERT_EQUAL(31243, number);
  number = 312143;
  intk_remove_last_of(&number, 2);
  TEST_ASSERT_EQUAL(31143, number);
  number = 312141213;
  intk_remove_last_of(&number, 121);
  TEST_ASSERT_EQUAL(312143, number);
  number = 123132123;
  intk_remove_last_of(&number, 123);
  TEST_ASSERT_EQUAL(123132, number);
  number = 123132123;
  intk_remove_last_of(&number, 132);
  TEST_ASSERT_EQUAL(123123, number);
}

void test_remove_all() {
  int number;

  number = 1212121;
  intk_remove_all(&number, 1);
  TEST_ASSERT_EQUAL(222, number);
  number = 1212121;
  intk_remove_all(&number, 2);
  TEST_ASSERT_EQUAL(1111, number);
  number = 3003;
  intk_remove_all(&number, 0);
  TEST_ASSERT_EQUAL(33, number);
  number = 3003;
  intk_remove_all(&number, 3);
  TEST_ASSERT_EQUAL(0, number);
}

int equals_1(int digit) { return digit == 1; }
int equals_2(int digit) { return digit == 2; }
int equals_0(int digit) { return digit == 0; }
int equals_3(int digit) { return digit == 3; }

void test_remove_digit_if() {
  int number;

  number = 1212121;
  intk_remove_digit_if(&number, equals_1);
  TEST_ASSERT_EQUAL(222, number);
  number = 1212121;
  intk_remove_digit_if(&number, equals_2);
  TEST_ASSERT_EQUAL(1111, number);
  number = 3003;
  intk_remove_digit_if(&number, equals_0);
  TEST_ASSERT_EQUAL(33, number);
  number = 3003;
  intk_remove_digit_if(&number, equals_3);
  TEST_ASSERT_EQUAL(0, number);
}