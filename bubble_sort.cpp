#include <stdio.h>
#include <iostream>

void bubbleSort(double *num, int size);
void give_numbers(double* array, int size);
double* get_numbers(double* koef, int size);
double write_number_input(double value);

int main() {
  double* sortable_array;
  int size_of_array = 0;
  std::cout << "Please, enter the size of the array!\n";
  size_of_array = write_number_input(size_of_array);
  std::cout << "Please, enter the elements of the array!\n";
  sortable_array = get_numbers(sortable_array, size_of_array);
  bubbleSort(sortable_array, size_of_array);  
  give_numbers(sortable_array, size_of_array);
  free(sortable_array);
}


void bubbleSort(double *num, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = (size - 1); j > i; j--) {
            if (num[j - 1] > num[j]) {
                double temp = num[j - 1]; 
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}


double* get_numbers(double* koef, int size) {
	koef = (double*)malloc(size * sizeof(double));
	int check;
	for (int i = 0; i < size; i++) {
	    koef[i] = write_number_input(koef[i]);
	}
	return koef;
}
 

void give_numbers(double* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

double write_number_input(double value){
    double check = 0;
	    while (check == 0) {
    	    check = scanf("%lf", &value);
    	    if (check == 0) {
    	        scanf("%*s");
    	        printf("Please, enter a number!\n");
    	    }
	    }
    return value;
}