#include<stdio.h>
//normal representation:
/*struct BirthDate{
 unsigned int d,m,y;
};*/
//if we want to optimize the storage using bitfield:

struct Birthdate
{
    // d has value between 1 and 31, so 5 bits are sufficient.
    unsigned int d :5;
// m has value between 1 and 12, so 4 bits are sufficient.
    unsigned int m :4;
    unsigned int y;

};
struct test{
unsigned int  a:1,b:2,c:3;
};

int main()
{
    printf("Size of date is %lu bytes\n", sizeof(struct Birthdate));//which is 8 bytes; but if we use normal representation it will take 12 bytes
    struct Birthdate Nahid = { 31, 12, 2000};
    printf("Birth Date is %d/%d/%d", Nahid.d, Nahid.m, Nahid.y);

//But it has some problem....
//The output comes out to be negative if the input is 31/12/2000 and we use only int instead of unsigned int(output is = -1/-4/2000).
 //What happened behind is that the value 31 was stored in 5 bit signed integer which is equal to 11111.
 //The MSB is a 1, so it’s a negative number and you need to calculate the 2’s complement of the binary number to get its actual value which is what is done internally.
  //By calculating 2’s complement you will arrive at the value 00001 which is equivalent to decimal number 1 and since it was a negative number you get a -1.
 //A similar thing happens to 12 in which case you get 4-bit representation as 1100 which on calculating 2’s complement you get the value of -4.


struct test x;
int i;

	for(i=0;i<8;i++)
	{
		x.a=x.b=x.c=i;
		printf("%d %d %d\n",x.a,x.b,x.c);//when i=2..tokhn a er jponno output ashbey 0..karon a holo 1 bit er..(2=01)tai 0 ashbe..bakigular khetrew same..
	}
	puts("-----");
	for(i=0;i<8;i++)
	{
		x.c=x.b=x.a=i;//in bitfield (x.a=x.b=x.c=i)!=(x.c=x.b=x.a)
		//assignment right theke left e hoy..tai i=5 jokhn x.a=1 x.a=x.b=x.c=1 hoye jay tokhn...
		printf("%d %d %d\n",x.a,x.b,x.c);
	}
}