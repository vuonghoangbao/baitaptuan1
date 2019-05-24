#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct node {
   int data;   
   struct node *leftChild;
   struct node *rightChild;
};
typedef node *binarytree;
void initializethetree(binarytree &s)
{
	s=NULL;
}
void  addnodetobinarytree(binarytree &s,int a)
{
	if(s==NULL)
	{
		node *p= new node;
		p->data=a;
		p->leftChild=NULL;
		p->rightChild=NULL;
		s=p;
	}else
	{
		if(s->data>a)
		{
			 addnodetobinarytree(s->leftChild,a);
		}
		else if(s->data<a)
		{
		 addnodetobinarytree(s->rightChild,a);
		}
	}
}
// duyet cay 
// Node -Left -Right
void NLR(binarytree s)
{
   if(s!=NULL)
   {
      printf("%d", s->data);
      NLR(s->leftChild);
      NLR(s->rightChild);
   }
}
// Left -Node -Right

void LNR(binarytree s)

{
   if(s!=NULL)
   {
      LNR(s->leftChild);
      printf("%d", s->data);
      LNR(s->rightChild);
   }
}

// Left - Right -Node

void LRN(binarytree s)

{
   if(s!=NULL)
   {
      LNR(s->leftChild);
      printf("%d", s->data);
      LNR(s->rightChild);
   }
}
void Replace(binarytree &m, binarytree &n)
{
    
    if(n->leftChild!=NULL){
        Replace(m,n->leftChild);
    }
    else {
        m->data = n->data;
        m=n;
        n=n->rightChild;
    }

}
void deleterootbuttonNode(binarytree &s,int data)
{
	if(s==NULL)
	{
		return;
	}
	else 
	{
		if(data < s->data)
		{
			deleterootbuttonNode(s->leftChild,data);
		}else if(data > s->data)
		{
			deleterootbuttonNode(s->rightChild,data);
		}else
		{
			node *p=s;
			if(s->leftChild==NULL)
			{
				s=s->rightChild;
			}
			else if(s->rightChild==NULL)
			{
				s=s->leftChild;
			}
			else 
			{
				Replace(p,s->rightChild);	
			}
			delete p;
		}
	}
}
// dem so node co 2 con
int countnode(binarytree b)
{
   if (b!=NULL) 
	{ 
      if( b->leftChild != NULL && b->rightChild  != NULL)
        {
            printf("%d ",b->data);
	    }
        countnode(b->leftChild);
        countnode(b->rightChild);
        return 0;
   }
}
//tong so node le 
int oddbutton(binarytree c)
{
	if (c!=NULL)
	{
		int a = oddbutton(c->leftChild);
		int b = oddbutton(c->rightChild);
		if(c->data % 2 != 0) 
		{
		  	return c->data + a + b;
		} 
		
		return a + b;
        
	}
	return 0;
}
// tong so node chan
int evenbutton(binarytree c)
{
   if (c!=NULL)
	{
		int a=evenbutton(c->leftChild);
		int b=evenbutton(c->rightChild);
		if(c->data % 2 == 0)
		{
			return c->data + a + b;
		}
		return a + b;
	}
	return 0;
}
bool listprimenumbers (int x)
{
	if(x<2)
	{
		return false;
	}
	else if(x==2)
	{
		return true;
	}
	else if(x%2==0)
	{
		return false;
	}
	else
	{
		for(int i=2;i<x;i++)
		{
			if(x%i==0)
			{
				return false;
			}
		}
	}
	return true;
}
// liet ke va tinh tong prime
int prime (binarytree p)
{
	if(p!=NULL)
	{
		int a=prime(p->leftChild);
		int b=prime(p->rightChild);
		if( listprimenumbers (p->data) == true)
		{
			printf("so nguyen to: %d \n",p->data);
			return p->data+a+b;
		}
		
	
			return a+b;
	}
	return 0;
}
int main()
{
	// khai bao cay
	binarytree s;
	initializethetree(s);
	while (true)
	{
		system("cls");
		printf("\n1. Nhap du lieu");
		printf("\n2. Xuat cay NLR");
		printf("\n3. Xuat cay LNR");
		printf("\n4. Xuat cay LRN");
		printf("\n5. Xoa 1 phan tu trong cay ");
		printf("\n6. xuat ra phan tu co 2 con");
		printf("\n7. xuat ra tong chan, tong le trong cay");
		printf("\n8. liet ke cac so nguyen to và tinh tong");
		printf("\n0. Ket thuc");
		int n;
		printf("\nNhap lua chon: ");
		scanf("%d",&n);
		if (n < 0 || n > 9)
		{
			printf("\nNhap sai lua chon");
			getch();
		}
		else if (n == 1)
		{
			int x;
			printf("\nNhap phan tu x: ");
			scanf("%d",&x);
			addnodetobinarytree(s, x);
		}
		else if (n == 2)
		{
			NLR(s);
			getch();
		}
		else if (n == 3)
		{
			LNR(s);
			getch();
		}
		else if (n == 4)
		{
			LRN(s);
			getch();
		}
		else if (n == 5)
		{
			int x;
			printf("\nPhan tu muon xoa: ");
			scanf("%d",&x);
			deleterootbuttonNode(s,x);
		}
		else if (n == 6)
		{
			printf("\nxuat phan tu co 2 con");
			countnode(s);
			getch();
		}
		else if (n == 7)
		{
			printf("\nxuat ra tong chan, tong le trong cay");
			printf("%d ",evenbutton(s));
			printf("%d ",oddbutton(s));
			getch();
		}
		else if (n == 8)
		{
			printf("\nliet ke cac so nguyen to và tinh tong");
		    printf("%d ", prime(s));
			getch();
		}
		else
		{
			break;
		}
	}
	getch();
	return 0;
}
