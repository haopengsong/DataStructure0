import java.util.Iterator;
/*
A generic, iterable implementation of Stack that keeps items in an array.
It resizes the array to keep the array size within a constant factor of the stack size
 */
public class ResizingArrayStack<Item> implements Iterable<Item> {
    private Item[] a = (Item[]) new Object[1]; // stack items
    private int n = 0;

    public boolean isEmpty() {
        return n == 0;
    }

    public int size() {
        return n;
    }

    private void resize(int max) {
        // Move stack elements to a new array of size max
        Item[] temp = (Item[]) new Object[max];
        for (int i = 0; i < n; i++) {
            temp[i] = a[i];
        }
        a = temp;
    }

    public void push(Item item) {
        // add item to top of the stack
        if (n == a.length) {
            resize(2 * a.length);
        }
        a[n++] = item;
    }

    public Item pop() {
        // remove item from top of stack
        Item item = a[--n];
        a[n] = null; // avoid loitering
        if (n > 0 && n == a.length/4) {
            resize(a.length / 2);
        }
        return item;
    }
    @Override
    public Iterator<Item> iterator() {
        return new ReverseArrayIterator();
    }

    private class ReverseArrayIterator implements Iterator<Item> {
        // for LIFO operation
        private int i = n - 1;
        @Override
        public boolean hasNext() {
            return i >= 0;
        }

        @Override
        public Item next() {
            return a[i--];
        }
    }

    public static void main(String[] args) {
        ResizingArrayStack<String> st = new ResizingArrayStack<>();
        st.push("first");
        st.push("second");
        st.push("third");
        System.out.println(st.pop());
        st.push("third");
        st.push("last");

        for (String element : st) {
            System.out.println(element);
        }
        System.out.println();
    }
}
