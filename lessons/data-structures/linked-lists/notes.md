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
3. Update the next pointer of the current tail to point to the current tail.

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

