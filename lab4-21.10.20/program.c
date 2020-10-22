#include <reg51.h>
#include <math.h>

double floatingPoint(double x) { return log(x); }

void floatPointWrapper() {
	float x;
	for (x = -1; x <= 1; x += 0.02) 
		P3 = floatingPoint(x) * 100 + 100;
}

unsigned char fixedPoint(unsigned char x, int accuracy) {
	int i;
	int res;
	for (i = 1; i < accuracy; i++) 
		res -= pow(x, accuracy);
	return res;
}

void fixPointWrapper() {
	unsigned char x;
	for (x = -100; x <= 100; x++)
		P3 = fixedPoint(x, 6) + 100;
}

void main() {
	while(1) {
		//floatPointWrapper();
		fixPointWrapper();
	}
}