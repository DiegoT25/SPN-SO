#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct processData{
    int llegada;        //SE DEFINE
    int burst;
}processData;


int main()
{
    struct processData proceso[10];
    int tiempos[10];
    int limit;
    int i;
    int opcion;
    printf("ESCOJA UNA OPCION");
    printf("\n1. Ingresar por archivo\n");
    printf("2. Ingresar por teclado\n");
    printf("Su opcion es: ");
    scanf("%d", &opcion);


    if(opcion==1){
        FILE* file = fopen("procesos.csv","r"); //Abre el archivo en formato read
        if (file == NULL){
            return 1;
        }
        char buffer[200];//Crea un almacenamiento
        fgets(buffer, 200, file);//Almacena los datos del archivo en el array buffer

        while(!feof(file)){
            processData p;
            sscanf(buffer,"%d,%d", &p.llegada, &p.burst);
            printf("Read: %d %d\n", p.llegada, p.burst);
            fgets(buffer, 200, file);
            proceso[limit].llegada = p.llegada;
            proceso[limit].burst = p.burst;
            tiempos[limit] = p.burst;
            limit++;
        }
        fclose(file);
    }
    if(opcion==2){
        printf("\nEnter the Total Number of Processes:\t");
        scanf("%d", &limit);
        for(i = 0; i < limit; i++)
      {
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &proceso[i].llegada); //Agrega el tiempo ingresado al arreglo de llegada
            printf("Enter Burst Time:\t");
            scanf("%d", &proceso[i].burst);//Agrega el tiempo ingresado al arreglo de tiempo de ejecucion
            tiempos[i] = proceso[i].burst;


      }

    }
    int temp[10];
    int wait_times[10];
    int turn_times[10];
    int smallest, count = 0, time;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;
    for(i = 0; i < limit; i++)
    {

        proceso[i].llegada;
        proceso[i].burst;
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
                turn_times[smallest] = time - proceso[smallest].llegada +1;
                wait_times[smallest] = turn_times[smallest] - tiempos[smallest];

            }

      }
        int j;
        for (j = 0; j<limit; j++){
        printf("\n");
        printf("Burst time of process %d", j+1);
        printf(" = %d\n", tiempos[j]);
        printf("Wait time of process %d", j+1);
        printf(" = %d\n", wait_times[j]);
        printf("Turnaround time of process %d", j+1);
        printf(" = %d\n", turn_times[j]);

        }
      average_waiting_time = wait_time / limit;
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
      return 0;
}

