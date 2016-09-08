fn="$1"
rm -f a.out
g++ $fn.cpp
./a.out <in
