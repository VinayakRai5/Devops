//Bubble sort
/* #define n 8

void main()
{
int arr[]={5,2,7,4,1,6,3,0},i,j,temp,flag;
clrscr();

printf("Unsorted array = ");
for (i=0; i<n; i++)
{
printf("%d ",arr[i]);
}

for (i=0; i<n; i++)
{
flag=0;
for (j=0; j<n-i-1; j++)
{
if (arr[j] > arr[j+1])
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
flag++;
}
}
if (flag == 0)
break;
}

printf("\nSorted array = ");
for (i=0; i<n; i++)
{
printf("%d ",arr[i]);
}
getch();
} */

//Insertion sort
/* #define n 8

void main()
{
int arr[]={5,2,7,4,1,6,3,0},i,j,temp;
clrscr();

printf("Unsorted array = ");
for (i=0; i<n; i++)
{
printf("%d ",arr[i]);
}

for (i=1; i<n; i++)
{
temp=arr[i];
j=i;
while (arr[j-1] > temp && j>0)
{
arr[j]=arr[j-1];
j--;
}
arr[j]=temp;
}

printf("\nSorted array = ");
for (i=0; i<n; i++)
{
printf("%d ",arr[i]);
}
getch();
} */

//Selection sort
/* #define n 8

void main()
{
int arr[]={5,2,7,4,1,6,3,0},i,j,index,temp;
clrscr();

printf("Unsorted array = ");
for (i=0; i<n; i++)
{
printf("%d ",arr[i]);
}

for (i=0; i<n-1; i++)
{
temp=arr[i];
for (j=i+1; j<n; j++)
{
if (arr[j] < temp)
{
temp=arr[j];
index=j;
}
}
arr[index]=arr[i];
arr[i]=temp;
}

printf("\nSorted array = ");
for (i=0; i<n; i++)
{
printf("%d ",arr[i]);
}
getch();
} */

//Quick sort
/* #include <time.h>
#define max 8

int arr[]={5,2,7,4,1,6,3,0};

int position(int lb,int ub)
{
int pivot=arr[lb],start=lb,end=ub,temp;

while (start < end)
{
while (arr[start] <= pivot)
start++;

while (arr[end] > pivot)
end--;

if (start < end)
{
temp=arr[start];
arr[start]=arr[end];
arr[end]=temp;
}
}
temp=arr[lb];
arr[lb]=arr[end];
arr[end]=temp;

return end;
}

void quick(int lb, int ub)
{
int location;

if (lb < ub)
{
location=position(lb,ub);
quick(lb,location-1);
quick(location+1,ub);
}
}

void main()
{
clock_t start_t,end_t;
double total_t;
int i;
clrscr();

printf("Array before sorting = ");
for (i=0; i<max; i++)
{
printf("%d ",arr[i]);
}

start_t=clock();
quick(0,max-1);
end_t=clock();
total_t=(double) (end_t-start_t)/CLOCKS_PER_SEC;
printf("\nTotal time taken = %f",total_t);

printf("\nArray after sorting = ");
for (i=0; i<max; i++)
{
printf("%d ",arr[i]);
}
getch();
} */

//Merge sort
/* #define max 8

int arr[]={5,2,7,4,1,6,3,0},temp[max];

void merge(int head, int mid, int tail)
{
int x,y,z;

for (x=head, y=mid+1, z=head; x <= mid && y <= tail; z++)
{
if (arr[x] <= arr[y])
temp[z]=arr[x++];
else
temp[z]=arr[y++];
}

while (x <= mid)
temp[z++]=arr[x++];

while (y <= tail)
temp[z++]=arr[y++];

for (z=head; z<=tail; z++)
arr[z]=temp[z];
}

void split(int head, int tail)
{
int mid;

if (tail>head)
{
mid=(head+tail)/2;
split(head,mid);
split(mid+1,tail);
merge(head,mid,tail);
}
}

void main()
{
int i;
clrscr();

printf("Array before sorting = ");
for (i=0; i<max; i++)
{
printf("%d ",arr[i]);
}

split(0,max-1);

printf("\nArray after sorting = ");
for (i=0; i<max; i++)
{
printf("%d ",arr[i]);
}
getch();
} */

