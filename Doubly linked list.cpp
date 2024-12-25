#include "file.h"
#include <bits/stdc++.h> // Include standard libraries

using namespace std; // Use the standard namespace

// Destructor to delete all nodes in the chain
template <class T>
Chain<T>::~Chain()
{
    Node<T> *current = head; // Start with the head node
    while (current) // Loop until there are no more nodes
    {
        Node<T> *nextNode = current->Next; // Store the next node
        delete current; // Delete the current node
        current = nextNode; // Move to the next node
    }
}

// Length (Iterative)
template <class T>
int Chain<T>::Length_Iterative() const
{
    int length = 0; // Initialize length counter
    Node<T> *current = head; // Start with the head node
    while (current) // Loop until there are no more nodes
    {
        length++; // Increment length
        current = current->Next; // Move to the next node
    }
    return length; // Return the total length
}

// Length (Recursive)
template <class T>
int Chain<T>::Length_Recursive(Node<T> *node) const
{
    if (!node) // Base case: if node is null
        return 0; // Return 0
    return 1 + Length_Recursive(node->Next); // Recursive case: count this node and move to the next
}

// Find the k'th element (based index)
template <class T>
bool Chain<T>::Find(int k, T &x) const
{
    if (k < 1) // Check if k is less than 1
        return false; // Invalid position
    Node<T> *current = head; // Start with the head node
    int index = 1; // Initialize index
    while (current && index < k) // Loop until we reach the k'th node
    {
        current = current->Next; // Move to the next node
        index++; // Increment index
    }
    if (current) // If current is not null
    {
        x = current->value; // Assign the value to x
        return true; // Found the element
    }
    return false; // Element not found
}

// Search for an element and return its position
template <class T>
int Chain<T>::Search(const T &x) const
{
    Node<T> *current = head; // Start with the head node
    int index = 1; // Initialize index
    while (current) // Loop through the nodes
    {
        if (current->value == x) // Check if current value matches x
            return index; // Return the index if found
        current = current->Next; // Move to the next node
        index++; // Increment index
    }
    return 0; // Return 0 if not found
}

// Insert an element at position k
template <class T>
Chain<T> &Chain<T>::Insert(int k, const T &x)
{
    if (k < 1) // Check if k is less than 1
        throw out_of_range("Invalid position"); // Throw an exception for invalid position

    Node<T> *newNode = new Node<T>(x); // Create a new node with value x
    if (k == 1) // If inserting at the head
    {
        newNode->Next = head; // Set newNode's next to current head
        if (head) // If head is not null
            head->Prev = newNode; // Set head's previous to newNode
        head = newNode; // Update head to newNode
    }
    else
    {
        Node<T> *current = head; // Start with the head node
        int index = 1; // Initialize index
        while (current && index < k - 1) // Loop until we reach the position before k
        {
            current = current->Next; // Move to the next node
            index++; // Increment index
        }
        if (!current) // If current is null
            throw out_of_range("Invalid position"); // Throw an exception for invalid position
        newNode->Next = current->Next; // Set newNode's next to current's next
        if (current->Next) // If current's next is not null
            current->Next->Prev = newNode; // Set current's next's previous to newNode
        current->Next = newNode; // Set current's next to newNode
        newNode->Prev = current; // Set newNode's previous to current
    }
    return *this; // Return the current chain
}

// Insert an element into a sorted list
template <class T>
Chain<T> &Chain<T>::InsertSorted(const T &x)
{
    Node<T> *newNode = new Node<T>(x); // Create a new node with value x
    if (!head || head->value >= x) // If the list is empty or newNode should be the new head
    {
        newNode->Next = head; // Set newNode's next to current head
        if (head) // If head is not null
            head->Prev = newNode; // Set head's previous to newNode
        head = newNode; // Update head to newNode
    }
    else
    {
        Node<T> *current = head; // Start with the head node
        while (current->Next && current->Next->value < x) // Loop until we find the correct position
        {
            current = current->Next; // Move to the next node
        }
        newNode->Next = current->Next; // Set newNode's next to current's next
        if (current->Next) // If current's next is not null
            current->Next->Prev = newNode; // Set current's next's previous to newNode
        current->Next = newNode; // Set current's next to newNode
        newNode->Prev = current; // Set newNode's previous to current
    }
    return *this; // Return the current chain
}

// Delete an element at position k
template <class T>
Chain<T> &Chain<T>::Delete(int k, T &x)
{
    if (k < 1 || !head) // Check if k is less than 1 or the list is empty
        throw out_of_range("Invalid position"); // Throw an exception for invalid position

    Node<T> *current = head; // Start with the head node
    if (k == 1) // If deleting the head
    {
        head = current->Next; // Update head to the next node
        if (head) // If head is not null
            head->Prev = nullptr; // Set head's previous to null
    }
    else
    {
        int index = 1; // Initialize index
        while (current && index < k) // Loop until we reach the k'th node {
            current = current->Next; // Move to the next node
            index++; // Increment index
    }
        if (!current) // If current is null
            throw out_of_range("Invalid position"); // Throw an exception for invalid position
        if (current->Prev) // If current's previous is not null
            current->Prev->Next = current->Next; // Bypass current node
        if (current->Next) // If current's next is not null
            current->Next->Prev = current->Prev; // Bypass current node
    x = current->value; // Assign the value to x
    delete current; // Delete the current node
    return *this; // Return the current chain
}

