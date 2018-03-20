# Project1 Realtime scheduling algorithm simulator

#### TODO:
    * parse input file -- done
    * output to a file
    * python drawer
    * RM
    * aperiodic
    * maybe split edf to several functions

#### ideas

* main.c: main function 
* rm.c: handling rm algorithm
* edf.c: handle edf algorithm
* aperiodic.c: handle aperiodic tasks
* helper.c: contains helper functions that will be used for both rm and edf

Note: rm and edf will take a struct as an input and return a lookup table linked list.

```
struct TableNode{
    int algorithm; // 0 RM; 1 EDF
    int Time;
    int Task;
    int preemption;
    int miss;
    struct TableNode *next;
};

```

or maybe

```
struct task_list{
    struct task T1;
    struct task T2;
    struct task T3;
    struct task T4;
    struct task T5;
    
};

struct task{
    int ID;
    int C;
    int T;
};

```

#### plan for output:

a lookup table output from c

a python drawer convert lookup table from text to graph.

#### reference

https://github.com/tylerjaywilson/lab2rts
