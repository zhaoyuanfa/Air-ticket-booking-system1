
//
// ��������ʵ��.cpp
//
#include<iostream>
#include<string>
#include<iomanip>
#include<process.h>
#include <windows.h>   
#include <stdio.h>  
#include "��Ķ���.h"
using namespace std;

const string com_pas = "D:\\book_planeticket_system\\company\\com_pas.dat";	//��˾��Կ�ļ�����
const string user_pas = "D:\\book_planeticket_system\\company\\user_pas.dat";
const string flightmassage = "D:\\book_planeticket_system\\company\\flight\\flightmassage.dat";

int userSignIn()
{
	string userfilename;
	fstream userfile;
	int userNum;
	string userid;			//�ͻ����֤��
	string name;			//�ͻ�����
	string password;		//�ͻ�����
	string credit_card;		//���п���
	string phonenumber;		//�û��绰����
	cout << "������������";
	cin >> name;
	cout << "���������֤�ţ�";
	cin >> userid;
	cout << "���������룺";
	cin >> password;
	cout << "������绰���룺";
	cin >> phonenumber;
	cout << "������п���" << endl;
	cout << "�������������п��ţ�";
	cin >> credit_card;
	user user1(userid, name, password, credit_card, phonenumber);
	if (user1.locatedUser() != 0)
	{
		system("cls");
		cout << endl << endl;
		cout << "���Ѿ�ע�������ǰ����½��" << endl;
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

	//�����û���¼�ļ�
	string inttostrname;//�û����ת��Ϊstring��
	IntToStr(user1.usercomid, inttostrname);
	userfilename = "D:\\book_planeticket_system\\user\\" + inttostrname + ".dat";//�Ա����������Ʊ��Ϣ
	userfile.open(userfilename, ios::in);
	if (!userfile)
	{
		userfile.open(userfilename, ios::out);//�½��û���¼�ļ�
	}
	userfile.close();
	system("cls");
	cout << endl << endl;
	cout << "ע��ɹ�,��ӭʹ�ñ����ඩƱϵͳ��";
	cout << endl << endl;
	return 1;
}

user user_login("dfsssa", "sssssssssssssss");
int userLogIn()
{
	int usercomid1;
	fstream userFile;
	string userid1, password1;		//�û���������֤�ź�����
	cout << "���������֤���룺";
	cin >> userid1;
	cout << "���������룺";
	cin >> password1;
	user user1(userid1, password1);
	usercomid1 = user1.locatedUser();
	if (usercomid1 == 0)
	{
		system("cls");
		cout << endl << endl;
		cout << "����δע�ᣬ����ע�ᣡ" << endl;
		cout << endl << endl;
		return 0;
	}
	userFile.open(user_pas, ios::in | ios::out | ios::binary);
	userFile.seekg((sizeof(int) + sizeof(user)*(user1.locatedUser() - 1)), ios::beg);
	userFile.read((char*)&user_login, sizeof(user));
	userFile.close();
	while (!user_login.identifypa(password1))
	{
		cout << "����������������루����0�˳���¼����";
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


