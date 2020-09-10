
#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size1;
    int length;

public:
    int i;
    // Input Size of array

    Array(int s, int len)
    {
        size1 = s;
        length = len;
    }

    void input_size()
    {
        cout << "Enter the size of array";
        cin >> size1;
    }

    //Input length for array
    void input_length()
    {
        cout << "Enter the length of an array";
        cin >> length;
    }
    // Initialize an array
    void initialize_array()
    {
        A = new int[size1];
    }

    // Enter the elements of array
    void input_elements()
    {
        cout << "Enter the elements of array" << endl;
        for (i = 0; i < length; i++)
            cin >> A[i];
    }

    int get(int index)
    {
        return A[index];
    }

    void set1(int item, int index)
    {
        A[index] = item;
    }

    // Display elements of array
    void display()
    {
        for (i = 0; i < length; i++)
            cout << A[i] << endl;
    }

    // Appending an element at the end of list
    void append(int item)
    {
        A[length] = item;
        length++;
    }

    // Inserting element "item" at a index "pos"
    void insert1(int item, int pos)
    {
        if (pos >= 0 && pos <= length)
        {
            for (i = length; i > pos; i--)
                A[i] = A[i - 1];
            A[pos] = item;
            length++;
        }
        else
        {
            cout << "Wrong Index" << endl;
        }
    }

    // Delete element from an array at a given index
    void delete1(int pos)
    {
        if (pos >= 0 && pos <= length)
        {
            for (i = pos; i < length - 1; i++)
                A[i] = A[i + 1];
            length--;
        }
    }

    // Linear Search
    int linear_search(int key)
    {
        for (i = 0; i < length; i++)
        {
            if (A[i] == key)
                return i;
        }
        return -1;
    }

    // iterative binary Search
    // iterative binary Search
    int binary_search_i(int key)
    {
        int low = 0;
        int high = length - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (key == A[mid])
                return mid;
            else if (key < A[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    // Recursive binary Search
    int binary_search_r(int low, int high, int key)
    {
        int mid;

        if (low <= high)
        {
            mid = (low + high) / 2;
            if (key == A[mid])
                return mid;
            else if (key < A[mid])
                return binary_search_r(low, mid - 1, key);
            else
                return binary_search_r(low + 1, high, key);
        }
        return -1;
    }
};

int main()
{
    Array arr(50, 5);
    // int item, pos;

    // arr.input_size();
    arr.initialize_array();
    // arr.input_length();
    arr.input_elements();
    arr.display();

    // cout << "Enter the element to append" << endl;
    // cin >> item;
    // arr.append(item);
    // arr.display();

    // cout << "Enter the element and position to insert" << endl;
    // cin >> item >> pos;
    // arr.insert1(item, pos);
    // arr.display();

    // cout << "Enter the position to deleted";
    // cin >> pos;
    // arr.delete1(pos);
    // arr.display();

    // Linear Search
    // int key;
    // cout << "Enter the key to be searched" << endl;
    // cin >> key;
    // if (arr.linear_search(key) == -1)
    //     cout << "Key is not present in the array" << endl;
    // else
    //     cout << "Key is present at index:" << arr.linear_search(key) << endl;

    // cout << "Enter the key to be searched" << endl;
    // cin >> key;
    // if (arr.binary_search_i(key) == -1)
    //     cout << "Key is not present in the array" << endl;
    // else
    //     cout << "Key is present at index:" << arr.binary_search_i(key) << endl;

    // cout << "Enter the key to be searched" << endl;
    // cin >> key;
    // if (arr.binary_search_r(0, 5, key) == -1)
    //     cout << "Key is not present in the array" << endl;
    // else
    //     cout << "Key is present at index:" << arr.binary_search_r(0, 5, key) << endl;
}
