#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
class student
{
	int rollno;
	char name[50];
	int p_marks,c_marks,m_marks,e_marks,cs_marks;
	float per;
	char grade;
	int gr;
	int std;
	void calculate()
	{
		per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
		if(per>=91)
		       {	grade='A';
			gr=1;}
		else if(per>=81 && per<91)
		      {	grade='A';
			gr=2; }
		else if(per>=71 && per<81)
		      {	grade='B';
			gr=1; }
		else if(per>=61 && per<71)
		      {	grade='B';
			gr=2; }
		else if(per>=51 && per<61)
		      {	grade='C';
			gr=1; }
		else if(per>=41 && per<51)
		      {	grade='C';
			gr=2; }
		else if(per>=33 && per<41)
		      {	grade='D';
			 }
		else
			grade='F';
	}
 public:
	void search1();
	void getdata()
	{
		cout<<"\nEnter The roll number of student ";
		cin>>rollno;
		cout<<"\n\nEnter The Name of student ";
		gets(name);
		p:;
		cout<<"\nEnter The marks in physics out of 100 : ";
		cin>>p_marks;
		if(p_marks>100)
		goto p;

		c:;
		cout<<"\nEnter The marks in chemistry out of 100 : ";
		cin>>c_marks;
		if(c_marks>100)
		goto c;

		m:;
		cout<<"\nEnter The marks in maths out of 100 : ";
		cin>>m_marks;
		if(m_marks>100)
		goto m;

		e:;
		cout<<"\nEnter The marks in english out of 100 : ";
		cin>>e_marks;
		if(e_marks>100)
		goto e;

		cs:;
		cout<<"\nEnter The marks in computer science out of 100 : ";
		cin>>cs_marks;
		if(cs_marks>100)
		goto cs;
		calculate();
	}

	void showdata()
	{
		cout<<"\nRoll number of student : "<<rollno;
		cout<<"\nName of student : "<<name;
		cout<<"\nMarks in Physics : "<<p_marks;
		cout<<"\nMarks in Chemistry : "<<c_marks;
		cout<<"\nMarks in Maths : "<<m_marks;
		cout<<"\nMarks in English : "<<e_marks;
		cout<<"\nMarks in Computer Science :"<<cs_marks;
		cout<<"\nPercentage of student is  :"<<setprecision(2)<<per;
		cout<<"\nGrade of student is :"<<grade<<gr;
	}

	void show_tabular()
	{
	cout<<rollno<<setw(12)<<name<<setw(10)<<p_marks<<setw(5)<<c_marks<<setw(5)<<m_marks<<setw(5)<<
e_marks<<setw(5)<<cs_marks<<setw(8)<<setprecision(3)<<per<<"   "<<grade<<gr<<endl;
	}

	int  retrollno()
	{	return rollno;	}

}s,to;
 fstream fp,t;
 student st;
