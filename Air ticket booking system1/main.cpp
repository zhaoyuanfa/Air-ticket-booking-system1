//
// main.cpp
//
#include<iostream>
#include<string>
#include<iomanip>
#include<process.h>
#include <windows.h>   
#include <stdio.h>  
#include "��Ķ���.h"
using namespace std;

string bosspassword, bosspassword1;    //case�е��ϰ��������õ���������(���ظ�ʹ��)
string p;
string mpassword, mpassword1;
string flightidname;		//�����¼���ļ���
string flightid1;		//�����������Բ�ѯ������Ϣ
flight flight1;
user users;				//��½����û�

int main()
{
	//�ļ�����ģ��
	const string com_pas = "D:\\book_planeticket_system\\company\\com_pas.dat";	//��˾��Կ�ļ�����
	const string user_pas = "D:\\book_planeticket_system\\company\\user_pas.dat";
	const string flightmassage = "D:\\book_planeticket_system\\company\\flight\\flightmassage.dat";
	system("md D:\\book_planeticket_system\\company");			//��˾�ļ�
	system("md D:\\book_planeticket_system\\user");			//��˾�ļ�
	system("md D:\\book_planeticket_system\\company\\flight");	//�����ļ�
	fstream file; //���ڴ�����������ļ����Լ��ļ��Ķ�д

	if (1)	//�����ļ�
	{
		file.open(com_pas, ios::in);
		if (!file)
		{
			file.open(com_pas, ios::out);//��˾��Ա��Կ
		}
		file.close();

		file.open(user_pas, ios::in);
		if (!file)
		{
			file.open(user_pas, ios::out);//�û���Կ
		}
		file.close();

		file.open(flightmassage, ios::in);
		if (!file)
		{
			file.open(flightmassage, ios::out);//����������Ϣ�ļ�
		}
		file.close();
	}

	if (1)	//��ʼ�������½��ļ�
	{
		//��˾��Կ�ļ��ĳ�ʼ��
		file.open(com_pas, ios::in | ios::out | ios::binary);
		file.seekg(0, ios::beg);
		long pos = file.tellg();
		file.seekg(0, ios::end);
		long pos1 = file.tellg();
		if (pos == pos1)
		{
			boss boss1("0");
			file.seekg(sizeof(string), ios::beg);
			int managernumber = 0;
			file.write((char*)&managernumber, sizeof(int));
		}
		file.close();
		//������Ϣ�ļ��ĳ�ʼ��
		file.open(flightmassage, ios::in | ios::out | ios::binary);
		file.seekg(0, ios::beg);
		pos = file.tellg();
		file.seekg(0, ios::end);
		pos1 = file.tellg();
		if (pos == pos1)		//���ļ������ʼ��
		{
			file.seekg(0, ios::beg);
			int flightidnumber = 0;
			file.write((char*)&flightidnumber, sizeof(int));//��ʼ����������
		}
		file.close();

		//��˾��Կ�ļ��ĳ�ʼ��
		file.open(user_pas, ios::in | ios::out | ios::binary);
		file.seekg(0, ios::beg);
		pos = file.tellg();
		file.seekg(0, ios::end);
		pos1 = file.tellg();
		if (pos == pos1)
		{
			boss boss1("0");
			file.seekg(sizeof(string), ios::beg);
			int userernumber = 0;
			file.write((char*)&userernumber, sizeof(int));
		}
		file.close();
	}


	cout << "��ӭʹ�ú��ն�Ʊϵͳ��" << endl;
	int choose;
	system("CLS");
	cout << endl << endl;
	cout << "��ʾ�����������ѡ��������빦��ǰ������" << endl << endl;
	cout << "|--------------------------------��ǰλ�ã���ʼҳ�棨0��--------------------------------------|" << endl;
	cout << "���ѡ��    1���ϰ�       2������Ա        3���û�" << endl;
	cout << "��ѡ���������:";
	cin >> choose;
	while (choose<0 || choose>4)
	{
		cout << "������1~3��������ѡ����ݣ�" << endl;
		cout << "��ѡ����ݣ�";
		cin >> choose;
	}
	system("cls");
	cout << endl << endl;
	while (1)
	{
		int exitv = 0;
		switch (choose)
		{
		case 0:
		{
			cout << "|--------------------------------��ǰλ�ã���ʼҳ�棨0��--------------------------------------|" << endl;
			cout << "���ѡ��    1���ϰ�       2������Ա        3���û� " << endl;
			cout << "��ѡ���������:";
			cin >> choose;
			while (choose < 1 || choose>4)
			{
				cout << "������1~3��������ѡ����ݣ�" << endl;
				cout << "��ѡ����ݣ�";
				cin >> choose;
			}
			system("cls");
			cout << endl << endl;
			break;
		}
		case 1:
		{
			fstream f14;
			cout << "|-----------------------------��ǰλ�ã��ϰ��¼ҳ��---------------------------------|" << endl;
			f14.open(com_pas, ios::in | ios::out | ios::binary);
			f14.seekg(0, ios::beg);
			f14.read((char*)&bosspassword, sizeof(string));
			if (bosspassword == "0")			//����û���������趨����
			{
				cout << "���ϰ����趨���룺";
				cin >> bosspassword;
				f14.seekg(0, ios::beg);
				f14.write((char*)&bosspassword, sizeof(string));
				f14.close();
			}
			else
			{
				f14.close();
			}
			fstream f20;
			f20.open(com_pas, ios::in | ios::out | ios::binary);
			f20.seekg(0, ios::beg);
			f20.read((char*)&p, sizeof(string));
			boss boss2(p);
			f20.close();
			if (bosspassword != "0")
			{
				cout << "������������е�¼:";
				cin >> bosspassword1;
				while ((bosspassword != bosspassword1) && (bosspassword1 != "0"))
				{
					cout << "�����������������(������ʼҳ��������0)��";
					cin >> bosspassword1;
				}
				if (bosspassword1 == "0")
				{
					choose = 0;
					cout << "|---------------------------------------------------------------------------------------------|";
					cout << endl << endl;
					break;
				}
				system("cls");
				cout << endl << endl;
				cout << "��½�ɹ�!" << endl;
				cout << endl << endl;
				cout << "|-----------------------------��ǰλ�ã��ϰ����ҳ�棨1��---------------------------------|" << endl;
				cout << "����ѡ��      1���޸�����        2�����ù���Ա      0���ص���ʼ����" << endl;
				cout << "��ѡ���ܣ�";
				int bchoose;
				cin >> bchoose;
				while (bchoose<0 || bchoose>2)
				{
					cout << "������0~2��������ѡ���ܣ�" << endl;
					cout << "��ѡ���ܣ�";
					cin >> bchoose;
				}
				if (bchoose == 0)
				{
					choose = 0;
					system("cls");
					cout << endl << endl;
					break;
				}
				while (1)
				{
					switch (bchoose)
					{
					case 1:
					{
						cout << "�����������룺";
						cin >> bosspassword;
						boss2.resetpassword(bosspassword);
						system("cls");
						cout << endl << endl;
						cout << "�޸ĳɹ�!" << endl << endl << endl;
						break;
					}
					case 2:
					{
						boss2.setmanager();
						system("cls");
						cout << endl << endl << "���óɹ���" << endl << endl << endl;
						break;
					}
					}
					cout << "|-----------------------------��ǰλ�ã��ϰ����ҳ�棨1��---------------------------------|" << endl;
					cout << "����ѡ��      1���޸�����        2�����ù���Ա      0���ص���ʼ����" << endl;
					cout << "��ѡ���ܣ�";
					cin >> bchoose;
					while (bchoose<0 || bchoose>2)
					{
						cout << "������0~2��������ѡ���ܣ�" << endl;
						cout << "��ѡ���ܣ�";
						cin >> bchoose;
					}
					if (bchoose == 0) break;
				}
			}
			choose = 0;
			system("cls");
			cout << endl << endl;
			break;
		}
		case 2:
		{
			int exitchoose = 0;			//�����˳�����ѭ��

										//Ա����½ҳ��
			if (1)	//��½ҳ��
			{
				fstream f15;
				int total, id, fid;//��Ա������Ա������id����˾�ܱ��ļ�����Ա��id��
				int v1 = 0, v2, v3;//�����ж���֤�Ƿ�ɹ�
				cout << "|-----------------------------��ǰλ�ã�����Ա��¼ҳ��---------------------------------|" << endl;
				cout << "�����빤�ź����루�Կո��������";
				cin >> id >> mpassword;
				f15.open(com_pas, ios::in | ios::out | ios::binary);
				f15.seekg(sizeof(string), ios::beg);//�����ϰ�����
				f15.read((char*)&total, sizeof(int));
				manager *m = new manager[total];
				for (int i = 0; i < total; i++)
				{
					f15.read((char*)&m[i], sizeof(manager));
					if (m[i].verifym(id, mpassword))
					{
						v1 = 1;
						break;
					}
					v1 = 0;
				}
				f15.close();
				if (!v1)
				{
					cout << "�����ǹ���Ա�����������" << endl;
					cout << "�Ƿ�ص��˳���¼��1���ǣ�0���񣩣���ѡ��";
					cin >> v2;
					if (v2)
					{
						choose = 0;
						system("cls");
						cout << endl << endl;
						break;
					}
					if (!v2)
					{
						for (int j = 0; j < 2; j++)
						{
							cout << "���������빤�ź����룺";
							cin >> id >> mpassword;
							for (int i = 0; i < total; i++)
							{
								if (m[i].verifym(id, mpassword))
								{
									v3 = 1;
									break;
								}
								v3 = 0;
							}
							if (v3 == 1)
								break;
							else
								cout << "�����ǹ���Ա�����������" << endl;

						}
						if (!v3)
						{
							system("cls");
							cout << endl << endl;
							cout << "���Դ������࣬��ѯ���ϰ�������½����¼���棡" << endl;
							choose = 0;
							cout << endl << endl;
							break;
						}

					}
				}
			}

			//Ա������ҳ��
			if (1)		//����ҳ��
			{
				system("cls");
				cout << endl << endl;
				cout << "��¼�ɹ���" << endl << endl << endl;
				while (1)
				{
					cout << "|-----------------------------��ǰλ�ã�����Ա����ҳ��---------------------------------|" << endl;
					cout << "����ѡ��  1������������Ϣ                 2���鿴��Ʊ��Ϣ" << endl;
					cout << "            3���鿴��Ʊ��Ϣ             4���޸ĺ�����Ϣ" << endl;
					cout << "            0���ص���ʼҳ��" << endl;
					cout << endl << "��ѡ���ܣ�";
					int mchoose; mchoose = 0;
					cin >> mchoose;
					while (mchoose<0 || mchoose>4)		//�����û���ȷ����
					{
						cout << "������0~3��������ѡ���ܣ�" << endl;
						cout << "��ѡ���ܣ�";
						cin >> mchoose;
					}
					switch (mchoose)
					{
					case 0:		//�ص���ʼҳ��
					{
						choose = 0;
						system("cls");
						cout << endl << endl;
						exitchoose = 1;
						break;
					}
					case 1:		//����������Ϣ
					{
						int pid, y, m, d, h, mi; string we;
						int y1, m1, d1, h1, mi1; string we1, flid;
						string stas, lass;
						int fn, sn, tn;
						float fp, sp, tp;
						int yorn; yorn = 0;

						//���뺽����Ϣ
						if (1)
						{
							system("cls");
							cout << endl << endl;
							cout << "����������Ϣ����������룡��" << endl;
							cout << endl << endl;
							cout << "|-------------------------------����������Ϣ����---------------------------------|" << endl;
							cout << "�����뺽��ţ�";
							cin >> flid;
							cout << "������ɻ���ţ����ֱ�ţ���";
							cin >> pid;
							cout << "������������ڵģ�������ݡ��·ݣ�������Сʱ,���������Կո��������" << endl;
							cin >> y >> m >> d >> h >> mi;
							cout << "������������ڵ������������뺺�֡�һ�����������ġ��塢�����ա���ʾ������" << endl;
							cin >> we;
							cout << "�����뵽�����ڵģ�������ݡ��·ݣ�������Сʱ,���������Կո��������" << endl;
							cin >> y1 >> m1 >> d1 >> h1 >> mi1;
							cout << "�����뵽�����ڵ������������뺺�֡�һ�����������ġ��塢�����ա���ʾ������" << endl;
							cin >> we1;
							cout << "���������վ���յ�վ���Կո��������";
							cin >> stas >> lass;
							cout << "��ֱ�����һ�Ȳա����Ȳա����Ȳյ�����(�Կո����)��";
							cin >> fn >> sn >> tn;
							cout << "��ֱ�����һ�Ȳա����Ȳա����Ȳյļ۸�(�Կո����)��";
							cin >> fp >> sp >> tp;
						}

						flight flight1(pid, flid, y, m, d, h, mi, we, y1, m1, d1, h1, mi1, we1, stas, lass, fn, sn, tn, fp, sp, tp);
						cout << flight1;
						cout << endl;
						cout << "ȷ�Ϸ���������1��ȡ������������0��";
						cin >> yorn;

						//ȷ���Ƿ񷢲�����
						if (yorn)
						{
							fstream f16;
							//д�뺽����Ϣ�ļ�
							int flightnumber;
							f16.open(flightmassage, ios::in | ios::out | ios::binary);
							f16.read((char*)&flightnumber, sizeof(int));
							f16.seekg((sizeof(int) + sizeof(flight)*flightnumber), ios::beg);
							f16.write((char*)&flight1, sizeof(flight));
							flightnumber++;
							f16.seekg(0, ios::beg);
							f16.write((char*)&flightnumber, sizeof(int));	//�޸ĺ�������
							f16.close();

							fstream f17;
							//���ɺ����¼�ļ�
							flightidname = "D:\\book_planeticket_system\\company\\flight\\" + flight1.flightid + ".dat";//�Ժ�����������Ʊ��Ϣ
							f17.open(flightidname, ios::in);
							if (!f17)
							{
								f17.open(flightidname, ios::out);//�½������¼�ļ�
							}
							f17.close();

							fstream f18;
							f18.open(flightidname, ios::in | ios::out | ios::binary);
							f18.seekg(0, ios::beg);
							long pos = f18.tellg();
							f18.seekg(0, ios::end);
							long pos1 = f18.tellg();
							if (pos == pos1)
							{
								int flightidnumber = 0;
								int *a1 = new int[2 * flight1.getfirnumber()]();
								int *a2 = new int[2 * flight1.getsecnumber()]();
								int *a3 = new int[2 * flight1.gettrinumber()]();
								int *b1 = new int[4 * flight1.getfirnumber()]();
								int *b2 = new int[4 * flight1.getsecnumber()]();
								int *b3 = new int[4 * flight1.gettrinumber()]();
								for (int i = 0; i < 6; i++)
								{
									f18.seekg(0 + i * sizeof(int), ios::beg);
									f18.write((char*)&flightidnumber, sizeof(int));//��ʼ����Ʊ����
								}
								f18.seekg(6 * sizeof(int), ios::beg);
								f18.write((char*)a1, sizeof(int) * 2 * flight1.getfirnumber());
								f18.write((char*)b1, sizeof(int) * 4 * flight1.getfirnumber());
								f18.write((char*)a2, sizeof(int) * 2 * flight1.getsecnumber());
								f18.write((char*)b2, sizeof(int) * 4 * flight1.getsecnumber());
								f18.write((char*)a3, sizeof(int) * 2 * flight1.gettrinumber());
								f18.write((char*)b3, sizeof(int) * 4 * flight1.gettrinumber());
								delete[]a1; delete[]a2; delete[]a3; delete[]b1; delete[]b2; delete[]b3;
							}
							f18.close();
							system("cls");
							cout << endl << endl;
							cout << "�ѳɹ�������" << endl;
							cout << endl << endl;
							break;
						}
						else
						{
							system("cls");
							cout << endl << endl;
							cout << "��ȡ��������" << endl;
							cout << endl << endl;
							break;
						}
					}
					case 2:		// �鿴������Ϣ
					{
						int c = 0;
						cout << endl;
						cout << "��ѯ���к�����Ϣ������1����ѯĳ�˺�����Ϣ������0��";
						cin >> c;
						while (c<0 || c>1)		//ȷ���������0��1
						{
							cout << "������0��1ѡ���ܣ�" << endl;
							cout << "��ѡ���ܣ�";
							cin >> c;
						}

						//�鿴���˺�����Ϣ
						if (c == 0)
						{
							int flightnumber, v = 0;//��������;�˳������ж��Ƿ��ѯ������
							cout << endl;
							cout << "�����뺽��ţ�";
							cin >> flightid1;
							int id_i = locatedMassage(flightid1);
							flight flight1;
							if (id_i >= 0)
							{
								flight1 = readflight(id_i);
								system("cls");
								cout << "��ѯ������£�" << endl;
								cout << endl;
								cout << flight1;
								cout << endl << "!!!!���Ϸ�ҳ�ɲ鿴�����" << endl;
							}
							else
							{
								system("cls");
								cout << endl << endl;
								cout << "δ�������˺��࣡" << endl;
								cout << endl << endl;
								break;
							}
							break;
						}

						//�鿴���˺���
						if (c == 1)
						{
							system("cls");
							cout << "��ѯ������£�" << endl << endl;
							lookAllFlight();
							cout << endl;
							cout << "���Ϸ�ҳ�ɲ鿴�������û�н�������ǻ�û�з��������࣡��" << endl;
							cout << endl << endl;
							break;
						}
					}
					case 3:		//�鿴��Ʊ��Ϣ
					{
						int flightid_i = -1;
						while (1)
						{
							int v = 0;//�˳�����while�������
							int m1_choose;
							cout << endl;
							cout << "����������Ҫ��ѯ�ĺ��ඩƱ��Ϣ�ĺ�����(�˳���ѯ������0)��";
							cin >> flightid1;
							if (flightid1 == "0")
							{
								system("cls");
								cout << endl << endl;
								cout << "���˳��鿴��" << endl;
								cout << endl << endl;
								break;
							}
							flightid_i = locatedMassage(flightid1);
							while (flightid_i == -1)
							{
								system("cls");
								cout << endl << endl;
								cout << "δ�������˺��࣡" << endl;
								cout << endl << endl;
								cout << "���������뺽��Ų鿴������Ϣ������0���˳��鿴����";
								cin >> flightid1;
								if (flightid1 == "0")
								{
									system("cls");
									cout << endl << endl;
									cout << "���˳��鿴��" << endl;
									cout << endl << endl;
									break;
								}
								flightid_i = locatedMassage(flightid1);
							}
							if (flightid_i == -1)
							{
								break;
							}
							//file.open("D:\\book_planeticket_system\\company\\flight\\" + flightid1 + ".dat", ios::in | ios::binary);
							flight1 = readflight(flightid_i);
							//�鿴������Ϣ
							cout << "�ɲ鿴��Ϣ��         1��ȫ����Ա����Ʊ�ͺ�Ʊ��Ա���鿴             2����Ʊ����Ϣ" << endl;
							cout << "                     3����Ʊ��Ա��Ϣ                               0���˳�" << endl;
							cout << "��Ҫ�鿴��Щ�˵ľ�����Ϣ�أ�����������ѡ��" << endl;
							cin >> m1_choose;
							while (!(m1_choose == 1 || m1_choose == 2 || m1_choose == 3 || m1_choose == 4 || m1_choose == 0))
							{
								cout << "������0~3ѡ���ܣ�";
								cin >> m1_choose;
							}
							switch (m1_choose)
							{
							case 1:
							{
								;
							}
							case 2:
							{
								flight1.lookbt();
								if (m1_choose != 1)	//��4�Ļ���Ҫ������һ��case
								{
									//file.close();
									cout << endl << endl;
									cout << "�����Ϸ�ҳ�鿴����û�м�¼����û���˶�Ʊ����" << endl;
									cout << endl << endl;
									break;
								}
							}
							case 3:
							{
								flight1.lookwt();
								//file.close();
								cout << endl << endl;
								cout << "�����Ϸ�ҳ�鿴����û�м�¼����û���˶�Ʊ����" << endl;
								cout << endl << endl;
								break;
							}
							case 0:
							{
								v = 1;
								//file.close();
								break;
							}
							if (v == 1)
								break;
							}
						}
						break;

					}
					case 4:		//�޸ĺ�����Ϣ
					{
						int id_i;
						cout << endl;
						cout << "�����뽫Ҫ�޸ĵĺ�����Ϣ�ĺ�����(�˳��޸�������0)��";
						cin >> flightid1;
						if (flightid1 == "0")
						{
							system("cls");
							cout << endl << endl;
							cout << "���˳��޸ģ�" << endl;
							cout << endl << endl;
							break;
						}
						id_i = locatedMassage(flightid1);
						if (id_i < 0)
						{
							system("cls");
							cout << endl << endl;
							cout << "��δ�����ú��࣡" << endl;
							cout << endl << endl;
							break;
						}
						flight1 = readflight(id_i);
						flight1.resetmassage();
						break;
					}
					case 5:
					{
						exitchoose = 1;
						system("cls");
						cout << endl << endl;
						cout << "���˳��޸ģ�" << endl;
						cout << endl << endl;
						break;
					}
					}
					if (exitchoose) break;
				}
				if (exitchoose) break;

			}



		}
		case 3:
		{
			int v = 0;//�˳���case����ͨ��֤
			int userchoose;
			int usercomid1 = 0;

			//�û���¼����
			while (1)
			{
				int v1 = 0;//�˳���ѭ������ͨ��֤,1:�˳�ѭ��
				cout << "|-----------------------------��ǰҳ�棺�û�ע����¼ҳ��---------------------------------|" << endl;
				cout << "����Ҫ��           1����¼                    2��ע��               0�����س�ʼҳ��" << endl;
				cout << "����������ѡ���ܣ�";
				cin >> userchoose;
				while (!(userchoose == 0 || userchoose == 1 || userchoose == 2))
				{
					cout << "�������������0~2ѡ���ܣ�";
					cin >> userchoose;
				}
				switch (userchoose)
				{
				case 1:
				{
					int i = userLogIn();
					if (i)
					{
						usercomid1 = i;
						v1 = 1;
					}
					break;
				}
				case 2:
				{
					userSignIn();
					break;
				}
				case 0:
				{
					system("cls");
					cout << endl << endl;
					cout << "�ѻص���ʼҳ��" << endl;
					cout << endl << endl;
					choose = 0;
					v = 1;
					v1 = 1;
					break;
				}
				}
				if (v1 == 1)
					break;
			}
			if (v == 1)
				break;

			//�û���������
			if (v == 0)
			{
				fstream f19;
				f19.open(user_pas, ios::in | ios::out | ios::binary);
				f19.seekg(sizeof(int) + sizeof(user)*(usercomid1 - 1), ios::beg);
				f19.read((char*)&users, sizeof(user));
				f19.close();

				system("cls");
				cout << endl << endl;
				cout << "�ѳɹ���¼��" << endl;
				cout << endl << endl;
				int userchoose1;
				while (1)
				{
					int v2 = 0;//�˳���ǰѭ������ͨ��֤��1��ʱ���˳�
					cout << "|-----------------------------��ǰҳ�棺�û���Ʊ����ҳ��---------------------------------|" << endl;
					cout << "���ܣ�   1����ѯ��Ʊ               2����Ʊ                      3����Ʊ " << endl;
					cout << "         0���ص���ʼҳ�� " << endl;
					cout << "����������ѡ���ܣ�";
					cin >> userchoose1;
					while (!(userchoose1 == 0 || userchoose1 == 1 || userchoose1 == 2 || userchoose1 == 3 || userchoose1 == 4))
					{
						cout << "�������������0~4��ѡ���ܣ�";
						cin >> userchoose1;
					}
					switch (userchoose1)
					{
					case 0:
					{
						choose = 0;
						v2 = 1;
						v = 1;
						system("cls");
						cout << endl << endl;
						cout << "���˳��û��������棬�ص���ʼҳ�棡" << endl << endl << endl;
						break;
					}
					case 1:
					{
						fstream f20;
						int flightnumber;
						string lastplace;
						cout << "������Ŀ�ĵأ����������ɣ����ؼӡ�վ������";
						cin >> lastplace;
						f20.open(flightmassage, ios::in | ios::out | ios::binary);
						f20.read((char*)&flightnumber, sizeof(int));
						flight *flight2 = new flight[flightnumber];
						f20.seekg(sizeof(int), ios::beg);
						for (int i = 0; i < flightnumber; i++)
						{
							f20.read((char*)&flight2[i], sizeof(flight));
						}
						f20.close();
						system("cls");
						cout << endl << endl;
						cout << "��ѯ������£�" << endl;
						cout << endl << endl;
						users.displaytic(lastplace, flight2, flightnumber);
						cout << "�����Ϸ�ҳ�鿴�����" << endl << endl;
						break;
					}
					case 2:
					{
						int v3 = 0;
						int flightid_i;
						cout << "�����뺽��ţ�";
						cin >> flightid1;
						flightid_i = locatedMassage(flightid1);
						while (flightid_i < 0)
						{
							cout << "û�������˺��࣬���������뺽��ţ�����0�˳���Ʊ����";
							cin >> flightid1;
							if (flightid1 == "0")
							{
								v3 = 1;
								system("cls");
								cout << endl << endl;
								cout << "���˳���Ʊ��" << endl << endl << endl;
								break;
							}
							flightid_i = locatedMassage(flightid1);
						}
						if (v3 == 1)
						{
							break;
						}
						flight1 = readflight(flightid_i);
						cout << "��ѡ�еĺ����ǣ�" << endl;
						flight1.userlook();
						flight1.book_tic(users.usercomid);
						break;
						;					}
					case 3:
					{
						int v3 = 0;
						int flightid_i;
						cout << "�����뺽��ţ�";
						cin >> flightid1;
						flightid_i = locatedMassage(flightid1);
						while (flightid_i < 0)
						{
							cout << "û�������˺��࣬���������루����0�˳���Ʊ����";
							cin >> flightid1;
							if (flightid1 == "0")
							{
								v3 = 1;
								break;
							}
							flightid_i = locatedMassage(flightid1);
						}
						if (v3 == 1)
						{
							break;
						}
						flight1 = readflight(flightid_i);
						cout << "��ѡ�еĺ����ǣ�" << endl;
						flight1.userlook();
						system("cls");
						cout << endl << endl;
						flight1.refund_tic(users.usercomid);
						cout << endl << endl;
						break;
					}
					}
					if (v2 == 1)
						break;

				}
			}
			if (v == 1)
				break;
		}
		case 4:
		{
			exitv=1;
			break;
		}

		}
		if (exitv == 1)
			break;

	}

}