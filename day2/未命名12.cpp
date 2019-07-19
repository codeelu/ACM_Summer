#include<stdio.h>
#include<string.h>
int main()
{
    int s[550],book[550][550],num[550];
    int i,j,k,l,n,m,a,b,h;
    while(~scanf("%d %d",&n,&m))
    {
        l=0;
        memset(s,0,sizeof(s));
        memset(book,0,sizeof(book));
        memset(num,0,sizeof(num));
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&a,&b);
            if(book[a][b]==0)
            {
                    s[b]++;
                    book[a][b]=1;
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(s[j]==0)
                {
                    k=j;
                    break;
                }
            }
            num[l++]=k;
            s[k]=-1;
            for(h=1; h<=n; h++)
            {
                if(book[k][h])
                    s[h]--;
            }
        }
        printf("%d",num[0]);
        for(i=1; i<n; i++)
            printf(" %d",num[i]);
       printf("\n");
    }
    return 0;
}

