# Page Replacement Algorithms in C++

## Objective

This project demonstrates the implementation of page replacement algorithms in C++. The goal is to gain an understanding of how operating systems handle page faults and choose which pages to remove from virtual memory in the cache to make space for new pages. The project focuses on implementing the following page replacement algorithms:

- **FIFO (First In First Out)**
- **LRU (Least Recently Used)**
- **Random Replacement**

## Project Overview

When a page fault occurs, the operating system must decide which page to remove from memory to allow a new page to load. This project simulates the page replacement process, illustrating how different algorithms handle page faults and memory management.

## Algorithms Implemented

### FIFO (First In First Out)
- The oldest page in memory is removed to make space for the new page.

### LRU (Least Recently Used)
- The page that has not been used for the longest time is removed, as it's least likely to be needed soon.

### Random Replacement
- A randomly chosen page in memory is replaced to make room for the new page.

## Language and Tools

- **Programming Language**: C++
- **IDE**: Any C++ compatible IDE, such as Visual Studio, Code::Blocks, or VS Code.
