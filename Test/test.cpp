#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process {
    int id, at, bt, bt_remaining, priority;
    int ct, tat, wt;
};

void printTable(struct Process p[], int n) {
    printf("\nPID\tAT\tBT\tPRI\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].id, p[i].at, p[i].bt, p[i].priority, 
               p[i].ct, p[i].tat, p[i].wt);
    }
}

void printAvg(struct Process p[], int n) {
    float avgTAT=0, avgWT=0;
    for(int i=0;i<n;i++) {
        avgTAT+=p[i].tat;
        avgWT+=p[i].wt;
    }
    printf("\nAverage TAT = %.2f", avgTAT/n);
    printf("\nAverage WT  = %.2f\n", avgWT/n);
}

void fcfs(struct Process p[], int n) {
    printf("\n--- First Come First Serve (FCFS) ---\n");
    int time=0;
    printf("\nGantt Chart: ");
    for(int i=0;i<n;i++) {
        if(time < p[i].at) time = p[i].at;
        printf("| P%d ", p[i].id);
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
    printf("|\n");
    printTable(p,n);
    printAvg(p,n);
}

void sjf(struct Process p[], int n) {
    printf("\n--- Shortest Job First (Non-Preemptive) ---\n");
    int time=0, completed=0, isDone[20]={0};
    printf("\nGantt Chart: ");
    while(completed<n) {
        int idx=-1, minbt=INT_MAX;
        for(int i=0;i<n;i++) {
            if(!isDone[i] && p[i].at<=time && p[i].bt<minbt) {
                minbt=p[i].bt;
                idx=i;
            }
        }
        if(idx==-1) {
            time++;
        } else {
            printf("| P%d ", p[idx].id);
            time+=p[idx].bt;
            p[idx].ct=time;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
            isDone[idx]=1;
            completed++;
        }
    }
    printf("|\n");
    printTable(p,n);
    printAvg(p,n);
}

void srtf(struct Process p[], int n) {
    printf("\n--- Shortest Remaining Time First (Preemptive) ---\n");
    int time=0, completed=0;
    for(int i=0;i<n;i++) p[i].bt_remaining=p[i].bt;
    printf("\nGantt Chart: ");
    int prev=-1;
    while(completed<n) {
        int idx=-1, minbt=INT_MAX;
        for(int i=0;i<n;i++) {
            if(p[i].bt_remaining>0 && p[i].at<=time && p[i].bt_remaining<minbt) {
                minbt=p[i].bt_remaining;
                idx=i;
            }
        }
        if(idx==-1) {
            time++;
        } else {
            if(idx!=prev) printf("| P%d ", p[idx].id);
            p[idx].bt_remaining--;
            time++;
            if(p[idx].bt_remaining==0) {
                p[idx].ct=time;
                p[idx].tat=p[idx].ct-p[idx].at;
                p[idx].wt=p[idx].tat-p[idx].bt;
                completed++;
            }
            prev=idx;
        }
    }
    printf("|\n");
    printTable(p,n);
    printAvg(p,n);
}

void priorityScheduling(struct Process p[], int n) {
    printf("\n--- Priority Scheduling (Non-Preemptive) ---\n");
    int time=0, completed=0, isDone[20]={0};
    printf("\nGantt Chart: ");
    while(completed<n) {
        int idx=-1, maxp=INT_MIN;
        for(int i=0;i<n;i++) {
            if(!isDone[i] && p[i].at<=time && p[i].priority>maxp) {
                maxp=p[i].priority;
                idx=i;
            }
        }
        if(idx==-1) {
            time++;
        } else {
            printf("| P%d ", p[idx].id);
            time+=p[idx].bt;
            p[idx].ct=time;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
            isDone[idx]=1;
            completed++;
        }
    }
    printf("|\n");
    printTable(p,n);
    printAvg(p,n);
}

void preemptivePriority(struct Process p[], int n) {
    printf("\n--- Preemptive Priority Scheduling ---\n");
    int time=0, completed=0;
    for(int i=0;i<n;i++) p[i].bt_remaining=p[i].bt;
    printf("\nGantt Chart: ");
    int prev=-1;
    while(completed<n) {
        int idx=-1, maxp=INT_MIN;
        for(int i=0;i<n;i++) {
            if(p[i].bt_remaining>0 && p[i].at<=time && p[i].priority>maxp) {
                maxp=p[i].priority;
                idx=i;
            }
        }
        if(idx==-1) {
            time++;
        } else {
            if(idx!=prev) printf("| P%d ", p[idx].id);
            p[idx].bt_remaining--;
            time++;
            if(p[idx].bt_remaining==0) {
                p[idx].ct=time;
                p[idx].tat=p[idx].ct-p[idx].at;
                p[idx].wt=p[idx].tat-p[idx].bt;
                completed++;
            }
            prev=idx;
        }
    }
    printf("|\n");
    printTable(p,n);
    printAvg(p,n);
}

void roundRobin(struct Process p[], int n, int tq) {
    printf("\n--- Round Robin Scheduling ---\n");
    int time=0, completed=0;
    int q[100], front=0,rear=0;
    int inqueue[20]={0};
    for(int i=0;i<n;i++) p[i].bt_remaining=p[i].bt;

    printf("\nGantt Chart: ");

    // push first arrived process
    int first=0;
    for(int i=1;i<n;i++)
        if(p[i].at<p[first].at) first=i;
    q[rear++]=first; inqueue[first]=1;
    time=p[first].at;

    while(completed<n) {
        if(front==rear) break;
        int idx=q[front++];
        if(p[idx].bt_remaining==0) continue;

        printf("| P%d ", p[idx].id);
        int exec_time = (p[idx].bt_remaining>=tq)?tq:p[idx].bt_remaining;
        p[idx].bt_remaining-=exec_time;
        time+=exec_time;

        for(int i=0;i<n;i++) {
            if(!inqueue[i] && p[i].at<=time && p[i].bt_remaining>0) {
                q[rear++]=i; inqueue[i]=1;
            }
        }

        if(p[idx].bt_remaining>0) {
            q[rear++]=idx;
        } else {
            p[idx].ct=time;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
            completed++;
        }
    }
    printf("|\n");
    printTable(p,n);
    printAvg(p,n);
}

int main() {
    int n, choice, tq;
    struct Process p[20], copy[20];
    printf("Enter number of processes (>=5): ");
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        p[i].id=i+1;
        printf("Enter AT, BT, Priority for P%d: ", i+1);
        scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].priority);
    }

    do {
        for(int i=0;i<n;i++) copy[i]=p[i];
        printf("\nCPU Scheduling Algorithms:\n");
        printf("1. FCFS\n2. SJF (Non-preemptive)\n3. SRTF\n4. Priority Scheduling\n5. Preemptive Priority\n6. Round Robin\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: fcfs(copy,n); break;
            case 2: sjf(copy,n); break;
            case 3: srtf(copy,n); break;
            case 4: priorityScheduling(copy,n); break;
            case 5: preemptivePriority(copy,n); break;
            case 6: printf("Enter Time Quantum: "); scanf("%d",&tq); roundRobin(copy,n,tq); break;
            case 0: break;
            default: printf("Invalid choice!\n");
        }
    } while(choice!=0);
    return 0;
}
