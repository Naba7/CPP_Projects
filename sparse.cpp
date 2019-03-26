//prog 6.2
#include<stdio.h>
main()
{
    int a[100][100],b[100][100];
    int i,m,n,j,z=1,c=0;
    printf("enter the order of the matrix");
    scanf("%d %d",&m,&n);

    printf("enter the elements");
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                b[z][0]=i;
                b[z][1]=j;
                b[z][2]=a[i][j];
                z++;c++;
            }
        }
    }
    b[0][0]=m;
    b[0][1]=n;
    b[0][2]=c;
     for (i=0;i<=(c);i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d \t",b[i][j]);
        }
        printf("\n");
    }
}
