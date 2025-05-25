# 🧠 Memory Management in Operating Systems

This folder contains C programs that demonstrate fundamental memory allocation strategies used in Operating Systems.

✅ Implemented Algorithms:
- First Fit
- Best Fit
- Worst Fit

---

## 📚 What Is Memory Management?

Memory management is a critical component of any operating system. It handles allocation and deallocation of memory to various processes, ensuring efficient use of available memory and avoiding fragmentation.

In contiguous memory allocation, each process is allocated a single continuous block of memory. The OS uses allocation strategies to determine which block should be assigned to a process.

---

## 🧪 Algorithms Overview

| Strategy     | Description |
|--------------|-------------|
| First Fit    | Allocates the first memory block that is large enough. |
| Best Fit     | Allocates the smallest suitable block to reduce wasted space. |
| Worst Fit    | Allocates the largest available block to reduce fragmentation. |

---

## 🚀 How to Run

1. Make sure you have a C compiler like gcc installed.
2. Use terminal to navigate into this folder.

Run the desired algorithm:

```bash
gcc first_fit.c -o first_fit
./first_fit

gcc best_fit.c -o best_fit
./best_fit

gcc worst_fit.c -o worst_fit
./worst_fit

You will be prompted to input:

- Number of memory blocks
- Size of each memory block
- Number of files (or processes)
- Size of each file

### Sample Input
```text
Enter the number of blocks: 3
Enter the number of files: 2
Enter the size of the blocks:
Block 1: 5
Block 2: 2
Block 3: 7
Enter the size of the files:
File 1: 1
File 2: 4
```

### Sample Output (First Fit)
```text
File No   File Size   Block No   Block Size   Fragment
1         1           1          5            4
2         4           3          7            3
```

### Learn More
- [GeeksForGeeks – Memory Allocation Strategies](https://www.geeksforgeeks.org/memory-allocation-strategies/)
- [Wikipedia – Memory Management](https://en.wikipedia.org/wiki/Memory_management)
- [Little OS Book (Free)](https://littleosbook.github.io/)
- OS Textbooks like Galvin, Tanenbaum, or Stallings

📝 License
MIT License – free to use, modify, and contribute.

🙌 Contributions Welcome
Feel free to open a PR to:

Add new strategies like Next Fit

Improve input validation

Add visualization or ASCII diagrams

Happy coding! 💻✨