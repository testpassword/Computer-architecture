# include <reg51.h>

void Int00(void) interrupt 0 {
	int i = 0;
	float n;
	char digit;
	char xdata str[8];
	char m = 1;
	int mm;
	char x = P3;
	switch (x) {
		case 0xfe: digit = '1'; break;
		case 0x02: digit = '2'; break;
		case 0xfd: digit = '3'; break;
		case 0x79: digit = '4'; break;
		case 0xfb: digit = '5'; break;
		
		case 0x08: digit = '6'; break;
		case 0xf7: digit = '7'; break;
		case 0x10: digit = '8'; break;
		case 0xef: digit = '9'; break;
		case 0x01: digit = '0'; break;
		
		case 0xfa: digit = '-'; break;
		case 0xbe: digit = ','; break;
		case 0xfc: digit = 'e'; break;
		default: digit = 0xff;
	}
	if (digit == ',' || digit == '-') {
		mm = m;
		str[i++] = digit;
	}
	if (digit == 'e') {
		digit = 0xff;
		n /= mm;
	}
	if (digit != 0xff) {
		str[i++] = digit;
		m *= 10;
		n = n * 10 + (digit & 0xff);
	}
	while (~INT0);
}

int main() {
	EX0 = 1;
	IT0 = 1;
	EA = 1;
	while(1);
	return 0;
}