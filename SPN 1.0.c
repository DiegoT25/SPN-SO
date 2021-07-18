#include <stdio.h>

struct proc{
  int llegada;
  int burst;
};

int main()
{
      struct proc proceso[10];
      int temp[10];
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &limit);
      printf("\nEnter Details of %d Processes\n", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &proceso[i].llegada);
            printf("Enter Burst Time:\t");
            scanf("%d", &proceso[i].burst);
            temp[i] = proceso[i].burst;
      }
      proceso[9].burst = 9999;
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(proceso[i].llegada <= time && proceso[i].burst < proceso[smallest].burst && proceso[i].burst > 0)
                  {
                        smallest = i;
                  }
            }
            proceso[smallest].burst--;
            if(proceso[smallest].burst == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - proceso[smallest].llegada - temp[smallest];
                  turnaround_time = turnaround_time + end - proceso[smallest].llegada;
            }
      }
      average_waiting_time = wait_time / limit;
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
      return 0;
}
