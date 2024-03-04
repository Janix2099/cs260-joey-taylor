Joey Taylor
3/4/2024
CS 260
Assignment 6

1. Create a design, before you start coding, that shows how your binary tree functions and what attributes it keeps track of to function
    I would need nodes to store values left or right, an add function that adds nodes to their proper location, a remove function that ensures the properties of the tree through proper successors, 
    and a method that traverses the tree in an ordered fashion (left node, current node, right node) and processes or prints the values in a sorted order.

2. Create tests for the Binary Search Tree (BST) before I start coding:
    Add Elements Test: Insert 10, 5, 15, 3, 7, 13, 17 and ensure the BST structure reflects the correct relationships.
    Remove Leaf Node Test: Delete 3 and check the tree adjusts without 3.
    Remove Node with One Child Test: Delete 15 and ensure 15 is replaced by its child 17.
    Remove Node with Two Children Test: Delete 10 (root) and verify it's replaced by 13 (its successor).
    Traversal Order Test: Perform in-order traversal and expect the sequence 5, 7, 13, 17 after all removals.
    BST Integrity Test: After all add/remove operations, confirm all nodes maintain BST property (left < node < right).

3. Implement a binary search tree that includes:
  3a. Nodes to store values
      binarynode.h
  3b. An add function that adds a new value in the appropriate location based on our ordering rules
      binary_search_tree.cpp lines 30-47
  3c. A remove function that finds and removes a value and then picks an appropriate replacement node
      binary_search_tree.cpp lines 49-116
  3d. Have at least one tree traversal function (I recommend starting with an in-order traversal!)
      binary_search_tree.cpp lines 133-144

4. Analyze and compare the complexity of insert and search as compared to a binary tree without any order in its nodes (what is the run-time of an unordered tree...?).
  Binary Search Tree (BST)
    Insertion and Search Complexity:
        Average Case O(log n): In a BST, you can skip half of the tree every time you make a decision to go left or right, making things considerably faster
        Worst Case O(n): If the tree is all lopsided, then it is practically a line rather than a tree and the skips do not happen

  Unordered Binary Tree
      Insertion Complexity O(n): When you add a new node, you might have to look at lots of nodes to find where it goes because there's no rule to where the next open spot is
      Search Complexity O(n): If you're looking for a specific value, you have to check each and every node, since they're not in any particular order

5. Once you have implemented and tested your code, add to the README file what line(s) of code or inputs and outputs show your work meeting each of the above requirements (or better, include a small screen snip of where it meets the requirement!).
  test_bst.cpp includes all the tests made for the code. Here is the output, line requirements specified in the above questions:
  image: https://media.discordapp.net/attachments/1195139337843642378/1214319373297131681/image.png?ex=65f8ae0b&is=65e6390b&hm=d107434dd0e131d24e4b919556b76a447c7d8722bf8f36d2c2b30822b2117ba8&=&format=webp&quality=lossless
