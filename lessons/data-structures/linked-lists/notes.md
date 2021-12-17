# Linked Lists

> https://www.coursera.org/lecture/data-structures/singly-linked-lists-kHhgK:w

## Singly-Linked List
Links in a chain.
- Node contains:
  - Key
  - Next Pointer

## List API
- `PushFront(key)  add to front`
- `Key TopFront()  return front item`
- `PopFront()  remove front item`
- `PushBack(Key)  add to back (aka Append)`
- `Key TopBack()  return back item`
- `Boolean Find(Key)  is key in list?`
- `Erase(Key)  remove key from list`
- `Boolean Empty()  empty list?`
- `AddBefore(Node, Key)  adds key before node`
- `AddAfter(Node, Key)  adds key after node`

## Times for Some Operations
---
### PushFront O(1)
1. Create a new node (Key/Pointer) pair.
2. Update pointer to point to former front element node.
3. Update head pointer to point to new node.

### PopFront O(1)
1. Update head pointer to point to next node.
2. Remove and return front node.

---

### PushBack (No Tail) O(n)
1. Start at the head
2. Walk down the list till end is reached.
3. Add a node there.

### PopBack (No Tail) O(n)
1. Start at the head
2. Walk down the list till end is reached.
3. Pop element at end.

---

### PushBack (With Tail) O(1)
1. Allocate a node.
2. Put in new key.
3. Update the next pointer of the current tail to point to the new tail.

### PopBack (With Tail) O(n)
1. Start at head until 2nd to last node is reached.
2. Update tail to point to 2nd last node.
4. Pop and return node at end.

---

## Singly-Linked List
### `PushFront(key)`
```
node ← new node
node.key ← key
node.next ← head
head ← node
if tail = nil:
    tail ← head
```

### `PopFront()`
```
if head = nil:
    ERROR: empty list
head ← head.next
if head = nil:
    tail ← nil
```

### `PushBack(key)`
```
node ← new node
node.key ← key
node.next = nil
if tail = nil:
    head ← tail ← node
else:
    tail.next ← node
    tail ← node
```

### `PopBack()`
```
if head = nil:
    ERROR: empty list
if head = tail:
    head ← tail ← nill
else:
    p ← head
    while p.next.next != nil:
        p ← p.next
    p.next ← nil; tail ← p
```

### `AddAfter(node, key)`
```
node2 ← new node
node2.key ← key
node2.next = node.next
node.next = node2
if tail = node:
    tail ← node2
```
---
### `Runtimes of Common Operations`

| Operation	           | Runtime (No tail)  | Runtime (Tail)
| :-----------:        | :--------:         | :---:
| PushFront(Key)       | O(1)               |
| TopFront()   	       | O(1)               |	    
| PopFront()   	       | O(1)               |	    
| PushBack(Key)        | O(n)               | O(1)
| TopBack()            | O(n)    			| O(1)
| PopBack()            | O(n)    			|	    
| Find(Key)            | O(n)    			|	    
| Erase(Key)           | O(n)               |
| Empty()              | O(1)				|
| AddBefore(Node, Key) | O(n)				|
| AddAfter(Node, Key)  | O(1)				|
 
# Linked Lists I
> https://archive.org/details/ucberkeley_webcast_htzJdKoEmO0

## Lists
### Example
Suppose you want to store a list of items like your shopping list
- Obvious way to do this is with an array.
  - Store a list of ints as an array.
    - **Disadvantages:**
      1. Insert item at beginning or middle of list takes time proportional to length of array O(n).
      2. Arrays have a fixed length.

---
```java
public class List() {
    int[] a;
    int lastItem;
}

public List() {
    a = new int[10];
    lastItem = -1;
}

public void insertItem(int nesItem, int location) {
    int i;
    
    // if array a is full, create new array with greater capacity.
    if (lastItem + 1 == a.length) {
        int[] b = new int[2*a.length];
        for (i=0; i <= lastItem; i++) {
            b[i] = a[i];
        }
        a = b;
    }

    for (i = lastItem; i >= location; i--) {
        a[i + 1] = a[i];
    }
    a[location] = newItem;
    lastItem++;
}
```

## Linked Lists
A recursive data type, made of data strcutures called "nodes"
- Each node has two things:
    1. An item.
    2. A reference to next node in the list.

### `Definition of ListNode Class`
```java
public class ListNode {
    int item;
    ListNode next;
}

ListNode l1 = new ListNode();
ListNode l2 = new ListNode(); 
ListNode l3 = new ListNode();

l1.item = 7;
l2.item = 0;
l3.item = 6;

l1.next = l2;
l2.next = l3;
l3.next = null;
```

### `Node Operations`
```java
public ListNode(int item, ListNode next) {
    this.item = item;
    this.next = next;
}

public ListNode(int item) {
    this(item, null);
}

ListNode l1 = new ListNode(7, new ListNode(0, 
                            new ListNode(6)))))
```

### Advantages Over Array Lists
- Inserting item into middle of list takes constant time O(1) if you have reference to previous node
- Moreover, list can keep growing until memory runs out.

Inserts a new item after "this".

```java
public void insertAfter(int item) {
    next = new ListNode(item, next);
}
.
.
.
l2.insertAfter(3);
```

### Disadvantages Over Array Lists
- Finding the nth item of a linked list time proportional to n
    > Constant time on array lists.

```java
public ListNode nth(int position) {
    if (position == 1) {
        return this;
    } else if ((position < 1) || (next == null)) {
        return null;
    } else {
        return next.nth(position - 1);
    }
}
```

## Lists of Objects
Reference any object by declaring a reference of Type Object
```java
public class SListNode {
    public Object item;
    public  SListNode next;
}
```

