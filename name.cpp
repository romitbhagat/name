#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Node
{
	public:
		int data;
		Node * next;
		
		Node()
		{
			data = 0;
			next = NULL;
		}
		Node(int x)
		{
			data = x;
			next = NULL;
		}
};
class SLL
{
	Node * head;
	
	public:
		SLL()
		{
			head = NULL;
		}
		void create()
		{
			int n;
			cout<<"\nHow many nodes you want create = ";
			cin>>n;
			cout<<"\nEnter data for first Node = ";
			int x;
			cin>>x;
			head = new Node(x);
			Node * p;
			p = head;
			int i;
			for(i=1;i<=n-1;i++)
			{
				cout<<"\nEnter data = ";
				cin>>x;
				p->next= new Node(x);
				p=p->next;
			}
			cout<<"\nList crated ";
		}
		void show()
		{
			Node * p;
			p = head ;
			while(p!=0)
			{
				cout<<"    "<<p->data;
				p=p->next;
			}
		}
		int search(int x)
		{
			Node * p;
			p = head;
			while(p!=NULL)
			{
				if(p->data == x)
				{
					return 1;
				}
				p=p->next;
			}
			return 0;
		}
		void addatbeg(int x)
		{
			Node * p;
			p = new Node(x);
			p->next = head;
			head = p;
			p = head;
			cout<<"\nafter adding data at beginng = ";
			while (p!=NULL)
			{
				cout<<"    "<<p->data;
				p = p->next;
			}
		}
		void addatend(int x)
		{
			Node * p = head;
			Node * q;
			q = new Node(x);
			while(p->next!=NULL)
			{
				p = p->next;
			}
			p->next = q;
		/*	p = head;
			cout<<"\nData after add at end  = ";
			while(p!=NULL)
			{
				cout<<"   "<<p->data;
				p=p->next;
			}*/
		}
		int count()
		{
			Node * p = head;
			int c = 0;
			while(p!=NULL)
			{
				c++;
				p = p->next;
			}
			return c;
		}
		void addbypos(int pos, int x)
		{
			Node * p;
			p = head;
			int n;
			n = count();
			if(pos<1 || pos > n)
			{
				cout<<"\nposition is not valid";
			}
			if(pos == 1)
			{
				addatbeg(x);
			}
			else
			{
				Node *p , *q;
				q = new Node(x);
				p = head;
				int i;
				for(i=1;i<pos -1;i++)
				{
					p = p->next;
				}
				q->next = p->next;
				p->next = q;
			}
			cout<<"\n data after add by position = ";
			p = head ;
			while(p!=NULL)
			{
				cout<<"   "<<p->data;
				p = p->next;
			}
		}
		void delatbeg()
		{
			if(head == NULL)
			{
				cout<<"\nList empty ";
			}
			if(head->next == NULL)
			{
				delete head;
				head = NULL;	
			}
			else
			{
				Node * p;
				p = head;
				head = head->next;
				delete p;
			}
			Node * p = head;
			cout<<"\nAfter delteing data = ";
			while(p!=NULL)
			{
				cout<<"   "<<p->data;
				p = p->next;
			}
		}
		void delatend()
		{
			Node*p,*q;
			if(head == NULL)
			{
				cout<<"list empty";
				return ;
			}
			if(head->next == NULL)
			{
				delete head;
				head = NULL;
			}
			else
			{
				p=head;
				q=NULL;
				while(p->next!=NULL)
				{
					q=p;
					p=p->next;
				}
				q->next = NULL;
				delete p;
			}
			p=head;
			cout<<"\nafter deleting data at end = ";
			while(p!=NULL)
			{
				cout<<"   "<<p->data;
				p = p->next;
			}
		}
		void delbypos(int pos)
		{
			int n;
			n = count();
			if(pos<1 || pos>n)
			{
				cout<<"\n Invalid position ";
			}
			if(pos == 1)
			{
				delatbeg(); 
			}
			else
			{
				Node *p,*q;
				p=head;
				q=NULL;
				int i;
				for(i=1;i<pos-1;i++)
				{
					p=p->next;
				}
				q=p->next;
				p->next = q->next;
				delete q;
			}
			Node * p=head;
			cout<<"\nAfter deleting at given position = ";
			while(p!=NULL)
			{
				cout<<"    "<<p->data;
				p=p->next;
			}
		}
		void Asorting()
		{
			Node *i,*j;
			for(i=head;i!=NULL;i=i->next)
			{
				for(j=i->next;j!=NULL;j=j->next)
				{
					if(i->data > j->data)
					{
						int temp;
						temp= i->data;
						i->data = j->data;
						j->data = temp;
					}
				}
			}
			Node * p=head;
			cout<<"\nAfter ascending order data = ";
			while(p!=NULL)
			{
				cout<<"   "<<p->data;
				p = p->next;
			}
		}
		void Dsorting()
		{
			Node *i,*j;
			for(i=head;i!=NULL;i=i->next)
			{
				for(j=i->next;j!=NULL;j=j->next)
				{
					if(i->data < j->data)
					{
						int temp;
						temp= i->data;
						i->data = j->data;
						j->data = temp;
					}
				}
			}
			Node * p=head;
			cout<<"\nAfter Descending order data = ";
			while(p!=NULL)
			{
				cout<<"   "<<p->data;
				p = p->next;
			}
		}
		void create_1()
		{
			int x;
			cout<<"\nKeep entering Data or -1 to STOP = ";
		
			while(1)
			{
				cout<<"\nEnter data = ";
				cin>>x;
				if(x==-1)
				{
					break;
				}
				addatend(x);
			}
		    show();
		}
		void create_2()
		{
			char str[10];
			int x;
			cout<<"\nKeep entering data or STOP to stop = ";
			while(1)
			{
				cin.getline(str,10);
				if(strcmp(str,"STOP")==0)
				{
					break;
				}
				x=atoi(str);
				addatend(x);
			}
			show();
		}
};
int main()
{
   SLL Obj;
   
   Obj.create();
   cout<<"\nYou entered = ";
   Obj.show();
   int x;
   cout<<"\nEnter data to search = ";
   cin>>x;
   int res;
   res = Obj.search(x);	
   if(res == 1)
   {
   		cout<<"\nData found";
   }
   else 
   {
		cout<<"\nData not found ";	   	
   }
   cout<<"\nEnter data to add at begining = ";
   cin>>x;
   Obj.addatbeg(x);
   cout<<"\nEnter data to add at end = ";
   cin>>x;
   Obj.addatend(x);
   cout<<"\nEnter position to add data = ";
   int pos;
   cin>>pos;
   cout<<"\nEnter data to add = ";
   cin>>x;
   Obj.addbypos( pos ,  x);
   Obj.delatbeg();
   Obj.delatend();
   cout<<"\nEnter position to delete data = ";
   cin>>pos;
   Obj.delbypos(pos);
   Obj.Asorting();
   Obj.Dsorting();
   Obj.create_1();
   Obj.create_2();
   
 
}