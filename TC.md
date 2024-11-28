# Binary Search Tree Operations and Time Complexities

## Operations

1. **`createNode`**  
   **Time Complexity**: O(1)  
   Description: Creates a new node with the given value.

2. **`insert`**  
   **Time Complexity**: O(h)  
   Description: Inserts a value into the tree.  
   - `h` is the height of the tree.

3. **`countNodes`**  
   **Time Complexity**: O(n)  
   Description: Counts the total number of nodes in the tree.  
   - `n` is the number of nodes in the tree.

4. **`countLeafNodes`**  
   **Time Complexity**: O(n)  
   Description: Counts the number of leaf nodes in the tree.  
   - `n` is the number of nodes in the tree.

5. **`findHeight`**  
   **Time Complexity**: O(n)  
   Description: Finds the height of the tree.  
   - `n` is the number of nodes in the tree.

6. **`findMin`**  
   **Time Complexity**: O(h)  
   Description: Finds the minimum value in the tree.  
   - `h` is the height of the tree.

7. **`delNode`**  
   **Time Complexity**: O(h)  
   Description: Deletes a node with a specified value from the tree.  
   - `h` is the height of the tree.

8. **`inOrderTraversal`**  
   **Time Complexity**: O(n)  
   Description: Performs an in-order traversal of the tree.  
   - `n` is the number of nodes in the tree.

9. **`preOrderTraversal`**  
   **Time Complexity**: O(n)  
   Description: Performs a pre-order traversal of the tree.  
   - `n` is the number of nodes in the tree.

10. **`postOrderTraversal`**  
    **Time Complexity**: O(n)  
    Description: Performs a post-order traversal of the tree.  
    - `n` is the number of nodes in the tree.


### Graph Traversal Operations

1. **`DFS(iterative)`** (Iterative Depth-First Search)  
   **Time Complexity**: O(V + E)  
   Description: Performs DFS using a stack.  
   - `V` is the number of vertices (nodes) in the graph.  
   - `E` is the number of edges in the graph.

2. **`DFS(Recursive)`** (Recursive Depth-First Search)  
   **Time Complexity**: O(V + E)  
   Description: Performs DFS recursively.  
   - `V` is the number of vertices (nodes) in the graph.  
   - `E` is the number of edges in the graph.

3. **`BFS`** (Breadth-First Search)  
   **Time Complexity**: O(V + E)  
   Description: Performs BFS using a queue.  
   - `V` is the number of vertices (nodes) in the graph.  
   - `E` is the number of edges in the graph.

# Singly Linked List Operations

### Insertions

1. **Insert at Beginning**
    - Adds a new node at the start of the linked list.
    - **Function:** `void insertAtBeginning(struct Node** head, int value);`
    - **Time Complexity:** O(1)

2. **Insert at End**
    - Adds a new node at the end of the linked list.
    - **Function:** `void insertAtEnd(struct Node** head, int value);`
    - **Time Complexity:** O(n), where `n` is the number of nodes in the list.

3. **Insert Before a Node**
    - Adds a new node before a given node with a specific value.
    - **Function:** `void insertBefore(struct Node** head, int value, int newValue);`
    - **Time Complexity:** O(n), where `n` is the number of nodes in the list.

### Deletions

1. **Delete a Specific Node**
    - Deletes the first occurrence of a node with the given value.
    - **Function:** `void deleteNode(struct Node** head, int value);`
    - **Time Complexity:** O(n), where `n` is the number of nodes in the list.

2. **Delete at Beginning**
    - Removes the first node (head node) from the list.
    - **Function:** `void deleteAtBeginning(struct Node** head);`
    - **Time Complexity:** O(1)

3. **Delete at End**
    - Deletes the last node in the linked list.
    - **Function:** `void deleteAtEnd(struct Node** head);`
    - **Time Complexity:** O(n), where `n` is the number of nodes in the list.