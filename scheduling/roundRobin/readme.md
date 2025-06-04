# 🔁 Round Robin (RR) Scheduling Algorithm

This folder contains a **C implementation of the Round Robin (RR)** CPU scheduling algorithm, one of the most widely used preemptive scheduling strategies in modern operating systems.

---

## 📌 What is Round Robin Scheduling?

- **Preemptive** CPU scheduling algorithm.
- Each process gets **a fixed time slot** (called **time quantum**).
- If a process doesn't finish in that slot, it goes to the **back of the queue**.
- Ensures **fair CPU time sharing**.

---

## 🧠 How It Works

1. All processes are placed in a circular queue.
2. Each process runs for up to `time_quantum`.
3. If a process finishes during its slot, it exits the queue.
4. If not, it gets added to the end of the queue.

---

## 📂 Files

| File             | Description                        |
|------------------|------------------------------------|
| `round_robin.c`  | Round Robin scheduling in C        |

---

## 🛠️ Build and Run

```bash
gcc round_robin.c -o round_robin
./round_robin
````

---

## 🧪 Sample Input

```
Enter the number of processes: 3
Enter Burst Time for process 1: 24
Enter Burst Time for process 2: 3
Enter Burst Time for process 3: 3
Enter the Time Quantum: 3
```

### ✅ Sample Output

```
Process	Burst Time	Waiting Time	Turnaround Time
1       24          6             30
2       3           4             7
3       3           7             10

Average Waiting Time: 5.67
Average Turnaround Time: 15.67
```
### Gantt chart
![Gantt Chart](image.png)
---

## 🧮 Key Concepts

* **Time Quantum**: The fixed time each process gets to run.
* **Waiting Time**: Total time a process waits in the ready queue.
* **Turnaround Time**: Total time from arrival to completion.

---

## 🧠 Use Cases

* Used in **time-sharing systems**.
* Ensures **fairness**.
* Prevents process starvation.

---

## 📚 Learn More

* [GeeksForGeeks – Round Robin](https://www.geeksforgeeks.org/round-robin-scheduling/)
* [Wikipedia – Round-robin Scheduling](https://en.wikipedia.org/wiki/Round-robin_scheduling)
* OS Textbooks like "Operating System Concepts" (Silberschatz et al.)

---

## 📝 License

Released under the **MIT License** – free to use, modify, and distribute.

---

## 🙌 Contributing

You can contribute by:

* Adding arrival time support
* Drawing Gantt charts
* Porting to Python/Java

Pull requests are welcome! 🔄🚀

```

---

Would you like me to do the same for **SJF**, **Priority**, or **Banker's Algorithm** next?
```
