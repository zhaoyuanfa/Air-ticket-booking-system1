//
// main.cpp
//
#include<iostream>
#include<string>
#include<iomanip>
#include<process.h>
#include <windows.h>   
#include <stdio.h>  
#include "类的定义.h"
using namespace std;

string bosspassword, bosspassword1;    //case中的老板密码所用的两个参数(可重复使用)
string p;
string mpassword, mpassword1;
string flightidname;		//航班记录的文件名
string flightid1;		//管理者中用以查询航班信息
flight flight1;
user users;				//登陆后的用户

int main()
{
	//文件定义模块
	const string com_pas = "D:\\book_planeticket_system\\company\\com_pas.dat";	//公司密钥文件代名
	const string user_pas = "D:\\book_planeticket_system\\company\\user_pas.dat";
	const string flightmassage = "D:\\book_planeticket_system\\company\\flight\\flightmassage.dat";
	system("md D:\\book_planeticket_system\\company");			//公司文件
	system("md D:\\book_planeticket_system\\user");			//公司文件
	system("md D:\\book_planeticket_system\\company\\flight");	//航班文件
	fstream file; //用于创建软件所需文件、以及文件的读写

	if (1)	//创建文件
	{
		file.open(com_pas, ios::in);
		if (!file)
		{
			file.open(com_pas, ios::out);//公司人员密钥
		}
		file.close();

		file.open(user_pas, ios::in);
		if (!file)
		{
			file.open(user_pas, ios::out);//用户密钥
		}
		file.close();

		file.open(flightmassage, ios::in);
		if (!file)
		{
			file.open(flightmassage, ios::out);//创建航班信息文件
		}
		file.close();
	}

	if (1)	//初始化各个新建文件
	{
		//公司密钥文件的初始化
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
		//航班信息文件的初始化
		file.open(flightmassage, ios::in | ios::out | ios::binary);
		file.seekg(0, ios::beg);
		pos = file.tellg();
		file.seekg(0, ios::end);
		pos1 = file.tellg();
		if (pos == pos1)		//空文件则需初始化
		{
			file.seekg(0, ios::beg);
			int flightidnumber = 0;
			file.write((char*)&flightidnumber, sizeof(int));//初始化航班数量
		}
		file.close();

		//公司密钥文件的初始化
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


	cout << "欢迎使用航空订票系统！" << endl;
	int choose;
	system("CLS");
	cout << endl << endl;
	cout << "提示：本软件功能选择均是输入功能前的数字" << endl << endl;
	cout << "|--------------------------------当前位置：起始页面（0）--------------------------------------|" << endl;
	cout << "身份选择：    1、老板       2、管理员        3、用户" << endl;
	cout << "请选择您的身份:";
	cin >> choose;
	while (choose<0 || choose>4)
	{
		cout << "请输入1~3的数字来选择身份！" << endl;
		cout << "请选择身份：";
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
			cout << "|--------------------------------当前位置：起始页面（0）--------------------------------------|" << endl;
			cout << "身份选择：    1、老板       2、管理员        3、用户 " << endl;
			cout << "请选择您的身份:";
			cin >> choose;
			while (choose < 1 || choose>4)
			{
				cout << "请输入1~3的数字来选择身份！" << endl;
				cout << "请选择身份：";
				cin >> choose;
			}
			system("cls");
			cout << endl << endl;
			break;
		}
		case 1:
		{
			fstream f14;
			cout << "|-----------------------------当前位置：老板登录页面---------------------------------|" << endl;
			f14.open(com_pas, ios::in | ios::out | ios::binary);
			f14.seekg(0, ios::beg);
			f14.read((char*)&bosspassword, sizeof(string));
			if (bosspassword == "0")			//若还没有密码则设定密码
			{
				cout << "请老板您设定密码：";
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
				cout << "请输入密码进行登录:";
				cin >> bosspassword1;
				while ((bosspassword != bosspassword1) && (bosspassword1 != "0"))
				{
					cout << "密码错误，请重新输入(返回起始页面请输入0)：";
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
				cout << "登陆成功!" << endl;
				cout << endl << endl;
				cout << "|-----------------------------当前位置：老板操作页面（1）---------------------------------|" << endl;
				cout << "功能选择：      1、修改密码        2、设置管理员      0、回到初始界面" << endl;
				cout << "请选择功能：";
				int bchoose;
				cin >> bchoose;
				while (bchoose<0 || bchoose>2)
				{
					cout << "请输入0~2的数字来选择功能！" << endl;
					cout << "请选择功能：";
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
						cout << "请输入新密码：";
						cin >> bosspassword;
						boss2.resetpassword(bosspassword);
						system("cls");
						cout << endl << endl;
						cout << "修改成功!" << endl << endl << endl;
						break;
					}
					case 2:
					{
						boss2.setmanager();
						system("cls");
						cout << endl << endl << "设置成功！" << endl << endl << endl;
						break;
					}
					}
					cout << "|-----------------------------当前位置：老板操作页面（1）---------------------------------|" << endl;
					cout << "功能选择：      1、修改密码        2、设置管理员      0、回到初始界面" << endl;
					cout << "请选择功能：";
					cin >> bchoose;
					while (bchoose<0 || bchoose>2)
					{
						cout << "请输入0~2的数字来选择功能！" << endl;
						cout << "请选择功能：";
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
			int exitchoose = 0;			//用于退出多重循环

										//员工登陆页面
			if (1)	//登陆页面
			{
				fstream f15;
				int total, id, fid;//总员工数、员工输入id、公司密保文件已有员工id；
				int v1 = 0, v2, v3;//用于判断验证是否成功
				cout << "|-----------------------------当前位置：管理员登录页面---------------------------------|" << endl;
				cout << "请输入工号和密码（以空格隔开）：";
				cin >> id >> mpassword;
				f15.open(com_pas, ios::in | ios::out | ios::binary);
				f15.seekg(sizeof(string), ios::beg);//跳过老板密码
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
					cout << "您不是管理员或者密码错误！" << endl;
					cout << "是否回到退出登录（1：是；0：否），请选择：";
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
							cout << "请重新输入工号和密码：";
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
								cout << "您不是管理员或者密码错误！" << endl;

						}
						if (!v3)
						{
							system("cls");
							cout << endl << endl;
							cout << "尝试次数过多，请询问老板或者重新进入登录界面！" << endl;
							choose = 0;
							cout << endl << endl;
							break;
						}

					}
				}
			}

			//员工操作页面
			if (1)		//操作页面
			{
				system("cls");
				cout << endl << endl;
				cout << "登录成功！" << endl << endl << endl;
				while (1)
				{
					cout << "|-----------------------------当前位置：管理员操作页面---------------------------------|" << endl;
					cout << "功能选择：  1、发布航班信息                 2、查看机票信息" << endl;
					cout << "            3、查看订票信息             4、修改航班信息" << endl;
					cout << "            0、回到初始页面" << endl;
					cout << endl << "请选择功能：";
					int mchoose; mchoose = 0;
					cin >> mchoose;
					while (mchoose<0 || mchoose>4)		//引导用户正确输入
					{
						cout << "请输入0~3的数字来选择功能！" << endl;
						cout << "请选择功能：";
						cin >> mchoose;
					}
					switch (mchoose)
					{
					case 0:		//回到初始页面
					{
						choose = 0;
						system("cls");
						cout << endl << endl;
						exitchoose = 1;
						break;
					}
					case 1:		//发布航班信息
					{
						int pid, y, m, d, h, mi; string we;
						int y1, m1, d1, h1, mi1; string we1, flid;
						string stas, lass;
						int fn, sn, tn;
						float fp, sp, tp;
						int yorn; yorn = 0;

						//输入航班信息
						if (1)
						{
							system("cls");
							cout << endl << endl;
							cout << "发布航班信息，请谨慎输入！！" << endl;
							cout << endl << endl;
							cout << "|-------------------------------发布航班信息界面---------------------------------|" << endl;
							cout << "请输入航班号：";
							cin >> flid;
							cout << "请输入飞机编号（数字编号）：";
							cin >> pid;
							cout << "请输入出发日期的；包括年份、月份，号数，小时,分钟数（以空格隔开）：" << endl;
							cin >> y >> m >> d >> h >> mi;
							cout << "请输入出发日期的星期数（输入汉字“一、二、三、四、五、六、日”表示）：：" << endl;
							cin >> we;
							cout << "请输入到达日期的；包括年份、月份，号数，小时,分钟数（以空格隔开）：" << endl;
							cin >> y1 >> m1 >> d1 >> h1 >> mi1;
							cout << "请输入到达日期的星期数（输入汉字“一、二、三、四、五、六、日”表示）：：" << endl;
							cin >> we1;
							cout << "请输入出发站和终点站（以空格隔开）：";
							cin >> stas >> lass;
							cout << "请分别输入一等舱、二等舱、三等舱的数量(以空格隔开)：";
							cin >> fn >> sn >> tn;
							cout << "请分别输入一等舱、二等舱、三等舱的价格(以空格隔开)：";
							cin >> fp >> sp >> tp;
						}

						flight flight1(pid, flid, y, m, d, h, mi, we, y1, m1, d1, h1, mi1, we1, stas, lass, fn, sn, tn, fp, sp, tp);
						cout << flight1;
						cout << endl;
						cout << "确认发布请输入1，取消发布请输入0：";
						cin >> yorn;

						//确认是否发布航班
						if (yorn)
						{
							fstream f16;
							//写入航班信息文件
							int flightnumber;
							f16.open(flightmassage, ios::in | ios::out | ios::binary);
							f16.read((char*)&flightnumber, sizeof(int));
							f16.seekg((sizeof(int) + sizeof(flight)*flightnumber), ios::beg);
							f16.write((char*)&flight1, sizeof(flight));
							flightnumber++;
							f16.seekg(0, ios::beg);
							f16.write((char*)&flightnumber, sizeof(int));	//修改航班数量
							f16.close();

							fstream f17;
							//生成航班记录文件
							flightidname = "D:\\book_planeticket_system\\company\\flight\\" + flight1.flightid + ".dat";//以航班名命名订票信息
							f17.open(flightidname, ios::in);
							if (!f17)
							{
								f17.open(flightidname, ios::out);//新建航班记录文件
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
									f18.write((char*)&flightidnumber, sizeof(int));//初始化订票人数
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
							cout << "已成功发布！" << endl;
							cout << endl << endl;
							break;
						}
						else
						{
							system("cls");
							cout << endl << endl;
							cout << "已取消发布！" << endl;
							cout << endl << endl;
							break;
						}
					}
					case 2:		// 查看航班信息
					{
						int c = 0;
						cout << endl;
						cout << "查询所有航班信息请输入1，查询某趟航班信息请输入0：";
						cin >> c;
						while (c<0 || c>1)		//确保输入的是0或1
						{
							cout << "请输入0或1选择功能！" << endl;
							cout << "请选择功能：";
							cin >> c;
						}

						//查看单趟航班信息
						if (c == 0)
						{
							int flightnumber, v = 0;//航班数量;退出用于判断是否查询到的量
							cout << endl;
							cout << "请输入航班号：";
							cin >> flightid1;
							int id_i = locatedMassage(flightid1);
							flight flight1;
							if (id_i >= 0)
							{
								flight1 = readflight(id_i);
								system("cls");
								cout << "查询结果如下：" << endl;
								cout << endl;
								cout << flight1;
								cout << endl << "!!!!向上翻页可查看结果！" << endl;
							}
							else
							{
								system("cls");
								cout << endl << endl;
								cout << "未发布该趟航班！" << endl;
								cout << endl << endl;
								break;
							}
							break;
						}

						//查看多趟航班
						if (c == 1)
						{
							system("cls");
							cout << "查询结果如下：" << endl << endl;
							lookAllFlight();
							cout << endl;
							cout << "向上翻页可查看结果（若没有结果，则是还没有发布过航班！）" << endl;
							cout << endl << endl;
							break;
						}
					}
					case 3:		//查看订票信息
					{
						int flightid_i = -1;
						while (1)
						{
							int v = 0;//退出当层while所需变量
							int m1_choose;
							cout << endl;
							cout << "请输入您将要查询的航班订票信息的航班编号(退出查询请输入0)：";
							cin >> flightid1;
							if (flightid1 == "0")
							{
								system("cls");
								cout << endl << endl;
								cout << "已退出查看！" << endl;
								cout << endl << endl;
								break;
							}
							flightid_i = locatedMassage(flightid1);
							while (flightid_i == -1)
							{
								system("cls");
								cout << endl << endl;
								cout << "未发布该趟航班！" << endl;
								cout << endl << endl;
								cout << "请重新输入航班号查看航班信息（输入0可退出查看）：";
								cin >> flightid1;
								if (flightid1 == "0")
								{
									system("cls");
									cout << endl << endl;
									cout << "已退出查看！" << endl;
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
							//查看具体信息
							cout << "可查看信息：         1、全部人员（订票和侯票人员）查看             2、订票人信息" << endl;
							cout << "                     3、侯票人员信息                               0、退出" << endl;
							cout << "您要查看哪些人的具体信息呢？请输入数字选择：" << endl;
							cin >> m1_choose;
							while (!(m1_choose == 1 || m1_choose == 2 || m1_choose == 3 || m1_choose == 4 || m1_choose == 0))
							{
								cout << "请输入0~3选择功能：";
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
								if (m1_choose != 1)	//是4的话将要进行下一个case
								{
									//file.close();
									cout << endl << endl;
									cout << "请向上翻页查看（若没有记录，则还没有人订票）！" << endl;
									cout << endl << endl;
									break;
								}
							}
							case 3:
							{
								flight1.lookwt();
								//file.close();
								cout << endl << endl;
								cout << "请向上翻页查看（若没有记录，则还没有人订票）！" << endl;
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
					case 4:		//修改航班信息
					{
						int id_i;
						cout << endl;
						cout << "请输入将要修改的航班信息的航班名(退出修改请输入0)：";
						cin >> flightid1;
						if (flightid1 == "0")
						{
							system("cls");
							cout << endl << endl;
							cout << "已退出修改！" << endl;
							cout << endl << endl;
							break;
						}
						id_i = locatedMassage(flightid1);
						if (id_i < 0)
						{
							system("cls");
							cout << endl << endl;
							cout << "还未发布该航班！" << endl;
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
						cout << "已退出修改！" << endl;
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
			int v = 0;//退出本case所需通行证
			int userchoose;
			int usercomid1 = 0;

			//用户登录界面
			while (1)
			{
				int v1 = 0;//退出本循环所需通行证,1:退出循环
				cout << "|-----------------------------当前页面：用户注册或登录页面---------------------------------|" << endl;
				cout << "您想要：           1、登录                    2、注册               0、返回初始页面" << endl;
				cout << "请输入数字选择功能：";
				cin >> userchoose;
				while (!(userchoose == 0 || userchoose == 1 || userchoose == 2))
				{
					cout << "输入错误！请输入0~2选择功能：";
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
					cout << "已回到初始页面" << endl;
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

			//用户操作界面
			if (v == 0)
			{
				fstream f19;
				f19.open(user_pas, ios::in | ios::out | ios::binary);
				f19.seekg(sizeof(int) + sizeof(user)*(usercomid1 - 1), ios::beg);
				f19.read((char*)&users, sizeof(user));
				f19.close();

				system("cls");
				cout << endl << endl;
				cout << "已成功登录！" << endl;
				cout << endl << endl;
				int userchoose1;
				while (1)
				{
					int v2 = 0;//退出当前循环所需通行证，1的时候退出
					cout << "|-----------------------------当前页面：用户订票界面页面---------------------------------|" << endl;
					cout << "功能：   1、查询机票               2、订票                      3、退票 " << endl;
					cout << "         0、回到初始页面 " << endl;
					cout << "请输入数字选择功能：";
					cin >> userchoose1;
					while (!(userchoose1 == 0 || userchoose1 == 1 || userchoose1 == 2 || userchoose1 == 3 || userchoose1 == 4))
					{
						cout << "输入错误！请输入0~4来选择功能：";
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
						cout << "已退出用户操作界面，回到初始页面！" << endl << endl << endl;
						break;
					}
					case 1:
					{
						fstream f20;
						int flightnumber;
						string lastplace;
						cout << "请输入目的地（城市名即可，不必加“站”）：";
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
						cout << "查询结果如下：" << endl;
						cout << endl << endl;
						users.displaytic(lastplace, flight2, flightnumber);
						cout << "请向上翻页查看结果！" << endl << endl;
						break;
					}
					case 2:
					{
						int v3 = 0;
						int flightid_i;
						cout << "请输入航班号：";
						cin >> flightid1;
						flightid_i = locatedMassage(flightid1);
						while (flightid_i < 0)
						{
							cout << "没发布该趟航班，请重新输入航班号（输入0退出订票）：";
							cin >> flightid1;
							if (flightid1 == "0")
							{
								v3 = 1;
								system("cls");
								cout << endl << endl;
								cout << "已退出订票！" << endl << endl << endl;
								break;
							}
							flightid_i = locatedMassage(flightid1);
						}
						if (v3 == 1)
						{
							break;
						}
						flight1 = readflight(flightid_i);
						cout << "您选中的航班是：" << endl;
						flight1.userlook();
						flight1.book_tic(users.usercomid);
						break;
						;					}
					case 3:
					{
						int v3 = 0;
						int flightid_i;
						cout << "请输入航班号：";
						cin >> flightid1;
						flightid_i = locatedMassage(flightid1);
						while (flightid_i < 0)
						{
							cout << "没发布该趟航班，请重新输入（输入0退出购票）：";
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
						cout << "您选中的航班是：" << endl;
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