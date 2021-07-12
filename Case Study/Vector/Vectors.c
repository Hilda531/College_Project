/* Dibuat oleh: Hilda Auliana

Keterangan:
Program ini dibuat untuk melihat hasil penjumlahan dan perkalian dua buah vektor.
*/

#include<stdio.h>

// Declaring Structure
struct complex
{
    float re_val;
    float im_val;
};

// Function Prototype
struct complex adding(struct complex *p, struct complex *q);
struct complex multiplying(struct complex *p, struct complex *q);

int main()
{
    // Declaring structure variable using struct complex
    struct complex n1, n2, add, mul;

    // Get input number
    printf("Enter real part of 1st complex number\t\t: ");
    scanf("%f", &n1.re_val);
    printf("Enter imaginary part of 1st complex number\t: ");
    scanf("%f", &n1.im_val);

    printf("\nEnter real part of 2nd complex number\t\t: ");
    scanf("%f", &n2.re_val);
    printf("Enter imaginary part of 2nd complex number\t: ");
    scanf("%f", &n2.im_val);

    // Displays the form of each complex function
    printf("\nComplex Function");
    printf("\na = %0.2f + j %0.2f", n1.re_val, n1.im_val);
    printf("\nb = %0.2f + j %0.2f", n2.re_val, n2.im_val);

    // Displays the result
    add = adding(&n1, &n2);
    mul = multiplying(&n1, &n2);

    printf("\n\nResult");
    printf("\na+b = %0.2f + j %0.2f", add.re_val, add.im_val);
    printf("\na*b = %0.2f + j %0.2f", mul.re_val, mul.im_val);

    printf("\n\npress any key to exit");
    getch();
    return 0;
}

// Function Definition (using pointers)
struct complex adding(struct complex *a, struct complex *b)
{
    struct complex num;
    num.re_val = (*a).re_val + (*b).re_val;
    num.im_val = (*a).im_val + (*b).im_val;
    return num;
}

struct complex multiplying(struct complex *a, struct complex *b)
{
    struct complex num;
    num.re_val = (*a).re_val * (*b).re_val - (*a).im_val * (*b).im_val;
    num.im_val = (*a).re_val * (*b).im_val + (*a).im_val * (*b).re_val;
    return num;
}
