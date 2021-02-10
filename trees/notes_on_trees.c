
#include <stdio.h>

/*
Trees good for storing naturally hierarchical data


                  () root (parent node)
                 /  \
                ()  () child nodes (these are also siblings (children of the same node))

Every node except the root node parent nodes.
Not every node has a child node. Such as leaf nodes 
(nodes that do not have a child node.)

We can use analogies like grandfather or great grandfather
or ancestors etc. 

Recursive data structure.

A strict/proper binary tree each node must have 2 child nodes.

A complete binary tree (all levels except the last are completely filled 
and all nodes are as left as possible) (see below)

    	0
       /  \
      0    0
     / \  / \
    0  0  0 0
   / \ 
  0  0

  A perfect binary tree would be like the above except every level is completely full

         0
       /  \
      0    0
     / \  / \
    0  0 0   0
   / \  /\  / \
  0  0 0  0 0  0

Highet of perfect binary tree with n nodes: h = log_2(n + 1) - 1

We like balanced binary trees: The difference between the 
height of the left and right subtree for every node is not more than 
k. (K is usually 1)

* Height of a tree: Number of edges in longest path from the root to a leaf.
Generally height of an empty tree is -1. Once the tree has one node, we 
say it has a height of 0, because *

For example when comparing the height of two subtrees

diff = |lefth - righth| = k where ideally we want k to equal 1 at the maximum.


when can use arrays to store binary tree

        (2)
       /   \
      (4)  (1)
     / \   /  \
    (5)(8)(7)(9)

[2][4][1][5][8][7][9]
 0  1  2  3  4  5  6

So the indices:
	
	     0
       /  \
      1    2
     / \  / \
    3  4  5  6

If it is a complete binary tree we can use 

given a node at index i:

leftchildindex  = (2 * i) + 1
rightchildindex = (2 * i) + 2  

*/

int main() {
	return 0;
}