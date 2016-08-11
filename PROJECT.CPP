//made by vasu sethia 
//class-12 -A
//program password:abcd
//admin passoword:edu 
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
char* returnpassword()
{                                   //gives password
	char str[15];
	cout<<"\n ENTER PASSWORD MAX 15 CHARACTERS";
	for(int i=0;i<15;i++)
	{
		str[i]=getch();
		if(str[i]=='\r')
		{
			break;
		}
		cout<<"*";
	}
	str[i]='\0';
	return str;
}
class course
{
	char teachername[20];
	char courseid[5];
	char coursename[20];
	char timing[10];
	char days[5];
	char clas[4];
	public:
	course()
	{
		strcpy(teachername,"NULL");
	}
	void addcourse();
	void showcourse();
	char* returncoursename()
	{
		return coursename;
	}
	char* returncid()
	{
		return courseid;
	}
	char* returntcname()
	{
		return teachername;
	}
	char* returnclas()
	{
		return clas;
	}
	void deletecourse();
	void modify(char *name)     //function to modify teacher name
	{
		strcpy(teachername,name);
	}
};
void course::addcourse()
{
	cout<<"\n ENTER COURSE NAME:  ";
	gets(coursename);
	cout<<"\n ENTER COURSE ID: ";
	gets(courseid);
	cout<<"\n DAYS AVAILABLE: ";
	gets(days);
	cout<<"\n TIMING: ";
	gets(timing);
	cout<<"\n FOR WHICH CLASSES COURSE IS AVAILABLE : ";
	gets(clas);
}
void course::showcourse()
{
	cout<<"\n COURSE NAME: "<<coursename;
	cout<<"\n TEACHER NAME: ";
	puts(teachername);
	cout<<"\n COURSE ID: "<<courseid;
	cout<<"\n TIMING : "<<timing;
	cout<<"\n DAYS : "<<days;
	cout<<"\n ELIGIBILITY: "<<clas;
}

