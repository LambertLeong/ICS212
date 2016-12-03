void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    int num1, num2 = 13;
    char c = 'H';
    float score1 = 12.5;
    char ca[3] = "Hi";
	

	printf("argc= %d\n",sizeof(argc));
	printf("addres of argc = %p\n ",&argc);

	printf("argv= %d\n",sizeof(argv));
	printf("addres of argv = %p\n ",&argv);
	
	printf("num1 = %d\n ",sizeof(num1));
	printf("addres of num1 = %p\n ",&num1);

	printf("num2 = %d\n ",sizeof(num2));
	printf("addres of num2 = %p\n ",&num2);

	printf("c = %d\n ",sizeof(c));
	printf("addres of c = %p\n ",&c);

	printf("score1 = %d\n",sizeof(score1));
	printf("addres of score1 = %p\n ",&score1+1);
	printf("Look here! score 1 + 1 = %c\n",&score1+1);

	printf("ca[0]= %d\n",sizeof(ca[0]));
	printf("addres of ca[0] = %p\n ",&ca[0]);

	printf("ca[1]= %d\n",sizeof(ca[1]));
	printf("addres of ca[1] = %p\n ",&ca[1]);

	printf("ca[2]= %d\n",sizeof(ca[2]));
	printf("addres of ca[2] = %p\n ",&ca[2]);

    dummy(num2, c, ca, score1);
    
    
    return 0;
}

void dummy(int x, char y, char * z, float w)
{
    x++;
    y++;
    w = w + 2.3;
	
	printf("x= %d\n",sizeof(x));
	printf("addres of x = %p\n ",&x+2);
	printf("at this address is = %c\n",&x+2);

	printf("y= %d\n",sizeof(y));
	printf("addres of y = %p\n ",&y);

	printf("z= %d\n",sizeof(z));
	printf("addres of z = %p\n ",&z);
	printf("what is the value of z %p\n",z);
	printf("w= %d\n",sizeof(w));
	printf("addres of w = %p\n ",&w);	
}


