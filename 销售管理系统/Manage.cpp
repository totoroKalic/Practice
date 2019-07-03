#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

class Staff{
protected:
	char id[20];
	char name[20];
	char age[20];
public:
	void Inputdate();
	void Outputdate();
	void *Showdata();
};

class Saleman : virtual public Staff{
protected:
	char saleroom[20];
private:
	static int number;
public:
	void Inputdate();
	void Outputdate();
	char *Showdata(int i);
	void AddNumber();
	void SubNumber();
	static int ShowNumber();
};

class Manager : virtual public Staff{
protected:
	char dep[20];
private:
	static int number;
public:
	void Inputdate();
	void Outputdate();
	char *Showdata(int i);
	void AddNumber();
	void SubNumber();
	static int ShowNumber();
};

class SalesManager : public Saleman, public Manager
{
private:
	static int number;
public:
	void Inputdate();
	void Outputdate();
	char *Showdata(int i);
	void AddNumber();
	void SubNumber();
	static int ShowNumber();
};


//class Saleman
int Saleman::number = 0;
void Saleman::Inputdate(void){
	cout << "Please input id" << endl;
	cin >> id;
	cout << "Please input name" << endl;
	cin >> name;
	cout << "Please input age" << endl;
	cin >> age;
	cout << "Please input saleroom" << endl;
	cin >> saleroom;
}
void Saleman::Outputdate(){
	cout << "id:" << id << endl;
	cout << "naem:" << name << endl;
	cout << "age:" << age << endl;
	cout << "saleroom:" << saleroom << endl;
}

char *Saleman::Showdata(int i){
	switch (i){
	case 1: return id;
	case 2: return name;
	case 3: return age;
	case 4: return saleroom;
	default:return NULL;
	}
}
void Saleman::AddNumber(){
	number++;
}
void Saleman::SubNumber(){
	number--;
}
int Saleman::ShowNumber(){
	return number;
}

//class Manager
int Manager::number = 0;
void Manager::Inputdate(void){
	cout << "Please input id" << endl;
	cin >> id;
	cout << "Please input name" << endl;
	cin >> name;
	cout << "Please input age" << endl;
	cin >> age;
	cout << "Please input department" << endl;
	cin >> dep;
}
void Manager::Outputdate(){
	cout << "id:" << id << endl;
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "department:" << dep << endl;
}

char *Manager::Showdata(int i){
	switch (i){
	case 1: return id;
	case 2: return name;
	case 3: return age;
	case 4: return dep;
	default:return NULL;
	}
}
void Manager::AddNumber(){
	number++;
}
void Manager::SubNumber(){
	number--;
}
int Manager::ShowNumber(){
	return number;
}

// class salesManeger
int SalesManager::number = 0;
void SalesManager::Inputdate(void){
	cout << "Please input id" << endl;
	cin >> id;
	cout << "Please input name" << endl;
	cin >> name;
	cout << "Please input age" << endl;
	cin >> age;
	cout << "Please input saleroom" << endl;
	cin >> saleroom;
	cout << "Please input department" << endl;
	cin >> dep;
}
void SalesManager::Outputdate(){
	cout << "id:" << id << endl;
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "saleroom:" << saleroom << endl;
	cout << "department:" << dep << endl;
}

char *SalesManager::Showdata(int i){
	switch (i){
	case 1: return id;
	case 2: return name;
	case 3: return age;
	case 4: return saleroom;
	case 5: return dep;
	default:return NULL;
	}
}
void SalesManager::AddNumber(){
	number++;
}
void SalesManager::SubNumber(){
	number--;
}
int SalesManager::ShowNumber(){
	return number;
}

//ADD function
void AddDate(){
	fstream fp;
	char flag, words[100];
	int i;
	cout << "1：Add Saleman   ";
	cout << "2：Add Manager   ";
	cout << "3：Add SalesManager   ";
	cout << "4：back" << endl;
	cin >> flag;
	if (flag == '1'){
		fp.open("E:\\C++_demo\\销售管理系统\\Saleman.txt", ios::out | ios::app);
		if (!fp){
			cout << "Saleman.txt open fail" << endl;
			abort();
		}
		Saleman sale;
		sale.Inputdate();
		for (i = 1; i <= 4; i++){
			fp << sale.Showdata(i);
			if (i<4)
				fp << " ";
			else
				fp << endl;
		}
		sale.AddNumber();
		fp.close();
	}
	else if (flag == '2'){
		fp.open("E:\\C++_demo\\销售管理系统\\Manager.txt", ios::out | ios::app);
		if (!fp){
			cout << "Manager.txt open fail" << endl;
			abort();
		}
		Manager sale;
		sale.Inputdate();
		for (i = 1; i <= 4; i++){
			fp << sale.Showdata(i);
			if (i<4)
				fp << " ";
			else
				fp << endl;
		}
		sale.AddNumber();
		fp.close();
	}
	else if (flag == '3'){
		fp.open("E:\\C++_demo\\销售管理系统\\SalesManager.txt", ios::out | ios::app);
		if (!fp){
			cout << "SalesManager.txt open fail" << endl;
			abort();
		}
		SalesManager sale;
		sale.Inputdate();
		for (i = 1; i <= 5; i++){
			fp << sale.Showdata(i);
			if (i<5)
				fp << " ";
			else
				fp << endl;
		}
		sale.AddNumber();
		fp.close();
	}
	else if (flag == '4')
		return;
}

