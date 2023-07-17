#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdlib.h>

START_TEST(abs_test) {
  ck_assert_int_eq(s21_abs(-123), abs(-123));
  ck_assert_int_eq(s21_abs(123), abs(123));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(acos_test) {
  ck_assert_double_eq_tol(s21_acos(0), acos(0), 0.000001);
  ck_assert_double_eq_tol(s21_acos(-1), acos(-1), 0.000001);
  ck_assert_double_nan(s21_acos(INFINITY));
  ck_assert_double_nan(s21_acos(NAN));
  ck_assert_double_nan(s21_acos(-INFINITY));
  ck_assert_double_eq_tol(s21_acos(1), acos(1), 0.000001);
}
END_TEST

START_TEST(asin_test) {
  ck_assert_double_eq_tol(s21_asin(1), asin(1), 0.000001);
  ck_assert_double_eq_tol(s21_asin(-1), asin(-1), 0.000001);
  ck_assert_double_nan(s21_asin(INFINITY));
  ck_assert_double_nan(asin(INFINITY));
  ck_assert_double_nan(s21_asin(NAN));
  ck_assert_double_nan(asin(NAN));
  ck_assert_double_nan(s21_asin(-INFINITY));
  ck_assert_double_nan(asin(-INFINITY));
  ck_assert_double_nan(s21_asin(16));
  ck_assert_double_eq_tol(s21_asin(0), asin(0), 0.000001);
}
END_TEST

START_TEST(atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_double_eq(s21_atan(INFINITY), atan(INFINITY));
  ck_assert_double_nan(s21_atan(NAN));
  ck_assert_double_nan(atan(NAN));
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_nan(ceil(S21_NAN));
  ck_assert_ldouble_eq(s21_ceil(S21_INF), ceil(S21_INF));
  ck_assert_ldouble_eq(s21_ceil(-S21_INF), ceil(-S21_INF));
  ck_assert_ldouble_eq(s21_ceil(0.0), ceil(-0.0));
  ck_assert_ldouble_eq(s21_ceil(+0.0), ceil(+0.0));
  ck_assert_ldouble_eq(s21_ceil(+0), ceil(+0));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
  ck_assert_ldouble_eq(s21_ceil(0.0), ceil(0.0));
  ck_assert_ldouble_eq(s21_ceil(0.123), ceil(0.123));
  ck_assert_ldouble_eq(s21_ceil(1.123), ceil(1.123));
  ck_assert_ldouble_eq(s21_ceil(11.123), ceil(11.123));
  ck_assert_ldouble_eq(s21_ceil(22.123), ceil(22.123));
  ck_assert_ldouble_eq(s21_ceil(-0.123), ceil(-0.123));
  ck_assert_ldouble_eq(s21_ceil(-1.123), ceil(-1.123));
  ck_assert_ldouble_eq(s21_ceil(-11.123), ceil(-11.123));
  ck_assert_ldouble_eq(s21_ceil(-22.123), ceil(-22.123));
  ck_assert_ldouble_eq(s21_ceil(S21_EPS / 10), ceil(S21_EPS / 10));
  ck_assert_ldouble_eq(s21_ceil(-S21_EPS / 10), ceil(-S21_EPS / 10));
}
END_TEST

START_TEST(cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(999), cos(999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-999), cos(-999), 1e-6);
  ck_assert_ldouble_nan(s21_cos(S21_INF));
  ck_assert_ldouble_nan(s21_cos(-S21_INF));
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
}
END_TEST

