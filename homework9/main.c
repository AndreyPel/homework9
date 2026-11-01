#define _CRT_SECURE_NO_DEPRECATE 
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define M_PI 3.14159265358979323846

void create_parallelogram(char symvol, int h, int a, float alpha) {
    float alpha_rad = alpha * M_PI / 180.0;

    int shift = (int)round(1.0 / tan(alpha_rad) * 0.5);
    if (shift < 1) shift = 1;

    printf("Заполненный параллелограмм:\n");

    for (int i = 0; i < h; i++) {
        int offset = (h - 1 - i) * shift;

        for (int j = 0; j < offset; j++) {
            printf(" ");
        }
        for (int j = 0; j < a; j++) {
            printf("%c", symvol);
        }
        printf("\n");
    }
}

int main() {

    setlocale(LC_ALL, "RUS");

    char symvol;
    int h, a;
    float alpha;
    int continue_flag = 1;

    while (continue_flag != 0) {
        printf("Введите символ из которого будет строиться фигура:\n");
        scanf(" %c", &symvol);

        printf("Введите высоту:\n");
        scanf("%d", &h);

        printf("Введите ширину основания:\n");
        scanf("%d", &a);

        printf("Введите угол альфа (в градусах):\n");
        scanf("%f", &alpha);

        create_parallelogram(symvol, h, a, alpha);

        printf("Продолжить ? (Да - введите любое число, Нет - введите 0)\n");
        scanf("%d", &continue_flag);
    }

    return 0;
}