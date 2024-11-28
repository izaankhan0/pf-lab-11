#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char id[20];
    char title[100];
    char author[100];
    int quantity;
    float price;
};

void add_book() {
    FILE *file = fopen("books.txt", "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    struct Book book;
    printf("Enter Book ID: ");
    scanf(" %[^\n]", book.id);
    printf("Enter Title: ");
    scanf(" %[^\n]", book.title);
    printf("Enter Author: ");
    scanf(" %[^\n]", book.author);
    printf("Enter Quantity: ");
    scanf("%d", &book.quantity);
    printf("Enter Price: ");
    scanf("%f", &book.price);

    fprintf(file, "%s,%s,%s,%d,%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
    fclose(file);
}

void view_books() {
    FILE *file = fopen("books.txt", "r");
    if (!file) {
        printf("Error opening file or file is empty.\n");
        return;
    }

    struct Book book;
    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%f\n", book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        printf("ID: %s, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n",
               book.id, book.title, book.author, book.quantity, book.price);
    }

    fclose(file);
}

void search_book() {
    FILE *file = fopen("books.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char search_term[100];
    printf("Enter Book ID or Title to search: ");
    scanf(" %[^\n]", search_term);

    struct Book book;
    int found = 0;
    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%f\n", book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        if (strcmp(book.id, search_term) == 0 || strcmp(book.title, search_term) == 0) {
            printf("ID: %s, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n",
                   book.id, book.title, book.author, book.quantity, book.price);
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(file);
}

void delete_book() {
    FILE *file = fopen("books.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        printf("Error opening file.\n");
        return;
    }

    char delete_id[20];
    printf("Enter Book ID to delete: ");
    scanf(" %[^\n]", delete_id);

    struct Book book;
    int deleted = 0;
    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%f\n", book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        if (strcmp(book.id, delete_id) != 0) {
            fprintf(temp, "%s,%s,%s,%d,%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
        } else {
            deleted = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (deleted) {
        printf("Book deleted successfully.\n");
    } else {
        printf("Book not found.\n");
    }
}

void calculate_inventory_value() {
    FILE *file = fopen("books.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    struct Book book;
    float total_value = 0;

    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%f\n", book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        total_value += book.quantity * book.price;
    }

    printf("Total Inventory Value: %.2f\n", total_value);

    fclose(file);
}

int main() {
    while (1) {
        int choice;
        printf("\n1. Add Book\n2. View Books\n3. Search Book\n4. Delete Book\n5. Calculate Inventory Value\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) add_book();
        else if (choice == 2) view_books();
        else if (choice == 3) search_book();
        else if (choice == 4) delete_book();
        else if (choice == 5) calculate_inventory_value();
        else if (choice == 6) break;
        else printf("Invalid choice.\n");
    }

    return 0;
}
