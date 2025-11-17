#include <stdio.h>

void addProduct(int ProductID[], int Quantity[], int Price[], int n) {
    int id, q, p, i, duplicate = 0;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (ProductID[i] == id) duplicate = 1;
    }
    if (duplicate) {
        printf("Duplicate ID not allowed.\n");
        return;
    }

    printf("Enter Quantity: ");
    scanf("%d", &q);
    if (q <= 0) {
        printf("Invalid quantity.\n");
        return;
    }

    printf("Enter Price: ");
    scanf("%d", &p);
    if (p <= 0) {
        printf("Invalid price.\n");
        return;
    }

    ProductID[n] = id;
    Quantity[n] = q;
    Price[n] = p;

    printf("Product Added.\n");
}

void searchProduct(int ProductID[], int Quantity[], int Price[], int n) {
    int id, i, found = 0;

    printf("Enter Product ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (ProductID[i] == id) {
            printf("ID: %d  Quantity: %d  Price: %d\n", ProductID[i], Quantity[i], Price[i]);
            found = 1;
        }
    }
    if (!found) printf("Not Found.\n");
}

void updateQuantity(int ProductID[], int Quantity[], int n) {
    int id, i, ch, val;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (ProductID[i] == id) {
            printf("1. Increase\n2. Decrease\nEnter choice: ");
            scanf("%d", &ch);

            printf("Enter value: ");
            scanf("%d", &val);

            if (ch == 1) Quantity[i] += val;
            else if (ch == 2) {
                if (Quantity[i] - val >= 0) Quantity[i] -= val;
                else printf("Quantity cannot go negative.\n");
            }
            return;
        }
    }
    printf("Not Found.\n");
}

void rackReport(int stock[3][3]) {
    int i, j;
    int max = stock[0][0], min = stock[0][0];
    int maxR = 0, maxC = 0, minR = 0, minC = 0;
    int total = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (stock[i][j] > max) {
                max = stock[i][j];
                maxR = i; maxC = j;
            }
            if (stock[i][j] < min) {
                min = stock[i][j];
                minR = i; minC = j;
            }
            total += stock[i][j];
        }
    }

    printf("Max Stock: %d at (%d,%d)\n", max, maxR, maxC);
    printf("Min Stock: %d at (%d,%d)\n", min, minR, minC);
    printf("Total Items in Racks: %d\n", total);
}

void stockValueReport(int ProductID[], int Quantity[], int Price[], int n) {
    int i;
    int maxVal = 0, minVal = 0;
    int maxID = -1, minID = -1;
    int total = 0;

    for (i = 0; i < n; i++) {
        int value = Quantity[i] * Price[i];
        printf("ID: %d  Value: %d\n", ProductID[i], value);

        if (i == 0) {
            maxVal = minVal = value;
            maxID = minID = ProductID[i];
        } else {
            if (value > maxVal) {
                maxVal = value;
                maxID = ProductID[i];
            }
            if (value < minVal) {
                minVal = value;
                minID = ProductID[i];
            }
        }

        total += value;
    }

    printf("\nHighest Value Product: %d (%d)\n", maxID, maxVal);
    printf("Lowest Value Product: %d (%d)\n", minID, minVal);
    printf("Total Warehouse Value: %d\n", total);
}

void displayAll(int ProductID[], int Quantity[], int Price[], int n) {
    int i;
    printf("\nID\tQty\tPrice\tValue\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", ProductID[i], Quantity[i], Price[i], Quantity[i] * Price[i]);
    }
}

int main() {
    int ProductID[20], Quantity[20], Price[20];
    int stock[3][3];
    int n = 0;
    int i, j, ch;

    printf("Enter 3x3 Rack Matrix:\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &stock[i][j]);

    while (1) {
        printf("\n1. Add Product\n2. Search Product\n3. Update Quantity\n4. Rack Report\n5. Stock Value Report\n6. Display All Products\n7. Exit\n");
        scanf("%d", &ch);

        if (ch == 1) { addProduct(ProductID, Quantity, Price, n); n++; }
        else if (ch == 2) searchProduct(ProductID, Quantity, Price, n);
        else if (ch == 3) updateQuantity(ProductID, Quantity, n);
        else if (ch == 4) rackReport(stock);
        else if (ch == 5) stockValueReport(ProductID, Quantity, Price, n);
        else if (ch == 6) displayAll(ProductID, Quantity, Price, n);
        else if (ch == 7) break;
    }

    return 0;
}