START_TEST(exp_test) {
  ck_assert_ldouble_nan(exp(S21_NAN));
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_eq(s21_exp(S21_INF), exp(S21_INF));
  ck_assert_ldouble_eq(s21_exp(-S21_INF), exp(-S21_INF));
  ck_assert_ldouble_eq_tol(s21_exp(S21_EPS / 10), exp(S21_EPS / 10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-S21_EPS / 10), exp(-S21_EPS / 10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.1), exp(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0.1), exp(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(3), exp(3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-3), exp(-3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(S21_PI), exp(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-S21_PI), exp(-S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.0), exp(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0.0), exp(-0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(S21_EPS), exp(S21_EPS), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-S21_EPS), exp(-S21_EPS), 1e-6);
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_double_eq_tol(s21_fabs(568.36), fabs(568.36), 0.000001);
  ck_assert_double_eq_tol(s21_fabs(-14720.5689), fabs(-14720.5689), 0.000001);
  ck_assert_double_eq(s21_fabs(INFINITY), fabs(INFINITY));
  ck_assert_double_nan(s21_fabs(NAN));
  ck_assert_double_nan(fabs(NAN));
  ck_assert_double_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

START_TEST(floor_test) {
  ck_assert_ldouble_nan(floor(S21_NAN));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
  ck_assert_ldouble_eq(s21_floor(S21_INF), floor(S21_INF));
  ck_assert_ldouble_eq(s21_floor(-S21_INF), floor(-S21_INF));
  ck_assert_ldouble_eq(s21_floor(-0.0), floor(-0.0));
  ck_assert_ldouble_eq(s21_floor(+0.0), floor(+0.0));
  ck_assert_ldouble_eq(s21_floor(-0), floor(-0));
  ck_assert_ldouble_eq(s21_floor(+0), floor(+0));
  ck_assert_ldouble_eq(s21_floor(0.123), floor(0.123));
  ck_assert_ldouble_eq(s21_floor(1.123), floor(1.123));
  ck_assert_ldouble_eq(s21_floor(11.123), floor(11.123));
  ck_assert_ldouble_eq(s21_floor(22.123), floor(22.123));
  ck_assert_ldouble_eq(s21_floor(-0.123), floor(-0.123));
  ck_assert_ldouble_eq(s21_floor(-1.123), floor(-1.123));
  ck_assert_ldouble_eq(s21_floor(-11.123), floor(-11.123));
  ck_assert_ldouble_eq(s21_floor(-22.123), floor(-22.123));
  ck_assert_ldouble_eq(s21_floor(S21_EPS / 10), floor(S21_EPS / 10));
  ck_assert_ldouble_eq(s21_floor(-S21_EPS / 10), floor(-S21_EPS / 10));
}
END_TEST

START_TEST(fmod_test) {
  ck_assert_ldouble_nan(fmod(S21_NAN, 0.0));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 0.0));
  ck_assert_ldouble_nan(fmod(S21_INF, 0.0));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 0.0));
  ck_assert_ldouble_nan(fmod(-S21_INF, 0.0));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, 0.0));
  ck_assert_ldouble_nan(fmod(0.0, 0.0));
  ck_assert_ldouble_nan(s21_fmod(0.0, 0.0));
  ck_assert_ldouble_nan(fmod(-0.0, 0.0));
  ck_assert_ldouble_nan(s21_fmod(-0.0, 0.0));
  ck_assert_ldouble_nan(fmod(1.0, 0.0));
  ck_assert_ldouble_nan(s21_fmod(1.0, 0.0));
  ck_assert_ldouble_nan(fmod(-1.0, 0.0));
  ck_assert_ldouble_nan(s21_fmod(-1.0, 0.0));
  ck_assert_ldouble_nan(fmod(S21_INF, S21_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
  ck_assert_ldouble_nan(fmod(-S21_INF, S21_INF));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, S21_INF));
  ck_assert_ldouble_nan(fmod(S21_INF, 17));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 17));
  ck_assert_ldouble_nan(fmod(-S21_INF, 17));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, 17));
  ck_assert_ldouble_eq_tol(s21_fmod(1e-3, 1e-11), fmod(1e-3, 1e-11), 1e-6);
  ck_assert_ldouble_eq(s21_fmod(-0.0, S21_INF), fmod(-0.0, S21_INF));
  ck_assert_ldouble_eq(s21_fmod(0.0, S21_INF), fmod(0.0, S21_INF));
  ck_assert_ldouble_eq(s21_fmod(-0.0, -S21_INF), fmod(-0.0, -S21_INF));
  ck_assert_ldouble_eq(s21_fmod(0.0, -S21_INF), fmod(0.0, -S21_INF));
  ck_assert_ldouble_eq(s21_fmod(0.123, 1.0), fmod(0.123, 1.0));
  ck_assert_ldouble_eq(s21_fmod(1.123, 1.0), fmod(1.123, 1.0));
  ck_assert_ldouble_eq(s21_fmod(-1.123, 1.0), fmod(-1.123, 1.0));
  ck_assert_ldouble_eq(s21_fmod(-0.123, 1.0), fmod(-0.123, 1.0));
  ck_assert_ldouble_eq(s21_fmod(0.123, 11.11), fmod(0.123, 11.11));
  ck_assert_ldouble_eq(s21_fmod(1e-321, 1e-323), fmod(1e-321, 1e-323));
  ck_assert_ldouble_eq(s21_fmod(-S21_EPS, 10), fmod(-S21_EPS, 10));
}
END_TEST

