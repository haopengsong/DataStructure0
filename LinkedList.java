import java.util.NoSuchElementException;
/*

 */
public class LinkedList<T> {

    private ListNode<T> head;

    private static class ListNode<T> {
        T val;
        ListNode<T> next;
        public ListNode(T val) {
            this.val = val;
            next = null;
        }
    }

    public LinkedList() {
        head = null;
    }

    public boolean isEmpty() {
        return head == null;
    }

    // insert a new node at the beginning of this list, o(1)
    public void addFirst(T val) {
        ListNode<T> node = new ListNode<T>(val);
        node.next = head;
        head = node;
    }

    // return the first element in the list, o(1)
    public T getFirst() {
        if (head == null) {
            throw new NoSuchElementException();
        }
        return head.val;
    }

    // removes the first element in the list, o(1)
    public T removeFirst() {
        T temp = getFirst();
        head = head.next;
        return temp;
    }

    // insert a new node to the end of this list, o(n)
    public void addLast(T val) {
        if (head == null) {
            addFirst(val);
        } else {
            ListNode<T> temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = new ListNode<T>(val);
        }
    }

    // returns the last element in the list, o(n)
    public T getLast() {
        if (head == null) {
            throw new NoSuchElementException();
        }
        ListNode<T> temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        return temp.val;
    }

    // removes all nodes from the list
    public void clear() {
        head = null;
    }

    // returns true if this list contains the specified element, o(n)
    public boolean contains(T val) {
        ListNode<T> temp = head;
        while (temp != null) {
            if (temp.val.equals(val)) {
                return true;
            }
            temp = temp.next;
        }
        return false;
    }

    // returns the data at the specified position in the list, o(n)
    public T get(int pos) {
        if (head == null) {
            throw new IndexOutOfBoundsException();
        }
        ListNode<T> temp = head;
        for (int i = 0; i < pos; i++) {
            if (temp == null) {
                throw new IndexOutOfBoundsException();
            }
            temp = temp.next;
        }
        if (temp == null) {
            throw new IndexOutOfBoundsException();
        }
        return temp.val;
    }

    // removes the first occurrence of the specified element in this list, o(n)
    public void remove(T val) {
        if (head == null) {
            throw new RuntimeException("Cannot find the element to delete");
        }
        if (head.val.equals(val)) {
            head = head.next;
            return;
        }
        ListNode<T> curr = head, prev = null;
        while (curr != null && !curr.val.equals(val)) {
            prev = curr;
            curr = curr.next;
        }
        if (curr == null) {
            throw new RuntimeException("Cannot find the element to delete");
        }
        prev.next = curr.next;
    }

    // returns a deep copy of the list
    public ListNode<T> copy() {
        LinkedList<T> twin = new LinkedList<T>();
        ListNode<T> temp = head;
        while (temp != null) {
            twin.addFirst(temp.val);
            temp = temp.next;
        }
        return twin.reverse();
    }

    // reverse the LinkedList
    public ListNode<T> reverse() {
        ListNode<T> prev = null;
        while (head != null) {
            ListNode<T> next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        head = prev;
        return head;
    }

    // testing in main()
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList <String>();
        list.addFirst("p");
        list.addFirst("a");
        list.addFirst("e");
        list.addFirst("h");

        //System.out.println(list);

        //list.reverse();

        list.remove("a");
        list.addLast("x");
        System.out.println(list);


    }
}
