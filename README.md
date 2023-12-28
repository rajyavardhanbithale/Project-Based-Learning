
## OS
Simulate Page Replacement Algorithm: FIFO, LRU, LFU, OPT Techniques using C.

## PPL
# Secret Vault

## Problem Statement:

You are tasked with creating a secret vault that stores valuable items. The vault has a limited storage capacity. Your job is to design a C++ class `Vault` that hides the data related to the vault's contents and provides methods for interacting with the vault. The class should have the following functionalities:

1. **Initialization:** The class should be initialized with an integer `capacity`, representing the maximum number of items the vault can hold.

2. **Method 1: AddItem:** Implement a method `void AddItem(string item)`, which adds an item to the vault. If the vault is full, don't add the item.

3. **Method 2: RemoveItem:** Implement a method `void RemoveItem(string item)`, which removes an item from the vault if it exists.

4. **Method 3: ContainsItem:** Implement a method `bool ContainsItem(string item)`, which checks if the vault contains a specific item and returns true if the item is found, and false otherwise.

5. **Method 4: IsFull:** Implement a method `bool IsFull()`, which returns true if the vault is full and false if there is space for more items.

Write a C++ class `Vault` with these methods and ensure that the vault's data is hidden from direct access.

## Input:

The first line contains an integer `capacity` (1 <= capacity <= 100), the maximum number of items the vault can hold. The second line contains an integer `q` (1 <= q <= 100), the number of queries. The following `q` lines represent the queries. Each query has one of the following formats:

- "1 item" (Add the item to the vault)
- "2 item" (Remove the item from the vault)
- "3 item" (Check if the item is in the vault)
- "4" (Check if the vault is full)

## Output:

For each query of type 3, if the item is found in the vault, output "1." Otherwise, output "0."

For each query of type 4, if the vault is full, output "1." Otherwise, output "0."

For other query types, there is no output.

## Constraints:

- The item in each query is a string of alphanumeric characters, and its length is at most 20 characters.

## Example Test Cases:

### Test Case 1:

#### Input:
```plaintext
3
6
1 GoldBars
1 Diamonds
2 GoldBars
1 SilverCoins
3 Diamonds
4
```
