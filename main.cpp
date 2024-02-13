#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
#include <ctype.h>
using namespace std;

// Global Variable
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
int flag = 0;
// Global Variable End

class db_response
{
public:
    static void ConnectionFunction()
    {
        conn = mysql_init(0);
        if (conn)
        {
            cout << "Database Connected" << endl;
            cout << "Press any key to continue..." << endl;
            //getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "", "cpp_food_db", 0, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            cout << "Press any key to continue..." << endl;
            //getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
};
void UserMenu();
void AdminREgistration();
void UserRegistration();
void AdminMenu();
void UserLogin();
void ForgetPassword();
void AddNewItemInDatabase();
void ShowAllItems();
void ItemInStock();
void FindFood();
void EditItem();
void RemoveItem();
void CreateOrder();
void SoldItems();


int main()
{
    // Initial Load
    system("cls");
    system("title Food Ordering System");
    system("mode con: cols=140 lines=30");
    system("color 1");
    // Initial Load
   // db_response db_response;

// Login Module


       // Login Module

    // Call Methods
    db_response::ConnectionFunction();
    // Call Methods End

    // Variables
//    int chooseOneFromMenu = 0;
//    char exitSurity;
    int num;
    // Variables End

    cout << "\t\t\t\t\tWelcome To The Restaurant Food Ordering And Management System" << endl;
    cout << "\t\t\t\t\t-------------------------------------------------------------"<< endl << endl;
    cout << "\t\t\t1. Log in  "<< endl;
    cout << "\t\t\t2. Sign up  "<< endl;
    cout << "\t\t\t3. Exit  "<<endl<<endl;
    cout << "\t\t\tChoose one : ";
    cin >> num;
    if(num == 1){
        UserLogin();
        if(flag == 1){
            AdminMenu();
        }
        else
            UserMenu();
    }
    else if(num == 2){
        UserRegistration();
    }
    else if(num == 3){
        return 0;
    }
    else{

        cout<<"\t\t\tInvalid Input."<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "\t\t\tChoose 1 to 3 "<< endl;
        cout << "\t\t\t";
        Sleep(2000);
        system("pause");


        main();

    }

    return 0;
}

void AdminREgistration(){
    string username;
    string fname;
    string lname;
    string email;
    string password;
    char choose;
    system("cls");
            cout << "\n\t\t --------------------------------------------------------------------"<<endl;
            cout << "\t\t                           REGISTRITION PAGE                     "<<endl;
            cout << "\t\t                          -------------------                     ";
            cout<<"\n\n"<<endl;
            //cout << "\t\t\t Enter username: ";
            //getline(cin,username);
            string forger_query = "select username from user where username = '"+username+"'";
            const char* qn = forger_query.c_str();
            qstate = mysql_query(conn, qn);
             if (!qstate)
                {
                    res = mysql_store_result(conn);
                    if (row = mysql_fetch_row(res))
                    {
                        cout<<"Error"<<endl;
                         cout<<"Username is already in databaes"<<endl;
                         cout<<"Try agin"<<endl;
                         Sleep(3000);
                         AdminREgistration();
                    }

                }
             int nameLength = fname.length();
             char name1[nameLength];
            cout << "\t\t\t Enter First Name: ";
            //getline(cin,fname);
            cin>>fname;


            cout << "\t\t\t Enter Last Name: ";
            cin>>lname;
            cout << "\t\t\t Enter E-mail: ";
            cin>>email;

            //int emmailvalidation = 0;




            string forger_query1 = "select email from user where email = '"+email+"'";
            const char* qq = forger_query1.c_str();
            qstate = mysql_query(conn, qq);
             if (!qstate)
                {
                    res = mysql_store_result(conn);
                    if (row = mysql_fetch_row(res))
                    {
                        cout<<endl;
                        cout<<"\t\t\tError"<<endl;
                         cout<<"\t\t\tEmail is already in databaes"<<endl;
                         cout<<"\t\t\tTry agin"<<endl;
                         Sleep(3000);
                         AdminREgistration();
                    }

                }


                cout << "\t\t\t Enter User Name: ";
                cin >> username;
           // cout << "\t\t\t Enter password: ";
           // cin>>password;
           char ch;
            cout << "\t\t\t Enter Password: ";
            ch = _getch();
            while(ch != 13){//character 13 is enter
            password.push_back(ch);
            cout << '*';
            ch = _getch();
            }

         //   cout << "\t\t\t Register for Admin?(0 for user/1 for Admin) : ";
         //   cin>>choose;
            choose = '1';
          //  int res=isalpha(choose);


          /*   if (res){

                if(choose!='0' && choose!='1'){

              cin.clear();
              cin.ignore(1000,'\n');
              cout<<"\t\t\t Invalid Input."<<endl;
              cout << "\t\t\t ";
              system("pause");
              UserRegistration();

                }
             }*/


            string insert_query = "insert into user (username, fName, lName,email, password,userTpe) values ('"+username+"','"+fname+"','"+lname+"','"+email+"','"+password+"','"+choose+"')";
            const char* q = insert_query.c_str();

            qstate = mysql_query(conn, q);

            if (!qstate)
            {
                cout << endl << "\n\n\t\t\tSuccessfully added in database." << endl;
                Sleep(3000);

                main();
            }
            else
            {
                cout << "\n\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
            }

}
void ForgetPassword(){
    {
     system("cls");
     string Newpassword="";
     string proveIdentity = ""; // variable for any current username or email
     char letTry;
            cout << "\n\t\t --------------------------------------------------------------"<<endl;
            cout <<"\t\t                       RESET PASSWORD PAGE                     "<<endl;
            cout <<"\t\t                      ----------------------                   ";
            cout<<"\n\n"<<endl;
            cout<<"\t\t\tEnter your Email or Username :";
            cin>>proveIdentity;

       string proveIdentity_query = "select * from user where email = '"+proveIdentity+"' or username = '"+proveIdentity+"'";
      const char* qn = proveIdentity_query.c_str();
      qstate = mysql_query(conn, qn);

        if (!qstate)
    {
        res = mysql_store_result(conn);
        if (row = mysql_fetch_row(res))
        {
            cout<<endl;
            cout<<"\t\t\tWaite to check"<<endl;
            Sleep(2000);
            cout<<"\t\t\tWell! you are found"<<endl;
            Sleep(2000);
            system("cls");
            cout<<endl;
            //cout<<"\t\t\tEnter new password : ";
           // cin>>Newpassword;

            char ch;
            cout << "\t\t\t\t Enter new Password: ";
            ch = _getch();
            while(ch != 13){//character 13 is enter
            Newpassword.push_back(ch);
            cout << '*';
            ch = _getch();
            }


             string update_query = "update user set password = '"+Newpassword+"' where email = '"+proveIdentity+"' or username = '"+proveIdentity+"'" ;
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

            if (qstate)
            {

                cout << endl << "\t\t\tSuccessfully Updated." << endl;
                Sleep(2000);
                main();
            }
            else
            {
                cout <<"\t\t\tFailed To Update!" << mysql_errno(conn) << endl;
            }
        }
        else
        {
               cout<<"\t\t Error"<<endl;
               cout<<"\t\tNot matched. Enter t to try again or Enter r to Register"<<endl;
               cin>>letTry;
                for (int i = 0; i < 1; i++)
                {
                   if(letTry=='t' || letTry=='T')
                    {
                        main();
                    }
                    else if (letTry=='r' || letTry=='R')
                    {
                        UserRegistration();
                    }

                }


        }
    }
    else
    {
        cout << "\n\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
    }

}
}
void UserRegistration(){
    string username;
    string fname;
    string lname;
    string email;
    string password;
    char choose;
    system("cls");
            cout << "\n\t\t --------------------------------------------------------------------"<<endl;
            cout << "\t\t                           REGISTRITION PAGE                     "<<endl;
            cout << "\t\t                          -------------------                     ";
            cout<<"\n\n"<<endl;
            //cout << "\t\t\t Enter username: ";
            //getline(cin,username);
            string forger_query = "select username from user where username = '"+username+"'";
            const char* qn = forger_query.c_str();
            qstate = mysql_query(conn, qn);
             if (!qstate)
                {
                    res = mysql_store_result(conn);
                    if (row = mysql_fetch_row(res))
                    {
                        cout<<"Error"<<endl;
                         cout<<"Username is already in databaes"<<endl;
                         cout<<"Try agin"<<endl;
                         Sleep(3000);
                         UserRegistration();
                    }

                }
             int nameLength = fname.length();
             char name1[nameLength];
            cout << "\t\t\t Enter First Name: ";
            //getline(cin,fname);
            cin>>fname;


            cout << "\t\t\t Enter Last Name: ";
            cin>>lname;
            cout << "\t\t\t Enter E-mail: ";
            cin>>email;

            //int emmailvalidation = 0;




            string forger_query1 = "select email from user where email = '"+email+"'";
            const char* qq = forger_query1.c_str();
            qstate = mysql_query(conn, qq);
             if (!qstate)
                {
                    res = mysql_store_result(conn);
                    if (row = mysql_fetch_row(res))
                    {
                        cout<<endl;
                        cout<<"\t\t\tError"<<endl;
                         cout<<"\t\t\tEmail is already in databaes"<<endl;
                         cout<<"\t\t\tTry agin"<<endl;
                         Sleep(3000);
                         UserRegistration();
                    }

                }


                cout << "\t\t\t Enter User Name: ";
                cin >> username;
                char ch;
                cout << "\t\t\t Enter Password: ";
                ch = _getch();
                while(ch != 13){//character 13 is enter
                password.push_back(ch);
                cout << '*';
                ch = _getch();
            }

          //  cout << "\t\t\t Enter password: ";
          //  cin>>password;
         //   cout << "\t\t\t Register for Admin?(0 for user/1 for Admin) : ";
         //   cin>>choose;
            choose = '0';
          //  int res=isalpha(choose);


          /*   if (res){

                if(choose!='0' && choose!='1'){

              cin.clear();
              cin.ignore(1000,'\n');
              cout<<"\t\t\t Invalid Input."<<endl;
              cout << "\t\t\t ";
              system("pause");
              UserRegistration();

                }
             }*/


            string insert_query = "insert into user (username, fName, lName,email, password,userTpe) values ('"+username+"','"+fname+"','"+lname+"','"+email+"','"+password+"','"+choose+"')";
            const char* q = insert_query.c_str();

            qstate = mysql_query(conn, q);

            if (!qstate)
            {
                cout << endl << "\n\t\t\tSuccessfully added in database." << endl;
                Sleep(3000);

                main();
            }
            else
            {
                cout << "\n\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
            }



}
void UserLogin(){
   int currentchoice;
    string username,password;
           int choose = 0;
          char c = '*';
            system("cls");
            cout << "\n\t\t -----------------------------------------------------------------------------"<<endl;
            cout << "\t\t                                     LOGIN PAGE                     "<<endl;
            cout << "\t\t                                    ------------                     "<<endl;
            cout<<"\n\n"<<endl;

            cout<<"\t\t\t\tusername: ";
            cin>>username;




     //       string password ="";
            char ch;
            cout << "\t\t\t\tPassword: ";
            ch = _getch();
            while(ch != 13){//character 13 is enter
            password.push_back(ch);
            cout << '*';
            ch = _getch();
            }

            string login_query = "select * from user where username  = '"+username+"' and password = '"+password+"' ";
            const char* qn = login_query.c_str();
            qstate = mysql_query(conn, qn);
            if (!qstate) //if success
            {
                res = mysql_store_result(conn);
                if ((row = mysql_fetch_row(res)))
                {
                    if(atoi(row[5])==1)
                    {
                     cout<<"\n\t\t\t\tAdmin successfully logged in "<<endl;
                      Sleep(2000);
                      system("cls");
                      flag = 1;

                     }
                    else if(atoi(row[5])==0) // if user login
                    {
                        cout<<"\n\n\n\t\t\t\tUser successfully logged in "<<endl;
                        Sleep(2000);
                        system("cls");
                        flag = 0;
                    }
                }
                 else{
                cout<<" \n\t\t\t\tInvalid username or password."<<endl;
                cout <<"\n\t\t\t\t1. Go To Login Again" << endl;
                cout <<"\t\t\t\t2. Forget Password" << endl;
                cout <<"\t\t\t\t3. Back To Main" << endl;
                cout << "\t\t\t\tSelect One Choice : ";
                cin >> choose;

                    switch (choose)
                        {
                            case 1:
                              UserLogin();
                            break;
                            case 2:
                              ForgetPassword();
                            break;
                            case 3:
                               main();
                               break;



                        }

                }
            }
            else
            {
                cout << "\n\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
            }

        }


void UserMenu(){
    db_response::ConnectionFunction();
    int chooseOneFromMenu  = 0;
    char exitSurity;
    cout << "\t\t\t\t Customer Menu"<<endl;
    cout << "\t\t\t\t---------------"<< endl<< endl;
    cout << "\t\t\t1. Create Order" << endl;
    cout << "\t\t\t2. Find Food " << endl;
    cout << "\t\t\t3. Exit "<<endl<< endl;
    cout << "\t\t\tChoose one : ";
    cin >> chooseOneFromMenu;
    switch (chooseOneFromMenu)
    {
    case 1:
        CreateOrder();
        break;
    case 2:
        FindFood();
        break;
    case 3:
        ExitProgram:
        cout << "\t\t\tProgram terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            main();
        }else if (exitSurity == 'n' || exitSurity == 'N') {
            system("cls");
            UserMenu();
        }else {
            cout << "\t\t\tPlease choose (Y/N)" << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "\t\t\tPlease choose between 1 - 3. Press Any key To Continue...";
       getch();
       cin.clear();
       cin.ignore();
        system("CLS");
        UserMenu();
        break;
    }
}
void AdminMenu(){

    db_response::ConnectionFunction();
    int chooseOneFromMenu = 0;
    char exitSurity;
    cout << "\t\t\t\t Admin Menu"<<endl;
    cout << "\t\t\t\t---------------"<< endl<< endl;
    cout << "\t\t\t\t1. Sold Items." << endl;
    cout << "\t\t\t\t2. Item in Stock." << endl;
    cout << "\t\t\t\t3. Add New Item." << endl;
    cout << "\t\t\t\t4. Edit Item." << endl;
    cout << "\t\t\t\t5. Remove Item." << endl;
    cout << "\t\t\t\t6. Admin Sign up"<<endl;
    cout << "\t\t\t\t7. Exit." << endl<<endl;;
    cout << "\t\t\t\tChoose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        SoldItems();
        break;
    case 2:
        ItemInStock();
        break;
    case 3:
        AddNewItemInDatabase();
        break;
    case 4:
       EditItem();
        break;
    case 5:
        RemoveItem();
        break;
    case 6:
        AdminREgistration();
    case 7:
        ExitProgram:
        cout << "\t\t\t\tProgram terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            main();
        }else if (exitSurity == 'n' || exitSurity == 'N') {
            system("cls");
            AdminMenu();
        }else {
            cout << "\t\t\t\tPlease Press (Y/N)" << endl;
            goto ExitProgram;
        }
        break;

    default:
        cout << "\t\t\t\tPlease choose between 1 - 7. Press any key to continue...";
   getch();
   cin.clear();
   cin.ignore();
        system("CLS");
        Sleep(1000);
          AdminMenu();
        break;
    }

}
/*void ShowAllItems()
{
    system("cls");
    // Variables
    char choose;
    // Variables End

    cout << "Welcome To Food Ordering System" << endl << endl;
    cout << "Show All Items Menu" << endl << endl;

    qstate = mysql_query(conn, "select * from foodinfo");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << "\t\t\tID: " << row[0] << "\n\t\t\tCategory: " << row[1] << "\n\t\t\tType: " << row[2] << "\n\t\t\tName: " << row[3] << "\n\t\t\tManufacturer: " << row[4] << "\n\t\t\tPrice: " << row[5] << "\n\t\t\tQuantity: " << row[6] << endl << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "\t\t\tPress 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        AdminMenu();
    }
    else
    {
        exit(0);
    }
}*/
void AddNewItemInDatabase()
{
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string category = "";
    string type = "";
    string name = "";
    string manufacturer = "";
    float price = 0.0;
    int quantity = 0;
    char choose;
    // Variables End

   // cout << "Welcome To Food Ordering System" << endl << endl;
    cout << "\t\t\tAdd New Item Menu" << endl;
    cout << "\t\t\t------------------"<<endl<<endl;

    cin.ignore(1, '\n');
    cout << "\t\t\tEnter Category (Drinks/Dryfood/Fastfood/snacks?: ";
    getline(cin, category);
    cout << "\t\t\tEnter Type(Juice/coffee/Biscuits/cake/Burger: ";
    getline(cin, type);
    cout << "\t\t\tEnter Name: ";
    getline(cin, name);
    cout << "\t\t\tEnter Manufacturer: ";
    getline(cin, manufacturer);
    cout << "\t\t\tEnter Price: ";
    cin >> price;
    cout << "\t\t\tEnter Quantity: ";
    cin >> quantity;

    stringstream streamPrice, streamQuan;
    string sprice, squan;
    streamPrice << price;
    streamPrice >> sprice;
    streamQuan << quantity;
    streamQuan >> squan;


    string insert_query = "insert into foodinfo (f_category, f_type, f_name, f_manufacturer, f_price, f_quantity) values ('"+category+"','"+type+"','"+name+"','"+manufacturer+"','"+sprice+"','"+squan+"')";

    const char* q = insert_query.   c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "\t\t\tSuccessfully added in database." << endl;
    }
    else
    {
        cout << "\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "\t\t\tPress 'm' to Menu and 'a' to Insert Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        AdminMenu();
    }
    else if (choose == 'a' || choose == 'A')
    {
        AddNewItemInDatabase();
    }
    else
    {
        exit(0);
    }
}
void ItemInStock()
{
    system("cls");

    // Variables
    char choose;
    // Variables End

   // cout << "\t\t\tWelcome To Food Ordering System" << endl << endl;
    cout << "\t\t\tItems In Stock Menu" << endl;
    cout<< "\t\t\t---------------------"<< endl<<endl;

    qstate = mysql_query(conn, "select f_name, f_manufacturer, f_price, f_quantity from foodinfo");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            if (atoi(row[3]) > 0)
            {
                cout << "\t\t\tName: " << row[0] << "\n\t\t\tManufacturer: " << row[1] << "\n\t\t\tPrice: " << row[2] << "\n\t\t\tQuantity: " << row[3] << endl << endl;
            }
        }
    }
    else
    {
        cout << "\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
    }

    cout << "\t\t\tPress 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        AdminMenu();
    }
    else
    {
        exit(0);
    }
}

