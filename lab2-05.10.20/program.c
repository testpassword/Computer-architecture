#include <reg51.h>

int main() {
    int y = (((P1 & 0xf0) >> 4) * 10 + (P1 & 0xf) << 8);
    y = (y % 100 > 50) ? (y / 100 + 1) : (y / 100);
    P2 = y;
    y *= 10;
    P3 = ((y & 0xf00) >> 4);
    P3 += (((y & 0xff) * 10) & 0xf00) >> 8;
    return 0;
}