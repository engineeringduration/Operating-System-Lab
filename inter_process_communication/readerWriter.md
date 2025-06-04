# 📖 Readers–Writers Problem (Writer Priority)

This directory contains an implementation of the classic **Readers–Writers Problem** using **pthreads and semaphores** in C.

> **Goal:**  
> - Allow multiple readers to access shared data **concurrently**.  
> - Ensure **exclusive access** for writers.  
> - Give **writers priority** so they aren't starved by a continuous stream of readers.

---

## 🗂️ Files

| File | Description |
|------|-------------|
| `readerWriter.c` | Fully‑commented C source implementing the writer‑priority Readers–Writers solution |

---
<div style="text-align: center;">
    <img src="https://files.prepinsta.com/2023/01/reader-writer-problem.webp" alt="Profile-gif" width="100%">
</div>

---
## 📌 Quick Theory

| Term | Meaning |
|------|---------|
| **Reader** | Thread that only needs to **read** the shared data. Multiple readers can read simultaneously. |
| **Writer** | Thread that **writes/updates** shared data and needs exclusive access. |
| **Semaphore** | Kernel object used here to coordinate access (`sem_wait`, `sem_post`). |
| **Writer Priority** | Readers will wait if any writer is waiting or writing, preventing writer starvation. |

---

## 🛠️ Build & Run

```bash
# Compile
gcc reader_writer.c -lpthread -o reader_writer

# Run
./reader_writer
```

Press **Ctrl+C** to stop the demo (threads loop indefinitely).

---

## 🧪 Example Console Output

```
Writer 1: updated shared_data to 6
Reader 1: read shared_data = 6
Reader 2: read shared_data = 6
Writer 2: updated shared_data to 15
Reader 3: read shared_data = 15
...
```

---

## 📚 Further Resources

- [Wikipedia – Readers–writers problem](https://en.wikipedia.org/wiki/Readers%E2%80%93writers_problem)
- [GeeksForGeeks – Reader-Writer problem with semaphore](https://www.geeksforgeeks.org/reader-writer-problem-using-semaphores-set-1/)
- [Little Book about OS](https://littleosbook.github.io/)
- **Operating System Concepts** by Silberschatz, Galvin, and Gagne – Chapter on Process Synchronization

---

## 📝 License

Released under the **MIT License** – feel free to use, modify, and distribute.

---

## 🙌 Contributing

1. Fork the repository
2. Create your feature branch: `git checkout -b feature/my-change`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin feature/my-change`
5. Open a Pull Request

Happy hacking! 🚀
