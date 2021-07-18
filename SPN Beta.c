#include <stdio.h>

int main()
{
      int arrival_time[10], burst_time[10], temp[10]; // Crea tres arreglos de enteros, tamaño 10
      int i, smallest, count = 0, time, limit; // Define variables enteras
      double wait_time = 0, turnaround_time = 0, end; // Define variables de tipo double
      float average_waiting_time, average_turnaround_time; // Define variables de punto flotante
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &limit); // Lee el número de procesos ingresado por el usuario
      printf("\nEnter Details of %d Processes\n", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &arrival_time[i]); //Agrega el tiempo ingresado al arreglo de llegada
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_time[i]);//Agrega el tiempo ingresado al arreglo de tiempo de ejecucion
            temp[i] = burst_time[i];
      }
      burst_time[9] = 9999; // Define el tiempo de ejecución máximo en la última posición
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
/* Compara el tiempo de llegada con el tiempo y el tiempo de ejecución con el tiempo de ejecución del proceso más pequeño.*/
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];//Calcula el tiempo de espera del proceso
                  turnaround_time = turnaround_time + end - arrival_time[smallest]; //Calcula el tiempo de ejecución del proceso
            }
      }
      average_waiting_time = wait_time / limit; // Calcula el promedio en base al total y la cantidad
      average_turnaround_time = turnaround_time / limit; // Calcula el promedio en base al total y la cantidad
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
      return 0;
}
