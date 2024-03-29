/*************************************************************************
	> File Name: 12_unstable_sort1.c
	> Author: Daniel
	> Mail: 292382967@qq.com
	> Created Time: 六  7/28 09:52:33 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "rand_test.h"

void select_sort(int*, int);
void quick_sort(int*, int, int);
void ungarded_insert_sort(int*, int);

int main() {
    int*num;
    TEST(20, select_sort(num, 20));
    TEST(20, quick_sort(num, 0, 19));
    return 0;
}

void select_sort(int*num, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int ind = i;
        for (int j = i + 1; j < n; ++j) {
            if (num[j] < num[ind]) {
                ind = j;
            }
        }
        swap(num[i], num[ind]);
    }
}

void quick_sort(int*num, int l , int r) {
    while (r - l >= 16) {          //缩短压栈时间(递归改循环)
        int x = l, y = r, z = rand() % (r - l + 1) + l;
        swap(num[z], num[l]);
        z = num[l];
        while (x < y) {
            while (x < y && num[y] >= z) --y;
            if (x < y) num[x++] = num[y];
            while (x < y && num[x] <= z) ++x;
            if (x < y) num[y--] = num[x];
        }
        num[x] = z;
        quick_sort(num, l, x - 1);
        l = x + 1;
    }
    ungarded_insert_sort(num + l, r - l + 1);
    return;
}

void ungarded_insert_sort(int*num, int n) {
    int ind =0;
    for (int i = 1; i < n; ++i) {
        if (num[i] < num[ind]) ind = i;
    }
    swap(num[ind], num[0]);
    for (int i = 2; i < n; ++i) {
        int j = i;
        while (num[j] < num[j - 1]) {
            swap(num[j], num[j - 1]);
            j--;
        }
    }
    return ;
}
