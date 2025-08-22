// Fractional Knapsack Program

#include <stdio.h>
int main() {
    int n , capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int weight[n], value[n];
    float ratio[n], x[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
        ratio[i] = (float)value[i] / weight[i];
        x[i] = 0; // Initialize x[i] to 0
    }

    // Sort items by value-to-weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0 + 1; j < n - i; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // Swap ratio
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                // Swap weight
                int tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;

                // Swap value
                int tempValue = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tempValue;
            }
        }
    }

    float totalValue = 0.0;
    int currentWeight = 0;
    int x[n];
    
    for (int i = 0; i < n; i++) {
        x[i] = 0; // Initialize x[i] to 0
    }

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= capacity) {
            x[i] = 1; // Take the whole item
            currentWeight += weight[i];
            totalValue += value[i];
        } else {
            int remaining capacity = capacity - currentWeight;
            x[i] = (float)(remaining / weight[i]); // Take the fraction of the item
            totalValue += ratio[i] * remaining;
            break; // Knapsack is full
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", totalValue);

    return 0;
} 