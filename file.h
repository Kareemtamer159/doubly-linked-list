#ifndef FILE_H
#define FILE_H

template <class T> // Template class for Node
class Node
{
public:
    T value; // Value of the node
    Node *Next; // Pointer to the next node
    Node *Prev; // Pointer to the previous node

    Node(T val) : value(val), Next(nullptr), Prev(nullptr) {} // Constructor to initialize node
};

template <class T> // Template class for Chain
class Chain
{
private:
    Node<T> *head; // Pointer to the first node
public:
    Chain() : head(nullptr) {} // Constructor to initialize the chain
    ~Chain(); // Destructor to clean up the chain

    bool IsEmpty() const { return head == nullptr; } // Check if the chain is empty
    int Length_Iterative() const; // Get length of the chain iteratively
    int Length_Recursive(Node<T> *node = nullptr) const; // Get length of the chain recursively
    bool Find(int k, T &x) const; // Find the k'th element in the chain
    int Search(const T &x) const; // Search for an element and return its position
    Chain<T> &Insert(int k, const T &x); // Insert an element at position k
    Chain<T> &InsertSorted(const T &x); // Insert into sorted list
    Chain<T> &Delete(int k, T &x); // Delete an element at position k
    void Output() const; // Output the chain
    void Reverse(); // Reverse the chain
    void Swap(T x, T y); // Swap two elements
    int Max() const; // Get maximum value
    int Min() const; // Get minimum value
    int Sum() const; // Get sum of values
    double Average() const; // Get average value
    double Median() const; // Get median value
    double StrDev() const; // Get standard deviation
    void Max_Second() const; // Get the first and second maximum values
    void Min_Second() const; // Get the first and second minimum values
    Chain<T> &Merge(const Chain<T> &other); // Merge two chains
    void Split(Chain<T> &firstHalf, Chain<T> &secondHalf) const; // Split the chain into two halves
    bool Sorted() const; // Check if the list is sorted
    bool Even() const; // Check if all elements are even
    bool Odd() const; // Check if all elements are odd
};
#endif