class teacher
{
	char name[20];
	int salary;
	int attendance;
	char address[20];
	char tcourse[20];
	char cid[4];
	char loginid[20];
	int unqo;
	char phoneno[12];
	char password[10];
	public:
	teacher()
	{
		attendance=0;
	}
	void addteacherdata(int ukey);
	void showteacherdata();
	int returnunqo()
	{
		return unqo;
	}
	char* returntname()
	{
		return name;
	}
	char* returntpassword()
	{
		return password;
	}
	char* returntcourse()
	{
		return tcourse;
	}
	char* returntloginid()
	{
		return loginid;
	}
	void entertphoneno()             //update phone no
	{
		cout<<"\n ENTER UPDATED PHONE NO : ";
		gets(phoneno);
	}
	void entertaddress()              //update address
	{
		cout<<"\n ENTER UPDATED ADDRESS : ";
		gets(address);
	}
	void entertpassword()             //changes password
	{
		cout<<"\n ENTER UPDATED PASSWORD : ";
		strcpy(password,returnpassword());
	}
	void getattendance()
	{
		attendance=attendance+1;
	}
};
void teacher::addteacherdata(int ukey)
{
	int option;
	int rec=0;
	course c;
	int flag=0;
	cout<<"\n ENTER NAME :";
	gets(name);
	do                 //add teacher checking whether coures are available or not
	{
		ifstream filein("couse.dat",ios::binary);
		cout<<"\n ENTER COURSE ID WHERE TEACHER NAME IS NULL";
		while(filein.read((char*)&c,sizeof(c)))
		{
				clrscr();
				c.showcourse();
				cout<<"\n PRESS ANY KEY TO CONITUE";
				getch();
		}
		cout<<"\n ENTER COURSE ID ";
		gets(cid);
		fstream file("couse.dat",ios::binary|ios::in|ios::out);
		while(file.read((char*)&c,sizeof(c)))
		{
			if(strcmp(c.returncid(),cid)==0 && strcmp(c.returntcname(),"NULL")==0)
			{
				clrscr();
				strcpy(tcourse,c.returncoursename());
				strcpy(cid,c.returncid());
				file.seekp(rec*sizeof(c));
				c.modify(name);
				file.write((char*)&c,sizeof(c));
				flag=1;
				break;
			}
			else
			{
				flag=0;
				rec++;
			}
		}
		if(flag==0)
		{
			cout<<"\n NO VACANCIES VACANT";
		}
		file.close();
	}while(flag==0);
	cout<<"\n ENTER ADDRESS: ";
	gets(address);
	cout<<"\n ENTER CONTACT NUMBER: ";
	gets(phoneno);
	cout<<"\n ENTER SALARY TO BE PAID: ";
	cin>>salary;
	unqo=ukey;
	for(int i=0;name[i]!='\0';i++)
	{
		if(name[i]==' ')
		{
			loginid[i]='@';
		}
		else
		{
			loginid[i]=name[i];
		}
	}
	loginid[i]='\0';
	strcpy(password,returnpassword());
	cout<<"\n LOGIN INFORMATION MUST BE REMEBERED";
	cout<<"\n LOGIN ID :";
	puts(loginid);
	cout<<"\n PASSWORD :";
	puts(password);
}
void teacher::showteacherdata()
{
	cout<<"\n NAME :";
	puts(name);
	cout<<"\n PHONE NO :"<<phoneno;
	cout<<"\n ADDRESS :";
	puts(address);
	cout<<"\n SALARY :"<<salary;
	cout<<"\n COURSE :";
	puts(tcourse);
	cout<<"\n UNIQUE KEY :"<<unqo;
	cout<<"\n ATTENDANCE :"<<attendance;
}
class student
{
	char name[40];
	char add[40];
	char scourse[5];
	char loginid[20];
	int rollno;
	char cid[5];
	char clas[5];
	char password[20];
	char phoneno[12];
	int attendance;
	public:
	student()
	{
		attendance=0;
	}
	void addstudentdata(int ukey);
	void showstudentdata();
	int returnrollno()
	{
		return rollno;
	}
	char* returnname()
	{
		return name;
	}
	char* returncid()
	{
		return cid;
	}
	char* returnpassword()
	{
		return password;
	}
	char* returncourse()
	{
		return scourse;
	}
	char* returnloginid()
	{
		return loginid;
	}
	void enterphoneno()  //updates phoneno
	{
		clrscr();
		cout<<"\n ENTER UPDATED PHONE NO: ";
		gets(phoneno);
	}
	void enteraddress()  //updates address
	{
		clrscr();
		cout<<"\n ENTER UPDATED ADDRESS: ";
		gets(add);
	}
	void enterpassword();
	void getsattendance()
	{
		attendance=attendance+1;
	}

};
void student::enterpassword()
{
	clrscr();
	char password[15];
	cout<<"\n ENTER PASSWORD MAX 15 CHARACTERS";
	for(int i=0;i<15;i++)                 //generates password for student
	{
		password[i]=getch();
		if(password[i]=='\r')
		{
			break;
		}
		cout<<"*";
	}
	password[i]='\0';
}
void student::addstudentdata(int ukey)
{
	int option;
	int flag=0;
	char cd[4];
	course c;
	cout<<"\n ENTER STUDENT NAME: ";
	gets(name);
	cout<<"\n ENTER STUDENT PHONENO: ";
	gets(phoneno);
	cout<<"\n ENTER STUDENTS ADDRESS: ";
	gets(add);
	do
	{
	clrscr();
	ifstream filein("couse.dat",ios::binary);
	cout<<"\n FOLLOWING COURSES ARE AVAILABLE: ";
	while(filein.read((char*)&c,sizeof(c)))
	{
		clrscr();
		c.showcourse();
		getch();
	}
	cout<<"\n ENTER COURSEID TO ASSIGN THE COURSE: ";
	gets(cid);

		filein.close();
		ifstream file("couse.dat",ios::binary);
		while(file.read((char*)&c,sizeof(c)))
		{
			if(strcmp(c.returncid(),cid)==0)
			{
				strcpy(scourse,c.returncoursename());
				strcpy(cid,c.returncid());
				strcpy(clas,c.returnclas());
				flag=1;
				break;
			}

			else
			{
				flag=0;
			}
		}
	if(flag==0)
	{
		cout<<"\n WRONG COURSE SELECTED";
	}
		file.close();
	}while(flag==0);
	cout<<"\n ENTER PASSWORD MAX 15 CHARACTERS";
	for(int i=0;i<15;i++)
	{
		password[i]=getch();
		if(password[i]=='\r')
		{
			break;
		}
		cout<<"*";
	}
	password[i]='\0';
	for( i=0;name[i]!='\0';i++)  //generates login id
	{
		if(name[i]==' ')
		{
			loginid[i]='@';
		}
		else
		{
			loginid[i]=name[i];
		}
	}
	loginid[i]='\0';
	cout<<"\n LOGIN INFO FOR THE STUDENT IS: ";
	cout<<"\n USER LOGIN ID: ";
	puts(loginid);
	cout<<"\n PASSWORD: "<<password;
	rollno=ukey;
};
void student::showstudentdata()
{
	cout<<"\n NAME :: ";
	puts(name);
	cout<<"\n ADDRESS:: ";
	puts(add);
	cout<<"\n ROLLNO :: "<<rollno;
	cout<<"\n CLASS :: "<<clas;
	cout<<"\n PHONE NO :: "<<phoneno;
	cout<<"\n COURSE :: ";
	puts(scourse);
	cout<<"\n COURSE ID :: "<<cid;
	cout<<"\n ATTENDANCE :: "<<attendance;
}
int getcode() //generates rollno for student
{
	student s;
	int code;
	ifstream filein("student.dat",ios::binary);
	if(filein==0)
	{
		code=0;
	}
	else
	{
		filein.seekg(0,ios::end);
		int count=filein.tellg();
		int rec=count/sizeof(s);
		if(rec==0)
		{
			code=0;
		}
		else
		{
			filein.seekg((rec-1)*sizeof(s));
			filein.read((char*)&s,sizeof(s));
			int n=s.returnrollno();
			code=n+1;
			filein.close();
		}
	}
	return code;
}
int getstudent()
{

	student s;
	int ukey=getcode();
	ofstream fileout("student.dat",ios::binary|ios::ate);
	s.addstudentdata(ukey);
	fileout.write((char*)&s,sizeof(s));
	fileout.close();
	return 0;
}
void showstudentdata()
{
	student s;
	ifstream filein("student.dat",ios::binary);
	if(filein==0)
	{
		cout<<"\n UNABLE TO OPEN FILE";
		return;
	}
	while(filein.read((char*)&s,sizeof(s)))
	{
		clrscr();
		s.showstudentdata();
		getch();
	}
	filein.close();
}

