#include<iostream>
#include<algorithm>
using namespace std;

struct process{
	int id, arrival_time, burst_time, priority, status;
}p[10];


bool compare(process a, process b)
{
	return a.arrival_time < b.arrival_time;
}

int main()
{
	int n,i;
	cout<<"Enter the number of processes:\n";
	cin>>n;
	
	
	cout<<"Enter the arrival time of each process:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter the arrival time of P"<<i+1<<":"<<endl;
		cin>>p[i].arrival_time;
		p[i].id = i+1;
	}

	cout<<"Enter the burst time of each process:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter the burst time of P"<<i+1<<":"<<endl;
		cin>>p[i].burst_time;
	}
	
	cout<<"Enter the priority of each process:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter the priority of P"<<i+1<<":"<<endl;
		cin>>p[i].priority;
	}
	
	for(i=0;i<n;i++)
		p[i].status = 0;
		
	sort(p, p+n, compare);	
	
	
	int time = 0;			
	int count = 0, count2 = 0;
	i=0;
	while(count!=n)
	{
		if(p[i].status!=1 && p[i].status!=2)
		{	
			cout<<"Processing "<<p[i].id<<endl;
			for(int j=i+1;j<n;j++)
			{
				if(p[j].status != 1 && p[j].status!=2 && (p[j].priority < p[i].priority) && (p[j].arrival_time <= time))
				{
					cout<<"Process P"<<p[i].id<<" is interuppted by P"<<p[j].id<<".Pushing it into queue2"<<endl;
					cout<<"Process P"<<p[j].id<<" is processing"<<endl;
					p[i].status = 2;
					count2++;
					time += p[j].burst_time;
					p[j].status = 1;
					cout<<"Process P"<<p[j].id<<" is completely processed"<<endl;
					count += 2;
					break;
				}
			}
			if(p[i].status != 2)
			{
				time += p[i].burst_time;
				p[i].status = 1;
				cout<<"Process P"<<p[i].id<<" is completely processed"<<endl;
				count++;
			}
		}
		i = (i+1)%n;
	}
	
	int tq = 2;
	time = 0;
	count = 0;
	
	cout<<"Executing Queue2"<<endl;
	
	i=0;
	while(count != count2)
	{
		if(p[i].status == 2)
		{
			if(p[i].burst_time<2)
			{
				p[i].burst_time -= 1;
				time += 1;
				p[i].status = 1;
				cout<<"Completed P"<<p[i].id<<endl;
				count++; 
			}
			else
			{
				p[i].burst_time -= 2;
				time += tq;
				cout<<"Processing P"<<p[i].id<<endl;
			}
		}
		i = (i+1)%n;
	}
			
	return 0;
}
