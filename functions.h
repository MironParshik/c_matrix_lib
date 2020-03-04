//
//  functions.h
//  massiv_libary
//
//  Created by Паршиков Мирон on 08.10.17.
//  Copyright © 2017 Паршиков Мирон. All rights reserved.
//

#ifndef functions_h
#define functions_h


#endif /* functions_h */

struct matr{
    int m;
    int n;
    double** p;
};

struct matr input_matr (struct matr a){
    printf("Введите размер матрицы, где m - количество строк, n - столбцов.\n");
    int n, m;
    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);
    printf("Введите значения матрицы :\n");
    a.m = m;
    a.n = n;
    a.p = (double**)malloc(m*sizeof(double*));
    for (int i = 0; i < m; i++) {
        a.p[i] = (double*)malloc(n*sizeof(double));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a.p[i][j]);
        }
    }
    return a;
}

void output_matr (struct matr a) {
    if (a.p != NULL) {
        for (int i = 0 ; i < a.m; i++){
            for (int j = 0; j < a.n; j++) {
                printf("%.1lf ", a.p[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Параметры матрицы В не удовлетворяют условию\n");
}

void clear_matr (struct matr a){
    if (a.p){
    for (int i = 0; i < a.m; i++) {
            free(a.p[i]);
        }
        free(a.p);
    }
}

struct matr sum (struct matr a, struct matr b){
    struct matr c;
    if (a.m == b.m && a.n == b.n){
        c.m = a.m;
        c.n = a.n;
        c.p = (double**)malloc(a.m*sizeof(double*));
        for (int i = 0; i < (a.m); i++) {
            c.p[i] = (double*)malloc(a.n*sizeof(double));
        }
        for (int i = 0 ; i < a.m; i++){
            for (int j = 0; j < a.n; j++) {
                c.p[i][j] = a.p[i][j] + b.p[i][j]; //все очевидно
            }
        }
        return c;
    }
    else{
        c.p = NULL;
    }
    return c;
}

struct matr const_mul (struct matr a){
    printf("Введите число на которое хотите умножить матрицу\n");
    double k;
    scanf("%lf", &k);
    for (int i = 0 ; i < a.m; i++){
        for (int j = 0; j < a.n; j++){
            a.p[i][j] = a.p[i][j] * k; //все очевидно
        }
    }
    return a;
}

struct matr matr_mul (struct matr a, struct matr b){
    struct matr c;
    if (a.n == b.m){
        c.m = a.m;
        c.n = b.n;
        c.p = (double**)malloc(c.m*sizeof(double*));
        for (int i = 0; i < (c.m); i++) {
            c.p[i] = (double*)malloc(c.n*sizeof(double));
        }
        for (int i = 0; i < c.m; i++) {
            for (int j = 0; j < c.n ; j++) {
                c.p[i][j] = 0;
                for (int k = 0; k < a.n ; k++) { //k - переменная по которой будут бегать нужные строка и столбец
                    c.p[i][j] =c.p[i][j] + a.p[i][k] * b.p[k][j];
                }
            }
        }
    }
    else{
        c.p = NULL;
    }
     return c;
}




double det (struct matr a) {
    //определитель матрицы будем раскладывать по 1-ой строке => в индексации Си - по нулевой
    double d = 0;
    if (a.n == 1) {
        d = a.p[0][0];
        return d;
    }
    else {
        for (int j = 0; j < a.n; j++) {
            //создаем дополнительный минор на каждом шаге, пока матрица не будет иметь размер 1х1
            struct matr minor;
            minor.n = a.n - 1;
            minor.p = (double**)malloc((a.n-1)*sizeof(double*));
            for (int i = 0; i < a.n-1; i++){
                minor.p[i] = (double*)malloc((a.n-1)*sizeof(double));
            }
            for (int i1 = 0+1; i1 < a.n; i1++) {
                for (int j1 = 0; j1 < j; j1++) {
                    minor.p[i1-1][j1] = a.p[i1][j1];
                }
                for (int j1 = j+1; j1 < a.n; j1++) {
                    minor.p[i1-1][j1-1] = a.p[i1][j1];
                }
            }
            if ((0 + j) % 2 == 0){
                d = d + a.p[0][j]*det(minor); //
            }
            else{
                d = d - a.p[0][j]*det(minor);
            }
           // clear_matr(minor);
        }
        return d;
    }
}

struct matr transp (struct matr a){
    struct matr c;
    c.n = a.m;
    c.m = a.n;
    c.p = (double**)malloc(a.n*sizeof(double*));
    for (int i = 0; i < a.n; i++) {
        c.p[i] = (double*)malloc(a.m*sizeof(double));
    }
    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < a.m; j++) {
            c.p[i][j] = a.p[j][i];
        }
    }
    return c;
}
