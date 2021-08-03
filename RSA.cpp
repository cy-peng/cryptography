#include <iostream>
#include <stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>

int prime(unsigned long a)                 //�P�_�O�_����� 
{
    int i;
    int j = sqrt(a);
    for (i = 2; i <= j; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;							//��� 
}

int coprime(unsigned long x,unsigned long y)              //�P�_�O�_����
{
	int temp;
 	while(y)
 	{
    	temp=x;
    	x=y;
    	y=temp%y;
 	}
	if(x != 1) return 0;                    
	else return 1;                          //���� 
}

int mod(unsigned long a,unsigned long b,unsigned long c)       //���l�p�� 
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
  	
  	printf("��J�Ĥ@�ӽ�� p :");
  	scanf("%d",&p);
    int flag = prime(p);
    if (flag == 0)
    {
        printf("���~����J\n");
        exit(1);
    }
    
    printf("\n��J�ĤG�ӽ�� q :");
  	scanf("%d",&q);
    flag = prime(q);
    if (flag == 0 || p == q)
    {
        printf("���~����J\n");
        exit(1);
    }
    n=p*q;
    t=(p-1)*(q-1);    
    
  while(1)
  {
  	
      printf("\n1:�[�K  2:�ѱK  3:�H�üƲ��ͪ��_ e:");   //�[�K�θѱK���
      scanf("%d",&r);
      
      switch(r)
      {
        case 1: printf("\n�п�J���� M : ");       
                scanf("%d",&m);
                
                printf("\n��J�[�K�����_ e :");
  				scanf("%d",&e);
  				if((coprime(e,t))==0)
  				{
        			printf("���~����J\n");
        			exit(1);
    			}
    			
    			d=1;
  				while(((e * d) % t) != 1)					// �D�X���_ d
  				{
    				d++;                 
  				}
  				printf("\n�ѱK�����_ d �� %d",d);
  				
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
                printf("\n\n�[�K�����L�{: \n\n");
                ciphertext[m_i] = mod(m,e,n);
                    
  				
                printf("\n�[�K�᪺�K�嬰 :");
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
                
  				printf("\n�ѱK�����L�{: \n\n"); 
                mod(ciphertext[m_j],d,n);
                printf("\n�ѱK�᪺���嬰:");
                for(int i = m_j ; i >= 0 ;i--)
                {
                    printf("%d",plaintext[i]);
                }
                printf("\n");
                break;
        
        case 3: printf("\n�п�J���� M : ");       
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
				
				printf("\n�üƲ��ͪ����_e��:%d",random_e);
					d=1;
  					while(((random_e * d) % t) != 1)					// �D�X���_ d
  					{
    					d++;                 
  					}
  				printf("\n\n�ѱK�����_ d �� %d",d);
  				
  				printf("\n\n�[�K�����L�{: \n");
                ciphertext[m_i] = mod(m,random_e,n);
                
                printf("\n�[�K�᪺�K�嬰 :");
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
                
  				printf("\n�ѱK�����L�{: \n\n"); 
                mod(ciphertext[m_j],d,n);
                printf("\n�ѱK�᪺���嬰:");
                for(int i = m_j ; i >= 0 ;i--)
                {
                    printf("%d",plaintext[i]);
                }
                printf("\n");
                
            	break;
      }
    }
}
