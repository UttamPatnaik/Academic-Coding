echo "Enter 10 numbers:"

declare -a seen     # array to store unique numbers
count=0
even=0
odd=0

for i in {1..10}
do
    read num
    
    is_duplicate=0   # counter/flag for duplicate detection

    # Check if number already exists in the array
    for val in "${seen[@]}"
    do
        if [ "$val" -eq "$num" ]; then
            is_duplicate=1
            break
        fi
    done

    # If duplicate → skip processing
    if [ $is_duplicate -eq 1 ]; then
        echo "Duplicate number $num found — skipping..."
        continue
    fi
echo "Enter 10 numbers:"
even=0
odd=0

for i in {1..10}; do
    read num
    if [ $((num % 2)) -eq 0 ]; then
        even=$((even + 1))
    else
        odd=$((odd + 1))
    fi
done

echo "Even numbers: $even"
echo "Odd numbers: $odd"

    # Store number in array
    seen+=("$num")

    # Count even and odd
    if [ $((num % 2)) -eq 0 ]; then
        even=$((even + 1))
    else
        odd=$((odd + 1))
    fi
done

echo "Even numbers: $even"
echo "Odd numbers: $odd"
