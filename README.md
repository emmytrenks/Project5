# Tree Traversal Iterators
### By: Emily Trenka

## Project Description
My objective was to implement tree traversals using iterators.
To accomplish this, I had to implement a tree abstract data type, along with its accompanying node and methods for insertion, etc.

Following this, I implemented three basic tree traversals (pre, post, and in order) and exposed them via iterators. These iterators can then be used to progress forward or backward through the desired iteration.

After completing this project, I have a much deeper understanding of trees than before, and their traversals. More importantly, I now understand iterators too!

## Implementation
To implement this project, I started by implementing the tree. The tree had to be implemented in a special way so it was readily usable as a *binary* tree, such that the traversals could be performed.

To store the tree in such a fashion, I implemented the left-child right-sibling tree. Other methods include lists of children, or a parent pointer matrix. The left-child right-sibling tree is the easiest to convert to a binary tree, as the left-child signifies the left node of the binary node, and the right-sibling signifies the right node of the binary node. This provides a one-to-one method of reading a tree as a general tree or a binary tree.

For clarification purposes, my code explicitly converts the general tree into a binary tree before performing the traversals. This is partly due to the fact that when I first started the project I wasn't using the left-child right-sibling tree and required the binary nodes. I decided to leave them in after the fact to show more explicitly the traversals are being done on a binary representation of the tree.
