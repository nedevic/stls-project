void c3_p6() {
    int x = 10;
    int y = 1;
    while (0 < x) {
        y *= x;
        x -= 1;
    }
}

void c4_p4() {
    int x = 10;
    int y = 1;
    int z;
    if (x < y) {
        z = x;
    } else {
        z = y;
    }
    printf("%d\n", z);
}

void c4_p14() {
    int sum = 0;
    int i = 1;
    while (i < 11) {
        sum += i;
        i++;
    }
    printf("%d\n%d\n", sum, i);
}

void c6_p2() {
    int A[4][8] = {8};
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            sum += A[i][j];
        }
    }
    printf("%d\n", sum);
}

int main() {
    c3_p6();

    return 0;
}
