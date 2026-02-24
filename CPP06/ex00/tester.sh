#!/bin/bash

tests=(
#chars
"a" "Z" "0" "42" "-42"
#overflow
"2147483647" "2147483648"
#decimals
"42.0f" "-42.0f"
#not a number
"nan" "nanf"
#infinity
"+inf" "-inf"
"+inff" "-inff"
#doubles
"1e3" "1e309"
#words
"hello" "42abc"
)

for t in "${tests[@]}"
do
    echo "=========================="
    echo "Test: $t"
    ./converter "$t"
done
