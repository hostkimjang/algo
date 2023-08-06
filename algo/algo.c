#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand 값을 사용하기 위한 라이브러리 호출
#include <time.h> // srand값에서 seed 값을 시간으로 설정하여 난수 생성 라이브러리용

#define SHOW_LIMIT_NUMBER 50


void bubble_sort(int** arr, int col, int row);
void selection_sort(int** arr, int col, int row);
void insertion_sort(int** arr, int col, int row);

int main(void) {

	int i, j, n, m, row, col, tmp;

	srand(time(NULL)); // rand seed 값 설정

	printf("C언어 테스트 케이스 생성기\n");
	printf("데이터 개수 N 입력 : ");
	scanf("%d", &n);
	printf("테스트 개수 M 입력 : ");
	scanf("%d", &m);

	printf("N M = %d %d\n", n, m);

	col = n, row = m, tmp = col;
	
	int** arr = malloc(sizeof(int*) * row);
	int** arr1 = malloc(sizeof(int*) * row);
	int** arr2 = malloc(sizeof(int*) * row);

	for (i = 0; i < row; i++) {
		arr[i] = malloc(sizeof(int) * col);
		arr1[i] = malloc(sizeof(int) * col);
		arr2[i] = malloc(sizeof(int) * col);
	}

	// t0, t1 은 정렬,역정렬 출력 그후부터 랜던값

	for (j = 0; j < col; j++) { 
		arr[0][j] = j + 1;
		arr1[0][j] = j + 1;
		arr2[0][j] = j + 1;
	}

	for (j = 0; j < col; j++) {
		arr[1][j] = tmp;
		arr1[1][j] = tmp;
		arr2[1][j] = tmp;
		tmp--;
	}
	for (i = 2; i < row; i++) {
		for (j = 0; j < col; j++) {
			arr[i][j] = ((rand() % n) + 1);
			arr1[i][j] = arr[i][j];
			arr2[i][j] = arr[i][j];
		}
	}

	if (n <= 10 && m <= 10)
	{
		for (int i = 0; i < row; i++)
		{
			printf("[ T%d ] : ", i);

			for (int j = 0; j < col; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}	
		printf("----------------\n");
	}	
	else {
		printf("%d test case inputs generated.\n", m);
		printf("%d integers in each test case.\n", n);
	}

	// 정렬옵션
	bubble_sort(arr, col, row);
	selection_sort(arr1, col, row);
	insertion_sort(arr2, col, row);


	// 배열 heap clear
	for (int i = 0; i < row; i++)
	{
		free(arr[i]);
		free(arr1[i]);
		free(arr2[i]);
	}
	free(arr);
	free(arr1);
	free(arr2);

	return 0;
}

void bubble_sort(int** numarr, int col, int row) {

	int tmp, count = 0;
	clock_t start, end;
	double result, worst = 0, best = 0, avg, sum = 0;
	//매게변수로 잘 받았는지 확인.

	printf("----------------\n");
	if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
	{
		for (int i = 0; i < row; i++)
		{
			printf("[ T%d ] : ", i);

			for (int j = 0; j < col; j++)
			{
				printf("%d ", numarr[i][j]);
			}
			printf("\n");
		}
		printf("----------------\n");
	}
	else {
		printf("test case or inputs generated 가 너무 많습니다!\n");
		printf("I/O 병목 방지. 화면 무출력으로 작업합니다!\n");
		printf("----------------\n");
	}

	//버블 정렬 시작

	for (int i = 2; i < row; i++) {
		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER) {
			printf("[ T%d ] - Bubble_Sort\n", i);
		}
		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER) {
			count = 0;
			printf("L%d: ", count);
			count++;
			for (int d = 0; d < col; d++) {
				printf("%d ", numarr[i][d]);
			}printf("\n");
		}
		start = clock(); // 수행 시간 측정 시작
		for (int a = 0; a < col; a++) {
			for (int j = 0; j < col - a - 1; j++) {
				if (numarr[i][j] > numarr[i][j + 1])
				{
					tmp = numarr[i][j];
					numarr[i][j] = numarr[i][j + 1];
					numarr[i][j + 1] = tmp;
					if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
					{
						printf("L%d: ", count);
						count++;
						for (int d = 0; d < col; d++) {
							printf("%d ", numarr[i][d]);
						}
					}
					if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
					{
						printf("\n");
					}
				}
			}
		}
		end = clock(); //시간 측정 끝
		//시간측정 관련 
		result = (double)(end - start);
		sum = sum + result;
	
		if (best == 0) {
			best = result;
		}
		else {
			if (result < best) {
				best = result;
			}
		}

		if (worst == 0) {
			worst = result;
		}
		else {
			if (worst < result) {
				worst = result;
			}
		}

		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
		{
			printf("%f ms.\n", result);
			printf("\n");
		}

	}
	printf("Bubble_Sort_Done!\n");
	
	avg = sum / row;
	printf("best\t: %.5f ms.\n", best);
	printf("worst\t: %.5f ms.\n", worst);
	printf("avg\t: %.5f ms.\n", avg);

	printf("----------------\n");
}

