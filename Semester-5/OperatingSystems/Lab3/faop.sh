#!/bin/bash
echo -n "Enter first float: "
read a
echo -n "Enter second float: "
read b
echo "Addition: $(echo "$a + $b" | bc -l)"
echo "Subtraction: $(echo "$a - $b" | bc -l)"
echo "Multiplication: $(echo "$a * $b" | bc -l)"
echo "Division: $(echo "scale=2; $a / $b" | bc -l)"
