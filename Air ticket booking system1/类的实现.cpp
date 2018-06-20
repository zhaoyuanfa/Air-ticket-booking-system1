#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>
#include <windows.h>   
#include <stdio.h>  
#include "��Ķ���.h"
using namespace std;

const string com_pas = "D:\\book_planeticket_system\\company\\com_pas.dat";	//��˾��Կ�ļ�����
const string user_pas = "D:\\book_planeticket_system\\company\\user_pas.dat";
const string flightmassage = "D:\\book_planeticket_system\\company\\flight\\flightmassage.dat";
fstream file; //���ڴ�����������ļ����Լ��ļ��Ķ�д

void boss::resetpassword(string password)
{
	fstream com_pfile;
	com_pfile.open("D:\\book_planeticket_system\\company\\com_pas.dat", ios::in | ios::out | ios::binary);
	com_pfile.seekg(0, ios::beg);
	com_pfile.write((char*)&password, sizeof(string));	//�ļ���һ�У��ϰ�����루���24�ֽڣ�
	com_pfile.close();
}
void boss::setmanager()
{
	int M_id, idnumber = 0; string password, name;
	cout << "����������߹��š���������Ϊ���趨�����루���ź������Կո��������" << endl;
	cin >> M_id >> name >> password;
	manager m(M_id, password, name);
	fstream com_pfile;
	com_pfile.open("D:\\book_planeticket_system\\company\\com_pas.dat", ios::in | ios::out | ios::binary);
	com_pfile.seekg(sizeof(string), ios::beg);		//�ܿ��ϰ�����
	com_pfile.read((char*)&idnumber, sizeof(int));
	com_pfile.seekg(sizeof(string) + sizeof(int) + sizeof(manager)*idnumber, ios::beg);
	com_pfile.write((char*)&m, sizeof(manager));		//�ӵ��������ݿ�ʼ�ǹ����߱�ź�����
	com_pfile.seekg(sizeof(string), ios::beg);
	idnumber++;
	com_pfile.write((char*)&idnumber, sizeof(int));				//�޸Ĺ���������
	com_pfile.close();
}

void manager::outputmanager()
{
	cout << M_ID << "\t" << name << "\t" << endl;
}
int manager::verifym(int id, string pass)
{
	if (id == M_ID && pass == password)
		return 1;
	else
		return 0;
}



ostream& operator<<(ostream& output, flight_time& flight_time1)
{
	output << flight_time1.year << "��" << flight_time1.month << "��" << flight_time1.day << "��";
	output << flight_time1.hour << "ʱ" << flight_time1.min << "��" << " " << flight_time1.week;
	return output;
}
flight_time&flight_time::operator=(const flight_time&obj)
{
	year = obj.year; month = obj.month; day = obj.day; hour = obj.hour; min = obj.min;
	week = obj.week;
	return *this;
}
bool operator>(flight_time time1, flight_time time2)
{
	if (time1.year >= time2.year)
	{
		if (time1.year > time2.year)
			return 1;
		else
			if (time1.month >= time2.month)
			{
				if (time1.month > time2.month)
					return 1;
				else
					if (time1.day >= time2.day)
					{
						if (time1.day > time2.day)
							return 1;
						else
							if (time1.hour >= time2.hour)
							{
								if (time1.hour > time2.hour)
									return 1;
								else
									if (time1.min >= time2.min)
									{
										return 1;
									}
									else
										return 0;

							}
							else
								return 0;

					}
					else
						return 0;
			}
			else
				return 0;
	}
	else
		return 0;
}

