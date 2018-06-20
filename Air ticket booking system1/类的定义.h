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
		com_pfile.write((char*)&pass, sizeof(string));	//文件第一行，老板的密码（最多24字节）
														//com_pfile.write((char*)&managernumber, sizeof(int));	//文件第二个数据：管理者人数
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
	int verifym(int, string);//登录验证工号和密码
protected:
	int M_ID;			//管理人员工号
	string password, name;	//管理人员密码
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
	void resettime(int y, int m, int d, int h, int mi, string we)		//重置时间
	{
		year = y, month = m, day = d, hour = h, min = mi, week = we;
	}
	friend ostream& operator<<(ostream& output, flight_time&);
	flight_time & operator=(const flight_time&);
	friend bool operator>(flight_time, flight_time);
	int year, month, day, hour, min;	//航班年月日小时分钟
	string week;
};

class flight
{
public:
	//string flightid;			//航班号
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
	//构造函数
	flight(int pid, string flid,								//参数
		int y, int m, int d, int h, int mi, string we,		//参数
		int y1, int m1, int d1, int h1, int mi1, string we1,	//参数
		string stas, string lass,								//参数
		int fn, int sn, int tn, 								//参数
		float fp, float sp, float tp)							//参数
																/*参数顺序：飞机编号、航班编号、
																起始站的时间（年月日时分）、星期；
																终点站信息（年月日时分）、星期
																起始站名、终点站名、
																一、二、三等舱座位数//三个参数）
																一、二、三等舱座位价格//三个参数）
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
	friend ostream& operator<<(ostream& output, flight&);		//航班信息的输出（管理者用）
	flight & operator=(const flight&);
	int compare_last(string);		//比较目的地
	void userlook();		//顾客可看到的简化版信息
	void book_tic(int);		//订票
	void refund_tic(int);		//退票
	void lookat(string);	//查看订票的整体信息
	void lookbt();			//查看订票人员信息
	void lookwt();			//查看侯票人员信息
	void resetmassage();	//修改航班
							//下面三个函数返回三个舱座的数量
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
	friend bool operator>(flight, flight);		//重载运算符>
	int output_lagerflight(flight_time);		//输出比某一时间大的航班
	string flightid;			//航班号
protected:
	int fn_start;
	int sn_start;
	int tn_start;		//原始三个舱座的数量
	int planeid;			//飞机号
							//string flightid;		//航班号
	string stastation;		//起始站
	string lasstation;		//终点站
	flight_time statime;	//出发时间
	flight_time lastime;	//到站时间
	int firnumber;			//一等舱座位数
	int secnumber;			//二等舱座位数
	int trinumber;			//三等舱座位数
	int fir_rest_ticket;	//一等舱余票量
	int sec_rest_ticket;	//二等舱余票量
	int tri_rest_ticket;	//三等舱余票量
	float fticprice;		//一等舱价格
	float sticprice;		//二等舱价格
	float tticprice;		//三等舱价格
	int totle_rest_ticket;	//总余票数量
};

class user
{
public:
	user() { userid = "0"; name = "0"; password = "0"; credit_card = "0"; phonenumber = "0"; };
	user(string id, string pa) { userid = id; name = "0"; password = pa; credit_card = "0"; phonenumber = "0"; };
	user(string id, string na, string pa, string cre, string pho) :userid(id), name(na), password(pa), credit_card(cre), phonenumber(pho) {}
	user& operator=(const user&);
	int identify(string);	//确认身份证号码相同
	int identifypa(string);	//密码验证
	int locatedUser();		//返回的是用户的公司编号（从1开始）
	void displaytic(string, flight[], int);		//查询机票
	string outputusername();
	int usercomid = 0;			//用户公司编号
protected:
	string userid;			//客户身份证号
	string name;			//客户姓名s
	string password;		//客户密码
	string credit_card;		//银行卡号
	string phonenumber;     //客户电话号码
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
	int seatid;				//座位号
	user user1;
protected:
	int planeid;			//飞机号
	string fightid;			//航班号
	string stastation;		//起始站
	string lasstation;		//终点站
	flight_time statime;	//出发时间
	flight_time lastime;	//到站时间
	int cabinlelve;			//座位等级
	float price;			//票价
};


class ticket_record
{
public:
	int level;		//票的种类
	int number;
	int waitnumer;

};

int    locatedMassage(string);		//返回的是航班的文件位置（从0开始）
flight readflight(int);
user   readuser(int);
void   lookAllFlight();
void   inquire(string);
int    userSignIn();				//用户注册页面，注册成功返回1
int    userLogIn();				//用户登陆页面,登录成功返回1
void   IntToStr(const int&, string&);

void sortflight(flight[], int);		//航班排序

string getname(int);