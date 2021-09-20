/* 2 лабораторная, 1 задание.
#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	clock_t start, end; // объявляем переменные для определения времени выполнения
	int i = 0, j = 0, r, n = 0;
	cout << "Введите n:" << endl;
	cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
	}
	int** b = new int* [n];
	for (int i = 0; i < n; ++i) {
		b[i] = new int[n];
	}
	int** c = new int* [n];
	for (int i = 0; i < n; ++i) {
		c[i] = new int[n];
	}
	int elem_c;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < n)
	{
		while (j < n)
		{
			a[i][j] = rand() % 100; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < n)
	{
		while (j < n)
		{
			b[i][j] = rand() % 100; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			elem_c = 0;
			for (r = 0; r < n; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		delete[] a[i];
	}
	delete[] a;
	for (int i = 0; i < n; ++i) {
		delete[] b[i];
	}
	delete[] b;
	for (int i = 0; i < n; ++i) {
		delete[] c[i];
	}
	delete[] c;
	cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы
	return 0;
}*/

/* 2 задание алгоритм Шелла и быстрой сортировки пункт 1
#include <iostream>
using namespace std;
void shell(int* items, int count){
int i, j, gap, k;
int x, a[5];
a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
for (k = 0; k < 5; k++) {
gap = a[k];
for (i = gap; i < count; ++i){
x = items[i];
for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
items[j + gap] = items[j];
items[j + gap] = x;
}
}
for (int i = 0; i < count; i++)
{
cout << items[i] << "\t";
}
}
void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
int i, j;
int x, y;

i = left; j = right;
// выбор компаранда
x = items[(left + right) / 2];
do {
while ((items[i] < x) && (i < right)) i++;
while ((x < items[j]) && (j > left)) j--;
if (i <= j) {
y = items[i];
items[i] = items[j];
items[j] = y;
i++; j--;
}
} while (i <= j);
if (left < j) qs(items, left, j);
if (i < right) qs(items, i, right);

}
int main()
{
setlocale(LC_ALL, "rus");
srand(time(NULL)); // инициализируем параметры генератора случайных чисел
int count = 7;
int a[] = { 45,67,3,123,4,50,90 };
cout << "Результирующий массив:" << endl;
shell(a, count);
int first = 0, last = count - 1;
qs(a, first, last);
cout << endl;
for (int i = 0; i < count; i++) cout << a[i] << " ";
cout << endl;
cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы
return 0;
}
*/

/*пункт 2
int main()
{
setlocale(LC_ALL, "rus");
srand(time(NULL)); // инициализируем параметры генератора случайных чисел
int count = 7;
int a[] = { 3,16,34,57,90,124,458};
cout << "Результирующий массив:" << endl;
shell(a, count);
int first = 0, last = count - 1;
qs(a, first, last);
cout << endl;
for (int i = 0; i < count; i++) cout << a[i]«"\t";
cout << endl;
cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы
return 0;
}
*/

/* пункт 3
int main()
{
setlocale(LC_ALL, "rus");
srand(time(NULL)); // инициализируем параметры генератора случайных чисел
int count = 7;
int a[] = { 458, 378,135,78,36,13,3};
cout << "Результирующий массив:" << endl;
shell(a, count);
int first = 0, last = count - 1;
qs(a, first, last);
for (int i = 0; i < count; i++) cout << a[i]«"\t";
cout << endl;
cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы
return 0;
}

*/

/* пункт 4
int main()
{
setlocale(LC_ALL, "rus");
srand(time(NULL)); // инициализируем параметры генератора случайных чисел
int count = 8;
int a[] = { 78,123,367,567,789,458,34,2 };

cout << "Результирующий массив:" << endl;
shell(a, count);
int first = 0, last = count - 1;
qs(a, first, last);
for (int i = 0; i < count; i++) cout << a[i] <<"\t";
cout << endl;
cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы

return 0;
}
*/

/* 2 задание qsort пункт 1
int a[] = { 45,67,3,123,4,50,90 };
int compare(const void* x1, const void* x2) // функция сравнения элементов массива
{
return (*(int*)x1 - *(int*)x2); // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}
int main()
{
setlocale(LC_ALL, "rus");
srand(time(NULL)); // инициализируем параметры генератора случайных чисел
int count = 7;

cout << "Результирующий массив:" << endl;
int first = 0, last = count - 1;
qsort(a, count,sizeof(int),compare);
for (int i = 0; i < count; i++)
{
cout«a[i]<<"\t";
}
cout << endl;
cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы

return 0;
}
*/

/*пункт 2
int a[] = {  3,16,34,57,90,124,458 };
int compare(const void* x1, const void* x2) // функция сравнения элементов массива
{
return (*(int*)x1 - *(int*)x2);
}
int main()
{
setlocale(LC_ALL, "rus");
srand(time(NULL)); // инициализируем параметры генератора случайных чисел
int count = 7;

cout << "Результирующий массив:" << endl;
int first = 0, last = count - 1;
qsort(a, count,sizeof(int),compare);
for (int i = 0; i < count; i++)
{
cout«a[i]<<"\t";
}
cout << endl;
cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы

return 0;
}
*/

/* пункт 3
int a[] = { 458, 378,135,78,36,13,3 };
int compare(const void* x1, const void* x2) // функция сравнения элементов массива
{
return (*(int*)x1 - *(int*)x2);
}
int main()
{
setlocale(LC_ALL, "rus");
srand(time(NULL)); // инициализируем параметры генератора случайных чисел
int count = 7;

cout << "Результирующий массив:" << endl;
int first = 0, last = count - 1;
qsort(a, count,sizeof(int),compare);
for (int i = 0; i < count; i++)
{
cout<<a[i]<<"\t";
}
cout << endl;
cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы

return 0;
}
*/

/* пункт 4
int a[] = { 78,123,367,567,789,458,34,2 };
int compare(const void* x1, const void* x2) // функция сравнения элементов массива
{
return (*(int*)x1 - *(int*)x2); // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}
int main()
{
setlocale(LC_ALL, "rus");
srand(time(NULL)); // инициализируем параметры генератора случайных чисел
int count = 8;

cout << "Результирующий массив:" << endl;
int first = 0, last = count - 1;
qsort(a, count,sizeof(int),compare);
for (int i = 0; i < count; i++)
{
cout << a[i]<<"\t";
}
cout << endl;
cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы

return 0;
}
*/