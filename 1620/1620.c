#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _record {
    int id;
    char name[21];
} record;

int cmp_name(const void *a, const void *b) {
    record rec_a = *(record*)a;
    record rec_b = *(record*)b;

    return strcmp(rec_a.name, rec_b.name);
}

int find_name(record *records, int l, int r, char *name) {
    int m = (l + r) / 2;
    record *rec_m = &records[m];
    int res = strcmp(name, rec_m->name);

    if (res == 0) {
        return m;
    }
    else if (res > 0) {
        return find_name(records, m + 1, r, name);
    }
    else {
        return find_name(records, l, m - 1, name);
    }
}

int main(int argc, char **argv) {

    int N, M;
    scanf("%d %d", &N, &M);

    char name[21];
    record records[N + 1];
    record records_name[N + 1];

    for (int i = 0; i < N; i++) {
        scanf("%s", records[i].name);
        records[i].id = i + 1;
    }
    
    memcpy(&records_name, &records, sizeof(record) * N);
    
    qsort(records_name, N, sizeof(record), cmp_name);

    char qs[21];
    for (int i = 0; i < M; i++) {
        scanf("%s", qs);
        int id = atoi(qs);
        if (id > 0) {
            printf("%s\n", records[id - 1].name);
        }
        else {
            int idx = find_name(records_name, 0, N - 1, qs);
            printf("%d\n", records_name[idx].id);
        }
    }

    return 0;
}