START_TEST(log_test) {
  ck_assert_ldouble_nan(log(S21_NAN));
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_ldouble_nan(log(-1));
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_eq(s21_log(0), log(0));
  ck_assert_ldouble_eq(s21_log(-0.0), log(-0.0));
  ck_assert_ldouble_eq(s21_log(S21_INF), log(S21_INF));
  ck_assert_ldouble_eq(s21_log(1), log(1));
  ck_assert_ldouble_eq(s21_log(1 + 1e-20), log(1 + 1e-20));
  ck_assert_ldouble_eq_tol(s21_log(2), log(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(S21_EXP), log(S21_EXP), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(S21_PI), log(S21_PI), 1e-6);
}
END_TEST

START_TEST(pow_test) {
  ck_assert_ldouble_nan(pow(S21_NAN, 2));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 2));
  ck_assert_ldouble_nan(pow(S21_NAN, S21_INF));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_INF));
  ck_assert_ldouble_nan(pow(S21_NAN, -S21_INF));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -S21_INF));
  ck_assert_ldouble_nan(pow(0.0, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(0.0, S21_NAN));
  ck_assert_ldouble_nan(pow(-0.0, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(-0.0, S21_NAN));
  ck_assert_ldouble_eq(s21_pow(0, S21_INF), pow(0, S21_INF));
  ck_assert_ldouble_eq(s21_pow(0, -S21_INF), pow(0, -S21_INF));
}
END_TEST

START_TEST(sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(999), sin(999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-999), sin(-999), 1e-6);
  ck_assert_ldouble_nan(s21_sin(S21_INF));
  ck_assert_ldouble_nan(s21_sin(-S21_INF));
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
}
END_TEST

START_TEST(sqrt_test) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_eq(s21_sqrt(1), sqrt(1));
  ck_assert_ldouble_nan(s21_sqrt(-1));
  ck_assert_ldouble_eq_tol(s21_sqrt(999), sqrt(999), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(-999));
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
  ck_assert_ldouble_nan(s21_sqrt(-S21_INF));
  ck_assert_ldouble_nan(sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
}
END_TEST

START_TEST(tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(999), tan(999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-999), tan(-999), 1e-6);
  ck_assert_ldouble_nan(s21_sin(S21_INF));
  ck_assert_ldouble_nan(s21_sin(-S21_INF));
}
END_TEST

Suite *s21_math_suite(void) {
  Suite *suite = suite_create("s21_math");

  TCase *tcase = tcase_create("test");
  tcase_add_test(tcase, abs_test);
  tcase_add_test(tcase, fabs_test);
  tcase_add_test(tcase, acos_test);
  tcase_add_test(tcase, asin_test);
  tcase_add_test(tcase, atan_test);
  tcase_add_test(tcase, ceil_test);
  tcase_add_test(tcase, floor_test);
  tcase_add_test(tcase, fmod_test);
  tcase_add_test(tcase, exp_test);
  tcase_add_test(tcase, log_test);
  tcase_add_test(tcase, pow_test);
  tcase_add_test(tcase, sqrt_test);
  tcase_add_test(tcase, sin_test);
  tcase_add_test(tcase, cos_test);
  tcase_add_test(tcase, tan_test);
  suite_add_tcase(suite, tcase);

  return suite;
}

int main() {
  Suite *suite = s21_math_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? 0 : 1;
}
