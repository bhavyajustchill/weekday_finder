#include <iostream>
using namespace std;

void ans_day(int date,int month,int year,int dn)
{
	switch(dn) {
		case 0:
		cout<<date<<"/"<<month<<"/"<<year<<ends<<" is Sunday.";
		break;
		case 1:
		cout<<date<<"/"<<month<<"/"<<year<<ends<<" is Monday.";
		break;
		case 2:
		cout<<date<<"/"<<month<<"/"<<year<<ends<<" is Tuesday.";
		break;
		case 3:
		cout<<date<<"/"<<month<<"/"<<year<<ends<<" is Wednesday.";
		break;
		case 4:
		cout<<date<<"/"<<month<<"/"<<year<<ends<<" is Thursday.";
		break;
		case 5:
		cout<<date<<"/"<<month<<"/"<<year<<ends<<" is Friday.";
		break;
		case 6:
		cout<<date<<"/"<<month<<"/"<<year<<ends<<" is Saturday.";
		break;
	}
}

int findMonth_extra_days(int m_no,int year)
{
	int extra_days=0;
	if(m_no==4 || m_no==6 || m_no==9 || m_no==11 || m_no==1 || m_no==3 || m_no==5 || m_no==7 || m_no==8 || m_no==10 || m_no==12)
	{
	if(m_no==1)
	{
		extra_days=0;
	}
	else if(m_no==3)
	{
		if(year%4==0)
		extra_days=4;
		else
		extra_days=3;
	}
	else if(m_no==4)
	{
		if(year%4==0)
		extra_days=7;
		else
		extra_days=6;
	}
	else if(m_no==5)
	{
		if(year%4==0)
		extra_days=9;
		else
		extra_days=8;
	}
	else if(m_no==6)
	{
		if(year%4==0)
		extra_days=12;
		else
		extra_days=11;
	}
	else if(m_no==7)
	{
		if(year%4==0)
		extra_days=15;
		else
		extra_days=14;
	}
	else if(m_no==8)
	{
		if(year%4==0)
		extra_days=18;
		else
		extra_days=17;
	}
	else if(m_no==9)
	{
		if(year%4==0)
		extra_days=20;
		else
		extra_days=19;
	}
	else if(m_no==10)
	{
		if(year%4==0)
		extra_days=22;
		else
		extra_days=21;
	}
	else if(m_no==11)
	{
		if(year%4==0)
		extra_days=25;
		else
		extra_days=24;
	}
	else
	{
		if(year%4==0)
		extra_days=28;
		else
		extra_days=27;
	}
	}
	else if(m_no==2)
	{
	if(year%4==0)
	{
		extra_days=4;
	}
	else
	{
		extra_days=3;
	}
	}
	else
	{
		cout<<"Enter Proper Month...";
	}
	return extra_days%7;
}

int findDay(int date,int extra_days,int y_solved)
{
	int day_no;
	day_no=date+y_solved+extra_days;
	day_no=day_no%7;
	return day_no;
}

int year_solved(int year)
{
	int y_solve;
	if(year%4==0 && year%400==0)
	{
		y_solve=0;
	}
	else if(year%4==0 && year%100==0 && year%400!=0)
	{
		year=year%400;
		y_solve=2*(year/4)+(year-(year/4));
	}
	else
	{
		year=year%400;
		if(year>=0 && year<=100)
		{
			--year;
			y_solve=2*(year/4)+(year-(year/4));
		}
		else if(year>100 && year<=200)
		{
			--year;
			year=year-100;
			y_solve=2*(year/4)+(year-(year/4))+5;
		}
		else if(year>200 && year<=300)
		{
			--year;
			year=year-200;
			y_solve=2*(year/4)+(year-(year/4))+3;
		}
		else
		{
			--year;
			year=year-300;
			y_solve=2*(year/4)+(year-(year/4))+1;
		}
	}
	return y_solve%7;
}
int main()
{
	int dn,mn,ys,ed,date,year,month;

	cout<<"\nEnter Date:";
	cin>>date;

	cout<<"\nEnter Month:";
	cin>>month;

	cout<<"\nEnter Year:";
	cin>>year;

	ed=findMonth_extra_days(month,year);
	ys=year_solved(year);
	dn=findDay(date,ed,ys);
	ans_day(date,month,year,dn);

	return 0;
}
// made by rajkumartetar.
// altered by BhavyaJustChill