#include <iostream>
#include <stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>

int prime(unsigned long a)                 //判斷是否為質數 
{
    int i;
    int j = sqrt(a);
    for (i = 2; i <= j; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;							//質數 
}

int coprime(unsigned long x,unsigned long y)              //判斷是否互質
{
	int temp;
 	while(y)
 	{
    	temp=x;
    	x=y;
    	y=temp%y;
 	}
	if(x != 1) return 0;                    
	else return 1;                          //互質 
}

int mod(unsigned long a,unsigned long b,unsigned long c)       //取餘計算 
{ 		
	int q,r=1,s;
  	b=b+1;
  	s=b;
  	while(b!=1)
  	{
    	r=r*a; 
    	r=r%c;
    	b--;
    	q=s-b;
    	printf("\t%d^%dmod%d=%d \n\n",a,q,c,r);
  	}
  	return r;
}

int main()
{
	unsigned long p,q,e,d,m,n,t,c,r,m_t=0,m_i,m_j,random_e;
  	unsigned long plaintext[100],ciphertext[100];     
  	
  	printf("輸入第一個質數 p :");
  	scanf("%d",&p);
    int flag = prime(p);
    if (flag == 0)
    {
        printf("錯誤的輸入\n");
        exit(1);
    }
    
    printf("\n輸入第二個質數 q :");
  	scanf("%d",&q);
    flag = prime(q);
    if (flag == 0 || p == q)
    {
        printf("錯誤的輸入\n");
        exit(1);
    }
    n=p*q;
    t=(p-1)*(q-1);    
    
  while(1)
  {
  	
      printf("\n1:加密  2:解密  3:以亂數產生金鑰 e:");   //加密或解密選擇
      scanf("%d",&r);
      
      switch(r)
      {
        case 1: printf("\n請輸入明文 M : ");       
                scanf("%d",&m);
                
                printf("\n輸入加密的金鑰 e :");
  				scanf("%d",&e);
  				if((coprime(e,t))==0)
  				{
        			printf("錯誤的輸入\n");
        			exit(1);
    			}
    			
    			d=1;
  				while(((e * d) % t) != 1)					// 求出金鑰 d
  				{
    				d++;                 
  				}
  				printf("\n解密的金鑰 d 為 %d",d);
  				
                m_i = 0;
                while(m / 100)
                {
                    m_t = m % 100;
                    plaintext[m_i] = m_t;
                    ciphertext[m_i] = mod(m_t,e,n);
                    m /= 100;
                    m_i++;
                }
                plaintext[m_i] = m;
                printf("\n\n加密的的過程: \n\n");
                ciphertext[m_i] = mod(m,e,n);
                    
  				
                printf("\n加密後的密文為 :");
                for(int i = 0 ; i <= m_i ;i++)
                {
                    printf("%d ",ciphertext[i]);
                }
                printf("\n");
                break;
                
        case 2: m_j = 0;
                while(m_i--)
                { 
                   plaintext[m_j] = mod(ciphertext[m_j],d,n);
                   m_j++;
                }
                
  				printf("\n解密的的過程: \n\n"); 
                mod(ciphertext[m_j],d,n);
                printf("\n解密後的明文為:");
                for(int i = m_j ; i >= 0 ;i--)
                {
                    printf("%d",plaintext[i]);
                }
                printf("\n");
                break;
        
        case 3: printf("\n請輸入明文 M : ");       
                scanf("%d",&m);
                m_i = 0;
                while(m / 100)
                {
                    m_t = m % 100;
                    plaintext[m_i] = m_t;
                    ciphertext[m_i] = mod(m_t,e,n);
                    m /= 100;
                    m_i++;
                }
				plaintext[m_i] = m;
				while(1){
        		random_e=rand()%t;//1<random_e<t
				if(random_e!=1&&(coprime(random_e,t)==1))break;
				}	
				
				printf("\n亂數產生的金鑰e為:%d",random_e);
					d=1;
  					while(((random_e * d) % t) != 1)					// 求出金鑰 d
  					{
    					d++;                 
  					}
  				printf("\n\n解密的金鑰 d 為 %d",d);
  				
  				printf("\n\n加密的的過程: \n");
                ciphertext[m_i] = mod(m,random_e,n);
                
                printf("\n加密後的密文為 :");
                for(int i = 0 ; i <= m_i ;i++)
                {
                    printf("%d ",ciphertext[i]);
                }
                printf("\n");
                
                m_j = 0;
                while(m_i--)
                { 
                   ciphertext[m_j] = mod(plaintext[m_j],d,n);
                   m_j++;
                }
                
  				printf("\n解密的的過程: \n\n"); 
                mod(ciphertext[m_j],d,n);
                printf("\n解密後的明文為:");
                for(int i = m_j ; i >= 0 ;i--)
                {
                    printf("%d",plaintext[i]);
                }
                printf("\n");
                
            	break;
      }
    }
}
