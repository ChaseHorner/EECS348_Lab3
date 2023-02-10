#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prints sales and months
void print_sales(double *sales_array){
  char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  printf("Monthly sales report for 2022:\n");
  printf("  Month       Sales\n");
  for(int k = 0; k < 12; k++){
    printf("%-10s  $%.2f\n", months[k], sales_array[k]);}
  }


//Prints min, max, and mean
void min_max_mean(double *sales_array){
  char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  int min, max;
  double sum;
  for(int i = 0; i<12; i++){
    sum+= sales_array[i];
    if (sales_array[i] < sales_array[min]){
      min = i;}
    if (sales_array[i] > sales_array[max]){
      max = i;}
  }
  printf("\nSales summary:");
  printf("\nMinimum sales: $%.2f (%s)\n", sales_array[min], months[min]);
  printf("Maximum sales: $%.2f (%s)\n", sales_array[max], months[max]);
  printf("Average sales: $%.2f\n", sum/12);
}

//Prints moviving averages each 6 months
void moving_mean(double *sales_array){
  char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  printf("\nSix-Month Moving Average Report:\n");
  for(int i = 0; i<7; i++){
    double sum = sales_array[i] + sales_array[i+1] + sales_array[i+2] + sales_array[i+3] + sales_array[i+4] + sales_array[i+5];
    printf("%-10s -\t%-10s $%.2f\n", months[i], months[i+5], sum/6);
  }
}

//Prints the sales in desceding order
void descending(double *sales_array){
  char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  printf("\nSales report (Highest to Lowest):\n");
  char *month_temp;
  double temp;
  for(int i = 0; i < 12; i++){
    for(int j = 0; j < 12-i-1; j++){
      if(sales_array[j] < sales_array[j+1]){
        temp = sales_array[j];
        sales_array[j] = sales_array[j+1];
        sales_array[j+1] = temp;

        month_temp = months[j];
        months[j] = months[j+1];
        months[j+1] = month_temp;
      }
    }
  }
  printf("  Month       Sales\n");
  for(int k = 0; k < 12; k++){
    printf("%-10s  $%.2f\n", months[k], sales_array[k]);
  }
}


int main(){
//double sales_array[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};

//Opens, reads, and puts the content of a file into an sales_array
FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
      printf("Error opening file!\n");
      return 1;
  }

  int count = 0;
  double num;
  while (fscanf(fp, "%lf", &num) != EOF) {
      count++;
  }
  rewind(fp);

  double sales_array[count];
  int i = 0;
  while (fscanf(fp, "%lf", &sales_array[i]) != EOF) {
      i++;
  }
  fclose(fp);

// calls each function to complete the problem
  print_sales(sales_array);
  min_max_mean(sales_array);
  moving_mean(sales_array);
  descending(sales_array);
}
