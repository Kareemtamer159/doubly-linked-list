#include "file.h"
#include "Doubly linked list.cpp"
#include <bits/stdc++.h> // Include standard libraries
using namespace std; // Use the standard namespace
int main() // Main function
{
    Chain<int> list; // Create a chain of integers
    string input; // Variable to store user input

    cout << "---------------------------------------------------------------------------------\n"; // Print header
    cout << "||||||||||||||||||||            Available Commands           ||||||||||||||||||||\n"; // Print command list header
    cout << "---------------------------------------------------------------------------------\n"; // Print separator
    cout << "(1) Add         (2) Output       (3) Reverse      (4) Max       (5)  Min \n"; // Print command for minimum value
    cout << "(6) Sum         (7) Average      (8) Median       (9) StrDev    (10) MaxSecond \n"; // Print commands for sum, average, median, standard deviation, and max second
    cout << "(11) MinSecond  (12) Length      (13) Find       (14) Search    (15) InsertSorted\n"; // Print commands for min second, length, find, search, and insert sorted
    cout << "(16) Delete     (17) Swap        (18) Merge      (19) Split     (20) Sorted \n"; // Print commands for delete, swap, merge, split, and sorted
    cout << "(21) Even       (22) Odd          \n"; // Print commands for checking even and odd
    cout << "---------------------------------------------------------------------------------\n"; // Print separator
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"; // Print footer
    cout << "---------------------------------------------------------------------------------\n"; // Print separator

    cout << "Enter Number of commands (type 'Exit' to exit):\n"; // Prompt user for number of commands

    while (true) // Infinite loop to process commands
    {
        cout << "Command: "; // Prompt for command input
        cin >> input; // Read user input

        if (input == "Exit" || input == "exit") // Check for exit command
        {
            cout << "Exiting program.\n"; // Print exit message
            break; // Exit the loop
        }
        else if (input == "1") // Command to add a value
        {
            int value; // Variable to store the value to add
            cout << "Enter value to add: "; // Prompt for value
            cin >> value; // Read value
            list.Insert(list.Length_Iterative() + 1, value); // Insert value at the end of the list
            cout << "Value added.\n"; // Confirm value added
        }
        else if (input == "2") // Command to output the list
        {
            cout << "Current list: "; // Print current list message
            list.Output(); // Output the current list
        }
        else if (input == "3") // Command to reverse the list
        {
            list.Reverse(); // Reverse the list
            cout << "List reversed.\n"; // Confirm list reversed
        }
        else if (input == "4") // Command to get maximum value
        {
            cout << "Maximum value: " << list.Max() << endl; // Print maximum value
        }
        else if (input == "5") // Command to get minimum value
        {
            cout << "Minimum value: " << list.Min() << endl; // Print minimum value
        }
        else if (input == "6") // Command to get sum of values
        {
            cout << "Sum of values: " << list.Sum() << endl; // Print sum of values
        }
        else if (input == "7") // Command to get average value
        {
            cout << "Average value: " << list.Average() << endl; // Print average value
        }
        else if (input == "8") // Command to get median value
        {
            cout << "Median value: " << list.Median() << endl; // Print median value
        }
        else if (input == "9") // Command to get standard deviation
        {
            cout << "Standard deviation: " << list.StrDev() << endl; // Print standard deviation
        }
        else if (input == "10") // Command to get max second value
        {
            list.Max_Second(); // Print the first and second maximum values
        }
        else if (input == "11") // Command to get min second value
        {
            list.Min_Second(); // Print the first and second minimum values
        }
        else if (input == "12") // Command to get length of the list
        {
            cout << "Length of list: " << list.Length_Iterative() << endl; // Print length of the list
        }
        else if (input == "13") // Command to find a value at a position
        {
            int k, value; // Variables to store position and found value
            cout << "Enter position to find: "; // Prompt for position
            cin >> k; // Read position
            if (list.Find(k, value)) // Attempt to find the value at position k
                cout << "Value at position " << k << ": " << value << endl; else
                cout << "Position not found.\n"; // Print error if position not found
        }
        else if (input == "14") // Command to search for a value
        {
            int value; // Variable to store the value to search
            cout << "Enter value to search: "; // Prompt for value
            cin >> value; // Read value
            int pos = list.Search(value); // Search for the value
            if (pos != -1) // If value is found
                cout << "Value found at position: " << pos << endl; // Print position
            else
                cout << "Value not found.\n"; // Print error if value not found
        }
        else if (input == "15") // Command to insert a value in sorted order
        {
            int value; // Variable to store the value to insert
            cout << "Enter value to insert in sorted list: "; // Prompt for value
            cin >> value; // Read value
            list.InsertSorted(value); // Insert value in sorted order
            cout << "Value inserted.\n"; // Confirm value inserted
        }
        else if (input == "16") // Command to delete a value at a position
        {
            int pos, value; // Variables to store position and deleted value
            cout << "Enter position to delete: "; // Prompt for position
            cin >> pos; // Read position
            try
            {
                list.Delete(pos, value); // Attempt to delete value at position
                cout << "Deleted value: " << value << endl; // Print deleted value
            }
            catch (const out_of_range &e) // Catch out of range exception
            {
                cout << "Error: " << e.what() << endl; // Print error message
            }
        }
        else if (input == "17") // Command to swap two values
        {
            int x, y; // Variables to store values to swap
            cout << "Enter two values to swap: "; // Prompt for values
            cin >> x >> y; // Read values
            list.Swap(x, y); // Swap the values
            cout << "Values swapped.\n"; // Confirm values swapped
        }
        else if (input == "18") // Command to merge two chains
        {
            Chain<int> other; // Create another chain
            int n, value; // Variables to store number of elements and values
            cout << "Enter number of elements in second list: "; // Prompt for number of elements
            cin >> n; // Read number of elements
            cout << "Enter elements: "; // Prompt for elements
            for (int i = 0; i < n; ++i) // Loop to read elements
            {
                cin >> value; // Read value
                other.Insert(other.Length_Iterative() + 1, value); // Insert value into the other chain
            }
            list.Merge(other); // Merge the two chains
            cout << "Lists merged.\n"; // Confirm lists merged
        }
        else if (input == "19") // Command to split the chain
        {
            Chain<int> firstHalf, secondHalf; // Create two new chains for the halves
            list.Split(firstHalf, secondHalf); // Split the original chain
            cout << "First half: "; // Print first half message
            firstHalf.Output(); // Output the first half
            cout << "Second half: "; // Print second half message
            secondHalf.Output(); // Output the second half
        }
        else if (input == "20") // Command to check if the list is sorted
        {
            cout << (list.Sorted() ? "List is sorted.\n" : "List is not sorted.\n"); // Print if sorted or not
        }
        else if (input == "21") // Command to check if all elements are even
        {
            cout << (list.Even() ? "All elements are even.\n" : "Not all elements are even.\n"); // Print result
        }
        else if (input == "22") // Command to check if all elements are odd
        {
            cout << (list.Odd() ? "All elements are odd.\n" : "Not all elements are odd.\n"); // Print result
        }
        else
        {
            cout << "Invalid command. Please try again.\n"; // Print error for invalid command
        }
    }

    return 0; // Return 0 to indicate successful execution
}