// LOOK function
void LookData(char word[], int flag){
	fstream fp;
	int l = strlen(word), len, biaozhi = 1;
	char dada[100],t;
	if (flag == 1){
		fp.open("E:\\C++_demo\\销售管理系统\\Saleman.txt", ios::in);
		if (!fp){
			cout << "Saleman.txt open fail" << endl;
			abort();
		}
		while (!fp.eof()){
			dada[0] = '\0';
			fp.getline(dada, 100);
			t = dada[l];
			dada[l] = '\0';
			if (strcmp(dada, word) == 0){
				biaozhi = 0;
				dada[l] = t;
				len = strlen(dada);
				int j = 0;
				for (int i = 0; i<4; i++){
					if (i == 0)
						cout << "id: ";
					else if (i == 1)
						cout << "name: ";
					else if (i == 2)
						cout << "age: ";
					else if (i == 3)
						cout << "saleroom: ";
					while (dada[j] != ' '&&j<len){
						cout << dada[j];
						j++;
					}
					cout << endl;
					while (dada[j] == ' '&&j<len)
						j++;
				}
				break;
			}
		}
		fp.close();
	}
	else if (flag == 2){
		fp.open("E:\\C++_demo\\销售管理系统\\Manager.txt", ios::in);
		if (!fp){
			cout << "Manager.txt open fail" << endl;
			abort();
		}
		while (!fp.eof()){
			dada[0] = '\0';
			fp.getline(dada, 100);
			t = dada[l];
			dada[l] = '\0';
			if (strcmp(dada, word) == 0){
				biaozhi = 0;
				dada[l] = t;
				len = strlen(dada);
				int j = 0;
				for (int i = 0; i<4; i++){
					if (i == 0)
						cout << "id: ";
					else if (i == 1)
						cout << "name: ";
					else if (i == 2)
						cout << "age: ";
					else if (i == 3)
						cout << "dep: ";
					while (dada[j] != ' '&&j<len){
						cout << dada[j];
						j++;
					}
					cout << endl;
					while (dada[j] == ' '&&j<len)
						j++;
				}
				break;
			}
		}
		fp.close();
	}
	else if (flag == 3){
		fp.open("E:\\C++_demo\\销售管理系统\\SalesManager.txt", ios::in);
		if (!fp){
			cout << "SalesManager.txt open fail" << endl;
			abort();
		}
		while (!fp.eof()){
			dada[0] = '\0';
			fp.getline(dada, 100);
			t = dada[l];
			dada[l] = '\0';
			if (strcmp(dada, word) == 0){
				biaozhi = 0;
				dada[l] = t;
				len = strlen(dada);
				int j = 0;
				for (int i = 0; i<5; i++){
					if (i == 0)
						cout << "id: ";
					else if (i == 1)
						cout << "name: ";
					else if (i == 2)
						cout << "age: ";
					else if (i == 3)
						cout << "saleroom: ";
					else if (i == 4)
						cout << "dep: ";
						while(dada[j] != ' '&&j<len){
							cout << dada[j];
							j++;
						}
					cout << endl;
					while (dada[j] == ' '&&j<len)
						j++;
				}
				break;
			}
		}
		fp.close();
	}
	else if (flag == 4)
		return;
	if (biaozhi == 1)
		cout << "without the date" << endl;
}

