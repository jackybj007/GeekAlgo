struct hash_node {
    int key;
    int val;
    struct hash_node * next;
};

struct hash_table {
    struct hash_node ** nodes;
    int width;
};

int hashtable_hash(struct hash_table * ht, int key) {
    return abs(key) % ht->width;
}

int hashtable_init(struct hash_table * ht, int width) {
    if (width <= 0) {
        return -1;
    }
    int size = width * sizeof(struct hash_node *);
    struct hash_node ** nodes = (struct hash_node **)malloc(size);
    if (!nodes) {
        return -1;
    }
    memset(nodes, 0, size);
    ht->nodes = nodes;
    ht->width = width;
    return 0;
}

void hashtable_fini(struct hash_table * ht) {
    if (!ht) return;
    struct hash_node * node, *tmp; 
    if (ht->nodes) {
        for (int i = 0; i < ht->width; i ++) {
            node = ht->nodes[i];
            while (node) {
                tmp = node;
                node = node->next;
                free(tmp);
            }
        }
    }
    ht->width = 0;
}

struct hash_data * hashtable_get(struct hash_table * ht, int key) {
    int pos = hashtable_hash(ht, key);
    struct hash_node * node = ht->nodes[pos];

    while (node) {
        if (node->key == key) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

int hashtable_put(struct hash_table * ht, int key, int value) {

    int pos = hashtable_hash(ht, key);
    int size = sizeof(struct hash_node);
    struct hash_node * node;

    node = hashtable_get(ht, key);

    if (node) {
        node->key = key;
        node->val = value;
        return 0;
    }

    node = (struct hash_node *)malloc(size);
    if (!node) {
        return -1;
    }
    memset(node, 0, size);
    node->key = key;
    node->val = value;
    node->next = ht->nodes[pos];
    ht->nodes[pos] = node;

    return 0;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int * res = malloc(2 * sizeof(int));
    struct hash_table table, * ht = &table;

    * returnSize = 0;

    hashtable_init(ht, 32);

    for (int i = 0; i < numsSize ; i ++) {
        int key = target - nums[i];
        struct hash_node * node = hashtable_get(ht, key);
        if (node) {
            res[0] = node->val;
            res[1] = i;
            * returnSize = 2;
            break;
        }
        hashtable_put(ht, nums[i], i);
    }

    hashtable_fini(ht);

    return res;
}
