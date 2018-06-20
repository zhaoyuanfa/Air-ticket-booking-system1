
//
// 其他功能实现.cpp
//
#include<iostream>
#include<string>
#include<iomanip>
#include<process.h>
#include <windows.h>   
#include <stdio.h>  
#include "类的定义.h"
using namespace std;

const string com_pas = "D:\\book_planeticket_system\\company\\com_pas.dat";	//公司密钥文件代名
const string user_pas = "D:\\book_planeticket_system\\company\\user_pas.dat";
const string flightmassage = "D:\\book_planeticket_system\\company\\flight\\flightmassage.dat";

int userSignIn()
{
	string userfilename;
	fstream userfile;
	int userNum;
	string userid;			//客户身份证号
	string name;			//客户姓名
	string password;		//客户密码
	string credit_card;		//银行卡号
	string phonenumber;		//用户电话号码
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入身份证号：";
	cin >> userid;
	cout << "请设置密码：";
	cin >> password;
	cout << "请输入电话号码：";
	cin >> phonenumber;
	cout << "请绑定银行卡！" << endl;
	cout << "请输入您的银行卡号：";
	cin >> credit_card;
	user user1(userid, name, password, credit_card, phonenumber);
	if (user1.locatedUser() != 0)
	{
		system("cls");
		cout << endl << endl;
		cout << "您已经注册过，请前往登陆！" << endl;
		cout << endl << endl;
		return 0;
	}
	userfile.open(user_pas, ios::in | ios::out | ios::binary);
	userfile.read((char*)&userNum, sizeof(int));
	user1.usercomid = userNum + 1;
	userfile.seekg(sizeof(int) + sizeof(user)*userNum, ios::beg);
	userfile.write((char*)&user1, sizeof(user));
	userfile.seekg(0, ios::beg);
	++userNum;
	userfile.write((char*)&(userNum), sizeof(int));
	userfile.close();

	//生成用户记录文件
	string inttostrname;//用户编号转化为string型
	IntToStr(user1.usercomid, inttostrname);
	userfilename = "D:\\book_planeticket_system\\user\\" + inttostrname + ".dat";//以编号名命名订票信息
	userfile.open(userfilename, ios::in);
	if (!userfile)
	{
		userfile.open(userfilename, ios::out);//新建用户记录文件
	}
	userfile.close();
	system("cls");
	cout << endl << endl;
	cout << "注册成功,欢迎使用本航班订票系统！";
	cout << endl << endl;
	return 1;
}

user user_login("dfsssa", "sssssssssssssss");
int userLogIn()
{
	int usercomid1;
	fstream userFile;
	string userid1, password1;		//用户输入的身份证号和密码
	cout << "请输入身份证号码：";
	cin >> userid1;
	cout << "请输入密码：";
	cin >> password1;
	user user1(userid1, password1);
	usercomid1 = user1.locatedUser();
	if (usercomid1 == 0)
	{
		system("cls");
		cout << endl << endl;
		cout << "您尚未注册，请先注册！" << endl;
		cout << endl << endl;
		return 0;
	}
	userFile.open(user_pas, ios::in | ios::out | ios::binary);
	userFile.seekg((sizeof(int) + sizeof(user)*(user1.locatedUser() - 1)), ios::beg);
	userFile.read((char*)&user_login, sizeof(user));
	userFile.close();
	while (!user_login.identifypa(password1))
	{
		cout << "密码错误，请重新输入（输入0退出登录）：";
		cin >> password1;
		if (password1 == "0")
			return 0;
	}
	return usercomid1;
}

void sortflight(flight p[], int n)
{
	for (int i = 0; i<n - 1; i++)
		for (int j = 0; j<n - i - 1; j++)
		{
			if (p[j]>p[j + 1])
			{
				flight temp;
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
}

void   IntToStr(const int& int_temp, string &str_temp)
{
	stringstream stream;
	stream << int_temp;
	str_temp = stream.str();
}