void searchdata()      //searches data on various ground
{
	clrscr();
	int option,rollno;
	char cid[4];
	int flag=0;
	char name[20];
	char coursename[10];
	char ch;
	student s;
	course c;
	cout<<"\n SEARCH BY FOLLWOING OPTIONS";
	cout<<"\n 1.COURSE ID";
	cout<<"\n 2.STUDENT NAME";
	cout<<"\n 3.ROLL NO";
	cout<<"\n 4.COURSES";
	cout<<"\n ENTER OPTION BETWEEN 1-4 ";
	cin>>option;
	if(option==1)
	{

		ifstream filein("couse.dat",ios::binary);
		while(filein.read((char*)&c,sizeof(c)))
		{
			clrscr();
			c.showcourse();
			getch();
		}
		filein.close();
		cout<<"\n ENTER COURSE ID YOU WANT TO SEARCH: ";
		gets(cid);
		ifstream file("student.dat",ios::binary);
		if(file==0)
		{
			cout<<"\n UNABLE TO OPEN FILE";
			return;
		}
		while(file.read((char*)&s,sizeof(s)))
		{
			if(strcmp(s.returncid(),cid)==0)
			{
				s.showstudentdata();
				flag=1;
			}
		}
		file.close();
		if(flag==0)
		{
			cout<<"\n RECORD NOT FOUND";
		}
	}
	else if(option==2)
	{
		cout<<"\n ENTER NAME OF THE STUDENT NAME: ";
		gets(name);
		ifstream filein("student.dat",ios::binary);
		if(filein==0)
		{
			cout<<"\n UNABLE TO OPEN FILE";
			return;
		}
		while(filein.read((char*)&s,sizeof(s)))
		{
			if(strcmp(s.returnname(),name)==0)
			{
				s.showstudentdata();
				flag=1;
			}
		}
		filein.close();
		if(flag==0)
		{
			cout<<"\n RECORD NOT FOUND";
		}
	}
	else if(option==3)
	{
		cout<<"\n ENTER ROLLNO: ";
		cin>>rollno;
		ifstream filein("student.dat",ios::binary);
		if(filein==0)
		{
			cout<<"\n UNABLE TO OPEN FILE";
			return;
		}
		while(filein.read((char*)&s,sizeof(s)))
		{
			if(s.returnrollno()==rollno)
			{
				s.showstudentdata();
				flag=1;
			}
		}
		filein.close();
		if(flag==0)
		{
			cout<<"\n RECORD NOT FOUND";
		}
	}
	else if(option==4)
	{

		course c;
		ifstream file("couse.dat",ios::binary);
		while(file.read((char*)&c,sizeof(c)))
		{
			c.showcourse();
		}
		file.close();
		cout<<"\n ENTER COURSE NAME FROM ABOVE COURSES AVAILABLE: ";
		gets(coursename);
		ifstream filein("student.dat",ios::binary);
		if(filein==0)
		{
			cout<<"\n UNABLE TO OPEN FILE";
			return;
		}
		while(filein.read((char*)&s,sizeof(s)))
		{
			if(strcmp(s.returncourse(),coursename)==0)
			{
				s.showstudentdata();
				flag=1;
			}

		}
		filein.close();
		if(flag==0)
		{
			cout<<"\n RECORD NOT FOUND";
		}
	}
	else
	{
		cout<<"\n ENTERED WRONG PLEASE FOLLOW INSTRUCTION CAREFULLY";
	}
}
void studentupdate()  //updates student data like phoneno etc
{
	int flag=0;
	int rec=0;
	char loginid[15];
	char password[20];
	int option;
	student s;
	clrscr();
	fstream filein("student.dat",ios::binary|ios::in|ios::out);
	if(filein==0)
	{
		cout<<"\n UNABLE TO OPEN FILE";
		return;
	}
	cout<<"\n ENTER NAME OF THE STUDENT LOGIN ID: ";
	gets(loginid);
	strcpy(password,returnpassword());
	while(filein.read((char*)&s,sizeof(s)))
	{
		if(strcmp(s.returnloginid(),loginid)==0 && strcmp(s.returnpassword(),password)==0)
		{
			s.showstudentdata();
			flag=1;
			cout<<"\n 1.UPDATE PHONE NO";
			cout<<"\n 2.UPDATE PASSWORD";
			cout<<"\n 3.UPDATE ADDRESS";
			cout<<"\n ENTER OPTION";
			cin>>option;
			if(option==1)
			{
				s.enterphoneno();
				filein.seekp(rec*sizeof(s));
				filein.write((char*)&s,sizeof(s));
			}
			else if(option==2)
			{
				s.enterpassword();
				filein.seekp(rec*sizeof(s));
				filein.write((char*)&s,sizeof(s));
			}
			else if(option==3)
			{
				s.enteraddress();
				filein.seekp(rec*sizeof(s));
				filein.write((char*)&s,sizeof(s));
			}
			else
			{
				cout<<"\ WRONG OPTION ENTERED";
			}
			flag=1;
			break;
		}
		else
		{
			flag=0;
			rec++;
		}
	}
	filein.close();
	if(flag==0)
	{
		cout<<"\n WRONG INFORMATION ENTERED";
	}
}

