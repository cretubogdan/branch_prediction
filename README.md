# Branch Prediction
Small test to demonstrate branch prediction power

## Output Branch Prediction Test 1:
[C11]: Counter: 498861000 with branch prediction: False in 9s  
[C11]: Counter: 500436000 with branch prediction: True in 2s  
[PY3]: Counter: 499812000 with branch prediction: False in 78s  
[PY3]: Counter: 499941000 with branch prediction: True in 72s  

## Output Branch Prediction Test 2:
Without -O3:  
Counted: 2147483647 odd numbers and: 2147483648 even numbers, in: 1068s with BP set to: False  
Counted: 2147483647 odd numbers and: 2147483648 even numbers, in: 603s with BP set to: True  
With -O3:  
Counted: 2147483647 odd numbers and: 2147483648 even numbers, in: 34s with BP set to: False  
Counted: 2147483647 odd numbers and: 2147483648 even numbers, in: 0s with BP set to: True  
