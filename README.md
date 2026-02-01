# WIDS-2025-types-of-trees 

### Week 1&2 : Implementing and using general trees, binary search trees, heaps and B-trees.
 
  
1) *What is a tree?*

A tree is like a toy with one top piece (the root) and branches that go down to other nodes.
~The top node is called the root.
~Toys right below a node are its children.
~The node above is the parent.
~nodes who share the same parent are siblings.
~nodes with no children are leaves

      A    <- root
     / \
    B   C  <- B and C are children; A is parent


3) *Why do we use trees?*

-Because they help organize things like folders on a computer or a family chart.


4) *Binary tree-*

A binary tree is a tree where each toy can have at most two children: a left child and a right child.

If a node has one child, it could be only left or only right.

If it has none, it’s a leaf.

We sometimes draw empty spots as Null so it’s clear if left or right is missing.
 
      8
     / \
    5   17
       /  \
      11   21



5) *Putting a tree into a computer*

We can store a tree as nodes that keep:

left pointer,

right pointer,

parent pointer,

and the label.


6) *Walking a tree*

-Preorder: Look at the node first, then its left toys, then its right toys. (Parent → children)

-Inorder (binary trees only): Look left nodes first, then the toy, then right toys. (Left → parent → right)

-Postorder: Look at left and right nodes first, then the node last. (Children → parent)

        +
       / \
      *   /
     / \ / \
     5 4 6 3
-To evaluate the math, we use postorder: first compute 5*4, 6/3, then +. That way we have numbers to add


7) *Binary Search Tree (BST);*


A BST is a special binary tree that keeps things sorted:

Every left toy has a number ≤ the parent’s number.

Every right toy has a number ≥ the parent’s number.

So if you want to find a number, you start at the top and go left or right like “is it smaller or bigger?”. 


8) *Insert in BST;*

To add a new number node, start at the top and follow left/right until you find an empty spot, and put the new node there as a leaf. The path you took keeps the tree sorted. 


9) *Minimum/Maximum in BST;*

To find the smallest number, keep going left until you cannot go further. That node is the minimum.

For largest, go right until you can’t. 


10) *Successor in BST;*

If you have a node with number n and want the toy with the next bigger number:

If the node has a right child, the successor is the smallest toy in that right subtree.

If no right child, walk up to the parent until you come from a left child — that parent is the successor.


11) *Deletion in BST;*

Three cases to remove a node:

Leaf (no children): just take it away.

One child: remove the node and connect its parent directly to its child.

Two children: find the successor, copy the successor’s number into the node to delete, then actually remove the successor (which will be easier because it has at most one child).

This keeps the shelf sorted after deletion. 


12) *Priority queue;*

A priority queue always gives the swing to the highest priority (like the smallest run-time job or the biggest number, depending on rules). We want a structure that:

lets you add a enqueue,

check who is first,

and remove the first quickly.

We implement this with a heap. 


13) *Heap;*

A heap is a binary tree shaped like a complete pyramid (filled left-to-right) and it obeys:

Every child toy has number ≤ its parent node.

This makes finding the biggest node super quick. 


14) *Insert into heap;*

Put the new node at the end.

If its bigger than its parent, swap them. Keep swapping up until it’s in the right spot. This makes the big nodes bubble up. This takes about how tall the heap is (log n). 


15) *Heapify*

If a parent is smaller than a child, we swap it with the largest child and continue down. This is used in removing the top or building a heap. 


16) *DeleteMax (remove the biggest) in heap;*

To remove the top biggest toy:

Swap the top node with the last node in the array.

Remove the last node (which is now the biggest).

Heapify from the top to push the swapped toy down into the right place.

This keeps the pyramid shape and heap property. 


17) *BuildHeap;*

If you have a pile of numbers, you can turn them into a heap quickly by calling Heapify on nodes starting from the bottom up.

Even though it calls Heapify many times, doing it bottom-up makes the whole process fast, in fact it takes linear time (O(n)). 


18) *Heapsort;*

To sort:

Build a heap from the list.

Repeatedly remove the maximum and place it at the end of the array. Each removal puts the next largest number into its correct final place.

This gives a sorted list and runs in O(n log n) time.     

###################################### Week 3 : RB trees and AVL trees#######################################



**1. Red-Black Trees**

_1.1 What is a Red-Black Tree?_

A red-black tree is a binary search tree (BST) with extra coloring rules to keep it balanced.


i) Every internal node is colored red or black

ii) The root is black

iii) Null leaves have no color

iv) A red node cannot have a red child

v) Every path from a node to its null leaves has the same number of black nodes

These rules guarantee logarithmic height.

_1.2 Null Leaves_

i) Missing children are replaced by dummy null nodes

ii) This simplifies defining and maintaining black height

_1.3 Black Height_

Black height (bh) of a node = number of black nodes on any path from that node to a null leaf.

Definition:

i) bh(null) = 0

