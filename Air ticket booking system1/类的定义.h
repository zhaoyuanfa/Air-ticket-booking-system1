#pragma once
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <windows.h>   
#include <stdio.h>  
using namespace std;

class boss
{
public:
	boss(string pass) :password(pass)
	{
		//int managernumber = 0;
		fstream com_pfile;
		com_pfile.open("D:\\book_planeticket_system\\company\\com_pas.dat", ios::in | ios::out | ios::binary);
		com_pfile.seekg(0, ios::beg);
		com_pfile.write((char*)&pass, sizeof(string));	//�ļ���һ�У��ϰ�����루���24�ֽڣ�
														//com_pfile.write((char*)&managernumber, sizeof(int));	//�ļ��ڶ������ݣ�����������
		com_pfile.close();
	}
	void setmanager();
	void resetpassword(string);
protected:
	int id;
	string password;
};

class manager
{
public:
	manager() { M_ID = 0; password = '0'; name = '0'; }
	manager(int id, string pa, string na) :M_ID(id), password(pa), name(na) {}
	void outputmanager();
	int verifym(int, string);//��¼��֤���ź�����
protected:
	int M_ID;			//������Ա����
	string password, name;	//������Ա����
};

class flight_time
{
public:
	flight_time()
	{
		year = 0, month = 0, day = 0, hour = 0, min = 0, week = '0';
	}
	flight_time(int y, int m, int d, int h, int mi, string we)
	{
		year = y, month = m, day = d, hour = h, min = mi, week = we;
	}
	flight_time(int y, int m, int d, int h, int mi)
	{
		year = y, month = m, day = d, hour = h, min = mi, week = "0";
	}
	void resettime(int y, int m, int d, int h, int mi, string we)		//����ʱ��
	{
		year = y, month = m, day = d, hour = h, min = mi, week = we;
	}
	friend ostream& operator<<(ostream& output, flight_time&);
	flight_time & operator=(const flight_time&);
	friend bool operator>(flight_time, flight_time);
	int year, month, day, hour, min;	//����������Сʱ����
	string week;
};

class flight
{
public:
	//string flightid;			//�����
	flight()
	{
		statime.resettime(0, 0, 0, 0, 0, "0");
		lastime.resettime(0, 0, 0, 0, 0, "0");
		stastation = "0";
		lasstation = "0";
		planeid = 0;
		flightid = "0";
		firnumber = 0;
		secnumber = 0;
		trinumber = 0;
		fticprice = 0;
		sticprice = 0;
		tticprice = 0;
		fir_rest_ticket = 0;
		sec_rest_ticket = 0;
		tri_rest_ticket = 0;
		totle_rest_ticket = 0;
	};
	//���캯��
	flight(int pid, string flid,								//����
		int y, int m, int d, int h, int mi, string we,		//����
		int y1, int m1, int d1, int h1, int mi1, string we1,	//����
		string stas, string lass,								//����
		int fn, int sn, int tn, 								//����
		float fp, float sp, float tp)							//����
																/*����˳�򣺷ɻ���š������š�
																��ʼվ��ʱ�䣨������ʱ�֣������ڣ�
																�յ�վ��Ϣ��������ʱ�֣�������
																��ʼվ�����յ�վ����
																һ���������Ȳ���λ��//����������
																һ���������Ȳ���λ�۸�//����������
																*/
	{
		statime.resettime(y, m, d, h, mi, we);
		lastime.resettime(y1, m1, d1, h1, mi1, we1);
		stastation = stas;
		lasstation = lass;
		planeid = pid;
		flightid = flid;
		firnumber = fn;
		fn_start = fn;
		secnumber = sn;
		sn_start = sn;
		trinumber = tn;
		tn_start = tn;
		fticprice = fp;
		sticprice = sp;
		tticprice = tp;
		fir_rest_ticket = fn;
		sec_rest_ticket = sn;
		tri_rest_ticket = tn;
		totle_rest_ticket = fn + sn + tn;
	}
	friend ostream& operator<<(ostream& output, flight&);		//������Ϣ��������������ã�
	flight & operator=(const flight&);
	int compare_last(string);		//�Ƚ�Ŀ�ĵ�
	void userlook();		//�˿Ϳɿ����ļ򻯰���Ϣ
	void book_tic(int);		//��Ʊ
	void refund_tic(int);		//��Ʊ
	void lookat(string);	//�鿴��Ʊ��������Ϣ
	void lookbt();			//�鿴��Ʊ��Ա��Ϣ
	void lookwt();			//�鿴��Ʊ��Ա��Ϣ
	void resetmassage();	//�޸ĺ���
							//������������������������������
	int getfirnumber()
	{
		return firnumber;
	}
	int getsecnumber()
	{
		return secnumber;
	}
	int gettrinumber()
	{
		return trinumber;
	}
	friend bool operator>(flight, flight);		//���������>
	int output_lagerflight(flight_time);		//�����ĳһʱ���ĺ���
	string flightid;			//�����
protected:
	int fn_start;
	int sn_start;
	int tn_start;		//ԭʼ��������������
	int planeid;			//�ɻ���
							//string flightid;		//�����
	string stastation;		//��ʼվ
	string lasstation;		//�յ�վ
	flight_time statime;	//����ʱ��
	flight_time lastime;	//��վʱ��
	int firnumber;			//һ�Ȳ���λ��
	int secnumber;			//���Ȳ���λ��
	int trinumber;			//���Ȳ���λ��
	int fir_rest_ticket;	//һ�Ȳ���Ʊ��
	int sec_rest_ticket;	//���Ȳ���Ʊ��
	int tri_rest_ticket;	//���Ȳ���Ʊ��
	float fticprice;		//һ�Ȳռ۸�
	float sticprice;		//���Ȳռ۸�
	float tticprice;		//���Ȳռ۸�
	int totle_rest_ticket;	//����Ʊ����
};

