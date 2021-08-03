#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <map>
using namespace std;
const int n=105;
int type;

//﹍竚传 
int IP[] =     
{
    58 , 50 , 42 , 34 , 26 , 18 , 10 ,  2 ,
    60 , 52 , 44 , 36 , 28 , 20 , 12 ,  4 ,
    62 , 54 , 46 , 38 , 30 , 22 , 14 ,  6 ,
    64 , 56 , 48 , 40 , 32 , 24 , 16 ,  8 ,
    57 , 49 , 41 , 33 , 25 , 17 ,  9 ,  1 ,
    59 , 51 , 43 , 35 , 27 , 19 , 11 ,  3 ,
    61 , 53 , 45 , 37 , 29 , 21 , 13 ,  5 ,
    63 , 55 , 47 , 39 , 31 , 23 , 15 ,  7
};

/*---ネΘ盞芲---*/
 
int KP[56] =    //盞芲竚传 64锣56 
{
    57 , 49 , 41 , 33 , 25 , 17 ,  9 ,  1 ,
    58 , 50 , 42 , 34 , 26 , 18 , 10 ,  2 ,
    59 , 51 , 43 , 35 , 27 , 19 , 11 ,  3 ,
    60 , 52 , 44 , 36 , 63 , 55 , 47 , 39 ,
    31 , 23 , 15 ,  7 , 62 , 54 , 46 , 38 ,
    30 , 22 , 14 ,  6 , 61 , 53 , 45 , 37 ,
    29 , 21 , 13 ,  5 , 28 , 20 , 12 ,  4
};

int CP[48] =    //溃罽竚传 56锣48盞芲 
{
    14 , 17 , 11 , 24 ,  1 ,  5 ,  3 , 28 ,
    15 ,  6 , 21 , 10 , 23 , 19 , 12 ,  4 ,
    26 ,  8 , 16 ,  7 , 27 , 20 , 13 ,  2 ,
    41 , 52 , 31 , 37 , 47 , 55 , 30 , 40 ,
    51 , 45 , 33 , 48 , 44 , 49 , 39 , 56 ,
    34 , 53 , 46 , 42 , 50 , 36 , 29 , 32
};

int KM[16] =     //盞芲–近簿 
{
    1 ,  1 ,  2 ,  2 ,  2 ,  2 ,  2 ,  2 ,
    1 ,  2 ,  2 ,  2 ,  2 ,  2 ,  2 ,  1
};

/*---盞絏ㄧ计---*/

int EP[48] =    //耎甶竚传 
{
    32 ,  1 ,  2 ,  3 ,  4 ,  5 ,  4 ,  5 ,
    6 ,  7 ,  8 ,  9 ,  8 ,  9 , 10 , 11 ,
    12 , 13 , 12 , 13 , 14 , 15 , 16 , 17 ,
    16 , 17 , 18 , 19 , 20 , 21 , 20 , 21 ,
    22 , 23 , 24 , 25 , 24 , 25 , 26 , 27 ,
    28 , 29 , 28 , 29 , 30 , 31 , 32 ,  1
};

