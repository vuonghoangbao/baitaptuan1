#include <conio.h>
#include <string.h>
#include <stdio.h>
struct sinhvien{
	char tensv[100];
	char masv[70];
	char tenmh[50];
	float diemmh;
};
struct node
	{
		sinhvien m;
		node *pNext;
	};
struct list
	{
		node *phead;
		node *ptail;
	};
void nhap(sinhvien &n)
{
    printf("Ten SV: ");
	 fflush(stdin);
    gets(n.tensv);
    printf("MSV: "); 
	fflush(stdin);
    gets(n.masv);
    printf("Ten mon hoc: ");
	fflush(stdin);
    gets(n.tenmh);
    printf("Diem mon hoc: "); 
	fflush(stdin);
    scanf("%f",&n.diemmh);
}
void xuat(sinhvien n)
{
	printf("Ten: ");
	puts(n.tensv);
    printf("MSV: ");
	puts(n.masv);
    printf("Ten mon: ");
	puts(n.tenmh);
    printf("Diem: %.2f",n.diemmh);
	printf("\n");
}
node* createnode(sinhvien n)
{
	node* pnode;
	pnode = new node;
	if (pnode==NULL)
		return NULL;
	pnode->m=n;
	pnode->pNext=NULL;
	return pnode;
}
void addhead(list &l,sinhvien n)
{
	node *pnode;
	pnode=createnode(n);
	if (l.phead==NULL)
	{
		l.phead=l.ptail=pnode;
	}
	else
	{
		pnode->pNext=l.phead;
		l.phead=pnode;
	}
}
void XuatDS(list l)
{
	node *pnode;
	pnode=l.phead;
	while (pnode!=NULL)
	{
		xuat(pnode->m);
		printf("\n");
		pnode=pnode->pNext;
	}
}
float max(list l)
{
	node *pnode;
	float max;
	pnode=l.phead;
	max=pnode->m.diemmh;
	while (pnode!=NULL)
	{
		if (max<pnode->m.diemmh)
			max=pnode->m.diemmh;
		pnode=pnode->pNext;	
	}
	return max;
}
float min(list l)
{
	node *pnode;
	float min;
	pnode=l.phead;
	min=pnode->m.diemmh;
	while (pnode!=NULL)
	{
		if (min>pnode->m.diemmh)
			min=pnode->m.diemmh;
		pnode=pnode->pNext;
	}
	return min;
}
int main()
{
	sinhvien sv[70];
	list l;
	l.phead=l.ptail=NULL;
	int n;
	printf("Nhap so sv: ");scanf("%d",&n);
	printf("Nhap thong tin sv: \n");
	for (int i=0;i<n;i++)
	{
		printf("Sinh vien %d",i+1);printf(":\n");
		nhap(sv[i]);
		addhead(l,sv[i]);
	}
	printf("\n------------------------------------\n");
	printf("Danh sach sv: \n");
	for (int i=0;i<n;i++)
	{
		printf("Sinh vien %d",i+1);
		xuat(sv[i]);
	}
	printf("\n------------------------------------\n");
	printf("Diem cao nhat: %.1f",max(l));
	printf("\nDiem that nhat: %.1f",min(l));
	return 0;
}