ostream& operator<<(ostream& output, flight& flight1)
{
	output << " ---------------------------------------------------------" << endl;
	output << "| ����ţ�" << setw(12) << flight1.flightid << "                                    |" << endl;
	output << "| �ɻ���ţ�" << setw(10) << flight1.planeid << "                                    |" << endl;
	output << "| ���վ��" << setw(12) << flight1.stastation << "                                    |" << endl;
	output << "| �յ�վ��" << setw(12) << flight1.lasstation << "                                    |" << endl;
	output << "| ����ʱ�䣺" << flight1.statime.year << "��" << setw(2) << flight1.statime.month << "��" << setw(2) << flight1.statime.day << "��" << " " << setw(2) << flight1.statime.hour << "ʱ" << setw(2) << flight1.statime.min << "��" << "   ����" << flight1.statime.week << "              |" << endl;
	output << "| ��վʱ�䣺" << flight1.lastime.year << "��" << setw(2) << flight1.lastime.month << "��" << setw(2) << flight1.lastime.day << "��" << " " << setw(2) << flight1.lastime.hour << "ʱ" << setw(2) << flight1.lastime.min << "��" << "   ����" << flight1.lastime.week << "              |" << endl;
	output << "|                                                         |" << endl;
	output << "| һ�Ȳ���λ������" << setw(12) << flight1.firnumber << "                            |" << endl;
	output << "| һ�Ȳ���λ���ۣ�" << setw(12) << flight1.fticprice << "                            |" << endl;
	output << "| һ�Ȳ���λ������" << setw(12) << flight1.fir_rest_ticket << "                            |" << endl;
	output << "|                                                         |" << endl;
	output << "| ���Ȳ���λ������" << setw(12) << flight1.secnumber << "                            |" << endl;
	output << "| ���Ȳ���λ���ۣ�" << setw(12) << flight1.sticprice << "                            |" << endl;
	output << "| ���Ȳ���λ������" << setw(12) << flight1.sec_rest_ticket << "                            |" << endl;
	output << "|                                                         |" << endl;
	output << "| ���Ȳ���λ������" << setw(12) << flight1.tn_start << "                            |" << endl;
	output << "| ���Ȳ���λ���ۣ�" << setw(12) << flight1.tticprice << "                            |" << endl;
	output << "| ���Ȳ���λ������" << setw(12) << flight1.tri_rest_ticket << "                            |" << endl;
	output << "|                                                         |" << endl;
	output << "| ����Ʊ����" << setw(12) << flight1.totle_rest_ticket << "                                  |" << endl;
	output << "|---------------------------------------------------------|" << endl << endl;
	return output;
}
flight & flight::operator=(const flight& obj)
{
	fn_start = obj.fn_start;
	sn_start = obj.sn_start;
	tn_start = obj.tn_start;
	statime = obj.statime;
	lastime = obj.lastime;
	planeid = obj.planeid;			//�ɻ���
	flightid = obj.flightid;		//�����
	stastation = obj.stastation;		//��ʼվ
	lasstation = obj.lasstation;		//�յ�վ
	firnumber = obj.firnumber;			//һ�Ȳ���λ��
	secnumber = obj.secnumber;			//���Ȳ���λ��
	trinumber = obj.trinumber;			//���Ȳ���λ��
	fir_rest_ticket = obj.fir_rest_ticket;	//һ�Ȳ���Ʊ��
	sec_rest_ticket = obj.sec_rest_ticket;	//���Ȳ���Ʊ��
	tri_rest_ticket = obj.tri_rest_ticket;	//���Ȳ���Ʊ��
	fticprice = obj.fticprice;		//һ�Ȳռ۸�
	sticprice = obj.sticprice;		//���Ȳռ۸�
	tticprice = obj.tticprice;		//���Ȳռ۸�
	totle_rest_ticket = obj.totle_rest_ticket;	//����Ʊ����
	return *this;
}
bool operator>(flight flight1, flight flight2)
{
	if (flight1.statime > flight2.statime)
		return 1;
	else
		return 0;
}
void flight::userlook()
{
	cout << " ---------------------------------------------------------" << endl;
	cout << "| ����ţ�" << setw(12) << flightid << "                                    |" << endl;
	cout << "| �ɻ���ţ�" << setw(10) << planeid << "                                    |" << endl;
	cout << "| ���վ��" << setw(12) << stastation << "                                    |" << endl;
	cout << "| �յ�վ��" << setw(12) << lasstation << "                                    |" << endl;
	cout << "| ����ʱ�䣺" << statime.year << "��" << setw(2) << statime.month << "��" << setw(2) << statime.day << "��" << " " << setw(2) << statime.hour << "ʱ" << setw(2) << statime.min << "��" << "   ����" << statime.week << "              |" << endl;
	cout << "| ��վʱ�䣺" << lastime.year << "��" << setw(2) << lastime.month << "��" << setw(2) << lastime.day << "��" << " " << setw(2) << lastime.hour << "ʱ" << setw(2) << lastime.min << "��" << "   ����" << lastime.week << "              |" << endl;
	cout << "|                                                         |" << endl;
	cout << "| һ�Ȳ���λ���ۣ�" << setw(12) << fticprice << "                            |" << endl;
	cout << "| һ�Ȳ���λ������" << setw(12) << fir_rest_ticket << "                            |" << endl;
	cout << "|                                                         |" << endl;
	cout << "| ���Ȳ���λ���ۣ�" << setw(12) << sticprice << "                            |" << endl;
	cout << "| ���Ȳ���λ������" << setw(12) << sec_rest_ticket << "                            |" << endl;
	cout << "|                                                         |" << endl;
	cout << "| ���Ȳ���λ���ۣ�" << setw(12) << tticprice << "                            |" << endl;
	cout << "| ���Ȳ���λ������" << setw(12) << tri_rest_ticket << "                            |" << endl;
	cout << "|---------------------------------------------------------|" << endl << endl;
}
void flight::lookat(string flightid1)
{
	fstream lookat_file;
	int bookfnum, refundfnum, waitfnum, choose;//��Ʊ��������Ʊ��������Ʊ����,ѡ����
	int booksnum, refundsnum, waitsnum;
	int booktnum, refundtnum, waittnum;
	lookat_file.open("D:\\book_planeticket_system\\company\\flight\\" + flightid1 + ".dat", ios::in | ios::binary);
	lookat_file.read((char*)&bookfnum, sizeof(int));
	lookat_file.read((char*)&refundfnum, sizeof(int));
	lookat_file.read((char*)&waitfnum, sizeof(int));
	lookat_file.read((char*)&booksnum, sizeof(int));
	lookat_file.read((char*)&refundsnum, sizeof(int));
	lookat_file.read((char*)&waitsnum, sizeof(int));
	lookat_file.read((char*)&booktnum, sizeof(int));
	lookat_file.read((char*)&refundtnum, sizeof(int));
	lookat_file.read((char*)&waittnum, sizeof(int));
	cout << "             " << setw(10) << "��Ʊ����" << setw(10) << "��Ʊ����" << setw(10) << "��Ʊ����" << endl;
	cout << "  һ����     " << setw(10) << bookfnum << setw(10) << refundfnum << setw(10) << waitfnum << endl;
	cout << "  ������     " << setw(10) << booksnum << setw(10) << refundsnum << setw(10) << waitsnum << endl;
	cout << "  ������     " << setw(10) << booktnum << setw(10) << refundtnum << setw(10) << waittnum << endl;
	lookat_file.close();
}
void flight::resetmassage()
{
	system("cls");
	cout << endl << endl;
	cout << "������ʾ�������ѷ�����������޸ģ�" << endl;
	cout << endl;
	cout << endl;
	while (1)
	{
		int n;
		cout << "|-----------------------------�޸ĺ�����Ϣҳ��---------------------------------|" << endl;
		cout << endl;
		cout << "���޸ĵ��������£�1������������ڣ������£�             2�����ൽ�����ڣ������£�" << endl;
		cout << "                  3��һ��������                           4������������" << endl;
		cout << "                  5������������                           6��һ�����۸�" << endl;
		cout << "                  7���������۸�                           8���������۸�" << endl;
		cout << "����Ҫ�޸�ʲô��Ϣ������������ѡ����(�˳��޸�����0)��" << endl;
		cin >> n;
		if (n == 1)
		{

			int y, m, d, h, mi;
			string wek;
			int c = 0;
			cout << "����������������ڣ��ꡢ�¡��ա�ʱ���־��ÿո��������" << endl;
			cin >> y >> m >> d >> h >> mi;
			cout << "���������ڣ�һ�����������ġ��塢�����գ���" << endl;
			cin >> wek;
			cout << "�޸ĺ�Ϊ��" << endl;
			flight f;
			f = *this;
			f.statime.resettime(y, m, d, h, mi, wek);
			cout << f << endl;
			cout << "ȷ���޸ģ�����������ѡ��ȷ�ϣ�1��ȡ����0������";
			cin >> c;
			if (c == 1)
			{
				fstream f0;
				int id_i = locatedMassage(flightid);
				f0.open(flightmassage, ios::in | ios::out | ios::binary);
				f0.seekg(sizeof(int) + sizeof(flight)*id_i, ios::beg);
				f0.write((char*)&f, sizeof(flight));
				f0.close();
				system("cls");
				cout << endl << endl;
				cout << "�޸ĳɹ���" << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				system("cls");
				cout << endl << endl;
				cout << "��ȡ���޸ģ�" << endl;
				cout << endl;
				cout << endl;
			}
		}
		if (n == 2)
		{
			int y, m, d, h, mi;
			string wek;
			int c = 0;
			cout << "���������뵽�����ڣ��ꡢ�¡��ա�ʱ���־��ÿո��������" << endl;
			cin >> y >> m >> d >> h >> mi;
			cout << "���������ڣ�һ�����������ġ��塢�����գ���" << endl;
			cin >> wek;
			cout << "�޸ĺ�Ϊ��" << endl;
			flight f;
			f = *this;
			f.lastime.resettime(y, m, d, h, mi, wek);
			cout << f << endl;
			cout << "ȷ���޸ģ�����������ѡ��ȷ�ϣ�1��ȡ����0������";
			cin >> c;
			if (c == 1)
			{
				fstream f1;
				int id_i = locatedMassage(flightid);
				f1.open(flightmassage, ios::in | ios::out | ios::binary);
				f1.seekg(sizeof(int) + sizeof(flight)*id_i, ios::beg);
				f1.write((char*)&f, sizeof(flight));
				f1.close();
				system("cls");
				cout << endl << endl;
				cout << "�޸ĳɹ���" << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				system("cls");
				cout << endl << endl;
				cout << "��ȡ���޸ģ�" << endl;
				cout << endl;
				cout << endl;
			}
		}
		if (n == 3)
		{
			int c = 0;
			int n;
			cout << "������һ����������" << endl;
			cin >> n;
			if (firnumber - n>fir_rest_ticket)
			{
				system("cls");
				cout << endl << endl;
				cout << "�Ѿ���" << n << "�����϶�Ʊ���������޸ĸ����ݣ���" << endl;
				cout << endl << endl;
				continue;
			}
			cout << "�޸ĺ�Ϊ��" << endl;
			flight f;
			f = *this;
			f.firnumber = n;
			f.fir_rest_ticket = fir_rest_ticket - (firnumber - n);
			f.totle_rest_ticket = totle_rest_ticket - (firnumber - n);
			cout << f << endl;
			cout << "ȷ���޸ģ�����������ѡ��ȷ�ϣ�1��ȡ����0������";
			cin >> c;
			if (c == 1)
			{
				fstream f2;
				int id_i = locatedMassage(flightid);
				f2.open(flightmassage, ios::in | ios::out | ios::binary);
				f2.seekg(sizeof(int) + sizeof(flight)*id_i, ios::beg);
				f2.write((char*)&f, sizeof(flight));
				f2.close();
				system("cls");
				cout << endl << endl;
				cout << "�޸ĳɹ���" << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				system("cls");
				cout << endl << endl;
				cout << "��ȡ���޸ģ�" << endl;
				cout << endl;
				cout << endl;
			}
		}
		if (n == 4)
		{
			int c = 0;
			int n;
			cout << "�����������������" << endl;
			cin >> n;
			if (secnumber - n>sec_rest_ticket)
			{
				system("cls");
				cout << endl << endl;
				cout << "�Ѿ���" << n << "�����϶�Ʊ���������޸ĸ����ݣ���" << endl;
				cout << endl << endl;
				continue;
			}
			cout << "�޸ĺ�Ϊ��" << endl;

			flight f;
			f = *this;
			f.secnumber = n;
			f.sec_rest_ticket = sec_rest_ticket - (secnumber - n);
			f.totle_rest_ticket = totle_rest_ticket - (secnumber - n);
			cout << f << endl;
			cout << "ȷ���޸ģ�����������ѡ��ȷ�ϣ�1��ȡ����0������";
			cin >> c;
			if (c == 1)
			{
				fstream f4;
				int id_i = locatedMassage(flightid);
				f4.open(flightmassage, ios::in | ios::out | ios::binary);
				f4.seekg(sizeof(int) + sizeof(flight)*id_i, ios::beg);
				f4.write((char*)&f, sizeof(flight));
				f4.close();
				system("cls");
				cout << endl << endl;
				cout << "�޸ĳɹ���" << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				system("cls");
				cout << endl << endl;
				cout << "��ȡ���޸ģ�" << endl;
				cout << endl;
				cout << endl;
			}
		}
		if (n == 5)
		{
			int c = 0;
			int n;
			cout << "������������������" << endl;
			cin >> n;
			if (trinumber - n>tri_rest_ticket)
			{
				system("cls");
				cout << endl << endl;
				cout << "�Ѿ���" << n << "�����϶�Ʊ���������޸ĸ����ݣ���" << endl;
				cout << endl << endl;
				continue;
			}
			cout << "�޸ĺ�Ϊ��" << endl;

			flight f;
			f = *this;
			f.trinumber = n;
			f.tri_rest_ticket = tri_rest_ticket - (trinumber - n);
			f.totle_rest_ticket = totle_rest_ticket - (trinumber - n);
			cout << f << endl;
			cout << "ȷ���޸ģ�����������ѡ��ȷ�ϣ�1��ȡ����0������";
			cin >> c;
			if (c == 1)
			{
				fstream f5;
				int id_i = locatedMassage(flightid);
				f5.open(flightmassage, ios::in | ios::out | ios::binary);
				f5.seekg(sizeof(int) + sizeof(flight)*id_i, ios::beg);
				f5.write((char*)&f, sizeof(flight));
				f5.close();
				system("cls");
				cout << endl << endl;
				cout << "�޸ĳɹ���" << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				system("cls");
				cout << endl << endl;
				cout << "��ȡ���޸ģ�" << endl;
				cout << endl;
				cout << endl;
			}
		}
		if (n == 6)
		{
			int c = 0;
			float n;
			cout << "������һ�����۸�" << endl;
			cin >> n;
			cout << "�޸ĺ�Ϊ��" << endl;
			flight f;
			f = *this;
			f.fticprice = n;
			cout << f << endl;

			cout << "ȷ���޸ģ�����������ѡ��ȷ�ϣ�1��ȡ����0������";
			cin >> c;
			if (c == 1)
			{
				fstream f5;
				int id_i = locatedMassage(flightid);
				f5.open(flightmassage, ios::in | ios::out | ios::binary);
				f5.seekg(sizeof(int) + sizeof(flight)*id_i, ios::beg);
				f5.write((char*)&f, sizeof(flight));
				f5.close();
				system("cls");
				cout << endl << endl;
				cout << "�޸ĳɹ���" << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				system("cls");
				cout << endl << endl;
				cout << "��ȡ���޸ģ�" << endl;
				cout << endl;
				cout << endl;
			}
		}
		if (n == 7)
		{
			int c = 0;
			float n;
			cout << "������������۸�" << endl;
			cin >> n;
			cout << "�޸ĺ�Ϊ��" << endl;

			flight f;
			f = *this;
			f.sticprice = n;
			cout << f << endl;
			cout << "ȷ���޸ģ�����������ѡ��ȷ�ϣ�1��ȡ����0������";
			cin >> c;
			if (c == 1)
			{
				fstream f6;
				int id_i = locatedMassage(flightid);
				f6.open(flightmassage, ios::in | ios::out | ios::binary);
				f6.seekg(sizeof(int) + sizeof(flight)*id_i, ios::beg);
				f6.write((char*)&f, sizeof(flight));
				f6.close();
				system("cls");
				cout << endl << endl;
				cout << "�޸ĳɹ���" << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				system("cls");
				cout << endl << endl;
				cout << "��ȡ���޸ģ�" << endl;
				cout << endl;
				cout << endl;
			}
		}
		if (n == 8)
		{
			int c = 0;
			float n;
			cout << "�������������۸�" << endl;
			cin >> n;
			cout << "�޸ĺ�Ϊ��" << endl;

			flight f;
			f = *this;
			f.tticprice = n;
			cout << f << endl;

			cout << "ȷ���޸ģ�����������ѡ��ȷ�ϣ�1��ȡ����0������";
			cin >> c;
			if (c == 1)
			{
				fstream f7;
				int id_i = locatedMassage(flightid);
				f7.open(flightmassage, ios::in | ios::out | ios::binary);
				f7.seekg(sizeof(int) + sizeof(flight)*id_i, ios::beg);
				f7.write((char*)&f, sizeof(flight));
				f7.close();
				system("cls");
				cout << endl << endl;
				cout << "�޸ĳɹ���" << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				system("cls");
				cout << endl << endl;
				cout << "��ȡ���޸ģ�" << endl;
				cout << endl;
				cout << endl;
			}
		}
		if (n == 0)
		{
			system("cls");
			cout << endl << endl;
			cout << "�ɹ��˳��޸ģ�" << endl;
			cout << endl;
			cout << endl;
			break;
		}
	}
}
int flight::output_lagerflight(flight_time t)
{
	if (statime > t)
	{
		userlook();
		return 1;
	}
	else
		return 0;
}
int flight::compare_last(string place)
{
	if (lasstation == place)
		return 1;
	else
		return 0;
}
void flight::book_tic(int usercomid1)
{
	fstream f8;
	f8.open(flightmassage, ios::in | ios::out | ios::binary);
	cout << locatedMassage(flightid);
	int flightid_i = -1;
	flightid_i = locatedMassage(flightid);
	//cout << "�������" << flightid_i << endl;
	//while (1);
	int choose, fn, sn, tn;//ѡ������һ����������Ʊ��
	user users;
	users = readuser(usercomid1);
	cout << "������������ѡ���λ��1��һ�Ȳ�     2�����Ȳ�      3�����Ȳ�" << endl;
	cin >> choose;
	if (choose == 1)
	{
		cout << "�����붩Ʊ������";
		cin >> fn;
		while (fn<0 || fn > firnumber)
		{
			cout << "��Ʊ����������" << firnumber << "�Ҳ�С��0��" << endl;
			cout << "���������룺";
			cin >> fn;
		}
		if (fn > fir_rest_ticket)
		{
			int v = 1;
			cout << "��Ʊ���㣬ֻʣ" << fir_rest_ticket << "�ţ��Ƿ��Ʊ?" << endl;
			cout << "����:1   ��:0������������ѡ��";
			cin >> v;
			if (v == 0)
			{
				system("cls");
				cout << endl << endl;
				cout << "����ȡ�����ι�Ʊ��" << endl << endl << endl;
				f8.close();
				return;
			}
			else
			{
				fstream file1;
				int *a = new int[fn_start * 2]; int *b = new int[4 * fn_start];
				int flook, fwait;//�ļ�������Ʊ��һ�ȶ�Ʊ������һ�Ⱥ�Ʊ����
				file1.open("D:\\book_planeticket_system\\company\\flight\\" + flightid + ".dat", ios::in | ios::out | ios::binary);
				file1.read((char*)&flook, sizeof(int));
				file1.read((char*)&fwait, sizeof(int));
				file1.seekg(sizeof(int) * 6, ios::beg);
				file1.read((char*)a, sizeof(int) * 2 * fn_start);
				file1.read((char*)b, sizeof(int) * 4 * fn_start);
				for (int i = 0; i < 4 * fn_start; i += 2)
				{
					if (b[i] == users.usercomid)
					{
						b[i + 1] += fn;
						break;
					}
					else
					{
						if (b[i] == 0)
						{
							b[i] = users.usercomid;
							b[i + 1] = fn;
							fwait++;
							break;
						}
					}
				}
				file1.seekg(sizeof(int), ios::beg);
				file1.write((char*)&fwait, sizeof(int));
				file1.seekg(sizeof(int) * 6 + sizeof(int) * 2 * fn_start, ios::beg);
				file1.write((char*)b, sizeof(int) * 4 * fn_start);
				file1.close();
				file.close();
				system("cls");
				cout << endl << endl;
				cout << "�Ѽ����Ʊ��" << endl;
				cout << endl << endl;
				delete[]a;
				delete[]b;
			}
		}
		if (fn <= fir_rest_ticket)
		{
			fstream file1;
			int *a = new int[fn_start * 2]; int *b = new int[4 * fn_start];
			int flook, fwait;//�ļ�������Ʊ��һ�ȶ�Ʊ������һ�Ⱥ�Ʊ����
			file1.open("D:\\book_planeticket_system\\company\\flight\\" + flightid + ".dat", ios::in | ios::out | ios::binary);
			file1.read((char*)&flook, sizeof(int));
			file1.read((char*)&fwait, sizeof(int));
			file1.seekg(sizeof(int) * 6, ios::beg);
			file1.read((char*)a, sizeof(int) * 2 * fn_start);
			//file1.seekg(sizeof(int) * 6 + sizeof(int) * 2 * fn_start, ios::beg);
			file1.read((char*)b, sizeof(int) * 4 * fn_start);
			for (int i = 0; i < 2 * fn_start; i += 2)
			{
				if (a[i] == users.usercomid)
				{
					a[i + 1] += fn;
					break;
				}
				else
				{
					if (a[i] == 0)
					{
						a[i] = users.usercomid;
						a[i + 1] = fn;
						if (fn != 0)
						{
							flook++;
						}
						break;
					}
				}
			}
			file1.seekg(0, ios::beg);
			file1.write((char*)&flook, sizeof(int));
			file1.seekg(sizeof(int) * 6, ios::beg);
			file1.write((char*)a, sizeof(int) * 2 * fn_start);
			file1.close();
			flight flight_look_f;
			flight_look_f = *this;
			flight_look_f.fir_rest_ticket -= fn;
			flight_look_f.totle_rest_ticket -= fn;
			system("cls");
			cout << endl << endl;
			cout << "��Ʊ�ɹ���" << endl;
			cout << endl << endl;
			f8.seekg(sizeof(int) + sizeof(flight)*flightid_i, ios::beg);
			f8.write((char*)&flight_look_f, sizeof(flight));
			delete[]a;
			delete[]b;
			f8.close();
		}
	}
	if (choose == 2)
	{
		cout << "�����붩Ʊ������";
		cin >> sn;
		while (sn > secnumber)
		{
			cout << "��Ʊ����������" << secnumber << endl;
			cout << "���������룺";
			cin >> sn;
		}
		if (sn > sec_rest_ticket)
		{
			int v = 1;
			cout << "��Ʊ���㣬ֻʣ" << sec_rest_ticket << "�ţ��Ƿ��Ʊ?" << endl;
			cout << "����:1   ��:0������������ѡ��";
			cin >> v;
			if (v == 0)
			{
				f8.close();
				return;
			}
			else
			{
				fstream file1;
				int *a = new int[sn_start * 2]; int *b = new int[4 * sn_start];
				int slook, swait;//�ļ�������Ʊ��һ�ȶ�Ʊ������һ�Ⱥ�Ʊ����
				file1.open("D:\\book_planeticket_system\\company\\flight\\" + flightid + ".dat", ios::in | ios::out | ios::binary);
				file1.seekg(sizeof(int) * 2, ios::beg);
				file1.read((char*)&slook, sizeof(int));
				file1.read((char*)&swait, sizeof(int));
				file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start, ios::beg);
				file1.read((char*)a, sizeof(int) * 2 * sn_start);
				file1.read((char*)b, sizeof(int) * 4 * sn_start);
				for (int i = 0; i < 4 * sn_start; i += 2)
				{
					if (b[i] == users.usercomid)
					{
						b[i + 1] += sn;
						break;
					}
					else
					{
						if (b[i] == 0)
						{
							b[i] = users.usercomid;
							b[i + 1] = sn;
							swait++;
							break;
						}
					}
				}
				file1.seekg(sizeof(int) * 3, ios::beg);
				file1.write((char*)&swait, sizeof(int));
				file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start + sizeof(int) * 2 * sn_start, ios::beg);
				file1.write((char*)b, sizeof(int) * 4 * sn_start);
				file1.close();
				f8.close();
				system("cls");
				cout << endl << endl;
				cout << "�Ѽ����Ʊ��" << endl;
				cout << endl << endl;
				delete[]a;
				delete[]b;
			}
		}
		if (sn <= sec_rest_ticket)
		{
			fstream file1;
			int *a = new int[sn_start * 2]; int *b = new int[4 * sn_start];
			int slook, swait;//�ļ�������Ʊ��һ�ȶ�Ʊ������һ�Ⱥ�Ʊ����
			file1.open("D:\\book_planeticket_system\\company\\flight\\" + flightid + ".dat", ios::in | ios::out | ios::binary);
			file1.seekg(sizeof(int) * 2, ios::beg);
			file1.read((char*)&slook, sizeof(int));
			file1.read((char*)&swait, sizeof(int));
			file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start, ios::beg);
			file1.read((char*)a, sizeof(int) * 2 * sn_start);
			file1.read((char*)b, sizeof(int) * 4 * sn_start);
			for (int i = 0; i < 2 * sn_start; i += 2)
			{
				if (a[i] == users.usercomid)
				{
					a[i + 1] += sn;
					break;
				}
				else
				{
					if (a[i] == 0)
					{
						a[i] = users.usercomid;
						a[i + 1] = sn;
						if (sn != 0)
						{
							slook++;
						}
						break;
					}
				}
			}
			file1.seekg(sizeof(int) * 2, ios::beg);
			file1.write((char*)&slook, sizeof(int));
			file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start, ios::beg);
			file1.write((char*)a, sizeof(int) * 2 * sn_start);
			file1.close();
			sec_rest_ticket -= sn;
			system("cls");
			cout << endl << endl;
			cout << "�Ѷ�Ʊ��" << endl;
			cout << endl << endl;
			f8.seekg(sizeof(int) + sizeof(flight)*flightid_i, ios::beg);
			f8.write((char*)this, sizeof(flight));
			f8.close();
			delete[]a;
			delete[]b;
		}
	}
	if (choose == 3)
	{
		cout << "�����붩Ʊ������";
		cin >> tn;
		while (tn > trinumber)
		{
			cout << "��Ʊ����������" << trinumber << endl;
			cout << "���������룺";
			cin >> tn;
		}
		if (tn > tri_rest_ticket)
		{
			int v = 1;
			cout << "��Ʊ���㣬ֻʣ" << tri_rest_ticket << "�ţ��Ƿ��Ʊ?" << endl;
			cout << "����:1   ��:0������������ѡ��";
			cin >> v;
			if (v == 0)
			{
				f8.close();
				return;
			}
			else
			{
				fstream file1;
				int *a = new int[tn_start * 2]; int *b = new int[4 * tn_start];
				int tlook, twait;//�ļ�������Ʊ��һ�ȶ�Ʊ������һ�Ⱥ�Ʊ����
				file1.open("D:\\book_planeticket_system\\company\\flight\\" + flightid + ".dat", ios::in | ios::out | ios::binary);
				file1.seekg(sizeof(int) * 4, ios::beg);
				file1.read((char*)&tlook, sizeof(int));
				file1.read((char*)&twait, sizeof(int));
				file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start + sizeof(int) * 6 * tn_start, ios::beg);
				file1.read((char*)a, sizeof(int) * 2 * tn_start);
				file1.read((char*)b, sizeof(int) * 4 * tn_start);
				for (int i = 0; i < 4 * tn_start; i += 2)
				{
					if (b[i] == users.usercomid)
					{
						b[i + 1] += tn;
						break;
					}
					else
					{
						if (b[i] == 0)
						{
							b[i] = users.usercomid;
							b[i + 1] = tn;
							twait++;
							break;
						}
					}
				}
				file1.seekg(sizeof(int) * 5, ios::beg);
				file1.write((char*)&twait, sizeof(int));
				file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start + sizeof(int) * 6 * sn_start + sizeof(int) * 2 * tn_start, ios::beg);
				file1.write((char*)b, sizeof(int) * 4 * tn_start);
				file1.close();
				f8.close();
				system("cls");
				cout << endl << endl;
				cout << "�Ѽ����Ʊ��" << endl;
				cout << endl << endl;
				delete[]a;
				delete[]b;
			}
		}
		if (tn <= tri_rest_ticket)
		{
			fstream file1;
			int *a = new int[tn_start * 2]; int *b = new int[4 * tn_start];
			int tlook, twait;//�ļ�������Ʊ��һ�ȶ�Ʊ������һ�Ⱥ�Ʊ����
			file1.open("D:\\book_planeticket_system\\company\\flight\\" + flightid + ".dat", ios::in | ios::out | ios::binary);
			file1.seekg(sizeof(int) * 4, ios::beg);
			file1.read((char*)&tlook, sizeof(int));
			file1.read((char*)&twait, sizeof(int));
			file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start + sizeof(int) * 6 * tn_start, ios::beg);
			file1.read((char*)a, sizeof(int) * 2 * tn_start);
			file1.read((char*)b, sizeof(int) * 4 * tn_start);
			for (int i = 0; i < 2 * tn_start; i += 2)
			{
				if (a[i] == users.usercomid)
				{
					a[i + 1] += tn;
					break;
				}
				else
				{
					if (a[i] == 0)
					{
						a[i] = users.usercomid;
						a[i + 1] = tn;
						if (tn != 0)
						{
							tlook++;
						}
						break;
					}
				}
			}
			file1.seekg(sizeof(int) * 4, ios::beg);
			file1.write((char*)&tlook, sizeof(int));
			file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start + sizeof(int) * 6 * sn_start, ios::beg);
			file1.write((char*)a, sizeof(int) * 2 * tn_start);
			file1.close();
			tri_rest_ticket -= tn;
			f8.seekg(sizeof(int) + sizeof(flight)*flightid_i, ios::beg);
			f8.write((char*)this, sizeof(flight));
			f8.close();
			cout << "�Ѷ�Ʊ��" << endl;
			delete[]a;
			delete[]b;
		}
	}
}
void flight::refund_tic(int usercomid1)
{
	fstream f9;
	f9.open(flightmassage, ios::in | ios::out | ios::binary);
	int flightid_i = locatedMassage(flightid);
	int choose, fn, sn, tn;//ѡ������һ����������Ʊ��
	user users;
	users = readuser(usercomid1);
	cout << "����ѡ����Ʊ��λ��1��һ�Ȳ�     2�����Ȳ�      3�����Ȳ�";
	cin >> choose;
	if (choose == 1)
	{
		int f_l_rest = 0, f_w_rest = 0;//�Ѷ����Ѻ�Ʊ��
		int f_l_refund = 0, f_w_refund = 0;//����Ʊ��
		fstream file1;
		int *a = new int[fn_start * 2]; int *b = new int[4 * fn_start];
		int flook, fwait;//�ļ�������Ʊ��һ�ȶ�Ʊ������һ�Ⱥ�Ʊ����
		file1.open("D:\\book_planeticket_system\\company\\flight\\" + flightid + ".dat", ios::in | ios::out | ios::binary);
		file1.read((char*)&flook, sizeof(int));
		file1.read((char*)&fwait, sizeof(int));
		file1.seekg(sizeof(int) * 6, ios::beg);
		file1.read((char*)a, sizeof(int) * 2 * fn_start);
		file1.read((char*)b, sizeof(int) * 4 * fn_start);
		for (int i = 0; i < 2 * fn_start; i += 2)//�õ��ͻ���Ʊ��
		{
			if (a[i] == users.usercomid)
			{
				f_l_rest = a[i + 1];
				break;
			}
			else
			{
				if (a[i] == 0)
				{
					f_l_rest = 0;
					break;
				}
			}
		}
		for (int i = 0; i < 4 * fn_start; i += 2)
		{
			if (b[i] == users.usercomid)
			{
				f_w_rest = b[i + 1];
				break;
			}
			else
			{
				if (b[i] == 0)
				{
					f_w_rest = b[i + 1] = 0;
					break;
				}
			}
		}
		if (f_w_rest == 0 && f_l_rest == 0)
		{
			cout << "����ǰ��" << f_l_rest << "���Ѷ���һ�Ȳ���Ʊ��" << f_w_rest << "�ŵȺ��һ�Ȳ���Ʊ,��������һ�Ȳ���Ʊ��" << endl;
			file1.close();
			f9.close();
			return;
		}
		cout << "����ǰ��" << f_l_rest << "���Ѷ���Ʊ��" << f_w_rest << "�ŵȺ��Ʊ��" << endl;
		cout << "���������˶��Ѷ���Ʊ�͵Ⱥ��Ʊ���������Կո���������˶�������0)��" << endl;
		cin >> f_l_refund >> f_w_refund;
		while (f_l_refund<0 || f_w_refund<0 || f_l_refund>f_l_rest || f_w_refund>f_w_rest)
		{
			cout << "������������벻С��0�Ҳ������Ѷ������������֣�";
			cin >> f_l_refund >> f_w_refund;
		}
		for (int i = 0; i < 2 * fn_start; i += 2)//�޸��û�����Ʊ��
		{
			if (a[i] == users.usercomid)
			{
				a[i + 1] -= f_l_refund;
				fir_rest_ticket += f_l_refund;
				totle_rest_ticket += f_l_refund;
				if (a[i + 1] == 0 && f_l_rest != 0)//�����޸Ķ�Ʊ����
				{
					flook--;
				}
				break;
			}
		}
		for (int i = 0; i < 4 * fn_start; i += 2)
		{
			if (b[i] == users.usercomid)
			{
				b[i + 1] -= f_w_refund;
				if (b[i + 1] == 0 && f_w_rest != 0)
				{
					fwait--;
				}
				break;
			}
		}
		int user_comid_i = 0;//���ں�Ʊ�����û���˾���
		int ticnumber = 0;
		for (int i = 0; i < 4 * fn_start; i += 2)
		{
			if (b[i] == 0)
				break;
			if (b[i + 1] > 0 && b[i + 1] <= fir_rest_ticket)
			{
				user_comid_i = b[i];
				ticnumber = b[i + 1];
				b[i + 1] = 0;
				break;
			}
		}
		if (user_comid_i)
		{
			for (int i = 0; i < 2 * fn_start; i += 2)
			{
				if (a[i] == user_comid_i)
				{
					a[i + 1] += ticnumber;
					fir_rest_ticket -= ticnumber;
					totle_rest_ticket -= ticnumber;
					break;
				}
				if (a[i] == 0)
				{
					a[i] = user_comid_i;
					a[i + 1] = ticnumber;
					fir_rest_ticket -= ticnumber;
					totle_rest_ticket -= ticnumber;
					break;
				}
			}
		}
		file1.seekg(0, ios::beg);
		file1.write((char*)&flook, sizeof(int));
		file1.write((char*)&fwait, sizeof(int));
		file1.seekg(sizeof(int) * 6, ios::beg);
		file1.write((char*)a, sizeof(int) * 2 * fn_start);
		file1.write((char*)b, sizeof(int) * 4 * fn_start);
		f9.seekg(sizeof(int) + sizeof(flight)*flightid_i, ios::beg);
		f9.write((char*)this, sizeof(flight));
		cout << "����Ʊ��" << endl;
		delete[]a;
		delete[]b;
	}
	if (choose == 2)
	{
		int s_l_rest = 0, s_w_rest = 0;//�Ѷ����Ѻ�Ʊ��
		int s_l_refund = 0, s_w_refund = 0;//����Ʊ��
		fstream file1;
		int *a = new int[sn_start * 2]; int *b = new int[4 * sn_start];
		int slook, swait;//�ļ�������Ʊ��һ�ȶ�Ʊ������һ�Ⱥ�Ʊ����
		file1.open("D:\\book_planeticket_system\\company\\flight\\" + flightid + ".dat", ios::in | ios::out | ios::binary);
		file1.seekg(sizeof(int) * 2, ios::beg);
		file1.read((char*)&slook, sizeof(int));
		file1.read((char*)&swait, sizeof(int));
		file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start, ios::beg);
		file1.read((char*)a, sizeof(int) * 2 * sn_start);
		file1.read((char*)b, sizeof(int) * 4 * sn_start);
		for (int i = 0; i < 2 * sn_start; i += 2)//�õ��ͻ���Ʊ��
		{
			if (a[i] == users.usercomid)
			{
				s_l_rest = a[i + 1];
				break;
			}
			else
			{
				if (b[i] == 0)
				{
					s_l_rest = 0;
					break;
				}
			}
		}
		for (int i = 0; i < 4 * sn_start; i += 2)
		{
			if (b[i] == users.usercomid)
			{
				s_w_rest = b[i + 1];
				break;
			}
			else
			{
				if (b[i] == 0)
				{
					s_w_rest = 0;
					break;
				}
			}
		}
		if (s_l_rest == 0 && s_w_rest == 0)
		{
			cout << "����ǰ��" << s_l_rest << "���Ѷ��Ķ��Ȳ���Ʊ��" << s_w_rest << "�ŵȺ�Ķ��Ȳ���Ʊ��" << endl;
			cout << "�����˶��Ȳ���Ʊ��";
			f9.close();
			file.close();
			return;
		}
		cout << "����ǰ��" << s_l_rest << "���Ѷ��Ķ��Ȳ���Ʊ��" << s_w_rest << "�ŵȺ�Ķ��Ȳ���Ʊ��" << endl;
		cout << "���������Ѿ����Ķ��Ȳ���Ʊ������(���˶�������0)��";
		cin >> s_l_refund;
		cout << "�������˵Ⱥ�Ķ��Ȳ���Ʊ������(���˶�������0)��";
		cin >> s_w_refund;
		while (s_l_refund<0 || s_w_refund<0 || s_l_refund>s_l_rest || s_w_refund>s_w_rest)
		{
			cout << "������������벻С��0�Ҳ������Ѷ������������֣�";
			cin >> s_l_refund >> s_w_refund;
		}
		for (int i = 0; i < 2 * sn_start; i += 2)//�޸��û�����Ʊ��
		{
			if (a[i] == users.usercomid)
			{
				a[i + 1] -= s_l_refund;
				sec_rest_ticket += s_l_refund;
				totle_rest_ticket += s_l_refund;
				if (a[i + 1] == 0 && s_l_rest != 0)//�����޸Ķ�Ʊ����
				{
					slook--;
				}
				break;
			}
		}
		for (int i = 0; i < 4 * sn_start; i += 2)
		{
			if (b[i] == users.usercomid)
			{
				b[i + 1] -= s_w_refund;
				if (b[i + 1] == 0 && s_w_rest != 0)
				{
					swait--;
				}
				break;
			}
		}
		int user_comid_i = 0;//���ں�Ʊ�����û���˾���
		int ticnumber = 0;
		for (int i = 0; i < 4 * sn_start; i += 2)
		{
			if (b[i] == 0)
				break;
			if (b[i + 1] > 0 && b[i + 1] <= sec_rest_ticket)
			{
				user_comid_i = b[i];
				ticnumber = b[i + 1];
				b[i + 1] = 0;
				break;
			}
		}
		if (user_comid_i)
		{
			for (int i = 0; i < 2 * sn_start; i += 2)
			{
				if (a[i] == user_comid_i)
				{
					a[i + 1] = ticnumber;
					sec_rest_ticket -= ticnumber;
					totle_rest_ticket -= ticnumber;
					break;
				}
				if (a[i] == 0)
				{
					a[i] = user_comid_i;
					a[i + 1] = ticnumber;
					sec_rest_ticket -= ticnumber;
					totle_rest_ticket -= ticnumber;
					break;
				}
			}
		}
		file1.seekg(sizeof(int) * 2, ios::beg);
		file1.write((char*)&slook, sizeof(int));
		file1.write((char*)&swait, sizeof(int));
		file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start, ios::beg);
		file1.write((char*)a, sizeof(int) * 2 * fn_start);
		file1.write((char*)b, sizeof(int) * 4 * fn_start);
		file1.close();
		f9.seekg(sizeof(int) + sizeof(flight)*flightid_i, ios::beg);
		f9.write((char*)this, sizeof(flight));
		f9.close();
		cout << "����Ʊ��" << endl;
		delete[]a;
		delete[]b;
	}
	if (choose == 3)
	{
		int t_l_rest = 0, t_w_rest = 0;//�Ѷ����Ѻ�Ʊ��
		int t_l_refund = 0, t_w_refund = 0;//����Ʊ��
		fstream file1;
		int *a = new int[tn_start * 2]; int *b = new int[4 * tn_start];
		int tlook, twait;//�ļ�������Ʊ��һ�ȶ�Ʊ������һ�Ⱥ�Ʊ����
		file1.open("D:\\book_planeticket_system\\company\\flight\\" + flightid + ".dat", ios::in | ios::out | ios::binary);
		file1.seekg(sizeof(int) * 4, ios::beg);
		file1.read((char*)&tlook, sizeof(int));
		file1.read((char*)&twait, sizeof(int));
		file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start + sizeof(int) * 6 * sn_start, ios::beg);
		file1.read((char*)a, sizeof(int) * 2 * tn_start);
		file1.read((char*)b, sizeof(int) * 4 * tn_start);
		for (int i = 0; i < 2 * tn_start; i += 2)//�õ��ͻ���Ʊ��
		{
			if (a[i] == users.usercomid)
			{
				t_l_rest = a[i + 1];
				break;
			}
			else
			{
				if (b[i] == 0)
				{
					t_l_rest = 0;
					break;
				}
			}
		}
		for (int i = 0; i < 4 * tn_start; i += 2)
		{
			if (b[i] == users.usercomid)
			{
				t_w_rest = b[i + 1];
				break;
			}
			else
			{
				if (b[i] == 0)
				{
					t_w_rest = b[i + 1] = 0;
					break;
				}
			}
		}
		if (t_l_rest == 0 && t_w_rest == 0)
		{
			cout << "����ǰ��" << t_l_rest << "���Ѷ��Ķ��Ȳ���Ʊ��" << t_w_rest << "�ŵȺ�Ķ��Ȳ���Ʊ��" << endl;
			cout << "�����˶��Ȳ���Ʊ��";
			f9.close();
			file.close();
			return;
		}
		cout << "����ǰ��" << t_l_rest << "���Ѷ������Ȳ���Ʊ��" << t_w_rest << "�ŵȺ�����Ȳ���Ʊ��" << endl;
		cout << "���������Ѿ��������Ȳ���Ʊ������(���˶�������0)��";
		cin >> t_l_refund;
		cout << "�������˵Ⱥ�����Ȳ���Ʊ������(���˶�������0)��";
		cin >> t_w_refund;
		cin >> t_l_refund >> t_w_refund;
		while (t_l_refund<0 || t_w_refund<0 || t_l_refund>t_l_rest || t_w_refund>t_w_rest)
		{
			cout << "������������벻С��0�Ҳ������Ѷ������������֣�";
			cin >> t_l_refund >> t_w_refund;
		}
		for (int i = 0; i < 2 * tn_start; i += 2)//�޸��û�����Ʊ��
		{
			if (a[i] == users.usercomid&&t_l_rest != 0)
			{
				a[i + 1] -= t_l_refund;
				sec_rest_ticket += t_l_refund;
				totle_rest_ticket += t_l_refund;
				if (a[i + 1] == 0 && t_l_rest != 0)//�����޸Ķ�Ʊ����
				{
					tlook--;
				}
				break;
			}
		}
		for (int i = 0; i < 4 * tn_start; i += 2)
		{
			if (b[i] == users.usercomid)
			{
				b[i + 1] -= t_w_refund;
				if (b[i + 1] == 0 && t_w_rest != 0)
				{
					twait--;
				}
				break;
			}
		}
		int user_comid_i = 0;//���ں�Ʊ�����û���˾���
		int ticnumber = 0;
		for (int i = 0; i < twait * 2; i += 2)
		{
			if (b[i] == 0)
				break;
			if (b[i + 1] > 0 && b[i + 1] <= tri_rest_ticket)
			{
				user_comid_i = b[i];
				ticnumber = b[i + 1];
				b[i + 1] = 0;
				break;
			}
		}
		if (user_comid_i)
		{
			for (int i = 0; i < 4 * tn_start; i += 2)
			{
				if (a[i] == user_comid_i)
				{
					a[i + 1] = ticnumber;
					sec_rest_ticket += t_l_refund;
					totle_rest_ticket += t_l_refund;
					break;
				}
				if (a[i] == 0)
				{
					a[i] = user_comid_i;
					a[i + 1] = ticnumber;
					sec_rest_ticket += t_l_refund;
					totle_rest_ticket += t_l_refund;
					break;
				}
			}
		}
		file1.seekg(sizeof(int) * 4, ios::beg);
		file1.write((char*)&tlook, sizeof(int));
		file1.write((char*)&twait, sizeof(int));
		file1.seekg(sizeof(int) * 6 + sizeof(int) * 6 * fn_start + sizeof(int) * 6 * sn_start, ios::beg);
		file1.write((char*)a, sizeof(int) * 2 * tn_start);
		file1.write((char*)b, sizeof(int) * 4 * tn_start);
		file1.close();
		f9.seekg(sizeof(int) + sizeof(flight)*flightid_i, ios::beg);
		f9.write((char*)this, sizeof(flight));
		f9.close();
		system("cls");
		cout << endl << endl;
		cout << "����Ʊ��" << endl;
		cout << endl << endl;
		delete[]a;
		delete[]b;
	}
}
void flight::lookbt()
{
	int *a = new int[2 * fn_start];
	int *b = new int[2 * sn_start];
	int *c = new int[2 * tn_start];
	fstream file2;
	file2.open("D:\\book_planeticket_system\\company\\flight\\" + flightid + ".dat", ios::in | ios::out | ios::binary);
	file2.seekg((sizeof(int) * 6), ios::beg);
	file2.read((char*)a, sizeof(int) * 2 * fn_start);
	file2.seekg((sizeof(int) * 6) + sizeof(int) * 6 * fn_start, ios::beg);
	file2.read((char*)b, sizeof(int) * 2 * sn_start);
	file2.seekg((sizeof(int) * 6) + sizeof(int) * 6 * fn_start + sizeof(int) * 6 * sn_start, ios::beg);
	file2.read((char*)c, sizeof(int) * 2 * tn_start);
	file2.close();
	cout << "��Ʊ�������£�" << endl << endl;
	cout << setw(12) << "����" << setw(10) << "��Ʊ��" << setw(10) << "��λ�ȼ�" << endl;
	for (int i = 0; i < 2 * fn_start; i += 2)
	{
		if (a[i] > 0 && a[i + 1] > 0)
		{
			cout << setw(12) << getname(a[i]) << setw(10) << a[i + 1] << setw(10) << 1 << endl;
		}
	}
	for (int i = 0; i < 2 * sn_start; i += 2)
	{
		if (b[i] > 0 && b[i + 1] > 0)
		{
			cout << setw(12) << getname(b[i]) << setw(10) << b[i + 1] << setw(10) << 2 << endl;
		}
	}
	for (int i = 0; i < 2 * tn_start; i += 2)
	{
		if (c[i] > 0 && c[i + 1] > 0)
		{
			cout << setw(12) << getname(c[i]) << setw(10) << c[i + 1] << setw(10) << 3 << endl;
		}
	}
	cout << endl;
}
void flight::lookwt()
{
	int *a = new int[4 * fn_start]();
	int *b = new int[4 * sn_start]();
	int *c = new int[4 * tn_start]();
	fstream file2;
	file2.open("D:\\book_planeticket_system\\company\\flight\\" + flightid + ".dat", ios::in | ios::out | ios::binary);
	file2.seekg((sizeof(int) * 6) + sizeof(int) * 2 * fn_start, ios::beg);
	file2.read((char*)a, sizeof(int) * 4 * fn_start);
	file2.seekg((sizeof(int) * 6) + sizeof(int) * 6 * fn_start + sizeof(int) * 2 * sn_start, ios::beg);
	file2.read((char*)b, sizeof(int) * 4 * sn_start);
	file2.seekg((sizeof(int) * 6) + sizeof(int) * 6 * fn_start + sizeof(int) * 6 * sn_start + sizeof(int) * 2 * tn_start, ios::beg);
	file2.read((char*)c, sizeof(int) * 4 * tn_start);
	file2.close();
	cout << "��Ʊ�������£�" << endl << endl;
	cout << setw(12) << "����" << setw(10) << "��Ʊ��" << setw(10) << "��λ�ȼ�" << endl;
	for (int i = 0; i < 4 * fn_start; i += 2)
	{
		if (a[i] > 0 && a[i + 1] > 0)
		{
			cout << setw(12) << getname(a[i]) << setw(10) << a[i + 1] << setw(10) << 1 << endl;
		}
	}
	for (int i = 0; i < 4 * sn_start; i += 2)
	{
		if (b[i] > 0 && b[i + 1] > 0)
		{
			cout << setw(12) << getname(b[i]) << setw(10) << b[i + 1] << setw(10) << 2 << endl;
		}
	}
	for (int i = 0; i < 4 * tn_start; i += 2)
	{
		if (c[i] > 0 && c[i + 1] > 0)
		{
			cout << setw(12) << getname(c[i]) << setw(10) << c[i + 1] << setw(10) << 3 << endl;
		}
	}
	cout << endl;
}