void write_student()
{
	fp.open("stude.dat",ios::app);
	st.getdata();
	fp.write((char*)&st,sizeof(student));
	fp.close();
	cout<<"\n\nstudent record Has Been Created ";
	getch();
}
void display_all()
{
	clrscr();
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	fp.open("stude.dat",ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n==================================================\n";
		getch();
	}
		fp.close();
		getch();
}
void display_sp(int n)
{
	int flag=0;
	fp.open("stude.dat",ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.retrollno()==n)
		{
			clrscr();
			st.showdata();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
		cout<<"\n\nrecord not exist";
	getch();
}
void modify_student()
{
	int no,found=0;
	clrscr();
	cout<<"\n\n\tTo Modify ";
	cout<<"\n\n\tPlease Enter The roll number of student";
	cin>>no;
	fp.open("stude.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(st.retrollno()==no)
		{
			st.showdata();
			cout<<"\nPlease Enter The New Details of student"<<endl;
			st.getdata();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
		fp.close();
		if(found==0)
			cout<<"\n\n Record Not Found ";
		getch();
}
void delete_student()
{
	int no;
	clrscr();
		cout<<"\n\n\n\tDelete Record";
		cout<<"\n\nPlease Enter The roll number of student You Want To Delete";
		cin>>no;
		fp.open("stude.dat",ios::in|ios::out);
		fstream fp2;
		fp2.open("Temp.dat",ios::out);
		fp.seekg(0,ios::beg);
		while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.retrollno()!=no)
		{
			fp2.write((char*)&st,sizeof(student));
		}
	}
		fp2.close();
		fp.close();
		remove("stude.dat");
		rename("Temp.dat","stude.dat");
		cout<<"\n\n\tRecord Deleted ..";
		getch();
}
void class_result()
{
	clrscr();
	fp.open("stude.dat",ios::in);
		if(!fp)
		{
				cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
				cout<<"\n\n\n Program is closing ....";
				getch();
				exit(0);
		}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"=============================================================\n";
	cout<<"Roll No. Name          P   C    M    E   CS    %age  Grade\n";
	cout<<"=============================================================\n";
	while(fp.read((char*)&st,sizeof(student)))
	{
		st.show_tabular();
	}
		fp.close();
		getch();
}
void result()
{                	int ans,rno;

		clrscr();
		 cout<<"\n\n\t Result Menu ";
		cout<<"\n\n\n1. Class Result\n\n2. Student Report Card\n\n3.Back to Main Menu";
		cout<<"\n\n\nEnter Choice (1/2)? ";
		cin>>ans  ;
		switch(ans)
		{
			case 1 : class_result();break;
			case 2 : {
				do{
					  clrscr();
				char ans;
				cout<<"\n\nEnter Roll Number Of Student : ";
				cin>>rno;
				display_sp(rno);
				cout<<"\n\nDo you want to See More Result (y/n)?";
				cin>>ans;
				  }while(ans=='y'||ans=='Y');
				 break;
					}
			case 3: break;
			default:  cout<<"\a";
		}
 }
void intro()
{
	clrscr();
       cout<<"\n\n\n\t\t\t  S.S.B.B.S.V.M. Firozabad";
	cout<<"\n\n\t\t\t\t   STUDENT";

	cout<<"\n\t\t\t\t  REPORT CARD";


       cout<<"\n\n\t\t\t\t       BY  :-";
	       cout<<"\n\n\t\t\t $$$$$ $    $$$$ $    $  $$$    $$$$ $    ";
		 cout<<"\n\t\t\t $     $$$$    $ $ $  $  $$$    $    $$$$ ";
		 cout<<"\n\t\t\t $     $  $ $ $$ $$   $  $        $  $  $ ";
		 cout<<"\n\t\t\t $$$$$ $  $ $$$$ $ $  $  $$$$$  $$$$ $  $ ";



	     cout<<"\n\n\n\t\t\t  #   # ####     #  ####  #    # ";
		 cout<<"\n\t\t\t   # #     #     #     #  #   #  ";
		 cout<<"\n\t\t\t    #   # ##  ####  ####   # #  ";
		 cout<<"\n\t\t\t    #   ####  ####  ####    #   ";
	getch();
}
void entry_menu()
{
	clrscr();
	char ch2;
 cout<<"\n\n\t Entry Menu ";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\t7.SEARCH BY NAME";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	ch2=getche();
	switch(ch2)
	{
			case '1': clrscr();
					write_student();
					break;
			case '2': display_all();break;
			case '3':
					int num;
					clrscr();
					cout<<"\n\n\tPlease Enter The roll number ";
					cin>>num;
					display_sp(num);
					break;
				case '4': modify_student();break;
				case '5': delete_student();break;
				case '6': break;
				case '7': to.search1();
				default:cout<<"\a";entry_menu();
		}
}
int passwords()
{

	char p1,p2,p3;
	gotoxy(30,10);
	cout<<"ENTER THE PASSWORD\n";
	gotoxy(30,20);
	p1=getch();
	cout<<"*";
	p2=getch();
	cout<<"*";
	p3=getch();
	cout<<"*";
	gotoxy(30,20);
	if ((p1=='s'||p1=='S')&&(p2=='v'||p2=='V')&&(p3=='m'||p3=='M'))

		return 1;

	else
		return 0;
}
void search1();
void student::search1()
{
 clrscr();
 char names[20];
 t.open("stude.dat",ios::in);
 int flag=0;
 cout<<"\n";
 cout<<"\t\t\t*-----------*"<<"\n";
 cout<<"\t\t\t| SEARCHING |"<<"\n";
 cout<<"\t\t\t*-----------*"<<"\n"<<"\n";
 cout<<"\n\tENTER THE NAME TO BE SEARCHED :";
 gets(names);
 cout<<"\n";
 cout<<"ROLL	 NAME     	MARKS   	  PERCENTAGE	GRADE"<<"\n";
 for(int i=0;i<2;i++)
  {
	while(t.read((char *) &s,sizeof(s)))
	{
	if(strcmp(names,s.name)==0)
	 {
	  flag=1;
	  s.showdata();
	  break;
	 }
   }
  }
 if(flag==0)
  {
	cout<<"\tSORRY\n";
	cout<<"\tTHE NAME DOES NOT EXIST.\n";
  }
 getch();
}
void main()
{                   clrscr();

		   cout<<"\t%%      %%      ";
		 cout<<"\n\t%%      %% %%%%%%% %%      %%%%%%  %%%%%% %%%%  %%%% %%%%%%%";
		 cout<<"\n\t%%      %% %%      %%      %%      %%  %% %%  %%% %% %%       ";
		 cout<<"\n\t%%  %%  %% %%%%%   %%      %%      %%  %% %%  %%% %% %%%%%      ";
		 cout<<"\n\t%%  %%  %% %%      %%      %%      %%  %% %%      %% %%           ";
		 cout<<"\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%% %%%%%% %%      %% %%%%%%%     ";

	       cout<<"\n\n\t\t\t        $$$$$$$$  $$$$$        ";
		 cout<<"\n\t\t\t           $$     $   $      ";
		 cout<<"\n\t\t\t           $$     $$$$$    ";

		 cout<<"\n\n\n\tCOMPUTER   PROJECT  (********  RESULT PROJECT>>  *******)";
		 cout<<"\n\n\n\tBY:-  Chaklesh Yadav 'XII'";

	 cout<<" \n\n\n\t\t     Press any KEY???? to continue: ";

	  getch();
	char ch;
	intro();
	clrscr();


	int passwords();
	if(!passwords())
			{
				for(int i=0;i<2;i++)
				{
					clrscr();
					cout<<"\nWrong password try once more\n";
					if(passwords())
					{
					goto last;
					}
					else
					{
						clrscr();
						cout<<"\n\n\t\t\t all attempts failed.....";
						cout<<"\n\n\n\t\t\t see you.................. ";
						exit(0);
					}

				 }
			  cout<<"\t\t\t sorry all attempts failed............. \n \t\t\tinactive";
			 }
	else do
		{
		last:;
		clrscr();
       cout<<"\n\n\t Main Menu ";
		cout<<"\n\n\t01. RESULT MENU";
		cout<<"\n\n\t02. ENTRY/EDIT MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		ch=getche();
		switch(ch)
		{
			case '1': clrscr();
				result();
					break;
			case '2': entry_menu();
					break;
			case '3': clrscr();
	     cout<<"\n\n";
	     cout<<"	         _/_/_/_/_/  _/                            _/            \n";
	     cout<<"	            _/      _/_/_/      _/_/_/  _/_/_/    _/  _/         \n";
	     cout<<"	           _/      _/    _/  _/    _/  _/    _/  _/_/            \n";
	     cout<<"	          _/      _/    _/  _/    _/  _/    _/  _/  _/           \n";
	     cout<<"	         _/      _/    _/    _/_/_/  _/    _/  _/    _/          \n";
	     cout<<"                                                                  \n";
	     cout<<"                                                                  \n";
	     cout<<"                                                                  \n";
	     cout<<"		         _/     _/                                       \n";
	     cout<<"		          _/  _/    _/_/    _/    _/                     \n";
	     cout<<"		            _/    _/    _/  _/    _/                     \n";
	     cout<<"		            _/    _/    _/  _/    _/                     \n";
	     cout<<"		           _/      _/_/      _/_/_/                     \n\n";

	     cout<<"..........oOoOo~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	     cout<<".........oOoOo~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	     cout<<".........oooo~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	     getch();
	     exit(0);
			default :cout<<"\a";
		}
		}while(ch!='3');
}