int S_box[8][4][16] =      //S舶 
{
    
    {   {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
        {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
        {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
        {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
    },
    
    {   {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
        {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
        {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
        {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
    },
    
    {   {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
        {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
        {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
        {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
    },
    
    {   {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
        {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
        {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
        {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
    },
    
    {   {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
        {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
        {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
        {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
    },
    
    {   {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
        {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
        {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
        {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
    },
    
    {   {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
        {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
        {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
        {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
    },
    
    {   {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
        {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
        {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
        {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
    }
};

int PP[32] =     //P舶 
{
    16 ,  7 , 20 , 21 , 29 , 12 , 28 , 17 ,
    1 , 15 , 23 , 26 ,  5 , 18 , 31 , 10 ,
    2 ,  8 , 24 , 14 , 32 , 27 ,  3 ,  9 ,
    19 , 13 , 30 ,  6 , 22 , 11 ,  4 , 25
};

int FP[64] =      //Ю竚传
{
    40 ,  8 , 48 , 16 , 56 , 24 , 64 , 32 ,
    39 ,  7 , 47 , 15 , 55 , 23 , 63 , 31 ,
    38 ,  6 , 46 , 14 , 54 , 22 , 62 , 30 ,
    37 ,  5 , 45 , 13 , 53 , 21 , 61 , 29 ,
    36 ,  4 , 44 , 12 , 52 , 20 , 60 , 28 ,
    35 ,  3 , 43 , 11 , 51 , 19 , 59 , 27 ,
    34 ,  2 , 42 , 10 , 50 , 18 , 58 , 26 ,
    33 ,  1 , 41 ,  9 , 49 , 17 , 57 , 25
};

vector <string> v;
map<char ,string> mp;
map<string ,char> mt;
char key[n],a[n],b[n];

void initial()
{
    mp['0']="0000";mp['1']="0001";mp['2']="0010";mp['3']="0011";
    mp['4']="0100";mp['5']="0101";mp['6']="0110";mp['7']="0111";
    mp['8']="1000";mp['9']="1001";mp['a']="1010";mp['b']="1011";
    mp['c']="1100";mp['d']="1101";mp['e']="1110";mp['f']="1111";
    for(map<char,string>::iterator it=mp.begin(); it!=mp.end(); it++)  mt[it->second]=it->first;
}

//1616秈锣传Θ642秈 
string change(char t[])   
{
    string st;
    for(int i=1; i<=16; i++)  st=st+mp[t[i]];
    return st;
}

//碻吏オ簿num
string LOR(string st,int num)    
{
    for(int i=0; i<num; i++)
    {
        char ch=st[0];
        st.erase(st.begin());
        st=st+ch;
    }
    return st;
}

//char int 锣传 
char get_char(int num)    
{
    if(num<=9)  return num+'0';
    else  return 'a'+num-10;
}

int get_num(char ch)       
{
    if(ch>='0' && ch<='9')  return ch-'0';
    else  return ch-'a'+10;
}

// XOR 
string XOR(string ty,string tx)   
{
    int len=ty.size();
    string p;
    for(int i=0; i<len; i++)
    {
        int a=ty[i]-'0',b=tx[i]-'0';
        p.push_back(a^b+'0');
    }
    return p;
}

// ㄧ计f
string F(string R,string K)    
{
    string r,p,ty,tx;
    for(int i=0; i<48; i++)  r.push_back(R[EP[i]-1]);
    p=XOR(r,K);
    for(int i=0,j=0; i<48; i+=6,j++)
    {
        string tp=p.substr(i,6);
        string u=tp.substr(1,4);
        int a=(tp[0]-'0')*2+tp[5]-'0',b=get_num(mt[u]);
        int c=S_box[j][a][b];
        string tmp=mp[get_char(c)];
        ty=ty+tmp;
    }
    for(int i=0; i<32; i++)  tx.push_back(ty[PP[i]-1]);
    return tx;
}

void input()
{
	printf("Input(1) to Encrypt, (2) to Decrypt: ");
	scanf("%d", &type);
	switch(type)
	{
		case 1:
			v.clear();
		    printf("Please input a plaintext(Hexadecimal 64-bit): ");
		    scanf("%s",a+1);
		    getchar();
		    printf("\nPlease input a key(Hexadecimal 64-bit): ");
		    scanf("%s",key+1);
		    break;
		case 2:
		    v.clear();
		    printf("Please input a ciphertext(Hexadecimal 64-bit): ");
		    scanf("%s",a+1);
		    getchar();
		    printf("\nPlease input a key(Hexadecimal 64-bit): ");
		    scanf("%s",key+1);
		    break;
	}
    
}

void get_key()     
{
    string s=change(key);
    string l,r,lr;
    for(int i=0; i<56; i++)
    {
        if(i<28) l.push_back(s[KP[i]-1]);
        else  r.push_back(s[KP[i]-1]);
    }
    for(int i=0; i<16; i++)
    {
        l=LOR(l,KM[i]);
        r=LOR(r,KM[i]);
        string str=l+r,st,k;
        for(int j=0; j<48; j++) st.push_back(str[CP[j]-1]);
        v.push_back(st);
    }
}

void DES_encrypt()
{
    string s=change(a);
    string d_s,l,r,a,b,t,ans,tmp;

    for(int i=0; i<64; i++)  d_s.push_back(s[IP[i]-1]);
    for(int i=0; i<64; i++)
    {
        if(i<32)  l.push_back(d_s[i]);
        else  r.push_back(d_s[i]);
    }
    for(int i=0; i<16; i++)
    {
        cout << "Round " << dec << i + 1 << endl;
        a=r;
        if(type == 1)	b=XOR(l,F(r,v[i]));
        else			b=XOR(l,F(r,v[15-i]));
        l=a;
        r=b;
        bitset<32> left(a);
        bitset<32> right(b);
        cout << "\tLeft: " << hex << left.to_ulong();
        cout << " Right: " << hex << right.to_ulong();
        cout << endl;
    }
    swap(l,r);
    tmp=l+r;
    for(int i=0; i<64; i++)  ans.push_back(tmp[FP[i]-1]);
    cout<<endl<<"The Ciphertext is :  ";
    for(int i=0; i<64; i+=4)
    {
        string now=ans.substr(i,4);
        cout<<mt[now];
    }
    cout<<endl;
}

int main()
{
    initial();
    input();
    get_key();
    DES_encrypt();
    return 0;
}
