#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long c1, c2;

void merge(int a[], int l, int m, int r) {
    int i=l,j=m+1,k=0,*t=malloc((r-l+1)*sizeof(int));

    while(i<=m && j<=r) {
        c1++;
        t[k++]=(a[i]<=a[j])?a[i++]:a[j++];
    }
    while(i<=m)t[k++]=a[i++];
    while(j<=r)t[k++]=a[j++];

    for(i=l,k=0;i<=r;i++,k++) a[i]=t[k];
    free(t);
}
void ms(int a[],int l,int r) {
    if(l<r) {
        int m=(l+r)/2;
        ms(a,l,m);
        ms(a,m+1,r);
        merge(a,l,m,r);
    }
}
void merge3(int a[],int l,int m1,int m2,int r) {
    int i=l,j=m1+1,k=m2+1,p=0,*t=malloc((r-l+1)*sizeof(int));

    while(i<=m1||j<=m2||k<=r) {
        if(i<=m1 && j<=m2) {
            c2++;
            if(a[i]<=a[j]) {
                if(k<=r) {
                    c2++;
                    t[p++]=(a[i]<=a[k])?a[i++]:a[k++];
                } else t[p++]=a[i++];
            } else {
                if(k<=r) {
                    c2++;
                    t[p++]=(a[j]<=a[k])?a[j++]:a[k++];
                } else t[p++]=a[j++];
            }
        }
        else if(i<=m1 && k<=r) {
            c2++;
            t[p++]=(a[i]<=a[k])?a[i++]:a[k++];
        }
        else if(j<=m2 && k<=r) {
            c2++;
            t[p++]=(a[j]<=a[k])?a[j++]:a[k++];
        }
        else if(i<=m1)t[p++]=a[i++];
        else if(j<=m2)t[p++]=a[j++];
        else t[p++]=a[k++];
    }
    for(i=l,p=0;i<=r;i++,p++)a[i]=t[p];
    free(t);
}
void ms3(int a[],int l,int r) {
    if(l<r) {
        int n=r-l+1,m1=l+n/3-1,m2=l+2*n/3-1;

        if(m1<l)m1=l;
        if(m2<m1)m2=m1;

        ms3(a,l,m1);
        ms3(a,m1+1,m2);
        ms3(a,m2+1,r);
        merge3(a,l,m1,m2,r);
    }
}
void createPlotFile()
{
    FILE *p = fopen("plot.gnu", "w");

    if (p == NULL)
    {
        printf("Error creating plot.gnu file.\n");
        return;
    }

    fprintf(p, "set title 'Merge Sort vs Modified Merge Sort'\n");
    fprintf(p, "set xlabel 'Number of elements (n)'\n");
    fprintf(p, "set ylabel 'Number of Comparisons'\n");
    fprintf(p, "set grid\n");
    fprintf(p, "set key left top\n");

    fprintf(p,
            "plot 'data.txt' using 1:2 with linespoints title 'Merge Sort', "
            "'data.txt' using 1:3 with linespoints title 'Modified Merge Sort'\n");

    fprintf(p, "pause -1\n");

    fclose(p);
}
int main() {
    int max,n,i;
    FILE *f;

    srand(time(NULL));

    printf("Enter maximum value of n: ");
    scanf("%d",&max);

    f=fopen("data.txt","w");

    printf("\n n\tMerge Sort\tModified Merge Sort\n");
    for(n=100;n<=max;n+=100) {
        int *a=malloc(n*sizeof(int));
        int *b=malloc(n*sizeof(int));

        for(i=0;i<n;i++)
            a[i]=b[i]=rand()%RAND_MAX;

        c1=c2=0;
        ms(a,0,n-1);
        ms3(b,0,n-1);

        printf("%d\t%lld\t\t%lld\n",n,c1,c2);
        fprintf(f,"%d %lld %lld\n",n,c1,c2);
        free(a);
        free(b);
    }
    fclose(f);

createPlotFile();

printf("\nOpening GNUPlot...\n");

system("\"C:\\Program Files\\gnuplot\\bin\\wgnuplot.exe\" plot.gnu");

return 0;
}