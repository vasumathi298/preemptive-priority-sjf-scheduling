#include<stdio.h>
void main()
{
    int bt[20],p[20],wt[20],tat[20];
int i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           
    } //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        } 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
     wt[0]=0;     //waiting time for first process =0
    for(i=1;i<n;i++)     //calculation of  waiting time
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
         total+=wt[i];
    }
     avg_wt=(float)total/n;      //average waiting time
     printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];//calculation of turnaround time
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
     avg_tat=(float)total/n; //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}

Enter Total Number of Process:10

Enter Burst Time and Priority

P[1]
Burst Time:20
Priority:9

P[2]
Burst Time:30
Priority:5

P[3]
Burst Time:10
Priority:2

P[4]
Burst Time:40
Priority:3

P[5]
Burst Time:10
Priority:2

P[6]
Burst Time:15
Priority:1

P[7]
Burst Time:32
Priority:3

P[8]
Burst Time:20
Priority:3

P[9]
Burst Time:16
Priority:2

P[10]
Burst Time:20
Priority:3

Process     Burst Time          Waiting Time    Turnaround Time
P[6]              15                0                   15
P[3]              10                15                  25
P[5]              10                25                  35
P[9]              16                35                  51
P[7]              32                51                  83
P[8]              20                83                  103
P[4]              40                103                 143
P[10]             20                143                 163
P[2]              30                163                 193
P[1]              20                193                 213

Average Waiting Time=81
Average Turnaround Time=102
--------------------------------
Process exited after 42.68 seconds with return value 0
Press any key to continue . . .



Enter Total Number of Process:15

Enter Burst Time and Priority

P[1]
Burst Time:20
Priority:2

P[2]
Burst Time:30
Priority:2

P[3]
Burst Time:25
Priority:7

P[4]
Burst Time:54
Priority:2

P[5]
Burst Time:10
Priority:6

P[6]
Burst Time:12
Priority:3

P[7]
Burst Time:14
Priority:4

P[8]
Burst Time:15
Priority:2

P[9]
Burst Time:16
Priority:3

P[10]
Burst Time:20
Priority:1

P[11]
Burst Time:24
Priority:1

P[12]
Burst Time:32
Priority:1

P[13]
Burst Time:25
Priority:3

P[14]
Burst Time:41
Priority:2

P[15]
Burst Time:12
Priority:3

Process     Burst Time          Waiting Time    Turnaround Time
P[10]             20                0                   20
P[11]             24                20                  44
P[12]             32                44                  76
P[4]              54                76                  130
P[8]              15                130                 145
P[1]              20                145                 165
P[2]              30                165                 195
P[14]             41                195                 236
P[9]              16                236                 252
P[6]              12                252                 264
P[13]             25                264                 289
P[15]             12                289                 301
P[7]              14                301                 315
P[5]              10                315                 325
P[3]              25                325                 350

Average Waiting Time=183
Average Turnaround Time=207
--------------------------------
Process exited after 59.34 seconds with return value 0
Press any key to continue . . .



Enter number of process:15

Enter Burst Time:
p1:20
p2:30
p3:25
p4:54
p5:10
p6:12
p7:14
p8:15
p9:16
p10:20
p11:24
p12:32
p13:25
p14:41
p15:12

Process     Burst Time          Waiting Time    Turnaround Time
p5                10                0                   10
p6                12                10                  22
p15               12                22                  34
p7                14                34                  48
p8                15                48                  63
p9                16                63                  79
p1                20                79                  99
p10               20                99                  119
p11               24                119                 143
p13               25                143                 168
p3                25                168                 193
p2                30                193                 223
p12               32                223                 255
p14               41                255                 296
p4                54                296                 350

Average Waiting Time=116.800003
Average Turnaround Time=256.933319

--------------------------------
Process exited after 124.6 seconds with return value 0
Press any key to continue . . .

The no of process: 15
The arrival time P1: 0
The arrival time P2: 2
The arrival time P3: 4
The arrival time P4: 6
The arrival time P5: 8
The arrival time P6: 10
The arrival time P7: 12
The arrival time P8: 14
The arrival time P9: 16
The arrival time P10: 18
The arrival time P11: 20
The arrival time P12: 22
The arrival time P13: 24
The arrival time P14: 26
The arrival time P15: 28
The burst time P1: 20
The burst time P2: 30
The burst time P3: 25
The burst time P4: 54
The burst time P5: 10
The burst time P6: 12
The burst time P7: 14
The burst time P8: 15
The burst time P9: 16
The burst time P10: 20
The burst time P11: 24
The burst time P12: 32
The burst time P13: 25
The burst time P14: 41
The burst time P15: 12
The priority for the process P1: 2
The priority for the process P2: 2
The priority for the process P3: 7
The priority for the process P4: 2
The priority for the process P5: 6
The priority for the process P6: 3
The priority for the process P7: 4
The priority for the process P8: 2
The priority for the process P9: 3
The priority for the process P10: 1
The priority for the process P11: 1
The priority for the process P12: 1
The priority for the process P13: 3
The priority for the process P14: 2
The priority for the process P15: 3
The timespan: 10

-------------Gantt Chart---------
0->P1->10->P1->20->P10->30->P10->40->P11->50->P11->60->P11->64->P12->74->P12->84->P12->94->P12->96->P8->106->P8->111->P2->121->P2->131->P2->141->P14->151->P14->161->P14->171->P14->181->P14->182->P4->192->P4->202->P4->212->P4->222->P4->232->P4->236->P6->246->P6->248->P15->258->P15->260->P9->270->P9->276->P13->286->P13->296->P13->301->P7->311->P7->315->P5->325->P3->335->P3->345->P3->350

-------------------TABLE----------------------------------

Process AT      BT      FT      PR      TAT     WT

P1      0       20      2       20      20      0

P2      2       30      2       141     139     109

P3      4       25      7       0       0       0

P4      6       54      2       0       0       0

P5      8       10      6       325     317     307

P6      10      12      3       0       0       0

P7      12      14      4       0       0       0

P8      14      15      2       0       0       0

P9      16      16      3       0       0       0

P10     18      20      1       40      22      2

P11     20      24      1       0       0       0

P12     22      32      1       0       0       0

P13     24      25      3       0       0       0

P14     26      41      2       0       0       0

P15     28      12      3       0       0       0


-----------------------------------------------------------
the average waiting time :27
the average turnaround  time :33

--------------------------------
Process exited after 0.1881 seconds with return value 0
Press any key to continue . . .