from math import *
from decimal import *
import sys

n, k = map(int, raw_input().split())

getcontext().prec = k +0 10

f = int(floor(sqrt(n)))

if f ** 2 == n:
    sys.stdout.write(str(str(f) + '.' + ('0' * k)))
else:
    s = str(Decimal(n).sqrt())
    sys.stdout.write(str(s[:(s.find('.') + k + 1)]))
