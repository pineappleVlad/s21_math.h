#include <math.h>
#include <stdio.h>
#define S21_PI 3.14159265358979323846L
#define S21_INF 1.0 / 0.0
#define S21_EPS 1e-10
#define S21_EXP 2.71828182845904523536028747135266250
#define S21_NAN (__builtin_nanf("0x7fc00000"))
#define S21_DBL_MAX 1.7976931348623158e+308

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_atan(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_factorial(int N);
long double s21_cos(double x);
long double s21_pow(double base, double expon);

// int main() {
//     long double x;
//     long double y;
//     x = s21_fmod(-0.0, 1.0 / 0.0);
//     y = fmod(-0.0, 1.0 / 0.0);
//     printf("%Lf      %Lf", x, y);
// }

int s21_abs(int x) {
  if (x < 0) {
    return -x;
  } else {
    return x;
  }
}

long double s21_fabs(double x) {
  if (x != x) {
    return x;
  }

  if (x < 0.0) {
    return x * -1.0;
  } else {
    return x;
  }
}

long double s21_acos(double x) {
  long double res = S21_NAN;
  if (x < 1 && x >= 0) res = s21_atan(s21_sqrt(1 - x * x) / x);
  if (x < 0 && x > -1) res = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  if (x == 1) res = 0;
  if (x == -1) res = S21_PI;
  return res;
}

long double s21_asin(double x) {
  long double res = S21_NAN;
  if (x > 1 || x < -1) return res;
  if (x == 1 || x == -1) res = S21_PI / (2 * x);
  if (x > -1 && x < 1) res = S21_PI / 2 - s21_acos(x);
  return res;
}

long double s21_atan(double x) {
  long double res = 0;
  if (x == S21_INF) return S21_PI / 2;
  if (x == S21_INF) return -S21_PI / 2;
  if (x != x) return x;
  if (x == 1) return 0.785398163;
  if (x == -1) return -0.785398163;
  int is_in_range = (x > -1 && x < 1);
  res = is_in_range ? x : 1.0 / x;
  for (int i = 1; i < 7000; i++) {
    double a = s21_pow(-1, i);
    double b = s21_pow(x, (1 + 2 * i) * (is_in_range ? 1 : -1));
    double c = 1 + 2 * i;
    res += a * b / c;
  }
  if (!is_in_range) res = (S21_PI * s21_fabs(x) / (2 * x)) - res;
  return res;
}

long double s21_ceil(double x) {
  if (x != x || x == S21_INF || x == -S21_INF) {
    return x;
  }
  int integerpart = (int)x;
  if (integerpart != x) {
    if (x > 0) {
      integerpart++;
    } else if (integerpart == 0 && x < 0) {
      return (double)-0.0;
    }
  }
  return (double)integerpart;
}

long double s21_floor(double x) {
  if (x != x || x == S21_INF || x == -S21_INF) {
    return x;
  }
  int integerpart = (int)x;
  if (x < 0.0 && x != integerpart) {
    integerpart--;
  }
  return (double)integerpart;
}

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (y == 0 || y == -0 || y == S21_NAN || x == S21_INF || x == -S21_INF ||
      x == S21_NAN)
    result = S21_NAN;
  else if (y == -S21_INF || y == S21_INF)
    result = x;
  else {
    long long int integerPart;
    integerPart = x / y;
    result = x - y * integerPart;
  }
  return result;
}

long double s21_log(double x) {
  if (x < 0 || x != x) {
    return (double)0.0 / 0.0;
  } else if (x == 0) {
    return -S21_INF;
  } else if (x == 1) {
    return (double)0.0;
  } else if (x == S21_INF) {
    return x;
  }

  int ex_pow = 0;
  double result = 0;
  double compare = 0;

  for (; x >= S21_EXP; x /= S21_EXP, ex_pow++) continue;

  for (int i = 0; i < 100; i++) {
    compare = result;
    result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
  }
  return (result + ex_pow);
}

long double s21_sin(double x) {
  long double res = 0, upper = 0, lower = 0;
  x = s21_fmod(x, 2 * S21_PI);
  for (int i = 0; i < 15; i++) {
    upper = s21_pow(-1, i) * s21_pow(x, 2 * i + 1);
    lower = s21_factorial(2 * i + 1);
    res += upper / lower;
  }
  return res;
}

long double s21_sqrt(double x) {
  long double left = 0;
  long double right = (x < 1) ? 1 : x;
  long double middle;
  if (x == S21_INF)
    middle = S21_INF;
  else if (x == -S21_INF || x < 0)
    middle = S21_NAN;
  else if (x == 0 || x == -0)
    middle = 0;
  else if (x == 1)
    middle = 1;
  else {
    middle = (left + right) / 2;
    while ((middle - left) > S21_EPS) {
      if ((middle * middle) > x)
        right = middle;
      else
        left = middle;
      middle = (left + right) / 2;
    }
  }
  return middle;
}

long double s21_tan(double x) {
  x = s21_fmod(x, S21_PI);
  long double cos_res = s21_cos(x);
  return !cos_res ? S21_NAN : s21_sin(x) / cos_res;
}

long double s21_factorial(int N) {
  if (N < 0) {
    return 0;
  }
  if (N == 0) {
    return 1;
  } else {
    return N * s21_factorial(N - 1);
  }
}

long double s21_pow(double base, double expon) {
  long double res;
  long double copy = base;

  if (copy != copy || copy == S21_INF || copy == -S21_INF) {
    return copy;
  }

  if (copy < 0) {
    copy = -copy;
    res = s21_exp(expon * s21_log(copy));
    if (s21_fmod(expon, 2) != 0) {
      res = -res;
    }
  } else {
    res = s21_exp(expon * s21_log(base));
  }
  return res;
}

long double s21_cos(double x) {
  long double res = S21_NAN;
  if (x != S21_INF || x != S21_INF || x != x) res = s21_sin(S21_PI / 2 - x);
  return res;
}

long double s21_exp(double x) {
  if (x == -S21_INF) {
    return (double)0.0;
  }
  if (x != x || x == S21_INF) {
    return x;
  }
  long double add_value = 1;
  long double series = 1;
  long double i = 1;
  while (s21_fabs(add_value) > S21_EPS) {
    add_value *= x / i;
    i += 1;
    series += add_value;
    if (series > S21_DBL_MAX) {
      series = S21_INF;
      break;
    }
  }
  return series;
}
