#include<bits/stdc++.h>
using namespace std;
class phoneBook{
	public:
	//----------------------------show all contact-------------------------//
	void showAllContact(){
	ifstream file("phone.csv");
	while(file.good()){
		string s;
		getline(file,s,'\n');
		cout<<s<<endl;
//		cout<<endl;
	}
		cout<<"Succesfully created and press any key to continue: ";
	system("pause");
	file.close();
	return;
}
	//--------------------------add new contact---------------------------------//
	void AddNewContact(){
	system("cls");
	ofstream file;
	file.open("phone.csv",ios::app);
	string name,number;
	cout<<"Enter Name : ";
	cin>>name;
	cout<<"Enter Mobile Number : ";
	cin>>number;
	string s = name + "," + number;
	file<<s<<endl;
	file.close();

	return;
	
}
//------------------------Remove any contact-----------------------//
void RemoveAnyContact(){
	
	

	string s;
	cin>>s;
	ofstream newFile;
	newFile.open("phone1.csv",ios::app);
	ifstream oldFile;
	oldFile.open("phone.csv");
	while(oldFile.good()){
		string s1;
		getline(oldFile,s1,'\n');
		if(s1 != s && s1 != ""){
//			cout<<s1<<endl;
			newFile<<s1<<endl;
		}
	}
	
	newFile.close();
	oldFile.close();
	remove("phone.csv");
	rename("phone1.csv","phone.csv");
	
	cout<<"Succesfully remove and press any key to continue: ";
	system("pause");
	return;
	

	
	
}
//-----------------search any name------------------------------//
void SearchAnyName(){
	system("cls");
	ifstream file;
	file.open("phone.csv");
	cout<<"Please Enter the name you want to search : ";
	string name;
	cin>>name;
	while(file.good()){
		string s;
		string s2;
		getline(file,s,',');
		getline(file,s2,'\n');
		if(s == name){
			cout<<name<<" "<<s2<<endl;
		}
	}
	file.close();
	cout<<"Succesfully remove and press any key to continue: ";
	system("pause");
	return;
}
//-----------------------------UpdateContact---------------------------//
void UpdateContact(){
	system("cls");
	cout<<"assume that name is ->mohit and mobile number is ->1234567890 that you want to update from list : \n";
	cout<<"please type-> mohit,1234567890";
	cout<<"Enter name,mobile number do you want to update : ";
	RemoveAnyContact();
	cout<<"Enter name and number you want to update : ";
	AddNewContact();
		cout<<"Succesfully updated and press any key to continue: ";
	system("pause");
}
//----------------------show info--------------------------------------//
int showInfo(){
	cout<<"Press 1 : for showing all contact : \n";
	cout<<"Press 2 : for add new contact : \n";
	cout<<"Press 3 : for removing any contact : \n";
	cout<<"Press 4 : for searching any name : \n";
	cout<<"Press 5 : for updating any contact : \n";
	cout<<"Press Any remains key : for exit : \n";
	int choose;
	cout<<"Please choose any key to perform any operation : ";
	cin>>choose;
	return choose;
}


};

int main(){
	phoneBook phone;
	while(1){
	system("cls");
	int choose = phone.showInfo();
	switch(choose){
		case 1:
			phone.showAllContact();
			break;
		case 2:
			phone.AddNewContact();
			cout<<"Succesfully created and press any key to continue: ";
			system("pause");
			break;
		case 3:
			system("cls");
			cout<<"assume that name is ->mohit and mobile number is ->1234567890 that you want to remove from list : \n";
			cout<<"please type-> mohit,1234567890";
			cout<<"Enter name,mobile number do you want to remove : ";
			phone.RemoveAnyContact();
			break;
		case 4:
			phone.SearchAnyName();
			break;
		case 5:
			phone.UpdateContact();
			break;
		default:
			exit(0);
			break;
}
	}
	return 1;
}