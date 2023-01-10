using System;

namespace sll
{
    public class sll
    {
        internal node head;

        internal void insert(int a )
        {
            node new_node = new node(a); 
            if (head == null )
            {
                head = new_node;
                return; 
            }

            node temp = new node();
            temp = head;
            while (temp.next !=null)
            {
                //Console.WriteLine(temp.info);
                temp = temp.next; 
            }

            temp.next = new_node; 
            return;
        }

        internal void PrintSll()
        {
            node temp = new node();
            temp = head; 
            //Console.WriteLine(temp.info);
            while (temp!= null)
            {
                Console.WriteLine(temp.info);
                temp = temp.next; 
            }

            return; 
        }
    }
}