//modify function
void ModifyDate(char no[], int flag){
	fstream fp, fp2;
	int l = strlen(no), len, biaozhi = 1;
	char t, dada[100];
	if (flag == 1){
		fp.open("E:\\C++_demo\\销售管理系统\\Saleman.txt", ios::in | ios::out);
		if (!fp){
			cout << "Saleman.txt open fail" << endl;
			abort();
		}
		fp2.open("E:\\C++_demo\\销售管理系统\\Saleman_Copy.txt", ios::out|ios::app);
		if (!fp2){
			cout << "Saleman_Copy.txt open fail" << endl;
			abort();
		}
		while (!fp.eof()){
			dada[0] = '\0';
			fp.getline(dada, 100);
			t = dada[l];
			dada[l] = '\0';
			if (strcmp(dada, no) == 0){
				biaozhi = 0;
				dada[l] = t;
				len = strlen(dada);
				int j = 0;
				for (int i = 0; i<4; i++){
					if (i == 0)
						cout << "id: ";
					else if (i == 1)
						cout << "name: ";
					else if (i == 2)
						cout << "age: ";
					else if (i == 3)
						cout << "saleroom: ";
					while (dada[j] != ' '&&j<len){
						cout << dada[j];
						j++;
					}
					cout << endl;
					while (dada[j] == ' '&&j<len)
						j++;
				}
				cout << "Please input new message" << endl;
				for (int i = 0; i<4; i++){
					if (i == 0){
						cout << "Please input id：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
					else if (i == 1){
						cout << "Please input name：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
					else if (i == 2){
						cout << "Please input age：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
					else if (i == 3){
						cout << "Please input saleroom：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
				}
				fp2 << endl;
			}
			else{
				dada[l] = t; fp2 << dada; fp2 << endl;
			}
		}
		fp.close();
		fp2.close();
		if (biaozhi == 0){
			char first[] = "E:\\C++_demo\\销售管理系统\\Saleman.txt";
			char second[] = "E:\\C++_demo\\销售管理系统\\Saleman_Copy.txt";
			DeleteFile("E:\\C++_demo\\销售管理系统\\Saleman.txt");
			if (rename(second, first)){
				cout << "failed" << endl;
			}
		}
		else
			DeleteFile("E:\\C++_demo\\销售管理系统\\Saleman_Copy.txt");
	}
	else if (flag == 2){
		fp.open("E:\\C++_demo\\销售管理系统\\Manager.txt", ios::in | ios::out);
		if (!fp){
			cout << "Manager.txt open fail" << endl;
			abort();
		}
		fp2.open("E:\\C++_demo\\销售管理系统\\Manager_Copy.txt", ios::out|ios::app);
		if (!fp2){
			cout << "Manager_Copy.txt open fail" << endl;
			abort();
		}
		while (!fp.eof()){
			dada[0] = '\0';
			fp.getline(dada, 100);
			t = dada[l];
			dada[l] = '\0';
			if (strcmp(dada, no) == 0){
				biaozhi = 0;
				dada[l] = t;
				len = strlen(dada);
				int j = 0;
				for (int i = 0; i<4; i++){
					if (i == 0)
						cout << "id: ";
					else if (i == 1)
						cout << "name: ";
					else if (i == 2)
						cout << "age: ";
					else if (i == 3)
						cout << "dep: ";
					while (dada[j] != ' '&&j<len){
						cout << dada[j];
						j++;
					}
					cout << endl;
					while (dada[j] == ' '&&j<len)
						j++;
				}
				cout << "Please input new message" << endl;
				for (int i = 0; i<4; i++){
					if (i == 0){
						cout << "Please input id：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
					else if (i == 1){
						cout << "Please input name：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
					else if (i == 2){
						cout << "Please input age：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
					else if (i == 3){
						cout << "Please input dep：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
				}
				fp2 << endl;
			}
			else{
				dada[l] = t; fp2 << dada; fp2 << endl;
			}
		}
		fp.close();
		fp2.close();
		if (biaozhi == 0){
			char first[] = "E:\\C++_demo\\销售管理系统\\Manager.txt";
			char second[] = "E:\\C++_demo\\销售管理系统\\Manager_Copy.txt";
				DeleteFile("E:\\C++_demo\\销售管理系统\\Manager.txt");
			if (rename(second, first)){
				cout << "failed" << endl;
			}
		}
		else
			DeleteFile("E:\\C++_demo\\销售管理系统\\Manager_Copy.txt");
	}
	else if (flag == 3){
		fp.open("E:\\C++_demo\\销售管理系统\\SaleManager.txt", ios::in | ios::out);
		if (!fp){
			cout << "SaleManager.txt open fail" << endl;
			abort();
		}
		fp2.open("E:\\C++_demo\\销售管理系统\\SaleManager_Copy.txt", ios::out|ios::app);
		if (!fp2){
			cout << "SalesManager_Copy.txt open fail" << endl;
			abort();
		}
		while (!fp.eof()){
			dada[0] = '\0';
			fp.getline(dada, 100);
			t = dada[l];
			dada[l] = '\0';
			if (strcmp(dada, no) == 0){
				biaozhi = 0;
				dada[l] = t;
				len = strlen(dada);
				int j = 0;
				for (int i = 0; i<5; i++){
					if (i == 0)
						cout << "id: ";
					else if (i == 1)
						cout << "name: ";
					else if (i == 2)
						cout << "age: ";
					else if (i == 3)
						cout << "saleroom: ";
					else if (i == 4)
						cout << "dep: ";
					while (dada[j] != ' '&&j<len){
						cout << dada[j];
						j++;
					}
					cout << endl;
					while (dada[j] == ' '&&j<len)
						j++;
				}
				cout << "Please input new message" << endl;
				for (int i = 0; i<5; i++){
					if (i == 0){
						cout << "Please input id：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
					else if (i == 1){
						cout << "Please input name：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
					else if (i == 2){
						cout << "Please input age：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
					else if (i == 3){
						cout << "Please input saleroom：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
					else if (i == 4){
						cout << "Please input dep：";
						cin >> dada; fp2 << dada; fp2 << " ";
					}
				}
				fp2 << endl;
			}
			else{
				dada[l] = t; fp2 << dada; fp2 << endl;
			}
		}
		fp.close();
		fp2.close();
		if (biaozhi == 0){
			char first[] = "E:\\C++_demo\\销售管理系统\\SaleManager.txt";
			char second[] = "E:\\C++_demo\\销售管理系统\\SaleManager_Copy.txt";
				DeleteFile("E:\\C++_demo\\销售管理系统\\SalesManager.txt");
			if (rename(second, first)){
				cout << "failed" << endl;
			}
		}
		else
			DeleteFile("E:\\C++_demo\\销售管理系统\\SalesManager_Copy.txt");
	}else if (flag == 4)
		return;
	if (biaozhi == 1)
		cout << "without the date" << endl;
}

//delete function
void Deletedate(char word[], int flag){
	fstream fp, fp2;
	int l = strlen(word), len, biaozhi = 0;
	char t, dada[100];
	if (flag == 1){
		fp.open("E:\\C++_demo\\销售管理系统\\Saleman.txt", ios::in | ios::out);
		if (!fp){
			cout << "Saleman.txt open fail" << endl;
			abort();
		}
		fp2.open("E:\\C++_demo\\销售管理系统\\Saleman_Copy.txt", ios::out|ios::app);
		if (!fp2){
			cout << "Saleman_Copy.txt open fail" << endl;
			abort();
		}
		while (!fp.eof()){
			dada[0] = '\0';
			fp.getline(dada, 100);
			t = dada[l];
			dada[l] = '\0';
			if (strcmp(dada, word) == 0){
				biaozhi = 1; continue;
			}
			else{
				dada[l] = t; fp2 << dada; fp2 << endl;
			}
		}
		fp.close(); fp2.close();
		if (biaozhi == 1){
			char sou[] = "E:\\C++_demo\\销售管理系统\\Saleman.txt", des[] = "E:\\C++_demo\\销售管理系统\\Saleman_Copy.txt";
			DeleteFile("E:\\C++_demo\\销售管理系统\\Saleman.txt");
			if (rename(des, sou))
				cout << "failed" << endl;
			else{
				cout << "Delete success!" << endl;
				Saleman e; e.SubNumber();
			}
		}
		else{
			cout << "without the date" << endl;
			DeleteFile("E:\\C++_demo\\销售管理系统\\Saleman_Copy.txt");
		}
	}
	else if (flag == 1){
		fp.open("E:\\C++_demo\\销售管理系统\\Manager.txt", ios::in | ios::out);
		if (!fp){
			cout << "Manager.txt open fail" << endl;
			abort();
		}
		fp2.open("E:\\C++_demo\\销售管理系统\\Manager_Copy.txt", ios::out|ios::app);
		if (!fp2){
			cout << "Manager_Copy.txt open fail" << endl;
			abort();
		}
		while (!fp.eof()){
			dada[0] = '\0';
			fp.getline(dada, 100);
			t = dada[l];
			dada[l] = '\0';
			if (strcmp(dada, word) == 0){
				biaozhi = 1; continue;
			}
			else{
				dada[l] = t; fp2 << dada; fp2 << endl;
			}
		}
		fp.close(); fp2.close();
		if (biaozhi == 1){
			char sou[] = "E:\\C++_demo\\销售管理系统\\Manager.txt", des[] = "E:\\C++_demo\\销售管理系统\\Manager_Copy.txt";
			DeleteFile("E:\\C++_demo\\销售管理系统\\Manager.txt");
			if (rename(des, sou))
				cout << "failed" << endl;
			else{
				cout << "Delete success!" << endl;
				Manager e; e.SubNumber();
			}
		}
		else{
			cout << "without the date" << endl;
			DeleteFile("E:\\C++_demo\\销售管理系统\\Manager_Copy.txt");
		}
			
	}
	else if (flag == 3){
		fp.open("E:\\C++_demo\\销售管理系统\\SalesManager.txt", ios::in | ios::out);
		if (!fp){
			cout << "SalesManager.txt open fail" << endl;
			abort();
		}
		fp2.open("E:\\C++_demo\\销售管理系统\\SalesManager_Copy.txt", ios::out|ios::app);
		if (!fp2){
			cout << "SalesManager_Copyl.txt open fail" << endl;
			abort();
		}
		while (!fp.eof()){
			dada[0] = '\0';
			fp.getline(dada, 100);
			t = dada[l];
			dada[l] = '\0';
			if (strcmp(dada, word) == 0){
				biaozhi = 1; continue;
			}
			else{
				dada[l] = t; fp2 << dada; fp2 << endl;
			}
		}
		fp.close(); fp2.close();
		if (biaozhi == 1){
			char sou[] = "E:\\C++_demo\\销售管理系统\\SalesManager.txt", des[] = "E:\\C++_demo\\销售管理系统\\SalesManager_Copy.txt";
			DeleteFile("E:\\C++_demo\\销售管理系统\\SalesManager.txt");
			if (rename(des, sou))
				cout << "failed" << endl;
			else{
				cout << "Delete success!" << endl;
				SalesManager e; e.SubNumber();
			}
		}
		else{
			cout << "without the date" << endl;
			DeleteFile("E:\\C++_demo\\销售管理系统\\SalesManager_Copy.txt");
		}
	}else if (flag == 4)
		return;
}

int main(){
	char words1, words2, t;
	int flag;
	char word[100], SelectNo[10];
	fstream fp;
	word[0] = '\0';
	cout << "*********Company enployee management system*********" << endl;
	cout << "Please choose：" << endl;
	cout << "1：Add message         ";
	cout << "2：Update message" << endl;
	cout << "3：Search message         ";
	cout << "4：Delete message" << endl;
	cout << "5：Stsff`s number         " << endl;
	cout << "6：Exit" << endl << endl;
	while (cin >> words1){
		if (words1 == '1')
			AddDate();
		else if (words1 == '2'){
			cout << "1：Update Saleman   ";
			cout << "2：Update Manager   ";
			cout << "3：Update SalesManager   ";
			cout << "4：back" << endl;
			cin >> flag;
			cout << "Please input the number that you want to Update：";
			cin >> SelectNo;
			ModifyDate(SelectNo, flag);
		}
		else if (words1 == '3'){
			cout << "1：Search Saleman   ";
			cout << "2：Search Manager   ";
			cout << "3：Search SalesManager   ";
			cout << "4：back" << endl;
			cin >> flag;
			cout << "Please input the number that you want to Search：";
			cin >> SelectNo;
			LookData(SelectNo, flag);
		}
		else if (words1 == '4'){
			cout << "1：Delete Saleman   ";
			cout << "2：Delete Manager   ";
			cout << "3：Delete SalesManager   ";
			cout << "4：back" << endl;
			cin >> flag;
			cout << "Please input the number that you want to Delete：";
			cin >> SelectNo;
			Deletedate(SelectNo, flag);
		}
		else if (words1 == '5'){
			cout << "1：Saleman`s numbers   ";
			cout << "2：Manager`s numbers   ";
			cout << "3：SalesManager`a numbers   ";
			cout << "4：back" << endl;
			cin >> flag;
			switch (flag){
			case 1:{Saleman e; cout << "Saleman`s Number is:" << e.ShowNumber() << endl; break; }
			case 2:{Manager e1; cout << "Manager`s Number is:" << e1.ShowNumber() << endl; break; }
			case 3:{SalesManager e2; cout << "SalesManager`s Number is:" << e2.ShowNumber() << endl; break; }
			default:break;
			}
		}
		cout << "Please choose  " << endl;
		cout << "1：Add message         ";
		cout << "2：Update message" << endl;
		cout << "3：Search message         ";
		cout << "4：Delete message" << endl;
		cout << "5：Stsff`s number         " << endl;
		cout << "6：Exit" << endl << endl;
	}

	return 0;
}