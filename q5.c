#include <stdio.h>

struct phone {
    int area_code;
    int exchange;
    int number;
};

int main() {
    struct phone my_number = {212, 767, 8900};
    struct phone your_number;

    printf("Enter area code: ");
    scanf("%d", &your_number.area_code);

    printf("Enter exchange: ");
    scanf("%d", &your_number.exchange);

    printf("Enter number: ");
    scanf("%d", &your_number.number);

    printf("My number is (%d) %d-%d\n", my_number.area_code, my_number.exchange, my_number.number);
    printf("Your number is (%d) %d-%d\n", your_number.area_code, your_number.exchange, your_number.number);

    return 0;
}