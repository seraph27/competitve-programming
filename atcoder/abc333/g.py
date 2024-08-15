from fractions import Fraction
r, n = Fraction(input()), int(input())
print(*(r-Fraction('1e-29')).limit_denominator(n).as_integer_ratio())
