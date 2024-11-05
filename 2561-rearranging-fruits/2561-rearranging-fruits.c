//KRITIKA AGRAHARI CH.SC.U4CSE23061
typedef struct {

    int key;    // fruit value
    int value;  // frequency difference
} HashMapItem;

// A simple hash function for fruit values
int hashFunc(int key, int size) {
    return key % size;
}

// Insert into hashmap
void insert(HashMapItem* hashMap, int size, int key, int value) {
    int index = hashFunc(key, size);
    while (hashMap[index].key != 0 && hashMap[index].key != key) {
        index = (index + 1) % size;
    }
    hashMap[index].key = key;
    hashMap[index].value += value;
}

// Get from hashmap
int get(HashMapItem* hashMap, int size, int key) {
    int index = hashFunc(key, size);
    while (hashMap[index].key != 0) {
        if (hashMap[index].key == key) {
            return hashMap[index].value;
        }
        index = (index + 1) % size;
    }
    return 0;
}

// Compare function for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find the minimum cost
long long min(long long a, long long b) {
    return (a < b) ? a : b;
}

long long minCost(int* basket1, int basket1Size, int* basket2, int basket2Size) {
    int totalSize = basket1Size + basket2Size;
    int mapSize = totalSize * 2;  // Arbitrary size to handle hash collisions
    HashMapItem* hashMap = (HashMapItem*)calloc(mapSize, sizeof(HashMapItem));
    int minFruit = INT_MAX;
    long long cost = 0;

    // Step 1: Populate the hashmap with frequency differences
    for (int i = 0; i < basket1Size; i++) {
        insert(hashMap, mapSize, basket1[i], 1);
        minFruit = min(minFruit, basket1[i]);
    }
    for (int i = 0; i < basket2Size; i++) {
        insert(hashMap, mapSize, basket2[i], -1);
        minFruit = min(minFruit, basket2[i]);
    }

    // Step 2: Collect the unbalanced fruits
    int imbalance[totalSize];
    int imbalanceSize = 0;

    for (int i = 0; i < mapSize; i++) {
        if (hashMap[i].key != 0) {
            int freq = get(hashMap, mapSize, hashMap[i].key);
            if (freq % 2 != 0) {
                free(hashMap);
                return -1;  // If there's an odd frequency, it's impossible to balance
            }

            for (int j = 0; j < abs(freq) / 2; j++) {
                imbalance[imbalanceSize++] = hashMap[i].key;
            }
        }
    }

    // Step 3: Sort imbalance array
    qsort(imbalance, imbalanceSize, sizeof(int), compare);

    // Step 4: Calculate the minimum cost to balance
    for (int i = 0; i < imbalanceSize / 2; i++) {
        cost += min(imbalance[i], 2 * minFruit);
    }

    free(hashMap);
    return cost;
}
