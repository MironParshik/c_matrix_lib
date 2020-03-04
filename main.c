//
//  main.c
//  massiv_libary
//
//  Created by Паршиков Мирон on 05.10.17.
//  Copyright © 2017 Паршиков Мирон. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Введите соответсвующее число в зависимости от того, что хотите сделать с матрицей / матрицами:\n1 - сложение матриц\n2 - умножние матрицы на число\n3 - умножение матриц\n4 - вычисление определителя матрицы\n5 - транспонирование\n");
    int i;
    scanf("%d", &i);
    struct matr A, B, C;
    A.p = B.p = C.p = NULL;
    switch (i) {
        case 1:
            A = input_matr(A);
            B = input_matr(B);
            C = sum(A, B);
            output_matr(C);
            break;
        case 2:
            A = input_matr(A);
            A = const_mul(A);
            output_matr(A);
            break;
        case 3:
            A = input_matr(A);
            B = input_matr(B);
            C = matr_mul(A, B);
            output_matr(C);
            break;
        case 4:
            A = input_matr(A);
            if (A.m == A.n) {
                double d = det(A);
                printf("%.1lf", d);
            }
            else
                printf("нельзя посчитать определитель\n");
            break;
        case 5:
            A = input_matr(A);
            A = transp(A);
            output_matr(A);
            break;
        default:
            printf("Такой операции нет, введите корректно номер операции\n");
            break;
        }
    clear_matr(A);
    clear_matr(B);
    clear_matr(C);
    return 0;
}




