#include "TXlib.h"
#include <stdlib.h>
#include <ctime>
#include <string>


struct CoordSys {
	int x0, y0;
	double scaleX, scaleY;
};


double* to_pixels(int x, int y, const CoordSys* coord);
void draw_point(int x, int y, int start_x, int start_y);
int bubbleSort(double* num, int size);
double* get_random_numbers(int size, int elem_for_random);
int count_of_comparison(int size);
void create_working_space();


int main() {

	create_working_space();
	
	srand(time(0));
	int elem_for_random = 1 + rand() % 1000000;

	for (int size_of_array = 10; size_of_array <= 5000; size_of_array += 10) {
		elem_for_random += size_of_array;

		double* sortable_array = get_random_numbers(size_of_array, elem_for_random);

		int count_of_exchange = bubbleSort(sortable_array, size_of_array);

		int count_of_comp = count_of_comparison(size_of_array);

		draw_point(size_of_array, count_of_comp, 50, 550);
		draw_point(size_of_array, count_of_exchange, 650, 550);

		delete[] sortable_array;
	}
}


double* to_pixels(int x, int y, const CoordSys* coord) {
	double* rec_coord = new double[2];
	rec_coord[0] = x * coord->scaleX + coord->x0;
	rec_coord[1] = coord->y0 - y * coord->scaleY;
	return rec_coord;
}


void draw_point(int x, int y, int start_x, int start_y) {
	const CoordSys coord = { start_x, start_y, 0.35, 0.001 };
	double* rec_coord = to_pixels(x, y, &coord);
	if (rec_coord[1] >= 100) {
		txCircle(rec_coord[0], rec_coord[1], 4);
	}
	delete[] rec_coord;
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


int count_of_comparison(int size) {
	return (size * size - size) / 2;
}


void create_working_space() {
	txCreateWindow(1200, 600);
	txSetColor(TX_LIGHTGREEN);
	txRectangle(50, 50, 550, 550);
	txRectangle(650, 50, 1150, 550);
	txSetFillColor(RGB(0, 191, 255));

	for (int line = 60; line < 550; line += 10) {
		txLine(line, 50, line, 550);
		txLine(line + 600, 50, line + 600, 550);
	}

	for (int line = 540; line > 50; line -= 10) {
		txLine(50, line, 550, line);
		txLine(650, line, 1150, line);
	}
}