string user::outputusername()
{
	return name;
}
int  user::identify(string str)
{
	if (str == userid)
		return 1;
	else
		return 0;
}
int  user::locatedUser()
{
	fstream userFile;
	int usernumber = 0;
	int userid_i = -1;
	userFile.open(user_pas, ios::in | ios::out | ios::binary);
	userFile.read((char*)&usernumber, sizeof(int));
	user *user1 = new user[usernumber];
	userFile.seekg(sizeof(int), ios::beg);
	for (int i = 0; i < usernumber; i++)
	{
		userFile.seekg(sizeof(int) + sizeof(user)*i, ios::beg);
		userFile.read((char*)&user1[i], sizeof(flight));
		if (user1[i].identify(userid))
		{
			userid_i = i;
			break;
		}
	}
	userFile.close();
	return (++userid_i);
}
int  user::identifypa(string pa)
{
	if (pa == password)
		return 1;
	else
		return 0;
}
void user::displaytic(string place, flight p[], int n)
{

	sortflight(p, n);
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	flight_time time((int)sys.wYear, (int)sys.wMonth, (int)sys.wDay, (int)sys.wHour, (int)sys.wMinute);
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{

		if (p[i].compare_last(place))
		{
			if (p[i].output_lagerflight(time))
			{
				a = 1;
			}
			b = 1;
		}
	}
	if (b == 0)
	{
		cout << endl;
		cout << "�Բ���û��ȥ" << place << "�ĺ��࣡" << endl;
		cout << endl;
	}
	if (b != 0 && a == 0)
	{
		cout << endl;
		cout << "�Բ���û�к���ʱ��ĺ��࣡" << endl;
		cout << endl;
	}
}
user& user::operator=(const user&user1)
{
	usercomid = user1.usercomid;
	userid = user1.userid;			//�ͻ����֤��
	name = user1.name;			//�ͻ�����
	password = user1.password;		//�ͻ�����
	credit_card = user1.credit_card;		//���п���
	phonenumber = user1.phonenumber;     //�ͻ��绰����
	return *this;
}

