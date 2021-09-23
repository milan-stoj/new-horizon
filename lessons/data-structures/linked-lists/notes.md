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

      3:33