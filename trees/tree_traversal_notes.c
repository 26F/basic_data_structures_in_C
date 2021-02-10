
#include <stdio.h>

/*
Binary tree traversal

Breadth-first
Depth-first

We give depth (level) of nodes from root (number of edges to that node
from root)

         a        L-0
       /  \
      b    c      L-1
     / \  / \
    d  e f   g    L-2
   / \  /\  / \
  h  i j  k l  m  L-3


Breadth-first:
a            L-0
b c          L-1
d e f g      L-2
h i j k l m  L-3

"Level order traversal"

Depth-first:
preorder traversal: Data Left Right    
<root> <left subtree> <right subtree>


Inorder traversal:  Left Data Right
<left subtree> <root> <right subtree>


Postorder traversal: Left Right Data
<left subtree> <right subtree> <root>

*------------------------------------------------------------------*

Example of Depth-first Preorder traversal:
DLR

         f
       /   \
      d     j
     / \   / \
     b  e  g  k
    /\     \ 
   a c      i
           /
          h

f d b a c e j g i h k

*------------------------------------------------------------------*

Example of Depth-first Inorder traversal:
LDR

         f
       /   \
      d     j
     / \   / \
     b  e  g  k
    /\     \ 
   a c      i
           /
          h

a b c d e f g h i j k

This prints the elements in order!

*------------------------------------------------------------------*

Example of Depth-first Postorder traversal
LRD

         f
       /   \
      d     j
     / \   / \
     b  e  g  k
    /\     \ 
   a c      i
           /
          h

a c b e d h i g k j f

*/

int main() {
	return 0;
}