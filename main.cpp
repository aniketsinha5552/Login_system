#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// by aniket sinha

bool  IsLoggedIn()
{
     string username, password,un,pw;
     cout<<"Enter Username: "; cin>>username;
     cout<<"Enter Password: "; cin>>password;
     
     ifstream read("C:/Users/New/Desktop/Login_system\\"+ username+".txt");
     getline(read,un);
     getline(read,pw);
     if(un==username && pw==password){
         return true;
        
     }
     else return false;
}

int main(){
    int choice;
    cout<<"1:Register \n2:Login \n3:Close\nYour Choice: ";cin>>choice;
    if(choice==1){
        string username,password;
        cout<<"select a username: " ; cin >> username;
        cout<<"select a password: "; cin >> password;
        
        ofstream file;
        file.open("C:/Users/New/Desktop/Login_system\\"+ username+".txt");
        file << username <<endl << password;
        file.close();
        main();
    }
    else if(choice==2){
        bool status=IsLoggedIn();
        if(status!=true) {
            cout<<"false login \n";
            system("PAUSE");
            return main();
        }
        else{
            cout<<"Succesfully Logged in!"<<endl;
            system("PAUSE");
            return main();
        }
    }
    if(choice==3) return 0;

}