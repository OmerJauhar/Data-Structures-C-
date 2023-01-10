#include <iostream>
using namespace std;
class Array
{
private:
    int *array;
    int length;
    int *temp;
    int capacity;

public:
    Array(int size)
    {
        array = new int[size];
        length = 0;
        capacity = size;
        temp = NULL;
    }
    ~Array()
    {
        delete[] array;
        delete temp;
    }
    bool is_full()
    {
        if (length == capacity)
        {
            cout << "array if full: " << endl;
            return true;
        }
        else
        {
            cout << "array is not full: " << endl;
            return false;
        }
    }
    bool is_empty()
    {
        if (length == 0)
        {
            cout << "array is empty: " << endl;
            return true;
        }
        else
        {
            cout << "array is not empty: " << endl;
            return false;
        }
    }
    void insert(int x)
    {
        if (!is_full())
        {
            if (length == 0)
            {
                temp = array;
                *temp = x;
                length++;
                return;
            }

            int pos;
            cout << "Enter the position you want to insert: " << endl;
            cin >> pos;
            if (pos > 0 && pos <= length)
            {
                temp = array + (length - 1);
                for (int i = length; i >= pos; i--)
                {
                    *(temp + 1) = *temp;
                    --temp;
                }
                temp++;
                *temp = x;
                length++;
                return;
            }
            else if (pos > length && pos < capacity)
            {
                temp = array + (pos - 1);
                *temp = x;
                length++;
                return;
            }
            else
            {
                cout << "invalid position" << endl;
                return;
            }
        }
        return;
    }
    void remove()
    {
        if (!is_empty())
        {
            int pos = 0;
            cout << "enter the position which you whant to remove" << endl;
            cin >> pos;
            if (pos >= 0 && pos <= length)
            {
                temp = array + pos;
                for (int i = pos; i <= length; i++)
                {
                    *temp = *(temp + 1);
                    temp++;
                }
                length--;
            }
            else
            {
                cout << "invalid position: " << endl;
            }
        }
        else
        {
            cout << "array is empty!" << endl;
        }
    }

    void print()
    {
        if (!is_empty())
        {
            temp = array;
            cout << "array is ";
            for (int i = 0; i < length; i++)
            {
                cout << *(temp + i) << " ";
            }
            return;
        }
    }
    void sort()
    {
        if (!is_empty())
        {
            temp = array;
            int k;
            for (int i = 0; i < length; i++)
            {
                for (int j = i + 1; j < length; j++)
                {
                    if (*(t + i) > *(t + j))
                    {
                        k = *(t + i);
                        *(t + j) = *(t + i);
                        *(t + i) = k;
                    }
                }
            }
        }
    }
};
int main()
{
    Array a(4);
    int c, val;
    do
    {
        cout << "1.Insert  2.Remove  3.Sort  4.Print  ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            a.insert(val);
            break;
        case 2:
            a.remove();
            break;
        case 3:
            a.sort();
            break;
        case 4:
            a.print();
            break;
        }
    } while (c == 1 || c == 2 || c == 3 || c == 4);

    return 0;
}