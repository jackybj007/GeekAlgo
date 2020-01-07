struct hash_data {
    int key;
    int val;
    struct hash_data * next;
};

struct hash_table {
    struct hash_data ** head;
    int width;
};

int hashtable_init(struct hash_table * ht, int width) {
    if (width <= 0) {
        return -1;
    }
    int size = width * sizeof(struct hash_data *);
    struct hash_data ** tmpht = (struct hash_data **)malloc(size);
    if (!tmpht) {
        return -1;
    }
    memset(tmpht, 0, size);
    ht->head = tmpht;
    ht->width = width;
    return 0;
}

int hashtable_hash(struct hash_table * ht, int key) {
    return abs(key) % ht->width;
}

void hashtable_fini(struct hash_table * ht) {
    if (!ht) return;
    struct hash_data * head, *tmp; 
    if (ht->head) {
        for (int i = 0; i < ht->width; i ++) {
            head = ht->head[i];
            while (head) {
                tmp = head;
                head = head->next;
                free(tmp);
            }
        }
    }
    ht->width = 0;
}

int hashtable_insert(struct hash_table * ht, int key, int value) {

    int pos = hashtable_hash(ht, key);
    int size = sizeof(struct hash_data);
    struct hash_data * data = (struct hash_data *)malloc(size);
    if (!data) {
        return -1;
    }
    memset(data, 0, size);
    data->key = key;
    data->val = value;
    data->next = ht->head[pos];
    ht->head[pos] = data;

    return 0;
}

struct hash_data * hashtable_find(struct hash_table * ht, int key) {
    int pos = hashtable_hash(ht, key);
    struct hash_data * hd = ht->head[pos];

    while (hd) {
        if (hd->key == key) {
            return hd;
        }
        hd = hd->next;
    }
    return NULL;
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
        struct hash_data * hd = hashtable_find(ht, key);
        if (hd) {
            res[0] = hd->val;
            res[1] = i;
            * returnSize = 2;
            break;
        }
        hashtable_insert(ht, nums[i], i);
    }

    hashtable_fini(ht);

    return res;
}
