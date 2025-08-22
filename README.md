# Fractional-Knapsack

Algorithm:

Assume all the items are arranged in descending order of their value per weight i.e. (v/w)

Fractioanl_Knapsack(w,v,W)
    n = lenght(w)
    for i = 1 to n
        do  x[i] = 0
    i = 1
    weight = 0
    while (i <= n and weight < W)
        do  if (weight + w[i] <= W)
            then x[i] = 1
                weight += w[i]
            else
                x[i] = (W - weight) / w
                weight = W
        return x