// Output the chain
template <class T>
void Chain<T>::Output() const
{
    Node<T> *current = head; // Start with the head node
    while (current) // Loop until there are no more nodes
    {
        cout << current->value << " "; // Print the current node's value
        current = current->Next; // Move to the next node
    }
    cout << endl; // Print a newline after outputting all values
}

// Reverse the chain
template <class T>
void Chain<T>::Reverse()
{
    Node<T> *current = head; // Start with the head node
    Node<T> *prev = nullptr; // Initialize previous node as null
    while (current) // Loop until there are no more nodes
    {
        Node<T> *nextNode = current->Next; // Store the next node
        current->Next = prev; // Reverse the next pointer
        current->Prev = nextNode; // Set previous pointer to next node
        prev = current; // Move prev to current
        current = nextNode; // Move to the next node
    }
    head = prev; // Update head to the last processed node
}

// Swap two elements
template <class T>
void Chain<T>::Swap(T x, T y)
{
    if (x == y) // If both values are the same
        return; // No need to swap

    Node<T> *nodeX = nullptr, *nodeY = nullptr; // Initialize pointers for the nodes to swap
    Node<T> *current = head; // Start with the head node
    while (current) // Loop through the nodes
    {
        if (current->value == x) // If current value matches x
            nodeX = current; // Assign nodeX
        if (current->value == y) // If current value matches y
            nodeY = current; // Assign nodeY
        current = current->Next; // Move to the next node
    }
    if (!nodeX || !nodeY) // If either node is not found
        return; // No swap can be performed

    if (nodeX->Prev) // If nodeX has a previous node
        nodeX->Prev->Next = nodeY; // Bypass nodeX
    else
        head = nodeY; // Update head if nodeX is the head
    if (nodeY->Prev) // If nodeY has a previous node
        nodeY->Prev->Next = nodeX; // Bypass nodeY
    else
        head = nodeX; // Update head if nodeY is the head
    if (nodeX->Next) // If nodeX has a next node
        nodeX->Next->Prev = nodeY; // Bypass nodeX
    if (nodeY->Next) // If nodeY has a next node
        nodeY->Next->Prev = nodeX; // Bypass nodeY

    swap(nodeX->Prev, nodeY->Prev); // Swap previous pointers
    swap(nodeX->Next, nodeY->Next); // Swap next pointers
}

// Max value
template <class T>
int Chain<T>::Max() const
{
    if (!head) // If the list is empty
        return INT_MIN; // Return minimum integer value
    int maxVal = INT_MIN; // Initialize maxVal
    Node<T> *current = head; // Start with the head node
    while (current) // Loop through the nodes
    {
        maxVal = max(maxVal, current->value); // Update maxVal if current value is greater
        current = current->Next; // Move to the next node
    }
    return maxVal; // Return the maximum value found
}

// Min value
template <class T>
int Chain<T>::Min() const
{
    if (!head) // If the list is empty
        return INT_MAX; // Return maximum integer value
    int minVal = INT_MAX; // Initialize minVal

    Node<T> *current = head; // Start with the head node
    while (current) // Loop through the nodes
    {
        minVal = min(minVal, current->value); // Update minVal if current value is smaller
        current = current->Next; // Move to the next node
    }
    return minVal; // Return the minimum value found
}

// Sum of values
template <class T>
int Chain<T>::Sum() const
{
    int sum = 0; // Initialize sum
    Node<T> *current = head; // Start with the head node
    while (current) // Loop through the nodes
    {
        sum += current->value; // Add current value to sum
        current = current->Next; // Move to the next node
    }
    return sum; // Return the total sum
}

// Average value
template <class T>
double Chain<T>::Average() const
{
    int length = Length_Iterative(); // Get the length of the chain
    return (length == 0) ? 0 : (double)Sum() / length; // Return average or 0 if length is 0
}

// Median value
template <class T>
double Chain<T>::Median() const
{
    int length = Length_Iterative(); // Get the length of the chain
    if (length == 0) // If the list is empty
        return 0; // Return 0 for median

    Node<T> *current = head; // Start with the head node
    for (int i = 0; i < length / 2; i++) // Move to the middle of the list
    {
        current = current->Next; // Move to the next node
    }
    if (length % 2 == 0) // If the length is even
    {
        return (current->value + current->Prev->value) / 2.0; // Return average of the two middle values
    }
    return current->value; // Return the middle value for odd length
}