ii) If node is black:
    bh = max(bh(left), bh(right)) + 1
iii) If node is red:
    bh = max(bh(left), bh(right))

Important property:
i) For every node,
    bh(left subtree) = bh(right subtree)

_1.4 Height Bound of Red-Black Tree_

Let h = black height and n = number of nodes.

i) Minimum nodes occur when all nodes are black
    → n = 2^h − 1

ii) Maximum nodes occur when red nodes alternate with black nodes
    → tree height ≤ 2h

iii) Hence,

    log₄ n < h ≤ log₂(n + 1)


iv) Therefore, tree height is O(log n)


_1.5 Searching in Red-Black Trees_


i) Search

ii) Minimum / Maximum

iii) Successor / Predecessor

_All operations are performed exactly like a BST but take O(log n) time due to bounded height._

**2. Insertion in Red-Black Tree**

_2.1 Basic Insertion Idea_

i) Insert the node using standard BST insertion

ii) Color the new node red

Effects:

i) Black height remains unchanged

ii) A red-red violation may occur

_2.2 Red-Red Violation_

i) Occurs when a red node has a red parent

ii) Violation starts at the inserted leaf and may move upward

Let:

i) n = newly inserted node

ii) p = parent of n

iii) g = grandparent of n

iv) u = uncle of n

_2.3 Fixing Red-Red Violation_

Case 1: Uncle is Red

i) Recolor parent and uncle to black

ii) Recolor grandparent to red

iii) Violation may propagate upward

Case 2: Uncle is Black and path is not straight

i) Rotate at (p, n)

ii) Converts the structure into Case 3

Case 3: Uncle is Black and path is straight

i) Rotate at (g, p)

ii) Swap colors of g and p

iii) Red-red violation is resolved

2.4 Insertion Summary

i) Insert node like BST

ii) Color new node red

iii) Fix red-red violations using recoloring or rotations

iv) Time complexity = O(log n)

**3. Deletion in Red-Black Tree**

_3.1 BST Deletion Step_

i) Delete node as in BST

ii) The deleted node has at most one non-null child

_3.2 Possible Violations After Deletion_

If the deleted node was red:

i) No violation occurs

If the deleted node was black:

i) Black-height violation may occur

ii) Red-red violation may also occur

_3.3 Violation Cases_

Let:

i) x = node replacing deleted node

ii) s = sibling of x

Case 1: x is red

i) Recolor x to black

ii) Violation resolved

Case 2: x is root

i) Do nothing

Case 3: Sibling of x is red

i) Rotate at (p, s)

ii) Swap colors

iii) Converts the situation into Case 4

_3.4 Case 4: Sibling is Black_

Case 4.1: Far nephew is red

i) Rotate at (p, s)

ii) Swap colors of p and s

iii) Color far nephew black

iv) Violation resolved

Case 4.2: Near nephew is red

i) Rotate at (s, near nephew)

ii) Converts into Case 4.1

Case 4.3: Both nephews are black

i) Color sibling red

ii) Black-height violation moves to parent

_3.5 Deletion Summary_

i) Delete like BST

ii) Fix violations using recoloring and rotations

iii) Only Case 4.3 propagates upward

iv) Time complexity = O(log n)

**4. AVL Trees**

_4.1 Definition_

An AVL tree is a BST such that for every node:

    |height(left) − height(right)| ≤ 1

_4.2 Height of AVL Tree_

Let n(h) be the minimum number of nodes of height h.

i) Base cases:
    n(1) = 1, n(2) = 2

ii) Recurrence relation:

    n(h) = 1 + n(h−1) + n(h−2)


iii) This grows exponentially

iv) Therefore, height of AVL tree is O(log n)

_4.3 Closest Leaf Property_

If the closest leaf from root is at level k:

i) height ≤ 2k − 1

_4.4 Structural Property_

i) Up to level k−2, all nodes have two children

ii) Hence, AVL trees are partially complete

**5. Insertion and Deletion in AVL Trees**

_5.1 General Strategy_

i) Insert and delete like BST

ii) At most one path becomes imbalanced

iii) Fix imbalance at the deepest unbalanced node

_5.2 Rebalancing Cases_

Let:

i) x = deepest imbalanced node

ii) t = taller child of x

iii) g = grandchild of x

Case 1: Both grandchildren have same height

i) Perform a single rotation

Case 2: Inner grandchild is taller

i) Perform a single rotation

Case 3: Outer grandchild is taller

i) Perform a double rotation

**Final Quick-Revision Points**

_i) Red-black trees balance using colors + rotations_

_ii) AVL trees balance using strict height difference_

_iii) Red-black trees perform fewer rotations_

_iv) AVL trees have smaller height_

_v) Both support search, insert, delete in O(log n)_






################################### Week 4 : Tries and suffix tries ###########################################


**1. When Keys Are Strings**

i) For unordered keys → hash tables are used

