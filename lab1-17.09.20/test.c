main() {
    int a[10] = {2, 5, -8, 7, -3, 15, 38, -11, 66, -6};
		int i, s = 0, p = 1;
    for (i = 1; i < 10; i++) {
        p = p * a[i];
        if (a[i] < 0) s = s + a[i];
    }
}