void selection_sort(int** numarr, int col, int row) {

	int tmp, min, count = 0;
	clock_t start, end;
	double result, worst = 0, best = 0, avg, sum = 0;
	//매게변수로 잘 받았는지 확인.

	printf("----------------\n");
	if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
	{
		for (int i = 0; i < row; i++)
		{
			printf("[ T%d ] : ", i);

			for (int j = 0; j < col; j++)
			{
				printf("%d ", numarr[i][j]);
			}
			printf("\n");
		}
		printf("----------------\n");
	}

	//선택 정렬 시작

	for (int i = 2; i < row; i++) {
		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER) {
			printf("[ T%d ] - Selection_Sort\n", i);
		}
		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
		{
			count = 0;
			printf("L%d: ", count);
			count++;
			for (int d = 0; d < col; d++)
			{
				printf("%d ", numarr[i][d]);
			}printf("\n");
		}
		start = clock(); // 수행 시간 측정 시작
		for (int a = 0; a < col - 1; a++) {
			min = a;
			for (int j = a + 1; j < col; j++) {
				if (numarr[i][j] < numarr[i][min]) {
					min = j;
					if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
					{
						printf("L%d: ", count);
						count++;
						for (int d = 0; d < col; d++) {
							printf("%d ", numarr[i][d]);
						}
					}
					if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
					{
						printf("\n");
					}
				}
			}
			tmp = numarr[i][a];
			numarr[i][a] = numarr[i][min];
			numarr[i][min] = tmp;
		}
		end = clock(); //시간 측정 끝
		//시간측정 관련 
		result = (double)(end - start);
		sum = sum + result;

		if (best == 0) {
			best = result;
		}
		else {
			if (result < best) {
				best = result;
			}
		}

		if (worst == 0) {
			worst = result;
		}
		else {
			if (worst < result) {
				worst = result;
			}
		}
		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
		{
			printf("L%d: ", count);
			count++;
			for (int d = 0; d < col; d++) {
				printf("%d ", numarr[i][d]);
			}
		}
		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
		{
			printf("\n");
		}
		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
		{
			printf("%f ms.\n", result );
			printf("\n");
		}
	}
	printf("Selection_Sort_Done!\n");

	avg = sum / row;
	printf("best\t: %.5f ms.\n", best );
	printf("worst\t: %.5f ms.\n", worst );
	printf("avg\t: %.5f ms.\n", avg );

	printf("----------------\n");
}

void insertion_sort(int** numarr, int col, int row) {

	int i, j, tmp, count = 0;
	clock_t start, end;
	double result, worst = 0, best = 0, avg, sum = 0;
	//매게변수로 잘 받았는지 확인.

	printf("----------------\n");
	if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
	{
		for (int i = 0; i < row; i++)
		{
			printf("[ T%d ] : ", i);

			for (int j = 0; j < col; j++)
			{
				printf("%d ", numarr[i][j]);
			}
			printf("\n");
		}
		printf("----------------\n");
	}

	for (i = 2; i < row; i++) {
		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER) {
			printf("[ T%d ] - Insertion_Sort\n", i);
		}
		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
		{
			count = 0;
			printf("L%d: ", count);
			count++;
			for (int d = 0; d < col; d++)
			{
				printf("%d ", numarr[i][d]);
			}printf("\n");
		}
		start = clock(); // 수행 시간 측정 시작
		for (int a = 1; a < col ; a++) {
			tmp = numarr[i][a];
			if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
			{
				printf("L%d: ", count);
				count++;
				for (int d = 0; d < col; d++) {
					printf("%d ", numarr[i][d]);
				}
			}
			if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
			{
				printf("\n");
			}
			for (j = a - 1; j >= 0; j--) {
				if (numarr[i][j] > tmp) {
					numarr[i][j + 1] = numarr[i][j];
				}
				else {
					break;
				}
			}
			numarr[i][j + 1] = tmp;
		}
		end = clock(); //시간 측정 끝
		//시간측정 관련 
		result = (double)(end - start);
		sum = sum + result;

		if (best == 0) {
			best = result;
		}
		else {
			if (result < best) {
				best = result;
			}
		}

		if (worst == 0) {
			worst = result;
		}
		else {
			if (worst < result) {
				worst = result;
			}
		}

		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
		{
			printf("L%d: ", count);
			count++;
			for (int d = 0; d < col; d++) {
				printf("%d ", numarr[i][d]);
			}
		}
		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
		{
			printf("\n");
		}
		if (col <= SHOW_LIMIT_NUMBER && row <= SHOW_LIMIT_NUMBER)
		{
			printf("%f ms.\n", result );
			printf("\n");
		}
	}
	printf("Insertion_Sort_Done!\n");
	avg = sum / row;
	printf("best\t: %.5f ms.\n", best );
	printf("worst\t: %.5f ms.\n", worst );
	printf("avg\t: %.5f ms.\n", avg );
	printf("----------------\n");

}