void FindFood()
{
    system("cls");

    // Variables
    char choose;
    string input;
    // Variables End

   // cout << "Welcome To Food Ordering System" << endl << endl;
    cout << "\t\t\tFind Food Menu" << endl;
    cout << "\t\t\t---------------"<<endl<<endl;

    cout << "\t\t\tFind by \n\t\t\t1. Name\n\t\t\t2. Category\n\t\t\t3. Type\n\t\t\t4. Manufacturer\n\t\t\tAny other number to Menu" << endl;
    cout << "\t\t\tChoose One: "; cin >> choose;
    system("cls");

    cin.ignore(1, '\n');
    if (choose == '1')
    {
        cout << "\t\t\tEnter Name: "; getline(cin, input);
        string findbyname_query = "select * from foodinfo where f_name like '"+input+"%'";
        const char* qn = findbyname_query.c_str();
        qstate = mysql_query(conn, qn);
    }
    else if (choose == '2')
    {
        cout << "\t\t\tEnter Category: "; getline(cin, input);
        string findbycategory_query = "select * from foodinfo where f_category like '"+input+"%'";
        const char* qc = findbycategory_query.c_str();
        qstate = mysql_query(conn, qc);
    }
    else if (choose == '3')
    {
        cout << "\t\t\tEnter Type: "; getline(cin, input);
        string findbytype_query = "select * from foodinfo where f_type like '"+input+"%'";
        const char* qt = findbytype_query.c_str();
        qstate = mysql_query(conn, qt);
    }
    else if (choose == '4')
    {
        cout << "\t\t\tEnter Manufacturer: "; getline(cin, input);
        string findbymanufacturer_query = "select * from foodinfo where f_manufacturer like '"+input+"%'";
        const char* qa = findbymanufacturer_query.c_str();
        qstate = mysql_query(conn, qa);
    }else
    {
        goto ExitMenu1;
    }

    cout << endl;
    if (choose == '1' || choose == '2' || choose == '3' || choose == '4')
    {
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while ((row = mysql_fetch_row(res)))
            {
             //   cout << "ID: " << row[0] << "\nCategory: " << row[1] << "\nType: " << row[2] << "\nName: " << row[3] << "\nManufacturer: " << row[4] << "\nPrice: " << row[5] << "\nQuantity: " << row[6] << endl << endl;
             cout << "\t\t\tID: " << row[0] << "\n\t\t\tName: " << row[3] << "\n\t\t\tPrice: " << row[5] << "\n\t\t\tCategory: " << row[1] << "\n\t\t\tType: " << row[2] << "\n\t\t\tManufacturer: " << row[4] << endl << endl;
             goto ExitMenu;
            }
        }
        else
        {
            cout << "\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    ExitMenu1:
        cout << "\t\t\tInvalid.Please press correct key "<<endl<<endl;
        cout << "\t\t\tPress 'm' to Menu, 'a' to Search again and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        UserMenu();
    }
    else if (choose == 'a' || choose == 'A')
    {
        FindFood();
    }
    else
    {
        exit(0);
    }

    ExitMenu:
    cout << "\t\t\tPress 'm' to Menu, 'a' to Search again and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        FindFood();
    }
    else
    {
        exit(0);
    }
}

