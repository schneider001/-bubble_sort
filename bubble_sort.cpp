#include <iostream>
#include <fstream>
#include <ctime>


int bubbleSort(double *num, int size);
void give_numbers(double* array, int size);
double* get_random_numbers(int size, int elem_for_random);
void write_to_file(int size, int count_of_exchange, int count_of_comparison);
int count_of_comparison(int size);


int main() {
    srand(time(0));
    int elem_for_random = 1 + rand() % 1000000;
    
    for (int size_of_array = 10; size_of_array <= 1000; size_of_array += 10) {
        elem_for_random += size_of_array;
        
        double* sortable_array = get_random_numbers(size_of_array, elem_for_random);
        
        std::cout << "================== " << size_of_array / 10 << " ==================\n\n";
        std::cout << "==================NOT SORTED!!:\n\n";
        give_numbers(sortable_array, size_of_array);
        std::cout << "\n\n";
        
        int count_of_exchange = bubbleSort(sortable_array, size_of_array);
        std::cout << "==================SORTED!!:\n\n";  
        give_numbers(sortable_array, size_of_array);
        
        int count_of_comp = count_of_comparison(size_of_array);
        write_to_file(size_of_array, count_of_exchange, count_of_comp);
        delete[] sortable_array;
        std::cout << "\n\n\n\n";
    }
}


int bubbleSort(double* num, int size) {
    int count_of_exchange = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = (size - 1); j > i; j--) {
            if (num[j - 1] > num[j]) {
                double temp = num[j - 1]; 
                num[j - 1] = num[j];
                num[j] = temp;
                count_of_exchange += 1;
            }
        }
    }
    return count_of_exchange;
}


double* get_random_numbers(int size, int elem_for_random) {
    srand(elem_for_random);
	double* koef = new double[size];
	for (int i = 0; i < size; i++) {
	    koef[i] = 1 + rand() % 1000;
	}
	return koef;
}
 

void give_numbers(double* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}


void write_to_file(int size, int count_of_exchange, int count_of_comparison) {
    std::ofstream fout;
    fout.open("file.csv", std::ios::app);
    fout << size << ";" << count_of_comparison << ";" << count_of_exchange << "\n";
    fout.close();
}


int count_of_comparison(int size) {
    return (size * size - size) / 2;
}
