#include <iostream>
#include <stdio.h>
#include<math.h>
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


int* D2B(int k,int test[],int z){		//十進位轉二進位 
			int w=0;
			while(z>0)   
    		{
        		test[w]=z%2;
        		w++;
        		z=z/2;
        		
    		}
	
		int lon;
		for(lon=w;lon<k;lon++) test[lon]=0; //補 0 到 k 位 
	
		int temp;                  
    	int cou;
    	for(cou=0;cou<k/2;cou++) 			//反轉陣列 
    	{
        	temp=test[cou];
        	test[cou]=test[k-1-cou];
        	test[k-1-cou]=temp;
    	}
    	/*for(lon=0;lon<k;lon++)printf("%d ",test[lon]);
    	printf("\n");*/
    	return test;
    	
}

int compare(int z,int count[],int min,int max){		//找出最大跟最小 

	for(int i=0;i<=z;i++)
	if (count[z]<min)
		min=count[z];
	else if(count[z]>max)
		max=count[z];	
			
	int dif=max-min;
	return dif;
}

int main()
{
	int s,p,q,n,x[8000],binary[8000],t;    
  	
  	printf("輸入第一個質數 p :");
  	scanf("%d",&p);
    int flag = prime(p);
    if ((flag == 0)||(p%4) != 3) 
    {
        printf("錯誤的輸入\n");
        exit(1);
    }
    
    printf("\n輸入第二個質數 q :");
  	scanf("%d",&q);
    flag = prime(q);
    if (flag == 0 || p == q || (q%4) != 3)
    {
        printf("錯誤的輸入\n");
        exit(1);
    }
    
    n=p*q;
    t=(p-1)*(q-1);    
    
  	printf("\n輸入 s :");
  	scanf("%d",&s);
  	
    if(coprime(s,n)!=1){
	printf("錯誤的輸入\n");
    exit(1);
	}
	
	x[0]=(s*s)%n;
	binary[0]=x[0]%2;
	
	for(int k=1;k<=8;k++){
	int ll=1000*k;
	printf("\n\n產生長度為%d的Binary string:\n\n",ll);
		for(int i=1;i<=ll;i++){
			x[i]=(x[i-1]*x[i-1])%n;
			binary[i]=x[i]%2;
			printf("%d",binary[i]); 
		}
	int max,min;
	//0~2^k-1之間的數字出現的機率中最大者與最小值之差
	int j,w=0,test[k];
	j=pow(2,k)-1;
	
	printf("\n\n以%dbits為一個單位的分析:\n\n",k);
	
	//int src[10] = {1,1,1,0,0,1,0,0,0,1};//測試用
	int count[j+1];
	int difference[j];
	int l;
	for(int z=0;z<=j;z++){
	D2B(k,test,z);//test長度為k 
	
	//出現次數計算 
	int a=0,b=0; 
	count[z]=0;
	//min max每跑一輪都會重新整理 
    while(a<ll){
    	while((binary[a]==test[b])&&(a<ll)) {
			if(b==(k-1)){
				count[z]++;a++;b=0;
				break;
			}
			else {
				a++;b++;
			}
		}
	
	if((binary[a]!=test[b])&&(binary[a]==test[0])) b=0;
	else if(binary[a]!=test[b]) {
		a++;b=0;
	}
	}
	min=count[0];
	max=count[0];
	for(int lon=0;lon<k;lon++) printf("%d",test[lon]);
	printf("出現%d次\n\n",count[z]);
    l=z;
   	
}
	float di;
    di=compare(l,count,min,max);
	printf("差值為%f\n",di/k);
}
}
