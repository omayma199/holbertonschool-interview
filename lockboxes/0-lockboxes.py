#!/usr/bin/python3
"""
Task 0: Lockboxes
"""


def canUnlockAll(boxes):
    # Total number of boxes
    n = len(boxes)  
    # Initialize a list to track visited boxes
    visited = [False] * n
    # Mark the first box as visited
    visited[0] = True 
    # Start the stack with the first box
    stack = [0]

    while stack:
        # Get the current box from the stack
        current_box = stack.pop()
        # Iterate through keys in the current box
        for key in boxes[current_box]:
            # Check if key is valid and not visited
            if key >= 0 and key < n and not visited[key]:
                # Mark the box as visited
                visited[key] = True
                # Add the box to the stack for further exploration
                stack.append(key)
    # Return True if all boxes are visited, otherwise False
    return all(visited)
