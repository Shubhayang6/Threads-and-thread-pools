# Concurrent Task Processing Engine

A lightweight, fixed-size **thread pool implementation in C++17** that supports concurrent task execution using a pool of worker threads, a thread-safe task queue, and graceful shutdown.

This project demonstrates core concepts in **concurrency, synchronization, and parallel performance**.

##  Features

- Fixed-size pool of worker threads  
- Thread-safe task queue  
- Task submission via `enqueue()`  
- Worker threads block when idle (efficient)  
- Graceful shutdown and clean exit  
- Minimal, header-only implementation  
- C++17 and above  

##  Architecture Overview

The thread pool is built around a **producer–consumer model**:
```
                 +---------------+
 enqueue() ----> |   Task Queue  | <----- worker threads
                 +---------------+
                        |
         +---------------+---------------+
         |               |               |
      worker 1       worker 2       worker N
```
## Components

| Component | Responsibility |
|----------|----------------|
| `workers` | Pool of threads executing tasks |
| `tasks` | Queue of pending work |
| `mutex_` | Protects the queue |
| `cond_` | Wakes workers when new work arrives |
| `stop` | Signals shutdown |

Workers repeatedly:

1. Wait for a task  
2. Pop task from queue  
3. Execute task  


## Performance

Thread pools avoid the overhead of repeatedly creating and destroying threads.

Typical speedups on multi-core CPUs:

- CPU-bound workloads: **3× – 6× faster**
- Depends on number of cores and task size


##  Learning Outcomes

- Multithreading and concurrency in C++
- Correct use of synchronization primitives
- Producer–consumer architecture
- Deadlock avoidance
- RAII-based resource management
- Parallel performance optimization

## Author

SHUBHAYAN GHOSH 
GitHub Profile: https://github.com/shubhayang6  

##  License

Apache License