int getunqo()     //generates unique key for teacher
{
	teacher t;
	int code;
	ifstream filein("teacher.dat",ios::binary);
	if(filein==0)
	{
		code=0;
	}
	else
	{
		filein.seekg(0,ios::end);
		int count=filein.tellg();
		int rec=count/sizeof(t);
		filein.seekg((rec-1)*sizeof(t));
		filein.read((char*)&t,sizeof(t));
		int n=t.returnunqo();
		code=n+1;
		filein.close();
	}
	return code;
}
void addteacher()
{
	clrscr();
	teacher t;
	course c;
	int rec=0;
	int ukey=getunqo();
	ifstream filein("couse.dat",ios::binary);
	while(filein.read((char*)&c,sizeof(c)))
	{
		if(strcmp(c.returntcname(),"NULL")==0)
		{
			rec++;
		}
	}
	if(rec==0)
	{
		cout<<"\n NO VACANCIES AVAILABLE: ";
		return;
	}
	filein.close();
	ofstream fileout("teacher.dat",ios::binary|ios::ate);
	if(fileout==0)
	{
		cout<<"\n UNABLE TO OPEN FILE";
		return;
	}
	t.addteacherdata(ukey);
	fileout.write((char*)&t,sizeof(t));
	fileout.close();
}
void showteacher()
{
	clrscr();
	teacher t;
	ifstream filein("teacher.dat",ios::binary);
	if(filein==0)
	{
		cout<<"\n UNABLE TO OPEN FILE";
		return;
	}
	while(filein.read((char*)&t,sizeof(t)))
	{
		t.showteacherdata();
	}
	filein.close();
}
void teacherupdate() //updates teacher data
{
	clrscr();
	int flag=1;
	int rec=0;
	char loginid[15];
	char password[20];
	int option;
	teacher s;
	clrscr();
	fstream filein("teacher.dat",ios::binary|ios::in|ios::out);
	if(filein==0)
	{
		cout<<"\n UNABLE TO OPEN FILE";
		return;
	}
	cout<<"\n ENTER NAME OF THE TEACHER LOGIN ID: ";
	gets(loginid);
	strcpy(password,returnpassword());
	while(filein.read((char*)&s,sizeof(s)))
	{
		if(strcmp(s.returntloginid(),loginid)==0 && strcmp(s.returntpassword(),password)==0)
		{
			s.showteacherdata();
			cout<<"\n 1.UPDATE PHONE NO";
			cout<<"\n 2.UPDATE PASSWORD";
			cout<<"\n 3.UPDATE ADDRESS";
			cout<<"\n ENTER OPTION";
			cin>>option;
			if(option==1)
			{
				s.entertphoneno();
				filein.seekp(rec*sizeof(s));
				filein.write((char*)&s,sizeof(s));
			}
			else if(option==2)
			{
				s.entertpassword();
				filein.seekp(rec*sizeof(s));
				filein.write((char*)&s,sizeof(s));
			}
			else if(option==3)
			{
				s.entertaddress();
				filein.seekp(rec*sizeof(s));
				filein.write((char*)&s,sizeof(s));
			}
			else
			{
				cout<<"\ WRONG OPTION ENTERED";
			}
			flag=1;
			break;
		}
		else
		{
			flag=0;
			rec++;
		}
	}
	filein.close();
	if(flag==0)
	{
		cout<<"\n WRONG INFORMATION ENTERED";
	}
}
void teachersearch() //searches teacher data on various grounds
{
	clrscr();
	int flag=0;
	char name[20];
	char course[12];
	teacher t;
	int option;
	int unqo;
	cout<<"\n 1.SEARCH BY NAME";
	cout<<"\n 2.SEARCH BY UNIQUE KEY";
	cout<<"\n 3.SEARCH BY COURSE";
	cout<<"\n ENTER OPTION";
	cin>>option;
		if(option==1)
		{
			ifstream filein("teacher.dat",ios::binary);
			if(filein==0)
			{
				cout<<"\n UNABLE TO OPEN FILE";
				return;
			}
			cout<<"\n ENTER NAME TO BE SEARCHED: ";
			gets(name);
			while(filein.read((char*)&t,sizeof(t)))
			{
				if(strcmp(t.returntname(),name)==0)
				{
					t.showteacherdata();
					flag=1;
				}
			}
			filein.close();
			if(flag==0)
			{
			cout<<"\n RECORD NOT FOUND";
			}
		}
		else if(option==2)
		{
			ifstream filein("teacher.dat",ios::binary);
			if(filein==0)
			{
				cout<<"\n UNABLE TO OPEN FILE";
				return;
			}
			cout<<"\n ENTER UNIQUE KEY: ";
			cin>>unqo;
			while(filein.read((char*)&t,sizeof(t)))
			{
				if(t.returnunqo()==unqo)
				{
					t.showteacherdata();
					flag=1;
				}
			}
			filein.close();
			if(flag==0)
			{
			cout<<"\n RECORD NOT FOUND";
			}
		}
		else if(option==3)
		{
			ifstream filein("teacher.dat",ios::binary);
			if(filein==0)
			{
				cout<<"\n UNABLE TO OPEN FILE";
				return;
			}
			cout<<"\n ENTER COURSE TEACHER IS TEACHING: ";
			gets(course);
			while(filein.read((char*)&t,sizeof(t)))
			{
				if(strcmp(t.returntcourse(),course)==0)
				{
					t.showteacherdata();
					flag=1;
				}
			}
			filein.close();
			if(flag==0)
			{
			cout<<"\n RECORD NOT FOUND";
			}
		}
		else
		{
			cout<<"\n WRONG OPTION ENTERED";
		}
}
void deletestudent() //delete student
{
	clrscr();
	int flag=0;
	char name[20];
	student s;
	int rollno;
	cout<<"\n ENTER NAME OF THE STUDENT YOU WANT TO DELETE THE RECORD: ";
	gets(name);
	cout<<"\n ENTER THE ROLLNO: ";
	cin>>rollno;
	ifstream filein("student.dat",ios::binary);
	if(filein==0)
	{
		cout<<"\n UNABLE TO OPEN FILE";
		return;
	}
	ofstream fileout("tempstud.dat",ios::binary);
	while(filein.read((char*)&s,sizeof(s)))
	{
		if(strcmp(s.returnname(),name)==0 && s.returnrollno()==rollno)
		{
			cout<<"\n RECORD FOUND AND DELETED";
			flag=1;
		}
		else
		{
			fileout.write((char*)&s,sizeof(s));
		}
	}
	filein.close();
	fileout.close();
	remove("student.dat");
	rename("tempstud.dat","student.dat");
	if(flag==0)
	{
		cout<<"\n RECORD NOT FOUND";
	}
}
void deleteteacher()//delete teacher data
{
	clrscr();
	teacher s;
	int flag=0;
	int rec=0;
	course c;
	char name[20];
	int rollno;
	cout<<"\n ENTER NAME OF THE TEACHER YOU WANT TO DELETE THE RECORD: ";
	gets(name);
	cout<<"\n ENTER THE UNIQUEKEY OF TEACHER: ";
	cin>>rollno;
	fstream file("couse.dat",ios::binary|ios::in|ios::out);
	ifstream filein("teacher.dat",ios::binary);
	if(filein==0)
	{
		cout<<"\n UNABLE TO OPEN FILE";
		return;
	}
	ofstream fileout("tempteach.dat",ios::binary);
	while(file.read((char*)&c,sizeof(c)))
	{
		if(strcmp(c.returntcname(),name)==0)
		{
			c.modify("NULL");
			file.seekp(rec*sizeof(c));
			file.write((char*)&c,sizeof(c));
		}
		else
		{
			rec++;
		}
	}
	file.close();
	while(filein.read((char*)&s,sizeof(s)))
	{
		if(strcmp(s.returntname(),name)==0 && s.returnunqo()==rollno)
		{
			cout<<"\n RECORD FOUND DELETED";
			flag=1;
		}
		else
		{
			fileout.write((char*)&s,sizeof(s));
		}
	}
	filein.close();
	fileout.close();
	remove("teacher.dat");
	rename("tempteach.dat","teacher.dat");
	if(flag==0)
	{
		cout<<"\n RECORD NOT FOUND";
	}
}
void takeattendancet()//takes teacher attendance
{
	teacher t;
	char ch;
	int rec=0;
	fstream file("teacher.dat",ios::binary|ios::out|ios::in);
	if(file==0)
	{
		cout<<"\n UNABLE TO OPEN FILE";
		return;
	}
	while(file.read((char*)&t,sizeof(t)))
	{
		clrscr();
		t.showteacherdata();
		cout<<"\n ENTER P FOR PRESENT AND A FOR ABSENT : ";
		cin>>ch;
		if(ch=='p'|| ch=='P')
		{
			t.getattendance();
			file.seekp(rec*sizeof(t));
			file.write((char*)&t,sizeof(t));
		}
		rec++;
	}
	file.close();
}
void takeattendances() //takes student attendance
{
	student s;
	int rec=0;
	char ch;
	fstream file("student.dat",ios::binary|ios::in|ios::out);
	if(file==0)
	{
		cout<<"\n UNABLE TO OPEN FILE";
		return;
	}
	while(file.read((char*)&s,sizeof(s)))
	{
		clrscr();
		s.showstudentdata();
		cout<<"\n ENTER P FOR PRESENT AND A FOR ABSENT: ";
		cin>>ch;
		if(ch=='p' || ch=='P')
		{
			s.getsattendance();
			file.seekp(rec*sizeof(s));
			file.write((char*)&s,sizeof(s));
		}
		rec++;
	}
	file.close();
}
void addcourse()//ADD COURSES TO THE FILE
{
	course c;
	char ch;
	ofstream fileout("couse.dat",ios::binary|ios::app);
	if(fileout==0)
	{
		cout<<"\n UNABLE TO OPEN FILE";
		return;
	}
	do
	{
		c.addcourse();
		fileout.write((char*)&c,sizeof(c));
		fileout.close();
		cout<<"\n WANT TO CONITUE ADDING MORE RECORDS PRESS (y/n)";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
void administrator()
{
	clrscr();
	char str[15];
	strcpy(str,"edu");    //checks whether password is correct or not
	if(strcmp(str,returnpassword())!=0)
	{
		cout<<"\n WRONG PASSWORD ENTERED";
		return;
	}
	course c;
	ifstream filein("couse.dat",ios::binary);
	if(filein==0)
	{
		cout<<"\n ERROR COURSES FILE IS CORRUPTED OR DELETED OR NOT AVAILABLE";
		cout<<"\n YOU NEED TO ADD COURSE FIRST TO ACCESS FURTHER FUNCTIONS";
		cout<<"\n REDIRECTING YOU TO ADDCOURSE FUNCTION";
		delay(3000);
		addcourse();
		return;
	}
	else
	{
			int option;
			cout<<"\n 1.WORK WITH STUDENTS ";
			cout<<"\n 2.WORK WITH TEACHERS ";
			cout<<"\n 3.TAKE STUDENT ATTENDANCE";
			cout<<"\n 4.TAKE TEACHER ATTENDANCE";
			cout<<"\n 5.ADD COURSE";
			cout<<"\n 6.DISPLAY COURSE";
			cout<<"\n ENTER AN OPTION";
			cin>>option;
			if(option==1)
			{
				clrscr();
				cout<<"\n 1.ENTER STUDENT RECORD";
				cout<<"\n 2.DELETE STUDENT RECORD";
				cout<<"\n 3.SEARCH STUDENT RECORDS";
				cout<<"\n 4.DISPLAY ALL RECORDS";
				cout<<"\n ENTER OPTION";
				cin>>option;
				if(option==1)
				{
					getstudent();
				}
				else if(option==2)
				{
					deletestudent();
				}
				else if(option==3)
				{
					searchdata();
				}
				else if(option==4)
				{
					showstudentdata();
				}
				else
				{
					cout<<"\n WRONG OPTION ENTERED";
				}

			}
			else if(option==2)
			{
				clrscr();
				cout<<"\n 1.ENTER A NEW RECORD OF TEACHER";
				cout<<"\n 2.DELETE A RECORD";
				cout<<"\n 3.SEARCH A RECORD";
				cout<<"\n 4.DISPLAY ALL RECORDS";
				cout<<"\n ENTER A OPTION";
				cin>>option;
				if(option==1)
				{
					addteacher();
				}
				else if(option==2)
				{
					deleteteacher();
				}
				else if(option==3)
				{
					teachersearch();
				}
				else if(option==4)
				{
					showteacher();
				}
				else
				{
					cout<<"\n WRONG OPTION ENTERED";
				}
			}
			else if(option==3)
			{
				takeattendances();
			}
			else if(option==4)
			{
				takeattendancet();
			}
			else if(option==5)
			{
				addcourse();
			}
			else if(option==6)
			{
				ifstream filein("couse.dat",ios::binary);
				course c;
				while(filein.read((char*)&c,sizeof(c)))
				{
					clrscr();
					c.showcourse();
					getch();
				}
				filein.close();
			}
			else
			{
				cout<<"\n WRONG OPTION ENTERED";
			}
	}

}

void studentfunc()
{
	clrscr();   //functions that student can perform
	int flag=0;
	char loginid[20];
	char password[20];
	student s;
	int option;
	cout<<"\n 1.DISPLAY DETAILS";
	cout<<"\n 2.UPDATE DETAILS";
	cout<<"\n ENTER OPTION";
	cin>>option;
	if(option==1)
	{
		clrscr();
		ifstream filein("student.dat",ios::binary);
		if(filein==0)
		{
			cout<<"\n UNABLE TO OPEN FILE";
			return;
		}
		cout<<"\n ENTER LOGIN ID: ";
		gets(loginid);
		strcpy(password,returnpassword());
		while(filein.read((char*)&s,sizeof(s)))
		{
			if(strcmp(s.returnloginid(),loginid)==0 && strcmp(s.returnpassword(),password)==0)
			{
				s.showstudentdata();
				flag=1;
			}
		}
		if(flag==0)
		{
			cout<<"\n RECORD NOT FOUND";
		}

	}
	else if(option==2)
	{
		studentupdate();
	}
}
void teacherfunc()
{
	clrscr();
	char loginid[20];  //function teacher can do
	int flag=0;
	char password[20];
	teacher t;
	int option;
	cout<<"\n 1.DISPLAY DETAILS";
	cout<<"\n 2.UPDATE DETAILS";
	cout<<"\n ENTER OPTION";
	cin>>option;
	if(option==1)
	{
		ifstream filein("teacher.dat",ios::binary);
		if(filein==0)
		{
			cout<<"\n UNABLE TO OPEN FILE";
			return;
		}
		cout<<"\n ENTER LOGIN ID: ";
		gets(loginid);
		strcpy(password,returnpassword());
		while(filein.read((char*)&t,sizeof(t)))
		{
			if(strcmp(t.returntloginid(),loginid)==0 && strcmp(t.returntpassword(),password)==0)
			{
				t.showteacherdata();
				flag=1;
			}
		}
		if(flag==0)
		{
			cout<<"\n RECORD NOT FOUND";
		}

	}
	else if(option==2)
	{
		teacherupdate();
	}
}
void introduction()
{
	cout<<"\n This program shows what one can achieve with programming";
	cout<<"\n This program can be used in any educational institute for";
	cout<<"\n holding student and teacher database with little modification";
	cout<<"\n now you will be redirected to main program";
	delay(2000);
}
void main()
{
	clrscr();
	introduction();
	clrscr();
	char passwd[10];
	strcpy(passwd,"abcd");    //program checks password
	if(strcmp(passwd,returnpassword())!=0)
	{
		cout<<"\n WRONG PASSWORD ENTERED";
		exit(0);
	}
	int option;
	char ch;
	do
	{
		clrscr();
		gotoxy(40,19);
		cout<<" MADE BY VASU SETHIA AND SHOURYA RASTOGI";
		gotoxy(40,20);
		cout<<"	CLASS 12 A ";
		gotoxy(40,21);
		cout<<" ROLLNO :31 & 29";
		gotoxy(30,10);
		cout<<"1.STUDENT";
		gotoxy(30,11);
		cout<<"2.TEACHER";
		gotoxy(30,12);
		cout<<"3.ADMINISTRATOR";
		gotoxy(30,13);
		cout<<"4.EXIT";
		gotoxy(30,14);
		cout<<" ENTER A OPTION";
		cin>>option;
		if(option==1)
		{
			studentfunc();
		}
		else if(option==2)
		{
			teacherfunc();
		}
		else if(option==3)
		{
			administrator();
		}
		else if(option==4)
		{
			exit(0);
		}
		else
		{
			cout<<"\n WRONG OPTION ENTERED";
		}
		cout<<"\n WANNNA CONTINUE TO MAIN MENU Press (y/n)";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	getch();
}







