fn="$1"
rm -f a.out
clang++ -std=c++11 -stdlib=libc++ -Weverything $fn.cpp
./a.out < in