## A List Class
2 problems with SListNodes by themselves:

1. Insert new item at beginning of list.   
`x = new SListNode("soap", x);`

2. How do you represent an empty list?  
`x = null;` Run-time error if you call a method on a null object.   
e.g. `x.nth(1);`
    - Solution: Separate SListClass to maintain head of the list.

```java
public class SList {
    private SListNode head;
    private int size;

    public SList() {
        head = null;
        size = 0;
    }
    
    public void insertFront(Object item) {
        head = new SListNode(item, head);
        size++;
    }
}
```

# Linked Lists II
> https://archive.org/details/ucberkeley_webcast_-c4I3gFYe3w

## Public & Private Keywords
Why make something public or private?

1. You want to prevent data from being corrupted by other classes.
2. By keeping certain things private, you ensure other classes wont come to depend on them.
3. You can improve the implementation without causing other classes to fail.

 **`Example of This`**
```java
public class Date {

    private int day;
    private int month;

    private void setMonth(int m) {
        month = m;
    }

    public Date(int month, int day) {
        // implementation with error-checking code here.
    }
}

public class EvilTamperer{
    public void tamper() {
        Date d = new Date(1, 1, 2006);
        d.day = 100;        // foiled!
        d.setMonth(0);      // foiled again!
    }
}
```

## Interface & ADT
**Interace of a Class:** prototypes for public methods, plus descriptions of 
those methods behaviors.
- Instructions to your programming partner, or to your self, of how to call your methods.
- Make public, and advertise to the world.

**Abstract Data Types (ADT):** A class with a well-defined interface, but implementation details are hidden from other classes.
- Hidden so you retain the flexibility to change your implementation later on.
- De-coupled from rest of system.

**Invariant:** a fact about a data structure that is always true:
> i.e. "A Date object always represents a valid date."

Not all classes are ADTs! Some classes are just data storage units 
(no invariants).

## The SList ADT
Another advantage of SList class:
> **SList ADT enforces 2 invariants.**
> 1. "Size" is always correct.
> 2. List is never circularly linked.

Both goals accomplished because only SList methods can change the lists.

> **SList ensures this:**
> 1. The fields of SList (head and size) are "private".
> 2. No method of SList returns an SListNode.

## Doubly-Linked Lists
Inserting/deleting at front of list is easy:
```java
public void deleteFront() {
    if (head != null) {
        head = head.next;
        size--;
    }
}
```

Inserting or deleting item at end of list takes a long time. Hence the benefit for Doubly Linked Lists:
```java
public class DListNode {
    Object item;
    DListNode next; // ref next node in list
    DListNode prev; // ref previous node in list
}

public class DList {
    private DListNode head;
    private DListNode tail;
}
```
Insert & delete items at both ends in constant running time per deletion or insertion

Removes the tail node (at least 2 items in DList):
```java
tail.prev.next = null;
tail = tail.prev;
```

**Sentinel:** A special node that does not represent an item.
- Prev pointer points to tail of the list.
- Next pointer points to head of list.
- Next field of tail, points to sentinel.
- Prev field of head tail points to sentinel.

DList v.2: circularly linked doubly linked list.

```java
public class DList {
    private DListNode head;     //sentinel
    private int size;
}
```

**DList invariants with sentinel:**
1.  For any DList d, d.head != null. 
2.  For any DListNode x, x.next != null. 
3.  ... x.prev != null
4. ... if x.next == y, then y.prev == x.
5. ... if x.prev == y, then y.next == x.
6. A Dlist's "size" variable is always correct. # of DListNodes not counting the sentinel.
7. An empty DList's sentinel.prev & sentinel.next points to itself.

# Linked List vs Array List
> https://www.coursera.org/lecture/data-structures-optimizing-performance/core-linked-lists-vs-arrays-rjBs9

Array List and Linked List are just both data structures that fulfil the promises defined in the List implementation.

**ArrayList** implements the list interface using an array[]
- Not efficient when it comes to adding items at front of list **O(n)**
    > ADT specifies functionality, but not efficiency!

To implement a linked list, you will need to implement two classes:
1. ListNode
2. LinkedList
3. SentinelNode - don't store data, always there when list is empty, and pointed to by head and tail pointer.
   > Buffers that keep you from running off either ends of the list.

How long does it take to get to an element of a particular index in an ArrayList?
- O(1)

How long does it take to get to an element of a particular index of a LinkedList?
- O(n) - much slower than array list. Only have constant time access to head and tail

> Underlying implementation will determine speed of operations, and it is up to you to determine which implementation makes the most sense for what is required.

# In the Real World: Lists vs. Arrays
> https://www.coursera.org/lecture/data-structures-optimizing-performance/in-the-real-world-lists-vs-arrays-QUaUd

When would you want to use a list over an array? 

Big advantage of the array is random access - reading the array.
> Arrays are faster to read, lists are faster to write.

# Why not to use Linked List
> https://www.youtube.com/watch?v=YQs6IC-vgmo

Vectors are more compact, linear search is unbeatable. Vectors stay compact, predictable, and more efficient as the size of the data structures increases.


# Doubly-Linked Lists
https://www.coursera.org/lecture/data-structures/doubly-linked-lists-jpGKD

Node contains:
- Key
- Next Pointer
- Prev Pointer

At any node, we can go forward or backwards. More function needs to be added to 
methods to handle the next and prev pointers of the node.

- Constant time to insert at or remove from the front.
- With tail and doubly-linked, constant time to insert at or remove from the back.
- O(n) time to find arbitrary element.
- List elements need not be contiguous.
- With doubly-linked list, constant time to insert between nodes or remove a node.


