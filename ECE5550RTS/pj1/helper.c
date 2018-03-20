#include <stdio.h>
#include "helper.h"


void parse(const char *file, struct Task tl[], int numtask){
    FILE *fp;
    char line[20];
    char *c = "";
    int i;
    fp  = fopen(file, "r");
    fgets(line, 20, fp);
    fgets(line, 20, fp);

    for (i = 0; i < numtask; i++){
        fgets(line, 20, fp);
        c = strtok(line, ",");
        tl[i].id = atoi(c);
        strcpy(c, strtok(NULL,","));
        tl[i].C = atoi(c);
        tl[i].C_rem = atoi(c);

        strcpy(c, strtok(NULL,","));
        tl[i].T = atoi(c);
        tl[i].ddl = atoi(c);

        tl[i].misses = 0;
        tl[i].preemption = 0;

    }
    fclose(fp);

}




int cmp(const void *a, const void *b){
    struct Task *A = (struct Task *)a;
    struct Task *B = (struct Task *)b;

    return A->T - B->T;
}

void write_out(const char *file, struct Schedule *head, int num_task){
    int preemp[num_task+1];
    int miss[num_task+1];
    int i, preemp_t=0, miss_t=0;
    FILE *fp;

    struct Schedule *tmp = head;
    fp = fopen(file, "w");

    fprintf(fp, "========================Lookup Table===================\n");
    fprintf(fp, "time,id\n");

    while(tmp != NULL){
        //TODO
        printf("%d %d %d %d\n", tmp->time, tmp->id, tmp->preemption, tmp->misses);
        fprintf(fp, "%d,%d\n",tmp->time, tmp->id);
        preemp[tmp->id] = tmp-> preemption;
        miss[tmp->id] = tmp->misses;
        tmp = tmp->next;
    }
    fprintf(fp, "========================Summary=======================\n");
    fprintf(fp, "id,preemption,miss\n");
    for(i = 1; i < num_task+1; i++) {
        preemp_t += preemp[i];
        miss_t += miss[i];
        fprintf(fp, "%d,%d,%d\n", i, preemp[i], miss[i]);
//        printf("preemption: %d\n", preemp[i]);
//        printf("miss: %d\n", miss[i]);
    }
    fprintf(fp, "total,%d,%d\n", preemp_t, miss_t);
    free(tmp);
    fclose(fp);
}

struct Schedule *add_node(int t, int id, int p, int m, struct Schedule *head){
    struct Schedule *temp, *newnode;
    newnode = malloc(sizeof(struct Schedule));
    memset(newnode, 0, sizeof *newnode);
    newnode -> time = t;
    newnode -> id = id;
    newnode -> preemption = p;
    newnode -> misses = m;

    if(head == NULL){
        head = newnode;
    }
    else{
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            printf("%x\n",temp->next);
        }

        temp -> next= newnode;
    }
    free(newnode);
    return head;
}

void print_sch(struct Schedule *head){
    struct Schedule *tmp;
    tmp = head;
    while (tmp != NULL){
//        printf("%d %d %d %d\n", tmp->time, tmp->id, tmp->preemption, tmp->misses);
        tmp = tmp->next;
    }
}