//Heap Sort
/* void down_heapify (int arr[], int i, int size)
{
int largest=i,left=(2*i)+1,right=(2*i)+2,temp;

if (left < size && arr[largest] < arr[left])
largest=left;
if (right < size && arr[largest] < arr[right])
largest=right;
if (largest != i)
{
temp=arr[largest];
arr[largest]=arr[i];
arr[i]=temp;
down_heapify(arr,largest,size);
}
}

void heap_sort (int arr[], int size)
{
int i,temp;

for (i=(size/2)-1; i >= 0; i--)
down_heapify(arr,i,size);

while (size > 0)
{
temp=arr[0];
arr[0]=arr[--size];
arr[size]=temp;
for (i=(size/2)-1; i >= 0; i--)
down_heapify(arr,i,size);
}
}

void main()
{
int arr[]={5,2,7,4,1,6,3,0},i,size=8;
clrscr();

printf("Array before sorting = ");
for (i=0; i<size; i++)
printf("%d ",arr[i]);

heap_sort(arr,size);

printf("\nArray after sorting = ");
for (i=0; i<size; i++)
printf("%d ",arr[i]);
getch();
} */

//Shell Sort
/* void main()
{
int arr[]={5,2,7,4,1,6,3,0},i,j,gap,size=8,temp;
clrscr();

printf("Array before sorting = ");
for (i=0; i<size; i++)
printf("%d ",arr[i]);

for (gap=size/2; gap > 0; gap=gap/2)
{
for (j=gap; j < size; j++)
{
for (i=j-gap; i >= 0; i=i-gap)
{
if (arr[i+gap] > arr[i])
break;
else
{
temp=arr[i+gap];
arr[i+gap]=arr[i];
arr[i]=temp;
}
}
}
}

printf("\nArray after sorting = ");
for (i=0; i<size; i++)
printf("%d ",arr[i]);
getch();
} */

//Counting Sort
/* void main()
{
int arr[]={5,2,7,4,1,6,3,0},size=8,i,j=0,max,*ptr;
clrscr();

printf("Array before sorting = ");
for (i=0; i<size; i++)
printf("%d ",arr[i]);

max=arr[0];
for (i=1; i < size; i++)
{
if (arr[i] > max)
max=arr[i];
}
ptr = (int *) calloc(max+1,sizeof(int));
for (i=0; i < size; i++)
ptr[arr[i]]++;
for (i=0; i < max+1; i++)
{
while (ptr[i] > 0)
{
arr[j++]=i;
ptr[i]--;
}
}
free(ptr);

printf("\nArray after sorting = ");
for (i=0; i<size; i++)
printf("%d ",arr[i]);
getch();
} */

//Radix Sort
#define size 8

void count (int arr[], int pos)
{
int count[10]={0},b[size],i;

for (i=0; i < size; i++)
count[(arr[i]/pos)%10]++;

for (i=1; i < 10; i++)
count[i]=count[i]+count[i-1];

for (i=size-1; i >= 0; i--)
b[--count[(arr[i]/pos)%10]]=arr[i];

for (i=0; i < size; i++)
arr[i]=b[i];
}

void main()
{
int arr[]={5,2,7,4,1,6,3,0},i,max;
clrscr();

printf("Array before sorting = ");
for (i=0; i<size; i++)
printf("%d ",arr[i]);

max=arr[0];
for (i=1; i < size; i++)
{
if (arr[i] > max)
max=arr[i];
}
for (i=1; max/i > 0; i=i*10)
count(arr,i);

printf("\nArray after sorting = ");
for (i=0; i<size; i++)
printf("%d ",arr[i]);
getch();
}