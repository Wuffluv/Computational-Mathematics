﻿#include <iostream>
#include <math.h>
using namespace std;

int main() {

	double B[4][8] = { 
	{ 1,  2, -2,  0, 1, 0, 0, 0},
	{-2, -3,  5, -2, 0, 1, 0, 0},
	{ 0,  0, -1,  1, 0, 0, 1, 0},
	{-2, -6,  2,  3, 0, 0, 0, 1} };
	int n = 4;
	int m;

	/// Проверка главной диагонали на наличие нулевых элементов. Если встречается ноль, то меняем строку с ненулевым
	/// элементом на данной позиции. 
	for (int k = 0; k < n; k++) {
		if (fabs(B[k][k]) < 0.00001) {
			m = k + 1;
			while (true) {
				if ((fabs(B[m][k]) > 0.00001) || (m > n)) {
					break;
				}
				else {
					m += 1;
				}
			}
			///Проходим по всем элементам строки k матрицы B и прибавляем к каждому элементу соответствующий элемент 
			///из строки m матрицы B. То есть, каждый элемент B[k][j] для j от 0 до 2n-1 
			///заменяется на B[k][j] + B[m][j]. Это делается для того, чтобы избавиться от нулей на главной диагонали,
			///так как при делении на ноль возникает ошибка. Прибавление строки m к строке k позволяет избавиться от 
			///нуля на главной диагонали. В результате, главная диагональ матрицы B становится ненулевой и можно 
			///продолжать расчет обратной матрицы.
			for (int j = 0; j < 2 * n ; j++) {
				B[k][j] = B[k][j] + B[m][j];
			}
		}

			/// Расчет элементов правее к-го столбца
			for (int i = 0; i < n ; i++) {
				for (int j = k + 1; j < 2 * n ; j++) {
					if (i != k) {
						B[i][j] = (B[i][j] * B[k][k] - B[k][j] * B[i][k]) / B[k][k];
						///Здесь мы используем уже рассчитанные значения элементов на главной диагонали, 
						///чтобы получить новые значения для остальных элементов.
					}
				}
			}

			///Обнуление всех элементов в столбцах, которые находятся ниже k-го элемента и вычисление элементов в 
			///строке k до k-го столбца. Для каждой строки i, кроме k-й строки, 
			///элемент B[i][k] устанавливается равным 0. Затем для каждого столбца j от k-го столбца до 2n-го 
			///столбца элемент B[k][j] делится на B[k][k].
			for (int i = 0; i < n ; i++) {
				if (i != k) {
					B[i][k] = 0;
				}
			}

			///Затем для каждого столбца j от k - го столбца до 2n - го
			///столбца элемент B[k][j] делится на B[k][k].
			///Расчет элементов в к-ой строке до к-го стобца
			for (int j = 2 * n - 1 ; j >= k; j--) {
				B[k][j] = B[k][j] / B[k][k];
			}
		///После каждой итерации основного цикла происходит вывод текущего состояния матрицы B
		///После завершения работы цикла получаем матрицу B, которая является обратной матрицей для исходной матрицы A.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				cout << B[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
	




