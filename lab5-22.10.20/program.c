#include <reg51.h>
#include <math.h>

char bdata mem;
sbit x1 = mem^0;
sbit x2 = mem^1;
sbit y1 = mem^2;
sbit y2 = mem^3;
sbit z = P1^0;

void main() {
	for (mem = 0; mem < 8; mem++) {
		P1 <<= 1;
		z = (!x1 | y1) & (x2 & y2 | !y1);
	}
}