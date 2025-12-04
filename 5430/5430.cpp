#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct _Deq {
    int capacity;
    int *data;
    int l;
    int r;
    bool reverse = false;
} Deq;

char p[100001];

void push_right(Deq *deq, int x) {
    deq->data[deq->r] = x;
    deq->r++;
}

Deq* create_deq(int n) {
    Deq *deq = new Deq;
    deq->capacity = n;
    deq->l = 0;
    deq->r = 0;
    deq->reverse = false;
    deq->data = new int[n + 1];

    int x = 0;

    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            x = 10 * x + (s[i] - '0');
        }
        else {
            if (x > 0) {
                push_right(deq, x);
            }
            x = 0;
        }
    }

    return deq;
}

void reverse(Deq *deq) {
    deq->reverse = !deq->reverse;
}

int pop_left(Deq *deq) {
    if (deq->l == deq->r) return -1;
    int x;
    x = deq->data[deq->l];
    deq->l++;
    return x;
}

int pop_right(Deq *deq) {
    if (deq->l == deq->r) return -1;
    int x = deq->data[deq->r - 1];
    deq->r--;
    return x;
}

int pop_front(Deq *deq) {
    if (deq->reverse) {
        return pop_right(deq);
    }
    else {
        return pop_left(deq);
    }
}

void print_deq(Deq *deq) {
    printf("[");
    if (deq->l != deq->r) {
        if (deq->reverse) {
            int i;
            for (i = deq->r - 1; i > deq->l; i--) {
                printf("%d,", deq->data[i]);
            }
            printf("%d", deq->data[i]);
        }
        else {
            int i;
            for (i = deq->l; i < deq->r - 1; i++) {
                printf("%d,", deq->data[i]);
            }
            printf("%d", deq->data[i]);
        }
    }
    printf("]\n");
}

void destroy_deq(Deq *deq) {
    delete deq->data;
    delete deq;
}

int main(int argc, char **argv) {

    int T;

    scanf("%d", &T);
    

    for (int i = 0; i < T; i++) {
        int n;
        bool error = false;
        string p;
        cin >> p;
        scanf("%d", &n);
        Deq *deq = create_deq(n);
        int j = 0;
        int len = p.length();
        while (j < len) {
            if (p[j] == 'R') {
                reverse(deq);
            }
            if (p[j] == 'D') {
                int x = pop_front(deq);
                if (x < 0) {
                    error = true;
                    printf("error\n");
                    break;
                }
            }
            j++;
        }
        if (!error) {
            print_deq(deq);
        }
        destroy_deq(deq);
    }

    return 0;
}