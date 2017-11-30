#include <bits/stdc++.h>
using namespace std;
void print_basic()
{
	puts("******************************************************************************");
	puts("1. These are the basic requirements, If you fail any of these then you can not participate\n");
	puts("2. You must be willing and able to compete in World Finals\n");
	puts("3. You must be enrolled in degree progam at sponsoring institution\n");
	puts("4. You should take at least 1/2 load OR co-op, exchange, or intern student!!!!\n");
	puts("5. You must compete for only one institution this year\n");
	puts("6. If you are foreign student then your foreign student visa does permit return from World Finals to institution\n");
	puts("7. Your (number of finals as contestant) < 2\n");
	puts("8. Your (number of regionals as contestant) < 5\n");
	puts("******************************************************************************");
}

void eligible()
{
	puts("\n\nCONGO YOU HAVE MADE IT. YOU ARE ELIGIBLE");
	exit(0);
}

void ineligible()
{
	puts("\n\nSO SAD YOU ARE DEAD. YOU ARE INELIGIBLE");
	exit(0);
}

void age_limits()
{
    int r,x;
    printf("Enter the year of the regional: ");
    scanf("%d",&r);
    printf("When(year) have you started your post secondary studies?: ");
    scanf("%d",&x);
    if( r - 4 <= x ) eligible();
    printf("What is your birth year?: ");
    scanf("%d",&x);
    if( r - 23 <= x ) eligible();
    printf("Have completed more than equivalent of 8 semester of full time study?\n1.YES\n2.NO\n(select 1 or 2)\n");
    while( 1 )
    {
		scanf("%d",&x);
		if( x == 1 || x == 2 ) break;
    }
    if( x == 1 ) ineligible();
    puts("Coach petitions for extension of eligibility. Provides full history of student academic and work history");
    printf("Your documents are verified as TRUE from the ICPC Managers?\n1.YES\n2.NO\n(select 1 or 2)\n");
    while( 1 )
    {
		scanf("%d",&x);
		if( x == 1 || x == 2 ) break;
    }
    if( x == 1 ) eligible();
    else ineligible();

}

int main()
{
	print_basic();
	age_limits();
	return 0;
}
