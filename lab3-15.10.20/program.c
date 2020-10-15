#include <reg51.h>

int main() {
    int key[] = {3, 1, 2, 0, 6};
    int keyLength = 5;
    char code str[] = "computer architecture";
		char xdata res[21];
    int codes[21];
		int i;
    for (i = 0; i < 21; i++) {
        codes[i] = key[i % keyLength];
    }
		//encrypt
    for (i = 0; i < 21; i++) {
        res[i] = (char) (((int) str[i]) + codes[i]);
    }
		//decrypt
		for (i = 0; i < 21; i++) {
        res[i] = (char) (((int) str[i]) - codes[i]);
		}
    return 0;
}