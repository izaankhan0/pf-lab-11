#include <stdio.h>
#include <string.h>

struct Invoice {
    char part_number[50];
    char part_description[100];
    int quantity;
    float price_per_item;
};

float calculate_invoice_amount(struct Invoice item) {
    if (item.quantity < 0) item.quantity = 0;
    if (item.price_per_item < 0) item.price_per_item = 0.0;
    return item.quantity * item.price_per_item;
}

int main() {
    struct Invoice item;
    strcpy(item.part_number, "A123");
    strcpy(item.part_description, "Hammer");
    item.quantity = 10;
    item.price_per_item = 25.5;

    float amount = calculate_invoice_amount(item);

    printf("Part Number: %s\n", item.part_number);
    printf("Description: %s\n", item.part_description);
    printf("Quantity: %d\n", item.quantity);
    printf("Price per Item: %.2f\n", item.price_per_item);
    printf("Invoice Amount: %.2f\n", amount);

    return 0;
}
