#include "controller.h"

void controller(){
    char * file = "input1.csv";
    FILE *fp;
    char line[20];

    fp  = fopen(file, "r");
    int simtime, numtask;

    fgets(line, 20, fp);
    simtime = atoi(line);

    fgets(line, 20, fp);
    numtask = atoi(line);

    struct Task tl[numtask];
    struct Schedule *head = NULL;
    head = malloc(sizeof(struct Schedule));
    parse(file, tl, numtask);
    head = EDF(tl, numtask, simtime);

    //RM(tl, numtask, simtime);

    write_out("edflist.out", head, numtask);
    //writefile(rmlist, filename);
    fclose(fp);

}