ii) For ordered keys → red-black trees are used

iii) When keys are strings, they have extra structure (prefix, substring)

iv) We want a data structure that exploits this structure


_Typical applications:_

i) Web search

ii) Text search (all occurrences of words)

iii) Routing tables (IP addresses)

**2. Trie**

_2.1 Definition of Trie_

Let Σ be the alphabet.

i) A trie is an ordered tree

ii) Each node (except root) stores one character from Σ

iii) Each node has at most |Σ| children, all with distinct labels

iv) A word is represented by a path from root to a leaf

Example:

Words {bear, bile, bid, bent} share prefix b, so they branch only when letters differ.

_2.2 End Marker_

Problem: one word may be a prefix of another.

i) Add a special end marker `$`

ii) `$` marks the end of a valid word

Example:

Words `{act, actor}`

i) `act$`

ii) `actor$`

This distinguishes `act` from `actor`.

_2.3 Time and Space Complexity_

i) Space complexity = O(W)
    where W = total length of all words

ii) Search, insert, delete time = O(|Σ| · m)
    where m = length of the word

iii) Reason: at each node, we may scan all children to find next letter

**3. Applications of Trie**

_3.1 Word Search in Text_

i) Store all words of a text in a trie

ii) Each leaf stores:
    a) first occurrence position, or
    b) list of all occurrence positions

This allows fast word lookup in large text.

_3.2 Routing Table_

i) IP addresses are stored as strings in a trie

ii) Packet IP is matched along the trie

iii) Longest prefix match determines the outgoing link

This is why tries are used in routers.

**4. Compressed Trie**

_4.1 Definition_

_A compressed trie is obtained by compressing chains of single-child nodes._

i) If a non-root node has only one child and no end marker, compress it

ii) Nodes store substrings instead of single characters

Example:

Words `{act, actor}` become:

edge labeled `"act"`

branch to `"or"` and `$`

_4.2 Number of Nodes_

i) Each leaf corresponds to one word

ii) Every internal node has at least two children

iii) Number of internal nodes < number of leaves

 Total nodes = O(number of words)

Conclusion:

i) Compressed tries save space

ii) Especially useful when words share long prefixes

_4.3 Practical Optimization_

i) Do not store substrings explicitly

ii) Store only `(start index, length)` pointing to original text

This saves memory for large texts.

**5. Suffix Tree**

_5.1 Motivation_

Given:

i) A mostly fixed text T

ii) Many pattern searches

Goal:

i) Preprocess T once

ii) Answer searches quickly

_5.2 Definition of Suffix Tree_

i) A suffix tree is a trie built on all suffixes of a text T

ii) Each suffix ends with a unique terminal symbol $

Example:

Text = `"abaa"`

Suffixes:

i) `abaa$`

ii) `baa$`

iii) `aa$`

iv) `a$`

_5.3 Uses of Suffix Tree_

i) Check if pattern P occurs in T

ii) Check if P is a suffix of T

iii) Count number of occurrences of P

iv) Find longest repeated substring

Key idea:

i) Deepest node with ≥ 2 children gives longest repeated substring

**6. Suffix Links**

_6.1 Definition_

i) Each node represents a string

ii) A suffix link connects `xα → α`

This allows fast traversal between related suffixes.

_6.2 Use of Suffix Links_

Used to solve advanced problems like:

i) Longest common substring of T and P

Procedure:

i) Walk P down the suffix tree

ii) On mismatch, follow suffix links

iii) Track maximum depth reached

**7. Constructing Suffix Tree**

_7.1 Incremental Construction_

i) Assume suffix tree for `T[0 : i−1]` is built

ii) Add character `T[i]` to all suffixes

iii) Use suffix links to move efficiently

_7.2 Complexity_

i) With suffix links → O(n²) construction

ii) Without suffix links → worse than O(n²)

_7.3 Ukkonen’s Algorithm_

i) Advanced algorithm

ii) Builds suffix tree in O(n) time

iii) Uses clever implementation tricks

iv) Not covered in detail in this course

**8. Things to Remember **

_i) Trie exploits prefix structure of strings_

_ii) End marker `$` is required for prefix words_

_iii) Compressed trie reduces space drastically_

_iv) Suffix tree stores all suffixes of text_

_v) Suffix trees allow very fast pattern queries_

vi) Suffix links speed up construction and queries












following are some of the problems i did during the project;
to be honest this project was a little bit tough for me as cs101 was kinda prerequisite for this but i dint knew;
but mentors rlly helped me a lot by clarifying my doubts and giving me some easier prblms that also i have listed below;


#### Problems  : 
#### 0.1 fizzbuzz
#### 0.2 parity
#### 0.3 pandidgital
#### 
#### 1.LC 94 
#### 2.LC 101 
#### 3.LC 108 
#### 4.LC 110 
#### 5.LC 144 
#### 6.LC 145 
#### 7.LC 501 

