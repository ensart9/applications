#include <stdio.h>
#include <stdlib.h>
int main()
{
    // pointers giriş

    int age = 21;
    printf("%d\n", age); // değişkenin değerini yazdırma
    printf("%p\n", &age); // değişkenin adresini yazdırma (%p ile bastırıldığı zaman & işareti olmalı)

    // pointer tanımlama(v1)

    int number = 9;
    int* ptr1 = &number; // pointer tanımlanan yer

    printf("%d\n", *ptr1); // değişkenin değerini yazdırma
    printf("%p\n", &number); // değişkenin adresini yazdırma

    // pointer tanımlama(v2)

    int number2 = 10;
    int* ptr2;
    ptr2 = &number2; // pointer değişkenin adresiyle eşlendi

    printf("%d\n", *ptr2); // değişkenin değerini yazdırma
    printf("%d\n", ptr2); // değişkenin adresini yazdırma 
   

    
    // değişken adresini değiştirmeden tutulan değerleri değiştirme
    int number = 99;
    int* n;
    n = &number;

    printf("%d\n", *n);
    printf("%d\n", n);

    *n = 45; // sayi değişti ve adresi sabit kaldı (number=45 de diyebilirdik)

    printf("%d\n", *n);
    printf("%d\n", n);
}