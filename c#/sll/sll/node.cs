namespace sll
{
    internal class node
    {
        internal int info;
        internal node  next;


        public node()
        {
            this.info = 0;
            this.next = null;
        }

        public node (int a)
        {
            this.info = a;
            this.next = null;
        }
    }
}