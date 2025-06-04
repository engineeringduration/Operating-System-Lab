# 📉 Shortest Job First (SJF) Scheduling Algorithm

This folder contains a **C implementation of the Shortest Job First (SJF)** CPU scheduling algorithm, a popular and efficient strategy for minimizing process wait times.

---

## 📌 What is SJF?

- **Non-preemptive** CPU scheduling algorithm.
- The process with the **shortest burst time** is selected next.
- Can significantly reduce **average waiting time**.
- Based on the principle: **"shortest job first" = fastest system throughput**.

---

## 📂 Files

| File     | Description                             |
|----------|-----------------------------------------|
| `sjf.c`  | Non-preemptive SJF scheduling in C      |

---

## 🧠 How It Works

1. All processes are added to a ready queue.
2. The process with the **least burst time** is selected and executed to completion.
3. The process is removed, and the next shortest job is selected.
4. Repeat until all processes are finished.

> ⚠️ Note: This version does **not** consider arrival time — all processes are assumed to arrive at time 0.

---

## 🛠️ Build and Run

```bash
gcc sjf.c -o sjf
./sjf
````

---

## 🧪 Sample Input

```
Enter the number of processes -- 4
Enter Burst Time for Process 0 -- 6
Enter Burst Time for Process 1 -- 8
Enter Burst Time for Process 2 -- 7
Enter Burst Time for Process 3 -- 3
```

### ✅ Sample Output

```
PROCESS   BURST TIME   WAITING TIME   TURNAROUND TIME
P3        3            0              3
P0        6            3              9
P2        7            9              16
P1        8            16             24

Average Waiting Time -- 7.00
Average Turnaround Time -- 13.00
```
###Gantt Chart

![Gantt Chart](image.png)

---

## 🧮 Key Concepts

* **Burst Time (BT)**: Time the CPU takes to complete a process.
* **Waiting Time (WT)**: Time a process waits before execution.
* **Turnaround Time (TAT)**: `TAT = WT + BT`

---

## 💡 When to Use

* Suitable for batch systems where all jobs are known in advance.
* Excellent when **arrival time is not a factor**.
* Not ideal for real-time systems due to possible long wait for larger jobs.

---

## 📚 Learn More

* [GeeksForGeeks – SJF Scheduling](https://www.geeksforgeeks.org/shortest-job-first-sjf-scheduling/)
* [Wikipedia – SJF Algorithm](https://en.wikipedia.org/wiki/Scheduling_%28computing%29#Shortest_job_next)
* "Operating System Concepts" by Silberschatz, Galvin, Gagne

---

## 📝 License

Released under the **MIT License** – free to use, modify, and share.

---

## 🙌 Contributing

Want to improve this?

* Add support for **arrival time**
* Implement **preemptive SJF** (Shortest Remaining Time First)


Pull requests welcome! 📊✨


