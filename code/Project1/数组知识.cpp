
#include <stdio.h>

int main() {
	int ints[20] = { 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200 };
	int* ip = ints + 3;//*ip表示该地址被原数组地址+3，形成新的数组ip

	printf("ints = 0x%x\n", ints);
	printf("ints[4] = %d\n", ints[4]);
	printf("ints + 4 = 0x%x\n", ints + 4);
	printf("*ints + 4 = %d\n", *ints + 4);
	printf("*ints= %d\n", *ints);
	printf("*ints= %x\n", &ints);
	printf("*(ints + 4) = %d\n", *(ints + 4));
	printf("ints[-2] = %d\n", ints[-2]);//数组就是地址，且等于第一个元素的地址

	printf("\n");

	printf("&ints= 0x%x\n", &ints);
	printf("&ints[4]= 0x%x\n", &ints[4]);
	printf("&ints[3]= 0x%x\n", &ints[3]);
	printf("&ints + 4= 0x%x\n", &ints + 4);
	printf("&ints[-2]= 0x%x\n", &ints[-2]);//取地址的地址就是地址

	printf("\n");

	printf("ip= 0x%x\n", ip);
	printf("ip[4]= %d\n", ip[4]);
	printf("ip+4= 0x%x\n", ip + 4);
	printf("*ip + 4= %d\n", *ip + 4);
	printf("*(ip+4) %d\n", *(ip + 4));
	printf("ip[-2] = %d\n", ip[-2]);

	printf("\n");

	printf("&ip= 0x%x\n", &ip);
	printf("&ip[4]= 0x%x\n", &ip[4]);
	printf("&ip + 4= 0x%x\n", &ip + 4);
	printf("&ip[-2]= 0x%x\n", &ip[-2]);


	printf("sizeof(int*) = %d", sizeof(int*));

	return 0;
}