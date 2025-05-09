#include <stdio.h>
#include <stdlib.h>

// Structure for item
typedef struct {
    int weight;
    int value;
    float ratio; // value/weight ratio
} Item;

// Comparison function to sort items by ratio of value/weight
int compare(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;

    if (item1->ratio < item2->ratio) return 1;
    if (item1->ratio > item2->ratio) return -1;
    return 0;
}

// Function to solve the Knapsack problem using Greedy approach
float knapsack(Item items[], int n, int W) {
    // Sort the items based on value/weight ratio in decreasing order
    qsort(items, n, sizeof(Item), compare);

    int currentWeight = 0;  // Current weight in knapsack
    float totalValue = 0.0; // Total value of items in knapsack

    // Iterate through all items
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fraction of the remaining item
            int remainingWeight = W - currentWeight;
            totalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    // Example items (weight, value)
    Item items[] = {
        {10, 60, 0},  // Item 1
        {20, 100, 0}, // Item 2
        {30, 120, 0}  // Item 3
    };
    int n = sizeof(items) / sizeof(items[0]);
    int W = 50;  // Capacity of the knapsack

    // Calculate value/weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Call knapsack function and print the result
    float result = knapsack(items, n, W);
    printf("Maximum value in Knapsack = %.2f\n", result);

    return 0;
}
