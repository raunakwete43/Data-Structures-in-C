#include <stdio.h>

// Define a struct named Update with two fields: remainingTime and decrement.
typedef struct Update
{
   int remTime;
   int decrement;
} Update;

// Function to update the remaining time of a process 
Update update_remaining(int arr[], int processID, const int quantum)
{
   if (arr[processID] < quantum)
   {
       // If the remaining time is less than the quantum, return a struct with 0 for remTime and the remaining time for decrement 
       return (Update){0, arr[processID]};
   }
   else
   {
       // If the remaining time is greater than or equal to the quantum, subtract the quantum from the remaining time and return a struct with the updated values 
       arr[processID] -= quantum;
       return (Update){arr[processID], quantum};
   }
}

// Function to print the contents of an array with a given description 
void printArray(int arr[], int size, char *desc)
{
   printf("%s:\t", desc);
   for (int i = 0; i < size; i++)
   {
       printf("%d \t", arr[i]);
   }
   printf("\n");
}

// Function to simulate the round-robin scheduling algorithm 
void roundRobin(int arrival1, int service[], int finish[], int time[], int quantum, int n)
{
   for (int i = 0; i < n; i++)
   {
       if (i == 0)
       {
           // Set the service time of the first process to the arrival time 
           service[0] = arrival1;
           continue;
       }
       Update process = update_remaining(time, i - 1, quantum);
       // Calculate the service time and finish time of the current process 
       service[i] = service[i - 1] + process.decrement;
       finish[i - 1] = service[i - 1] + process.decrement;
       time[i - 1] = process.remTime;
   }
   Update process = update_remaining(time, n - 1, quantum);
   // Calculate the finish time of the last process 
   finish[n - 1] = service[n - 1] + process.decrement;
   time[n - 1] = process.remTime;
}

// Function to calculate the waiting time of each process 
void waitCalc(int arrival[], int service[], int wait[], int finish[], int n)
{
   for (int i = 0; i < n; i++)
   {
       if (service[i] != finish[i])
       {
           // If the service time is not equal to the finish time, calculate the waiting time 
           wait[i] += service[i] - arrival[i];
       }
   }
}

// Function to adjust the arrival time of each process 
void ArrAdjust(int arrival[], int finish[], int n)
{
   for (int i = 0; i < n; i++)
   {
       // Set the arrival time of each process to its finish time 
       arrival[i] = finish[i];
   }
}

// Function to set all elements of an array to 0 
void makeZeroArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
       arr[i] = 0;
   }
}

// Function to calculate the turnaround time of each process 
void calcTAT(int tat[], int wait[], int burst[], int n)
{
   for (int i = 0; i < n; i++)
   {
       tat[i] = wait[i] + burst[i];
   }
}

// Function to copy the contents of one array to another 
void arrayCopy(int original[], int duplicate[], int n)
{
   for (int i = 0; i < n; i++)
   {
       duplicate[i] = original[i];
   }
}

// Function to calculate the average of an array of numbers 
float arrayAvg(int arr[], int n)
{
   float sum = 0;
   for (int i = 0; i < n; i++)
   {
       sum += arr[i];
   }

   return (float)(sum / n);
}

// Function to print the names of the processes 
void printProcessName(int size)
{
   printf("Process          :\t");
   for (int i = 0; i < size; i++)
   {
       printf("P%d\t", i + 1);
   }
   printf("\n\n");
}

// Function to take an array of numbers as input from the user 
void takeArr(int arr[], int n, char *desc)
{
   printf("%s\n", desc);
   for (int i = 0; i < n; i++)
   {
       printf("P%d => ", i + 1);
       scanf("%d", &arr[i]);
   }
}

int main()
{
   int n;

   // Get the number of processes from the user 
   printf("Enter the number of Processes => ");
   scanf("%d", &n);
   
   int arrival[n], burst[n];
   // Take the arrival and burst times of each process as input from the user 
   takeArr(arrival, n, "Enter Process Arrival Time in ms : ");
   takeArr(burst, n, "\nEnter Process Burst Time in ms: ");
   
   int quantum = 2;
   // Get the time slice value (quantum) from the user 
   printf("\nEnter the time slice value (quantum) in ms => ");
   scanf("%d", &quantum);
   
   int service[n], finish[n], wait[n], tat[n], time[n];
   // Set the finish time of the last process to the arrival time of the first process 
   finish[n - 1] = arrival[0];
   
   // Set all elements of the wait and time arrays to 0 
   makeZeroArray(wait, n);
   arrayCopy(burst, time, n);
   
   // Simulate the round-robin scheduling algorithm for each process 
   for (int i = 0; i < n; i++)
   {
       printf("\n---------------------%dst round---------------------\n", i + 1);
       printProcessName(n);
       roundRobin(finish[n - 1], service, finish, time, quantum, n);
       waitCalc(arrival, service, wait, finish, n);
       printArray(arrival, n, "Arrival Time (ms)");
       printArray(service, n, "Service Time (ms)");
       printArray(finish, n, "Finish Time  (ms)");
       printArray(wait, n, "Wait Time    (ms)");
       printArray(time, n, "Remaing Time (ms)");
       ArrAdjust(arrival, finish, n);
   }
   
   printf("\n\n---------------------Final Results---------------------\n");
   printProcessName(n);
   calcTAT(tat, wait, burst, n);
   printArray(wait, n, "Wait Time (ms)   ");
   printArray(tat, n, "TAT Time (ms)    ");

   // Calculate the average of each array
   printf("\nAverage Results\n");
   printf("1. Average Wait Time (ms) => %.2f ms\n", arrayAvg(wait, n));
   printf("2. Average Turn Around Time (ms) => %.2f ms\n", arrayAvg(tat, n));

   return 0;
}
