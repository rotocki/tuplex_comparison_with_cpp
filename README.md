# tuplex_comparison_with_cpp
Comparison of a simple solution to count all prime numbers up to a given value using tuplex and pure C++

Original article: [How to Speed up Python Data Pipelines up to 91X?](https://towardsdatascience.com/how-to-speed-up-python-data-pipelines-up-to-91x-80d7accfe7ec)

This article claims that:

```
Tuplex’s performance boost is remarkable compared to the other standard python ways. This trivial example resulted in 769k times shorter execution than multiprocessing and 1280k times faster than vanilla for-loops.

We’ll… let’s stick to the Tuplex team’s promise of 5–91X. Nevertheless, Tuplex urges me to think twice before I write another for loop ever.
```

Since execution speed-up seems too good to be true, let's check it ourselves.

After installing `tuplex` from PyPI in a virtual environment:
```
$ python -m venv .venv
$ source .venv/bin/active
(.venv) $ python -m pip install tuplex
```

We can run our examples and see the results:
```
(.venv) $ python script.py 
Welcome to

  _____            _
 |_   _|   _ _ __ | | _____  __
   | || | | | '_ \| |/ _ \ \/ /
   | || |_| | |_) | |  __/>  <
   |_| \__,_| .__/|_|\___/_/\_\ 0.3.1
            |_|
    
using Python 3.8.5 (default, Jul 28 2020, 12:59:40) 
[GCC 9.3.0] on linux
Single for-loop elapsed: 7.160334900000635. Result: [1229, 2262, 3245, 4203]
Multiprocessing elapsed: 3.9322520999994595. Result: [1229, 2262, 3245, 4203]
[2021-07-26 21:11:38.170] [local ee] [info] loaded runtime library from/mnt/c/Users/Remik/Ubuntu/Projects/tuplex-check/.venv/lib/python3.8/site-packages/tuplex/libexec/tuplex_runtime.cpython-38-x86_64-linux-gnu.so
[2021-07-26 21:11:38.170] [local ee] [info] initializing LLVM backend
[2021-07-26 21:11:38.170] [local ee] [warning] init JIT compiler also only in local mode
[2021-07-26 21:11:38.217] [LLVM] [info] compiling code for skylake
[2021-07-26 21:11:38.247] [history server] [warning] could not connect to http://localhost:5000/api/version, if you wish to disable the webui consider setting tuplex.webui=False for the context.
[2021-07-26 21:11:38.253] [memory] [info] allocated bitmap managed memory region (1.00 GB, 32.00 MB block size)
[2021-07-26 21:11:38.253] [memory] [info] allocated bitmap managed memory region (1.00 GB, 32.00 MB block size)
[2021-07-26 21:11:38.253] [memory] [info] allocated bitmap managed memory region (1.00 GB, 32.00 MB block size)
[2021-07-26 21:11:38.253] [memory] [info] allocated bitmap managed memory region (1.00 GB, 32.00 MB block size)
[2021-07-26 21:11:38.253] [memory] [info] allocated bitmap managed memory region (1.00 GB, 32.00 MB block size)
[2021-07-26 21:11:38.253] [memory] [info] allocated bitmap managed memory region (1.00 GB, 32.00 MB block size)
[2021-07-26 21:11:38.253] [memory] [info] allocated bitmap managed memory region (1.00 GB, 32.00 MB block size)
[2021-07-26 21:11:38.253] [memory] [info] allocated bitmap managed memory region (1.00 GB, 32.00 MB block size)
[2021-07-26 21:11:38.254] [local execution engine] [info] started local executor E/1 (1.00 GB, 32.00 MB default partition size)
[2021-07-26 21:11:38.254] [E/1] [info] starting detached process queue
[2021-07-26 21:11:38.254] [local execution engine] [info] started local executor E/2 (1.00 GB, 32.00 MB default partition size)
[2021-07-26 21:11:38.259] [E/2] [info] starting detached process queue
[2021-07-26 21:11:38.265] [E/2] [info] initialized runtime memory (4.00 MB)
[2021-07-26 21:11:38.265] [E/3] [info] starting detached process queue
[2021-07-26 21:11:38.265] [E/3] [info] initialized runtime memory (4.00 MB)
[2021-07-26 21:11:38.265] [local execution engine] [info] started local executor E/3 (1.00 GB, 32.00 MB default partition size)
[2021-07-26 21:11:38.265] [E/1] [info] initialized runtime memory (4.00 MB)
[2021-07-26 21:11:38.266] [local execution engine] [info] started local executor E/4 (1.00 GB, 32.00 MB default partition size)
[2021-07-26 21:11:38.266] [E/4] [info] starting detached process queue
[2021-07-26 21:11:38.266] [E/4] [info] initialized runtime memory (4.00 MB)
[2021-07-26 21:11:38.266] [local execution engine] [info] started local executor E/5 (1.00 GB, 32.00 MB default partition size)
[2021-07-26 21:11:38.266] [E/5] [info] starting detached process queue
[2021-07-26 21:11:38.267] [E/5] [info] initialized runtime memory (4.00 MB)
[2021-07-26 21:11:38.267] [E/6] [info] starting detached process queue
[2021-07-26 21:11:38.267] [local execution engine] [info] started local executor E/6 (1.00 GB, 32.00 MB default partition size)
[2021-07-26 21:11:38.267] [E/6] [info] initialized runtime memory (4.00 MB)
[2021-07-26 21:11:38.288] [local execution engine] [info] started local executor E/7 (1.00 GB, 32.00 MB default partition size)
[2021-07-26 21:11:38.289] [local execution engine] [info] started local executor E/8 (1.00 GB, 32.00 MB default partition size)
[2021-07-26 21:11:38.290] [memory] [info] allocated bitmap managed memory region (1.00 GB, 32.00 MB block size)
[2021-07-26 21:11:38.290] [local execution engine] [info] started driver (1.00 GB, 32.00 MB default partition size)
[2021-07-26 21:11:38.290] [E/8] [info] starting detached process queue
[2021-07-26 21:11:38.289] [E/7] [info] starting detached process queue
[2021-07-26 21:11:38.291] [python] [info] transferring 4 elements to tuplex
[2021-07-26 21:11:38.291] [python] [info] inferring type!
[2021-07-26 21:11:38.300] [E/8] [info] initialized runtime memory (4.00 MB)
[2021-07-26 21:11:38.307] [E/7] [info] initialized runtime memory (4.00 MB)
[2021-07-26 21:11:38.319] [python] [info] inferred default type is i64
[2021-07-26 21:11:38.319] [python] [info] Data transfer to backend took 0.027785 seconds (materialized: 32.00 MB)
[2021-07-26 21:11:38.383] [global] [info] performing static typing for UDF in operator map
[2021-07-26 21:11:38.384] [global] [info] performing static typing for UDF in operator map
[2021-07-26 21:11:38.385] [global] [info] performing static typing for UDF in operator map
[2021-07-26 21:11:38.386] [global] [info] performing static typing for UDF in operator map
[2021-07-26 21:11:38.387] [logical planner] [info] logical optimization took 0.001945ms
output type of specialized pipeline is: (i64)
is this the most outer stage?: 1
[2021-07-26 21:11:38.420] [codegen] [info] generating pipeline for (i64) -> (i64) (1 operator pipelined)
[2021-07-26 21:11:38.441] [codegen] [info] generating function count_primes for (i64) -> i64
[2021-07-26 21:11:38.480] [history server] [error] Could not register job, is history server running? To remove this error, set webui=False in the context configuration.
[2021-07-26 21:11:38.498] [global] [info] lazy init symbols
[2021-07-26 21:11:38.499] [global] [info] parse module in 0.000393
[2021-07-26 21:11:38.499] [global] [info] retrieved metrics object
[2021-07-26 21:11:38.646] [global] [info] Optimization via LLVM passes took 0.147187 ms
[2021-07-26 21:11:38.653] [global] [info] registering symbols...
[2021-07-26 21:11:38.653] [global] [info] starting code compilation
[2021-07-26 21:11:38.654] [global] [info] first compile done
[2021-07-26 21:11:38.773] [global] [info] functor Stage_0 retrieved from llvm
[2021-07-26 21:11:38.773] [global] [info] retrieving init/release stage functors
[2021-07-26 21:11:38.773] [global] [info] Compiled code paths for stage 0 in 0.12 ms
[2021-07-26 21:11:38.773] [global] [info] [Transform Stage] Stage 0 compiled to x86 in 0.292715s
[2021-07-26 21:11:39.285] [E/1] [info] [Task Finished] Transform to mem in 0.511459s (4 normal rows, 0 exceptions)
[2021-07-26 21:11:39.285] [global] [info] [Transform Stage] Stage 0 completed 1 load&transform tasks in 0.51244s
[2021-07-26 21:11:39.286] [global] [info] [Transform Stage] Stage 0 total wall clock time: 0.511459s, 4 input rows, time to process 1 row via fast path: 127.865ms
[2021-07-26 21:11:39.286] [global] [info] [Transform Stage] Stage 0 completed 1 sink tasks in 1.53e-05s
[2021-07-26 21:11:39.287] [global] [info] [Transform Stage] Stage 0 took 0.806455s
[2021-07-26 21:11:39.287] [global] [info] Query Execution took 0.90277s. (planning: 0.083188s, execution: 0.819581s)
[2021-07-26 21:11:39.287] [python] [info] Data transfer back to Python took 0.000027 seconds
[1229, 2262, 3245, 4203]
[2021-07-26 21:11:39.347] [local execution engine] [info] Stopped local executor E/1
[2021-07-26 21:11:39.348] [local execution engine] [info] Stopped local executor E/2
[2021-07-26 21:11:39.348] [local execution engine] [info] Stopped local executor E/3
[2021-07-26 21:11:39.349] [local execution engine] [info] Stopped local executor E/4
[2021-07-26 21:11:39.349] [local execution engine] [info] Stopped local executor E/5
[2021-07-26 21:11:39.349] [local execution engine] [info] Stopped local executor E/6
[2021-07-26 21:11:39.349] [local execution engine] [info] Stopped local executor E/7
[2021-07-26 21:11:39.349] [local execution engine] [info] Stopped local executor E/8
[GLOBAL] Local engine terminated.
[GLOBAL] releasing 1 active partitions
```

That's quite a lot of text so let's focus only on the results:
```
(.venv) $ python script.py 
Welcome to

  _____            _
 |_   _|   _ _ __ | | _____  __
   | || | | | '_ \| |/ _ \ \/ /
   | || |_| | |_) | |  __/>  <
   |_| \__,_| .__/|_|\___/_/\_\ 0.3.1
            |_|
    
using Python 3.8.5 (default, Jul 28 2020, 12:59:40) 
[GCC 9.3.0] on linux
Single for-loop elapsed: 7.160334900000635. Result: [1229, 2262, 3245, 4203]
Multiprocessing elapsed: 3.9322520999994595. Result: [1229, 2262, 3245, 4203]

[...]

[2021-07-26 21:11:39.287] [global] [info] Query Execution took 0.90277s. (planning: 0.083188s, execution: 0.819581s)
[2021-07-26 21:11:39.287] [python] [info] Data transfer back to Python took 0.000027 seconds
[1229, 2262, 3245, 4203]

[...]

```

As the example code written in Python is simple enough for me to port it to C++, I wrote it to see how much time is there to shave off the current result. You can check the code in `main.cpp` if you like.

My reasoning is that the best case scenario for parallel implementation would be equal to the time it takes to count primes for the largest given number. This is greatly simplified case but will do just fine for this comparison.

So we get:

| Scenario | Elapsed time [s] |
| -------- | ---------------- |
| Single for-loop | 7.1603 |
| Multiprocessing's Pool for 4 workers | 3.9326 |
| Tuplex | 0.9028 |
| C++ single for-loop | 0.3769 |
| C++ single for-loop (-O2) | 0.3088 |
| C++ (40k) | 0.1982 |
| C++ (40k) (-O2) | 0.1610 |

Based on this result, we can see that using `tuplex` is still beneficial compared to other available Python tools included in the standard library but it's nowhere near the claim made in the original article. There is still some potential to be squeezed compared to pure C++ code but most of the Python code will not be that easily ported to C++ so it might be still reasonable to stay at the current speed-up to keep full compatiblity with Python.
