#include <iostream>
using namespace std;

class Array
{
private:
    char *array;
    int cap;
    int length;

public:
    Array(int cap)
    {
        this->cap = cap;
        length = 0;
        array = new char[cap];
        for (int i = 0; i < cap; i++)
        {
            array[i] = NULL;
        }
    }
    ~Array()
    {
        delete[] array;
    }

    void insert(char val)
    {
        char *temp;
        temp = array;
        while (*temp != NULL)
        {
            temp++;
        }
        *temp = val;
        length++;
    }
    void common(Array A, Array B)
    {
        Array c(5);
        char *temp = A.array;
        char *temp1 = B.array;
        for (int i = 0; i < A.length; i++)
        {
            for (int j = 0; j < B.length; j++)
            {
                if (*(temp + i) == *(temp1 + j))
                {
                    c.insert(*(temp + i));
                }
            }
        }
        c.display();
    }
    void display()
    {
        char *temp = array;
        for (int i = 0; i < length; i++)
        {
            cout << *(temp + i) << " , ";
        }
    }
    void remove(int pos)
    {
        char *temp = array + (pos - 1);
        for (int i = pos; i < length; i++)
        {
            *(temp) = *(temp + 1);
            temp++;
        }
        length--;
    }
    void Remove(char a)
    {
        int pos = 1;
        char *temp = array;
        while (*temp != a)
        {
            temp++;
            pos++;
        }
        remove(pos);
    }

    void reverse()
    {
        char *temp = array;
        char *temp1 = array + (length - 1);
        int half = length / 2;
        for (int i = 0; i < half; i++)
        {
            swap(*(temp), *(temp1));
            temp++;
            temp1--;
        }
    }
};
int main()
{
    Array a(5), b(5), c(5);
    a.insert('t');
    a.insert('a');
    a.insert('c');
    a.insert('o');
    a.Remove('c');
    a.display();
    cout << endl;
    // a.reverse();
    // a.display();
    cout << endl;
    b.insert('a');
    b.insert('u');
    b.insert('c');
    // b.display();
    cout << endl;
    // c.common(a, b);

    // a.display();

    return 0;
}