# ⏱️ FCFS (First Come First Serve) Scheduling Algorithm

This folder contains a simple C implementation of the **First Come First Serve (FCFS)** CPU scheduling algorithm.

---

## 📌 What is FCFS?

- FCFS is the **simplest** CPU scheduling algorithm.
- The process that arrives **first gets executed first**.
- It is **non-preemptive** and easy to implement.

---

## 🧠 How It Works

1. Processes are lined up in a queue based on arrival order.
2. Each process runs **to completion** before the next one starts.
3. No context switching happens in the middle.

---

## 📂 Files

| File       | Description                           |
|------------|---------------------------------------|
| `fcfs.c`   | FCFS scheduling source code in C      |

---

## 🛠️ Build and Run

```bash
gcc fcfs.c -o fcfs
./fcfs
````

---

## 🧪 Sample Input

```
Enter the number of processes -- 3
Enter Burst Time for Process 0 -- 24
Enter Burst Time for Process 1 -- 3
Enter Burst Time for Process 2 -- 3
```

### ✅ Sample Output

```
PROCESS   BURST TIME   WAITING TIME   TURNAROUND TIME
P0        24           0              24
P1        3            24             27
P2        3            27             30

Average Waiting Time -- 17.00
Average Turnaround Time -- 27.00
```

---

## 🧮 Key Formulas

* **Waiting Time (WT):** Time spent in the ready queue
  `WT[i] = WT[i-1] + BT[i-1]`
* **Turnaround Time (TAT):** Total time from arrival to completion
  `TAT[i] = WT[i] + BT[i]`

---

## 📚 Learn More

* [GeeksForGeeks - FCFS Scheduling](https://www.geeksforgeeks.org/fcfs-scheduling-processes/)
* [Wikipedia - Scheduling (Computing)](https://en.wikipedia.org/wiki/Scheduling_%28computing%29)
* OS Textbook: "Operating System Concepts" by Silberschatz et al.

---

## 📝 License

This code is released under the **MIT License** – free to use and modify.

---

## 🙌 Contributing

Want to help?

* Add support for arrival times
* Add Gantt chart output
* Convert to other languages (e.g. Python, Java)

Pull requests welcome! 🚀





