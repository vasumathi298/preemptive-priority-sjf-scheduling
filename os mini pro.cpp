#include<iostream>
#include<cstdio>
#include<fstream>
#include<iomanip>
using namespace std;

typedef struct prpsjf
{
	int at,bt,ft,tat,wt,pr,id;
}prpsjf;
prpsjf p[20],p1[20],temp;

int ts;
int accept();
void prpsjfsort(int n);
void ganttprpsjf(int n);

int main()
{	
	int np;	
	np=accept();
	prpsjfsort(np);
	ganttprpsjf(np);
}

int accept()
{
	int np,i;
	ifstream infile;
	infile.open("input15.txt");	
	cout<<"The no of process: ";
	infile>>np;
	cout<<np;
	for(i=1;i<=np;i++)
	{
		cout<<"\nThe arrival time P"<<i<<": ";
		infile>>p[i].at;
		cout<<p[i].at;
		p[i].id=i;
	}
	for(i=1;i<=np;i++)
	{
		cout<<"\nThe burst time P"<<i<<": ";
		infile>>p[i].bt;
		cout<<p[i].bt;
	}
	for(i=1;i<=np;i++)
	{
		cout<<"\nThe priority for the process P"<<i<<": ";
		infile>>p[i].pr;
		cout<<p[i].pr;
	}
	for(i=1;i<=np;i++)
		p1[i]=p[i];
	cout<<"\nThe timespan: ";
	infile>>ts;
	cout<<ts;
	return np;
}

void prpsjfsort(int n)      
{
	int i,j;
	for(i=2;i<=n;i++)
		for(j=1;j<=i;j++)
			if(p[j].at>p[i].at)
	   		{
				temp=p[i];
			   	p[i]=p[j];
			    	p[j]=temp;
	   		}
	   		else if(p[j].at==p[i].at) 
	    			if(p[j].bt>p[i].bt)
	    			{
	     				temp=p[i];
	     				p[i]=p[j];
	     				p[j]=temp;
	    			}
}
                                                                         
void ganttprpsjf(int n)
{
	int i,m,min;
	int limit,nextval;
	limit=nextval=p[1].at;
	for(i=1;i<=n;i++)
		limit+=p[i].bt;
	cout<<"\n\n-------------Gantt Chart---------\n";	
	cout<<p[1].at;
	do 
	{
		min = 9999;
		for(i=1;p[i].at<=nextval && i<=n ;i++)
		{	
			if(p[i].pr<=min && p[i].bt>0)
			{
				if(p[i].pr<min)
				{				
					m=i;
					min=p[i].pr;
				}
				else if(p[i].pr==min)
				{
					if(p[m].bt>p[i].bt)
					{
						m=i;
						min=p[i].pr;
					}
				}
			}
		}
		if(p[m].bt>=ts)
			nextval=nextval+ts;	
		else
			nextval=nextval+p[m].bt;			
		cout<<"->P"<<p[m].id<<"->"<<nextval;
		if(p1[m].bt>=ts)
			p[m].bt=p[m].bt-ts;	
		else
			p[m].bt=0;
		if(p[m].bt==0)
		{
			p[m].ft=nextval;
			p[m].tat=p[m].ft-p[m].at;
			p[m].wt=p[m].tat-p1[m].bt;
			p[0].tat+=p[m].tat;
			p[0].wt+=p[m].wt;
		}
	}while(nextval<limit);
	p[0].tat=p[0].tat/n;
	p[0].wt=p[0].wt/n;	
	cout<<"\n\n-------------------TABLE----------------------------------\n";
	cout<<"\nProcess\tAT\tBT\tFT\tPR\tTAT\tWT\n";
	for(i=1;i<=n;i++)
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p1[i].bt,p[i].pr,p[i].ft,p[i].tat,p[i].wt);
	cout<<"\n\n-----------------------------------------------------------\n";	
}