class user
{
public:
	user() { userid = "0"; name = "0"; password = "0"; credit_card = "0"; phonenumber = "0"; };
	user(string id, string pa) { userid = id; name = "0"; password = pa; credit_card = "0"; phonenumber = "0"; };
	user(string id, string na, string pa, string cre, string pho) :userid(id), name(na), password(pa), credit_card(cre), phonenumber(pho) {}
	user& operator=(const user&);
	int identify(string);	//ȷ�����֤������ͬ
	int identifypa(string);	//������֤
	int locatedUser();		//���ص����û��Ĺ�˾��ţ���1��ʼ��
	void displaytic(string, flight[], int);		//��ѯ��Ʊ
	string outputusername();
	int usercomid = 0;			//�û���˾���
protected:
	string userid;			//�ͻ����֤��
	string name;			//�ͻ�����s
	string password;		//�ͻ�����
	string credit_card;		//���п���
	string phonenumber;     //�ͻ��绰����
};

class ticket
{
public:
	ticket()
	{
		planeid = 0;
		fightid = "0";
		stastation = "0";
		lasstation = "0";
		cabinlelve = 0;
		seatid = 0;
		price = 0;
	}
	ticket(int pid, int fid, string stas, string lass, flight_time t1, flight_time t2, int cabl, float pri)
	{
		planeid = pid;
		fightid = fid;
		stastation = stas;
		lasstation = lass;
		statime = t1;
		lastime = t2;
		cabinlelve = cabl;
		price = pri;
	}
	int seatid;				//��λ��
	user user1;
protected:
	int planeid;			//�ɻ���
	string fightid;			//�����
	string stastation;		//��ʼվ
	string lasstation;		//�յ�վ
	flight_time statime;	//����ʱ��
	flight_time lastime;	//��վʱ��
	int cabinlelve;			//��λ�ȼ�
	float price;			//Ʊ��
};


class ticket_record
{
public:
	int level;		//Ʊ������
	int number;
	int waitnumer;

};

int    locatedMassage(string);		//���ص��Ǻ�����ļ�λ�ã���0��ʼ��
flight readflight(int);
user   readuser(int);
void   lookAllFlight();
void   inquire(string);
int    userSignIn();				//�û�ע��ҳ�棬ע��ɹ�����1
int    userLogIn();				//�û���½ҳ��,��¼�ɹ�����1
void   IntToStr(const int&, string&);

void sortflight(flight[], int);		//��������

string getname(int);