void EditItem()
{
    system("cls");

    // Variables
    string category = "";
    string type = "";
    string name = "";
    string manufacturer = "";
    string items[5000];
    string price = "";
    string quantity = "";
    char choose;
    int itemId;
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForId = 0;

    // Store Variables
    string storeid = "";
    string storecategory = "";
    string storetype = "";
    string storename = "";
    string storemanufacturer = "";
    string storeprice = "";
    string storequantity = "";
    // Variables End

   // cout << "Welcome To Food Ordering System" << endl << endl;
    cout << "\t\t\tEdit Item Menu" << endl;
    cout << "\t\t\t---------------"<<endl<<endl;

    qstate = mysql_query(conn, "select f_id, f_name from foodinfo");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "\t\t\tID\tName\n" << endl;
        while ((row = mysql_fetch_row(res)))
        {
            cout <<"\t\t\t"<< row[0] << "\t" << row[1] << endl;
            items[indexForId] = row[0];
            indexForId++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "\t\t\tEnter Item ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "\t\t\tPlease Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << itemId;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string findbyid_query = "select * from foodinfo where f_id = '"+strid+"'";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                cout << endl;
                while ((row = mysql_fetch_row(res)))
                {
                    cout << "\t\t\tID: " << row[0] << "\n\t\t\tCategory: " << row[1] << "\n\t\t\tType: " << row[2] << "\n\t\t\tName: " << row[3] << "\n\t\t\tManufacturer: " << row[4] << "\n\t\t\tPrice: " << row[5] << "\n\t\t\tQuantity: " << row[6] << endl << endl;
                    storeid = row[0];
                    storecategory = row[1];
                    storetype = row[2];
                    storename = row[3];
                    storemanufacturer = row[4];
                    storeprice = row[5];
                    storequantity = row[6];
                }
            }
            else
            {
                cout << "\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
            }

            cin.ignore(1, '\n');
            cout << "\t\t\tEnter Category : ";
            getline(cin, category);
            if (category == "x")
            {
                category = storecategory;
            }
            cout << "\t\t\tEnter Type : ";
            getline(cin, type);
            if (type == "xN")
            {
                type = storetype;
            }
            cout << "\t\t\tEnter Name : ";
            getline(cin, name);
            if (name == "xN")
            {
                name = storename;
            }
            cout << "\t\t\tEnter Manufacturer : ";
            getline(cin, manufacturer);
            if (manufacturer == "xN")
            {
                manufacturer = storemanufacturer;
            }
            cout << "\t\t\tEnter Price : ";
            cin >> price;
            if (price == "xN")
            {
                category = storecategory;
            }
            cout << "\t\t\tEnter Quantity : ";
            cin >> quantity;
            if (quantity == "xN")
            {
                quantity = storequantity;
            }

            string update_query = "update foodinfo set f_category = '"+category+"', f_type = '"+type+"', f_name = '"+name+"', f_manufacturer = '"+manufacturer+"', f_price = '"+price+"', f_quantity = '"+quantity+"' where f_id = '"+strid+"'";
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

            if (!qstate)
            {
                cout << endl << "\t\t\tSuccessfully Saved In Database." << endl;
            }
            else
            {
                cout << "\t\t\tFailed To Update!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "\t\t\tItem Not Found in database." << endl;
        }
    }

    ExitMenu:
    cout << "\t\t\tPress 'm' to Menu, 'e' to edit another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        AdminMenu();
    }
    else if (choose == 'e' || choose == 'E')
    {
        EditItem();
    }
    else
    {
        exit(0);
    }
}
void RemoveItem()
{
    system("cls");

    // Variables
    char choose;
    int itemId;
    string items[5000];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;
    // Variables End

    cout << "\t\t\tRemove Item Menu" << endl;
    cout << "\t\t\t------------------"<<endl<<endl;

    qstate = mysql_query(conn, "select f_id, f_name from foodinfo");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "\t\t\tID\tName\n" << endl;
        while ((row = mysql_fetch_row(res)))
        {
            cout <<"\t\t\t"<< row[0] << "\t" << row[1] << endl;
            items[indexForId] = row[0];
            indexForId++;
        }
    }
    else
    {
        cout << "\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "\t\t\tEnter Item ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "\t\t\tPlease Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << itemId;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string delete_query = "delete from foodinfo where f_id = '"+strid+"'";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "\t\t\tSuccessfully Deleted From Database." << endl;
            }
            else
            {
                cout << "\t\t\tFailed To Delete!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "\t\t\tItem Not Found in database." << endl;
        }
    }

    // Exit Code
    ExitMenu:
    cout << "\t\t\tPress 'm' to Menu, 'd' to delete another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        AdminMenu();
    }
    else if (choose == 'd' || choose == 'D')
    {
        RemoveItem();
    }
    else
    {
        exit(0);
    }
}
void CreateOrder()
{
    system("cls");

    // Variables
    char choose;
    string getId = "";
    string itemId[5000];
    string itemName[5000];
    char chooseEditOrBuy;
    int itemIndex = 0;
    float totalPrice = 0.0;
    bool purchase, itemFalse = false;

    string storeId[5000];
    string storeName[5000];
    string storeCategory[5000];
    string storeType[5000];
    string storeManufacturer[5000];
    string storePrice[5000];
    string storeQuantity[5000];
    int storeIndex = 0, storeIndexN = 0;
    // Variables End

    cout << "\t\t\tWelcome To Food Ordering System" << endl << endl;
    cout << "\t\t\tShow All Items Menu" << endl << endl;

    qstate = mysql_query(conn, "select * from foodinfo");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            if (atoi(row[6]) > 0)
            {

                cout << "\t\t\tID: " << row[0] << "\n\t\t\tName: " << row[3] << "\n\t\t\tPrice: " << row[5] << "\n\t\t\tCategory: " << row[1] << "\n\t\t\tType: " << row[2] << "\n\t\t\tManufacturer: " << row[4] << endl << endl;
                storeId[storeIndex] = row[0];
                storeCategory[storeIndex] = row[1];
                storeType[storeIndex] = row[2];
                storeName[storeIndex] = row[3];
                storeManufacturer[storeIndex] = row[4];
                storePrice[storeIndex] = row[5];
                storeQuantity[storeIndex] = row[6];
                storeIndex++;
            }
        }
    }
    else
    {
        cout << "\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
    }

    for (itemIndex = 0;;itemIndex++)
    {
        cout << "\t\t\tEnter a Food ID's (q to exit): ";
        cin >> getId;
        if (getId == "q")
        {
            break;

        }
        else
        {
            for(int i = 0; i < storeIndex; i++)
            {
                if (getId == storeId[i])
                {
                    itemId[itemIndex] = getId;
                    itemFalse = false;
                    break;
                }
                else
                {
                    itemFalse = true;
                }
            }
            if (itemFalse == true)
            {
                cout << "\t\t\tEnter a valid number." << endl;
                itemIndex--;
                itemFalse = false;
            }
        }
    }

    cout << "\t\t\tYou choose this food id's: ";
    for (int i = 0; i < itemIndex; i++)
    {
        cout << itemId[i] << " ";
    }

    CHOOSEEDITORBUY:
    cout << endl << "\t\t\tDo you want to edit items(e) or buy this items(b): ";
    cin >> chooseEditOrBuy;

    if (chooseEditOrBuy == 'e')
    {
        for (int i = 0;;i++)
        {
            cout << "\t\t\tRemove item id's (q to exit): ";
            cin >> getId;
            if (getId == "q")
            {
                break;
            }
            else
            {
                for (int j = 0;j < itemIndex;j++)
                {
                    if (itemId[j] == getId)
                    {
                        for (int k = j; k < itemIndex; k++)
                        {
                            itemId[k] = itemId[k+1];
                        }
                        itemId[itemIndex--] = "\0";
                    }
                }
            }
        }

        cout << "\t\t\tYou choose this food id's: ";
        for (int i = 0; i < itemIndex; i++)
        {
            cout << itemId[i] << " ";
        }

        goto CHOOSEEDITORBUY;
    }
    else if (chooseEditOrBuy == 'b')
    {
        for (int i = 0; i < itemIndex; i++)
        {
            for (int j = 0; j < storeIndex; j++)
            {
                if (itemId[i] == storeId[j])
                {
                    qstate = mysql_query(conn, "select f_quantity from foodinfo");
                    if (!qstate)
                    {
                        res = mysql_store_result(conn);
                        while ((row = mysql_fetch_row(res)))
                        {
                            if (atoi(row[0]) > 0)
                            {
                                storeQuantity[storeIndexN] = row[0];
                                storeIndexN++;
                            }
                        }
                        storeIndexN = 0;
                    }
                    else
                    {
                        cout << "\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
                    }

                    totalPrice += strtof((storePrice[j]).c_str(), 0);

                    float quan1 = strtof((storeQuantity[j]).c_str(), 0);
                    quan1 -= 1;
                    float quan2 = strtof((storeQuantity[j]).c_str(), 0);
                    float quan = quan2 - quan1;
                    string getResult;
                    stringstream strquan;
                    strquan << quan;
                    strquan >> getResult;

                    string getQuan1;
                    stringstream strquan1;
                    strquan1 << quan1;
                    strquan1 >> getQuan1;

                    string insert_query = "insert into solditem (f_category, f_type, f_name, f_manufacturer, f_price, f_quantity) values ('"+storeCategory[j]+"','"+storeType[j]+"','"+storeName[j]+"','"+storeManufacturer[j]+"','"+storePrice[j]+"','"+getResult+"')";
                    purchase = true;

                    //cout << insert_query << endl;


                    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

                    qstate = mysql_query(conn, q);

                    if (!qstate)
                    {
                        purchase = true;
                    }
                    else
                    {
                        cout << "\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
                    }


                    string update_query = "update foodinfo set f_quantity = '"+getQuan1+"' where f_id = '"+storeId[j]+"'";
                    const char* qu = update_query.c_str();
                    //cout << update_query << endl;

                    qstate = mysql_query(conn, qu);

                    if (qstate)
                    {
                        cout << "Failed To Update!" << mysql_errno(conn) << endl;
                    }
                }
            }
        }

        if(purchase == true)
        {
            cout << endl << "\t\t\tPurchase Successfully Done." << endl;
            cout << endl << "\t\t\tTotal Price: " << totalPrice <<" RM"<< endl;
        }
    }
    else{
        cout << "\n\t\t\tInvalid.Please press the correct key to procced"<<endl;
        goto CHOOSEEDITORBUY;
    }

    // Exit Code
    cout << endl << "\t\t\tPress any key to Exit: ";
    cin >> choose;
    exit(0);
    /*if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else
    {
        exit(0);
    }*/
}
void SoldItems()
{

    system("cls");

    // Variables
    char choose;
    // Variables End


    cout << "\t\t\tSold Items Menu" << endl;
    cout << "\t\t\t----------------"<<endl<<endl;

    qstate = mysql_query(conn, "select f_name, f_manufacturer, f_category, f_type, f_price, sum(f_quantity) from solditem group by f_name");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << "\t\t\tName: " << row[0] << "\n\t\t\tManufacturer: " << row[1] << "\n\t\t\tCategory: " << row[2] << "\n\t\t\tType: " << row[3] << "\n\t\t\tPrice: " << row[4] << "\n\t\t\tQuantity: " << row[5] << endl << endl;
          //  cout << "\t\t\tID: " << row[0] << "\n\t\t\tName: " << row[3] << "\n\t\t\tPrice: " << row[5] << "\n\t\t\tCategory: " << row[1] << "\n\t\t\tType: " << row[2] << "\n\t\t\tManufacturer: " << row[4] << endl << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }


    cout << "\t\t\tPress 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        AdminMenu();
    }

    else
    {
        exit(0);
    }

}
