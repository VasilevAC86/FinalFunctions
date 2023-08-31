# include <iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>

// Заполение массива случайными числами
template <typename T>
void fill_array(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (short i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

// Вывод массива в консоль
template <typename T>
void print_arr (T arr[], const int length) {
	std::cout << "{ ";
	for (short i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

void type_Off(int num) { std::cout << "INT\n"; }
void type_Off(double num) { std::cout << "DOUBLE\n"; }
void type_Off(char sum) { std::cout << "CHAR\n"; }

int sum_AB(int A, int B); // Прототип функции sum_AB

template<typename T> // Сортировка массива
void middle_sort(T arr[], const int length);

template<typename T> // Смещение массива по кругу
void move_arr(T arr[],const int length, int steps);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// Задача 1. Вывод типа данных числа
	std::cout << "Задача 1. Тип данных\n\n";
	std::cout << "77 - "; type_Off(77);
	std::cout << "5.1 - "; type_Off(5.1);
	std::cout << "'A' - "; type_Off('A');
	std::cout << std::endl;

	// Задача 2. Рекурсивная сумма чисел от А до B
	std::cout << "Задача 2. Сумма чисел от А до В\n\nВведите два числа -> ";
	std::cin >> n >> m;	
	std::cout << "Сумма чисел от " << n << " до " << m << " = " << sum_AB(n, m) << "\n\n";

	// Задача 3. Сортировка массива между крайними отрицательными элементами
	std::cout << "Задача 3. Сортировка массива\n\nИзначальный массив:\n";
	const int size3 = 10;
	int arr3[size3];
	fill_array(arr3, size3, -10, 11);
	print_arr(arr3, size3);
	middle_sort(arr3, size3);
	std::cout << "Итоговый массив: ";
	print_arr(arr3, size3);

	// Задача 4. Сдвиг массива по кругу
	std::cout << "Задача 4. \nИзначальный массив:\n\n";
	const int size4 = 10;
	int arr4[size4]{ 1,2,3,4,5,6,7,8,9,10 };
	print_arr(arr4, size4);
	std::cout << "Введите число -> ";
	std::cin >> n;
	move_arr(arr4, size4, n);
	std::cout << "Итоговый массив:\n";
	print_arr(arr4, size4);

	return 0;
}

template<typename T>  
void move_arr(T arr[], const int length, int steps) {
	if (steps >= 0)
		for (int j = 0; j < steps; j++) {
			T tmp = arr[length - 1];
			for (short i = length - 1; i > 0; i--)
				arr[i] = arr[i - 1];
			arr[0] = tmp;
		}
	else
		for (short i = 0; i < -steps; i++)
			for (short j = 1; j < length; j++)
				std::swap(arr[j-1],arr[j]);
}

template<typename T>
void middle_sort(T arr[], const int length) {
	int first_index = 0, last_index = 0;
	for(short i=0;i<length;i++)
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	for(short i=length-1;i>=first_index;i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	// Пузырьковая сортировка
	/*for (short i = last_index - 1; i > first_index + 1; i--)
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);*/

	// Быстрая сортирвока
	std::sort(arr + first_index + 1, arr + last_index);
}

// Реализация функции sum_AB
int sum_AB(int A, int B) { 
	if (A == B)
		return A;
	return sum_AB(A, B - 1) + B;
}