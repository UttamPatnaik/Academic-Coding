echo -n "Enter cost price: "
read cp
echo -n "Enter selling price: "
read sp

if [ $sp -gt $cp ]; then
    profit=$((sp - cp))
    echo "Profit: $profit"
elif [ $sp -lt $cp ]; then
    loss=$((cp - sp))
    echo "Loss: $loss"
else
    echo "No profit, no loss"
fi
