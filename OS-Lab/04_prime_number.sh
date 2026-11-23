#!/bin/bash

is_prime() {
    num=$1
    if [ $num -lt 2 ]; then
        echo "$num is not prime."
        exit 1
    fi

    for ((i=2; i*i<=num; i++)); do
        if [ $((num % i)) -eq 0 ]; then
            echo "$num is not prime."
            exit 1
        fi
    done
    echo "$num is prime."
}

echo "Enter a Number"
read n
is_prime $n
