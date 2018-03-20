#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

struct Task {
    int id;
    int C;
    int T;
    int ddl;
    int C_rem;
    int preemption;
    int misses;
};

struct Schedule{
    int time;
    int id;
    int preemption;
    int misses;
    struct Schedule *next;
};

void parse(const char *file, struct Task tl[], int numtask);
int cmp(const void *a, const void *b);
void write_out(const char *file, struct Schedule * head, int num_task);
struct Schedule *add_node(int t, int id, int p, int m, struct Schedule *head);
void print_sch(struct Schedule *head);

#endif