// Standard deviation
template <class T>
double Chain<T>::StrDev() const
{
    double mean = Average(); // Calculate the mean
    int length = Length_Iterative(); // Get the length of the chain
    double variance = 0; // Initialize variance
    Node<T> *current = head; // Start with the head node
    while (current) // Loop through the nodes
    {
        variance += pow(current->value - mean, 2); // Calculate variance
        current = current->Next; // Move to the next node
    }
    return sqrt(variance / length); // Return the standard deviation
}

// Max second value
template <class T>
void Chain<T>::Max_Second() const
{
    if (!head || !head->Next) // If the list has less than two elements
    {
        cout << "List doesn't have enough elements!" << endl; // Print error message
        return; // Exit the function
    }
    int max1 = INT_MIN, max2 = INT_MIN; // Initialize max1 and max2
    Node<T> *current = head; // Start with the head node
    while (current) // Loop through the nodes
    {
        if (current->value > max1) // If current value is greater than max1
        {
            max2 = max1; // Update max2 to max1
            max1 = current->value; // Update max1 to current value
        }
        else if (current->value > max2 && current->value != max1) // If current value is greater than max2 and not equal to max1
        {
            max2 = current->value; // Update max2 to current value
        }
        current = current->Next; // Move to the next node
    }
    cout << "Max1: " << max1 << ", Max2: " << max2 << endl; // Print the two maximum values
}

// Min second value
template <class T>
void Chain<T>::Min_Second() const
{
    if (!head || !head->Next) // If the list has less than two elements
    {
        cout << "List doesn't have enough elements!" << endl; // Print error message
        return; // Exit the function
    }
    int min1 = INT_MAX, min2 = INT_MAX; // Initialize min1 and min2
    Node<T> *current = head; // Start with the head node
    while (current) // Loop through the nodes
    {
        if (current->value < min1) // If current value is less than min1
        {
            min2 = min1; // Update min2 to min1
            min1 = current->value; // Update min1 to current value
        }
        else if (current->value < min2 && current->value != min1) // If current value is less than min2 and not equal to min1
        {
            min2 = current->value; // Update min2 to current value
        }
        current = current->Next; // Move to the next node
    }
    cout << "Min1: " << min1 << ", Min2: " << min2 << endl; // Print the two minimum values
}

// Merge two chains
template <class T>
Chain<T> &Chain<T>::Merge(const Chain<T> &other)
{
    Node<T> *current = other.head; // Start with the head of the other chain
    while (current) // Loop through the nodes of the other chain
    {
        Insert(Length_Iterative() + 1, current->value); // Insert each value into the current chain
        current = current->Next; // Move to the next node in the other chain
    }
    return *this; // Return the current chain
}

// Split the chain into two halves
template <class T>
void Chain<T>::Split(Chain<T> &firstHalf, Chain<T> &secondHalf) const
{
    if (!head) // If the list is empty
        return; // Exit the function

    Node<T> *slow = head; // Initialize slow pointer to head
    Node<T> *fast = head; // Initialize fast pointer to head

    while (fast && fast->Next) // Loop until fast reaches the end
    {
        fast = fast->Next->Next; // Move fast two steps
        slow = slow->Next; // Move slow one step
    }

    firstHalf.head = head; // Set firstHalf's head to the current head
    secondHalf.head = slow; // Set secondHalf's head to the slow pointer
    if (slow) // If slow is not null
        slow->Prev = nullptr; // Set slow's previous to null

    Node<T> *current = firstHalf.head; // Start with the head of the first half
    while (current && current->Next != slow) // Loop until we reach the slow pointer
    {
        current = current->Next; // Move to the next node
    }
    if (current) // If current is not null
        current->Next = nullptr; // Terminate the first half
}

// Check if list is sorted
template <class T>
bool Chain<T>::Sorted() const
{
    if (!head || !head->Next) // If the list is empty or has only one element
        return true; // It is sorted
    Node<T> *current = head; // Start with the head node
    while (current->Next) // Loop until there are no more nodes
    {
        if (current->value > current->Next->value) // If current value is greater than the next value
            return false; // The list is not sorted
        current = current->Next; // Move to the next node
    }
    return true; // The list is sorted
}

// Check if all elements are even
template <class T>
bool Chain<T>::Even() const
{
    Node<T> *current = head; // Start with the head node
    while (current) // Loop through the nodes
    {
        if (current->value % 2 != 0) // If current value is odd
            return false; // Not all elements are even
        current = current->Next; // Move to the next node

    }
    return true; // All elements are even
}

// Check if all elements are odd
template <class T>
bool Chain<T>::Odd() const
{
    Node<T> *current = head; // Start with the head node
    while (current) // Loop through the nodes
    {
        if (current->value % 2 == 0) // If current value is even
            return false; // Not all elements are odd
        current = current->Next; // Move to the next node
    }
    return true; // All elements are odd
}