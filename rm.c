#include "rm.h"

void DEBUG(struct Task t){
	    printf("[DEBUG: ] %d %d %d %d %d %d %d\n",t.id, t.C, t.T, t.ddl, t.C_rem, t.misses, t.preemption);
}


void RM(struct Task tl[], int num_task, int sim_time)
{
	
	/*
	struct Task t1 = {1, 1, 5, 5, 1, 0};
	struct Task t2 = {2, 1, 2, 2, 1, 0};
	struct Task t3 = {3, 2, 10, 10, 2, 0, 0};
	struct Task t4 = {4, 1, 10, 10, 1, 0, 0};
	struct Task t5 = {5, 1, 10, 10, 1, 0, 0};
	struct Task tl[] = {t1,t2,t3,t4,t5};
	struct Task tl[] = {t1,t2, t3, t4, t5};
	int num_task = 5;
	int sim_time = 20;
				    */

	qsort(tl, num_task, sizeof(struct Task), cmpC);
	
	int curr=0;
	int queue[num_task];

	int t;
	int item=0, end=0;

	for(t=0; t<sim_time; t++)
	{
		item=0;
		end=0;

		for(item=0;item<num_task; item++){
			if(queue[item]!=-1){
				if(t>=tl[tiem].ddl){
					printf("deadline missed:%d%d\n",tl[tiem].id,t);
					tl[item].misses++;
					queue[item]=-1;
					curr=-1;
					tl[tiem].C_rem=tl[item].C;
				}
			}
		}


		if(t%(tl[tiem.T]==0)){
			queue[item]=item;
			tl[item].ddl=t+tl[item].T;
		}
	}

	int ready=0;

	if(curr==-1){
		item=0;
		int found=0;
		end=0;
		while(found==0&&end==0){
			if(queue[item]!=-1){
				curr=item;
				ready=1;
				found=1;
			}
			else if(item==(num_task-1)){
				end=1;
				printf("t:%d idle\n",t);
			}
			else
				item++;
		}
	}
	else{
		int preemption=0;
		ready=1;

		for(item=0; item<num_task; item++){
			if(queue[item]!=-1){
				tl[curr].preemption++;
				curr=item;
				preemption=1;
			}
		}
		if(ready){
			printf("t: %d id %d\n",t, tl[curr].id);
			tl[curr].C_rem=tl[curr].C_rem-1;
			if(tl[curr].C_rem==0){
				tl[curr].C_rem=tl[curr].C;
				queue[curr]=-1;
				curr=-1;
			}
		}
	}
	for(item=1; item<num_task; item++){
		DEBUG(tl[item]);
	}
}




