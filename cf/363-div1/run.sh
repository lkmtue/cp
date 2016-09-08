fn="$1"
rm -f a.out
clang++ $fn.cpp
./a.out < in