int locatedMassage(string flightid1)
{
	fstream ff;
	int flightnumber1 = 0;
	int flightid_i = -1;
	ff.open(flightmassage, ios::in | ios::out | ios::binary);
	ff.read((char*)&flightnumber1, sizeof(int));
	ff.seekg(sizeof(int), ios::beg);
	flight *flight4 = new flight[flightnumber1];
	for (int i = 0; i < flightnumber1; i++)
	{
		ff.read((char*)&flight4[i], sizeof(flight));
		if (flight4[i].flightid == flightid1)
		{
			flightid_i = i;
			break;
		}
	}
	ff.close();
	return flightid_i;
}
flight flight_readflight;
flight readflight(int id_i)
{
	fstream f11;
	f11.open(flightmassage, ios::in | ios::out | ios::binary);
	f11.seekg((sizeof(int) + sizeof(flight)*id_i), ios::beg);
	f11.read((char*)&flight_readflight, sizeof(flight));
	f11.close();
	return flight_readflight;
}
user user_readuser;
user   readuser(int usercomid)
{
	fstream f12;
	f12.open(user_pas, ios::in | ios::out | ios::binary);
	f12.seekg(sizeof(int) + sizeof(user)*(usercomid - 1), ios::beg);
	f12.read((char*)&user_readuser, sizeof(user));
	f12.close();
	return user_readuser;
}
void lookAllFlight()
{
	fstream f13;
	int flightnumber;//��������
	f13.open(flightmassage, ios::in | ios::out | ios::binary);
	f13.read((char*)&flightnumber, sizeof(int));
	f13.seekg(sizeof(int), ios::beg);
	flight *flight2 = new flight[flightnumber];
	for (int i = 0; i < flightnumber; i++)
	{
		f13.read((char*)&flight2[i], sizeof(flight));
		cout << flight2[i] << endl;
	}
	f13.close();
}

string getname(int userid_i)
{
	user user1 = readuser(userid_i);
	return user1.outputusername();
}