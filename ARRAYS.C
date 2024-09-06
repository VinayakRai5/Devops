/* void main()
{
int x[5]={1,2,3,4,5},i,j;   //arrays start count from 0 instead of 1


//printf("Enter marks of 5 students\n");

//for (i=0; i<5; i++)
//{
//scanf("%d", &x[i]);
//}
int *y=x;  //x = &x[0]. Only for address in arrays
clrscr();
*y=10;     //Here, *y is the address of 1st value
*y++;      //*y++ means move to x[1],ie. the next value
*y=20;
for (j=0; j<5; j++)
{
printf("Marks of student %d is %d\n",j+1,x[j]);
}
getch();
} */

/* void main()
{
int x=10,a=100;
int *y=&x, *b=&a;
clrscr();

printf("Addition=%d\n",*y+5);
printf("Subtraction=%d\n",*y-5);
printf("Pointer Subtraction=%d\n",*b-*y);
if (*y>*b)
{
printf("Greater");
}
else
{
printf("Lesser");
}
} */

/* void array(int *);
void main()
{
int x[3]={1,2,3},i,j;
clrscr();
for (i=0; i<3; i++)
{
printf("%d\n",x[i]);
}
array(x);
for (j=0; j<3; j++)
{
printf("%d\n",x[j]);
}
}

void array(int *y)
{
int a;
for (a=0; a<3; a++)
{
*y=50;
y++;
}
} */

/* void main()
{
int matrix[2][4]={{1,2,3,4},{5,6,7,8}};
int i,j;
clrscr();

for (i=0; i<2; i++) //For rows
{
for (j=0; j<4; j++) //For columns
{
printf("%d ",matrix[i][j]);
}
printf("\n");
}
getch();
} */

/* void main()
{
int x[10]={1,2,3,4,5,6,7,8,9,10};
int *y=x;
clrscr();

y=y+2;
printf("%d", *y);
} */

/* void main()
{
int a,b,s[10];
clrscr();

printf("Enter number\n");
scanf("%d", &a);

for (b=0; b<10; b++)
{
s[b]=a*(b+1);
}

for (b=0; b<10; b++)
{
printf("%d\n",s[b]);
}
getch();
} */

/* void flip(int [],int);

void main()
{
int a,x[5]={1,2,3,4,5};
clrscr();

for (a=0; a<5; a++)
{
printf("%d ",x[a]);
}
printf("\n");
flip(x,5);
}

void flip(int x[], int n)
{
int b,uno;

for (b=0; b<n/2; b++)
{
uno=x[b];
x[b]=x[n-b-1];
x[n-b-1]=uno;
}

for (b=0; b<n; b++)
{
printf("%d ",x[b]);
}
} */

/* void main()
{
int a,p=0,n=0,x[10]={1,-2,3,-4,5,-6,7,-8,9,-10};
int *y=x;
clrscr();

for (a=0; a<10; a++)
{
if (x[a]>0)
{
p=p+1;
y++;
}
else
{
n=n+1;
y++;
}
}
printf("Number of positive numbers are %d\n",p);
printf("Number of negative numbers are %d",n);
} */

/* void main()
{
int a,b,x,y,z;
clrscr();

printf("Enter 3 numbers to show the multiplication table in a 3x10 matrix\n");
scanf("%d",&x);
scanf("%d",&y);
scanf("%d",&z);
printf("\n");

for (a=0; a<3; a++)
{
for (b=1; b<11; b++)
{
if (a==0)
{
printf("%d ",x*b);
}
else if (a==1)
{
printf("%d ",y*b);
}
else
{
printf("%d ",z*b);
}
}
printf("\n");
}
getch();
} */

/* void main()
{
int i,j,k;  //i=block, j=row, k=column
int matrix[2][3][3]={ {{1,2,3},{1,2,3},{1,2,3}},   //elements of block 1
		      {{4,5,6},{4,5,6},{4,5,6}} }; //elements of block 2
clrscr();

for (i=0; i<2; i++)
{
for (j=0; j<3; j++)
{
for (k=0; k<3; k++)
{
printf("%d ",matrix[i][j][k]);
if (k==2)
{
printf("\n");
}
}
}
printf("\n");
}
} */

/* void main()
{
int x[5]={1,2,3,4,5},i;
int *ptr=x;
clrscr();

for (i=0; i<5; i++)
{
printf("%d\n", *ptr);
ptr++;
}
getch();
} */

/* void main()
{
int temp,i,j,k,x[5]={3,2,4,1,5};  //{2,3,4,1,5}
clrscr();                         //{1,3,4,2,5}
				  //{1,2,4,3,5}
for (i=0;i<5;i++)                 //{1,2,3,4,5}
{
temp = x[i];
for (j=0;j<5;j++)
{
if (temp < x[j]) //(temp > x[j]) will print in decreasing order
{
x[i]=x[j];
x[j]=temp;
temp=x[i];
}
}
}

for (k=0;k<5;k++)
{
printf("%d ",x[k]);
}
getch();
} */

//matrix multiplication
void main()
{
int x[][3]={{1,2,3},{2,3,4},{3,4,5}};
int y[][3]={{4,5,6},{5,6,7},{6,7,8}};
int z[3][3],i,j,k;
clrscr();

for(i=0; i<3; i++)
{
for (j=0; j<3; j++)
{
z[i][j]=0;
for (k=0; k<3; k++)
{
z[i][j] += x[i][k] * y[k][j];
}
}
}

for (i=0; i<3; i++)
{
for (j=0; j<3; j++)
{
printf("%d ",z[i][j]);
}
printf("\n");
}
getch();
} 