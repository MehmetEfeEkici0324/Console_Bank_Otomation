#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <vector>
#include <map>
#include <limits>
using namespace std;

static void clearScreen() {
    system("cls");
}

class TotalMoneyCalculate {
public:
    double MoneyThatCome = 0;
    double MoneyThatOut = 0;
    double Debts = 0;
    double Cash = 0;


    double CurrentCashMoney();
};

class ExchangeInvest {

public:
    string anyinvestmentname;
    int GoldSell = 0;
    double DolarSell = 0;
    double EuroSell = 0;
    double goldhave = 0;
    double dolarhave = 0;
    double eurohave = 0;

    void LIRA();
    void GOLD();
    void DOLAR();
    void EURO();
};

class Users : public ExchangeInvest, public TotalMoneyCalculate{
public:
    string username;
    string usersurname;
    string password;
    int personalID[11] = {};
    int ibannumber = 0;
    int iban[18] = {};
    bool ibancontrol = false;

    void ibanreturn() {

        if (!ibancontrol) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dist(0, 9);

            for (int i = 0; i < 18; i++) {
                ibannumber = dist(gen);
                iban[i] = ibannumber;
            }
        } ibancontrol = true;

        cout << "TR";
        for (int a = 0; a < 2; a++) {
            cout << iban[a];
        } cout << " ";

        for (int b = 2; b < 15; b += 4) {
            for (int c = b; c < b + 4; c++) {
                cout << iban[c];
            } cout << " ";
        }
    }

    void ibanreturn(int* IBAN) {

        cout << "TR";
        for (int a = 0; a < 2; a++) {
            cout << IBAN[a];
        } cout << " ";

        for (int b = 2; b < 15; b += 4) {
            for (int c = b; c < b + 4; c++) {
                cout << IBAN[c];
            } cout << " ";
        }
    }
};

vector<Users*> allUsers; //sitemdeki bütün kullancıları dinamik dizi içerisinde heapte saklamak içindir.  Array aksine sınırı konmayabilir.
TotalMoneyCalculate totalmoney;
ExchangeInvest totalinvest;
Users* currentUser = nullptr; //Hiçkimse kayıt yapmamış ise bir şey getirmez gelen kullanıcıya göre o kullanıcının nesnesini alır ve bilgilerini çeker.

class Logo {
public:

    void LogoBank() {
        clearScreen();

        cout << "\n\n\t\t";
        for (int i = 0; i < 60; i++) {
            cout << "-";
        }

        cout << "\n\t\t@@@@@   @  @   @   @@@@   @      @@@@    @   @   @   @  @";
        cout << "\n\t\t@       @ @        @             @   @  @ @  @@  @   @ @";
        cout << "\n\t\t@@@     @@     @   @      @      @@@@  @   @ @ @ @   @@";
        cout << "\n\t\t@       @ @    @   @      @      @   @ @@@@@ @  @@   @ @";
        cout << "\n\t\t@@@@@   @  @   @   @@@@   @      @@@@  @   @ @   @   @  @";

        cout << "\n\t\t";
        for (int i = 0; i < 60; i++) {
            cout << "-";
        }

    }
};

Logo logo;

void RegisterQuestion();
static void Register();
static void LogIn();
void ChangePassword();
void Account();
void MainPage();
void SendPage();
void InvestmentPage();
void Bill();
void sellDolar(double howMdolar);
void buyDolar(double howMdolar);
void sellEuro(double howMeuro);
void buyEuro(double howMeuro);
void sellGold(double howMgold);
void buyGold(double howMgold);
void withdrawCash(double howMcash);
void depositCash(double howMcash);

// class gibi farklı türdeki verileri aynı yapı altıda tutmayı sağlar.
struct bill {
    string billName;
    double billAmount;
};

// using ifadesi bir takma ad oluşturur burada da her seferinde map<string, vector<bill>> bu kodu yazmaktansa PersonBills yazıp bu tanımı çağıracağız.
using PersonBills = map<string, vector<bill>>;
PersonBills all_Bills;
void addBill(PersonBills& bills, const string& person, const string& name, double amount);

int main()
{
    RegisterQuestion();
}


void sellDolar(double howMdolar) {

    clearScreen();
    cout << "\n\n\t | YOUR DOLAR | : " << currentUser->dolarhave;
    if (howMdolar > currentUser->dolarhave) {
        clearScreen();
        cout << "\n\n\t\a > YOU HAVEN'T ENOUGH AMOUNT OF DOLAR !!!";
        system("timeout /t 2 > nul");
        MainPage();
    }
    else {
        currentUser->dolarhave -= howMdolar;
        currentUser->Cash += howMdolar * currentUser->DolarSell;
        currentUser->DOLAR();
        currentUser->LIRA();
        system("pause");
        clearScreen();
        MainPage();
    }

};
void buyDolar(double howMdolar) {

    clearScreen();
    cout << "\n\n\t | YOUR DOLAR | : " << currentUser->dolarhave;
    if (currentUser->Cash < howMdolar * (currentUser->DolarSell + 1.8)) {
        clearScreen();
        cout << "\n\n\t\a > YOU HAVEN'T ENOUGH MONEY !!!";
        system("timeout /t 2 > nul");
        MainPage();
    }
    else {
        currentUser->dolarhave += howMdolar;
        currentUser->Cash -= howMdolar * (currentUser->DolarSell + 1.8);
        currentUser->DOLAR();
        currentUser->LIRA();
        system("pause");
        clearScreen();
        MainPage();
    }

};
void sellEuro(double howMeuro) {

    clearScreen();
    cout << "\n\n\t | YOUR EURO | : " << currentUser->eurohave;
    if (howMeuro > currentUser->eurohave) {
        clearScreen();
        cout << "\n\n\t\a > YOU HAVEN'T ENOUGH AMOUNT OF EURO !!!";
        system("timeout /t 2 > nul");
        MainPage();
    }
    else {
        currentUser->eurohave -= howMeuro;
        currentUser->Cash += howMeuro * currentUser->EuroSell;
        currentUser->EURO();
        currentUser->LIRA();
        system("pause");
        clearScreen();
        MainPage();
    }

};
void buyEuro(double howMeuro) {

    clearScreen();
    cout << "\n\n\t | YOUR EURO | : " << currentUser->eurohave;
    if (currentUser->Cash < howMeuro * (currentUser->EuroSell + 2.1)) {
        clearScreen();
        cout << "\n\n\t\a > YOU HAVEN'T ENOUGH MONEY !!!";
        system("timeout /t 2 > nul");
        MainPage();
    }
    else {
        currentUser->eurohave += howMeuro;
        currentUser->Cash -= howMeuro * (currentUser->EuroSell + 2.1);
        currentUser->EURO();
        currentUser->LIRA();
        system("pause");
        clearScreen();
        MainPage();
    }

};
void sellGold(double howMgold) {

    clearScreen();
    cout << "\n\n\t | YOUR GOLD | : " << currentUser->goldhave;
    if (howMgold > currentUser->goldhave) {
        clearScreen();
        cout << "\n\n\t\a > YOU HAVEN'T ENOUGH AMOUNT OF GOLD !!!";
        system("timeout /t 2 > nul");
        MainPage();
    }
    else {
        currentUser->goldhave -= howMgold;
        currentUser->Cash += howMgold * currentUser->GoldSell;
        currentUser->GOLD();
        currentUser->LIRA();
        system("pause");
        clearScreen();
        MainPage();
    }

};
void buyGold(double howMgold) {

    clearScreen();
    cout << "\n\n\t | YOUR GOLD | : " << currentUser->goldhave;
    if (currentUser->Cash < howMgold * (currentUser->GoldSell + 200)) {
        clearScreen();
        cout << "\n\n\t\a > YOU HAVEN'T ENOUGH MONEY !!!";
        system("timeout /t 2 > nul");
        MainPage();
    }
    else {
        currentUser->goldhave += howMgold;
        currentUser->Cash -= howMgold * (currentUser->GoldSell + 200);
        currentUser->GOLD();
        currentUser->LIRA();
        system("pause");
        clearScreen();
        MainPage();
    }

};

void withdrawCash(double howMcash) {

    double withdraw = 0;

    if (currentUser->Cash >= howMcash) {
        clearScreen();
        cout << "\n\n\t | CURRENT MONEY | : " << currentUser->Cash;
        cout << "\n\n\t\t Process continuing ... ";
        withdraw = currentUser->Cash -= howMcash;
        cout << "\n\n\t | NEW MONEY | : " << withdraw;
        system("timeout /t 2 > nul");
        MainPage();
    }
    else {
        clearScreen();
        cerr << "\n\n\t\a > YOU HAVEN'T ENOUGH MONEY TO WITHDRAW !!! ";
        system("timeout /t 2 > nul");
        MainPage();
    }
};

void depositCash(double howMcash) {
    double deposit = 0;

    clearScreen();
    cout << "\n\n\t | CURRENT MONEY | : " << currentUser->Cash;
    cout << "\n\n\t\t Process continuing ... ";
    deposit = currentUser->Cash += howMcash;
    cout << "\n\n\t | NEW MONEY | : " << deposit;
    system("timeout /t 2 > nul");
    MainPage();
};


double TotalMoneyCalculate::CurrentCashMoney() {
    return currentUser->Cash - currentUser->Debts;
}

void ExchangeInvest::LIRA() {

        cout << "\n\n\t|    LIRA    | : " << currentUser->Cash << " | ";
        cout << "\n\t| EQUAL DOLAR | : " << currentUser->Cash / DolarSell << " | ";
        cout << "\n\t| EQUAL EURO | : " << currentUser->Cash / EuroSell << " | ";
        cout << "\n\t| EQUAL GOLD | : " << currentUser->Cash / GoldSell << " | ";
    }

void ExchangeInvest::GOLD() {

        cout << "\n\n\t|     AMOUNTS OF YOUR GOLDS     | : " << goldhave << " | ";
        cout << "\n\t|      VALUE OF YOUR GOLDS      | : " << goldhave * GoldSell << " | ";

    }
void ExchangeInvest::DOLAR() {

        cout << "\n\n\t|     AMOUNTS OF YOUR DOLARS      | : " << dolarhave << " | ";
        cout << "\n\t|       VALUE OF YOUR DOLARS      | : " << dolarhave * DolarSell << " | ";
    }
void ExchangeInvest::EURO() {

        cout << "\n\n\t|     AMOUNTS OF YOUR EUROS     | : " << eurohave << " | ";
        cout << "\n\t|      VALUE OF YOUR EUROS      | : " << eurohave * EuroSell << " | ";
    }

void RegisterQuestion() {

    ::logo.LogoBank();

    char sign;

    cout << "\n\n\t\t DO YOU HAVE A ACCOUNT ON EKICI BANK ? ( y/n ): ";
    cin >> sign;

    if (sign == 'y') {

        cout << "\n\n\t\t!!! YOU ARE DIRECTED TO LOG IN PAGE !!!";
        system("timeout /t 2 > nul");
        LogIn();

    }
    else if (sign == 'n') {

        cout << "\n\n\t\t!!! YOU ARE DIRECTED TO REGISTER PAGE !!!";
        system("timeout /t 2 > nul");
        Register();

    }
    else {

        cout << "\n\n\t\t!!! PLEASE ENTER ONLY y ( FOR YES ) OR n ( FOR NO ) !!! ";
        system("timeout /t 2 > nul");
        RegisterQuestion();
    }

};


static void Register() {

registerstart:

    ::logo.LogoBank();

    Users* newUser = new Users;

    string name;
    string surname;
    string password;
    long double personalid;
    double lira, dolar, euro, gold;
    char confirm;

    cout << "\n\n\t|    NAME    | : ";
    cin.ignore();
    getline(cin, name);
    cout << "\n\t|   SURNAME  | : ";
    getline(cin, surname);
    cout << "\n\t|     ID     | : ";
    cin >> personalid;
    cout << "\n\t|  PASSWORD  | : ";
    cin >> password;
    //totalinvst objecti ile değer ataması yaptıgın içni her açıp kapamada para miktarlarını kayediyorsun
    string translate = to_string(personalid);

    for (int i = 0; i < translate.length(); i++) {
        newUser->personalID[i] = translate[i] - '0';
    }

    bool idAlreadyExists = false;

    for (Users* u : allUsers) {
        bool match = true;
        for (int i = 0; i < 11; i++) {
            if (newUser->personalID[i] != u->personalID[i]) {
                match = false; 
                break;
            }
        }
        if (match) {
            idAlreadyExists = true;
            break;
        }
    }

    if (idAlreadyExists) {
        cout << "\n\n\t THIS ID IS ALREADY IN USE, TRY A NEW ID! [ Error Cx009 ] ";
        delete newUser; 
        system("timeout /t 2 > nul");
        clearScreen();
        goto registerstart;
    }

    (newUser->username) = name;
    (newUser->usersurname) = surname;
    (newUser->password) = password;

    cout << "\n\n\t| ENTER HOW MUCH YOU HAVE LIRA  | : ";
    cin >> lira;
    cout << "\n\t| ENTER HOW MUCH YOU HAVE DOLAR | : ";
    cin >> dolar;
    cout << "\n\t| DOLAR'S RATE | : ";
    cin >> newUser->DolarSell;
    cout << "\n\t| ENTER HOW MUCH YOU HAVE EURO  | : ";
    cin >> euro;
    cout << "\n\t| EURO'S RATE | : ";
    cin >> newUser->EuroSell;
    cout << "\n\t| ENTER HOW MUCH YOU HAVE GOLD  | : ";
    cin >> gold;
    cout << "\n\t| GOLD'S RATE | : ";
    cin >> newUser->GoldSell;

    newUser->Cash = lira;
    newUser->dolarhave = dolar;
    newUser->eurohave = euro;
    newUser->goldhave = gold;

    cout << "\n\n\t\tIF YOU CONFIRM THESE INFORMATIONS THAT ABOUT YOU ENTER ' C ' : ";
    cin >> confirm;

    switch (confirm) {
    case 'C':
        allUsers.push_back(newUser); //push_back vector dizisine yeni eleman gönderme komutudur
        currentUser = newUser;
        cout << "\n\n\t\t# YOUR ACCOUNT IS CREATED ... #";
        system("timeout /t 2 > nul");
        MainPage();
        break;

    case 'c':
        allUsers.push_back(newUser); //push_back vector dizisine yeni eleman gönderme komutudur
        currentUser = newUser;
        cout << "\n\n\t\t# YOUR ACCOUNT IS CREATED ... #";
        system("timeout /t 2 > nul");
        MainPage();
        break;

    default:
        cout << "\n\n\t\t!!! PLEASE ENTER ONLY C ( FOR CONFIRM ) !!!";
        cout << "\n\t\t*** YOU ARE DIRECTED TO REGISTER PAGE AGAIN ***";
        system("timeout /t 2 > nul");
        goto registerstart;
    }
}

static void LogIn() {

   LogInstart:

    ::logo.LogoBank();
    string Id1;
    string password;
    int id[11] = {};

    cout << "\n\n\tYOUR ID : ";
    cin >> Id1;

    if (Id1.length() != 11) {
        cout << "\n\n\tID MUST BE 11 DIGITS !!!";
        system("timeout /t 2 > nul");
        clearScreen();
        goto LogInstart;
    }

    for (int i = 0; i < 11; i++) {
        id[i] = Id1[i] - '0'; // '0' olayı onun chara dönmesini sağladı diğer türlü int oluyordu !!
    }

    cout << "\n\n\tYOUR PASSWORD : ";
    cin >> password;

    bool found = false;
    for (Users* u : allUsers) {
        bool idMatch = true;
        for (int i = 0; i < 11; i++) {
            if (id[i] != u->personalID[i]) {
                idMatch = false;
                break;
            }
        }

        if (idMatch && password == u->password) {
            currentUser = u;
            found = true;
            cout << "\n\n\t\t *** YOU ARE DIRECTED TO MAIN PAGE ***"; 
            system("timeout /t 2 > nul");
            MainPage();
            return;
        }
    }
    if (!found) {
        cout << "\n\n\t< WRONG PASSWORD OR ID, PLEASE TRY AGAIN >";
        system("timeout /t 2 > nul");
    }
    
    char detectback;

    do {
        cout << "\n\n\t< DO YOU WANT GO TO BACK ? ( n = no / y = yes ) > ";
        cin >> detectback;
        if (detectback == 'y') {
            system("timeout /t 2 > nul");
            clearScreen();
            RegisterQuestion();
        }
        else {
            break;
        }
    } while (0 > 1);

    system("timeout /t 2 > nul");
    clearScreen();

    goto LogInstart;

};

void ChangePassword() { //hata vaer şifre değişmiyor

    changeP:

    ::logo.LogoBank();

    string CurPas;
    
    cout << "\n\n\t| CURRENT PASSWORD | : ";
    cin >> CurPas;

            if (CurPas != currentUser->password) {
                cout << "\n\n\t< | CURRENT PASSWORD IS WRONG | >";
                system("timeout /t 2 > null");
                clearScreen();
                goto changeP;
            }
            else {

                system("timeout /t 2 > null");
                clearScreen();

                ::logo.LogoBank();

                string newPassword, controlNewPassword;
                cout << "\n\n\t| New Password | : ";
                cin >> newPassword;

                cout << "\n\n\t| Again New Password | : ";
                cin >> controlNewPassword;

                if (newPassword == controlNewPassword) {
                    currentUser->password = newPassword;
                    cout << "\n\n\t< YOUR PASSWORD WAS CHANGED > ";
                    system("timeout /t 2 > null");
                    clearScreen();
                    MainPage();
                }
                else {
                    cout << "\n\n\t !!! PASSWORDS NOT SAME WITH EACH OTHERS !!!";
                    system("timeout /t 2 > null");
                    clearScreen();
                    goto changeP;
                }
            }

}

void Account() {

    ::logo.LogoBank();

    int choice;

    if (currentUser == nullptr) {
        cout << "\n\n\t!!! NO USER LOGGED IN !!!";
        return;
    }

    cout << "\n\n\tIBAN : ";
    currentUser->ibanreturn();

    cout << "\n\t" << currentUser->username << " " << currentUser->usersurname;

    cout << "\n\t";
    for (int i = 0; i < 11; i++) {
        cout << currentUser->personalID[i];
    }

    //cout << "\n\n\t|      MONEY     | : " << moneycalculate();
    cout << "\n\t|      DEBTS     | : " << currentUser->Debts;
    cout << "\n\t| NET CASH MONEY | : " << currentUser->CurrentCashMoney();

    cout << "\n\n\t|1| - CHANGE PASSWORD     |";
    cout << "\n\t|2| - SHOW MY INVESTMENTS |";
    cout << "\n\t|3| - MAIN PAGE           |";
    cout << "\n\t|4| - EXIT                |";
    cout << "\n\t->";
    cin >> choice;

    switch (choice) {
    case 1:
        clearScreen();
        ChangePassword();
        break;
    case 2:
        clearScreen();
        cout << "\n\n\tYOUR INVESTMENTS...";
        InvestmentPage();
        break;
    case 3:
        clearScreen();
        cout << "\n\n\tYOU ARE DIRECTED MAIN PAGE ...";
        system("timeout /t 2 > nul");
        MainPage();
        break;
    case 4:
        cout << "\n\n\tThank you! Exiting...";
        system("timeout /t 2 > nul");
        exit(0);
        break;
    default:
        cout << "\n\n\tENTER A CHOICEABLE OPTION !";
        break;
    }
}

void SendPage() { 
                  

    ::logo.LogoBank();

    string ReceiverIBAN;
    int RecIB[18] = {};
    double AmountSendMoney = 0;
    double processCost = 0;
    int choose6 = 0;

sendpagestart:

    cout << "\n\n\t| Current Account | : " << currentUser->username << " " << currentUser->usersurname;
    cout << "\n\t| Available Money | : " << currentUser->CurrentCashMoney();

    cout << "\n\n\t 1 - ) Main Page "
        "\n\t 2 - ) Send Money"
        "\n\t> CHOOSE AN OPERATION : ";
    cin >> choose6;

    if (choose6 == 1) {
        clearScreen();
        MainPage();
    }
    else if (choose6 == 2) {
        cout << "\n\n\t > ENTER WITHOUT BLANK !!! \n\t| ENTER RECEIVER IBAN NO | : TR";
        cin >> ReceiverIBAN;
    }
    else {
        cerr << "\n\n\t > YOU ENTERED INVALID NUMBER - TRY AGAIN ... ";
        goto sendpagestart;
    }

    try {
        if (ReceiverIBAN.size() == 18) {
            for (int i = 0; i < 18; i++) {
                RecIB[i] = ReceiverIBAN[i] - '0';
            }
        }
        else {
            throw ReceiverIBAN.size();
        }

    }
    catch (size_t exception) {
        cout << "\n\n\t ( YOU ENTERED " << exception << " CHARACTERS, IBAN MUST BE 18 DIGITS [ Error Bx001 ] )";
        cout << "\n\n\t > TRY AGAIN ...";
        system("timeout /t 2 > nul");
        clearScreen();
        ::logo.LogoBank();
        goto sendpagestart;

    }
    catch (const string& exception) { //catch kısımlarını tekrar et
        cout << "\n\n\t ( IBAN CAN ONLY CONTAIN DIGITS [ Error Bx001a ] )";
        cout << "\n\n\t > TRY AGAIN ...";
        system("timeout /t 2 > nul");
        clearScreen();
        ::logo.LogoBank();
        goto sendpagestart;
    }

    bool idMatch = false;
    Users* targetUser = nullptr;

    for (Users* i : allUsers) {
        string targetIBAN = "";

        // iban dizisinin sayılarını stringe çevirir
        for (int k = 0; k < 18; k++) {
            targetIBAN += to_string(i->iban[k]);
        }

        if ( ReceiverIBAN.compare(targetIBAN) == 0) {
            idMatch = true;
            targetUser = i;
            break;
        }
     }
            
        char confirm2;

        if (idMatch == true) { //targetuser değişkeni tanımsızlığı çöz ve receiveriban kişisine para ekle
            cout << "\n\n\t| Receiver IBAN ( ";
            currentUser->ibanreturn(RecIB);
            cout << " ) |";

            cout << "\n\n\t( AVAILABLE FORMAT - xyz.ac ) \n\t| Enter amount of money | : ";
            cin >> AmountSendMoney;

            if (AmountSendMoney < 5000) {
                processCost = 5.4;
            }
            else {
                processCost = 16.2;
            }

            cout << "\n\n\t|--------------------------------------------------|";
            cout << "\n\t| Your IBAN : TR" << currentUser->iban << "                |";
            cout << "\n\t| Receiver IBAN : TR" << ReceiverIBAN << "             |";
            cout << "\n\t| Cost : " << processCost << "                                   |";
            cout << "\n\t| Sended Money : " << AmountSendMoney << "                  |";
            cout << "\n\t|--------------------------------------------------|";

            cout << "\n\n\t > DO YOU CONFIRM THIS OPERATION ?  ( y/n ) : ";
            cin >> confirm2;

            if (confirm2 == 'y') {
                if (AmountSendMoney + processCost > currentUser->Cash) {
                    cout << "\n\n\t !!! DON'T HAVE ENOUGH MONEY ( Error Bx002 ) !!!";
                }
                else {
                    currentUser->Cash -= (AmountSendMoney + processCost);
                    targetUser->Cash += AmountSendMoney;
                    system("timeout /t 2 > null");
                    clearScreen();
                    Account();
                }
            }

        }
        else {
            cout << "\n\n\t > THERE ISN'T ANY ACCOUNT THAT HAS THIS IBAN - PLEASE TRY AGAIN !!!";
            system("timeout /t 1 > null");
            clearScreen();
            ::logo.LogoBank();
            goto sendpagestart;
        }
    }


void MainPage() { 

    ::logo.LogoBank();

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //akıştaki girişleri sıfırla

    int choice;
    cout << "\n\n\tWELCOME TO EKICI BANK MAIN PAGE!";
    cout << "\n\n\t1 - CHANGE ACCOUNT / LOG OUT";
    cout << "\n\t2 - EXIT PROGRAM";
    cout << "\n\t3 - ACCOUNT INFORMATIONS";
    cout << "\n\t4 - SEND MONEY";
    cout << "\n\t5 - PAY BILL";
    cout << "\n\t6 - INVESTMENTS";
    cout << "\n\n\tYour choice: ";
    cin >> choice;
    char choice2;

    switch (choice) {
    case 1:
        cout << "\n\n\tWait...";
        system("timeout /t 1 > nul");
        clearScreen();
        system("timeout /t 1 > nul");
        cout << "\n\n\t< DO YOU WANT LOG IN OR CREAT NEW ACCOUNT ? : (L=log in / R=register) > ";
        cin >> choice2;
        if (choice2 == 'L') {
            LogIn();
        }
        else {
            Register();
        }
        break;
    case 2:
        cout << "\n\n\tThank you! Exiting...";
        system("timeout /t 2 > nul");
        exit(0);
        break;
    case 3:
        cout << "\n\n\tYou are directed to account page...";
        system("timeout /t 2 > nul");
        clearScreen();
        Account();
        break;
    case 4:
        cout << "\n\n\tSEND PAGE ...";
        system("timeout /t 2 > nul");
        clearScreen();
        SendPage();
        break;
    case 5:
        cout << "\n\n\tPAY PAGE ...";
        system("timeout /t 2 > nul");
        clearScreen();
        Bill();
        break;
    case 6:
        cout << "\n\n\tYou are directed to investment page...";
        system("timeout /t 2 > nul");
        clearScreen();
        InvestmentPage();
        break;
    default:
        cout << "\n\n\tInvalid choice! Returning...";
        system("timeout /t 2 > nul");
        clearScreen();
        MainPage();
        break;
    }
}

string static IDtranslater(string sPersonID) {

    sPersonID = "";
    for (int i = 0; i < 11; i++) {
        sPersonID += to_string(currentUser->personalID[i]);
    }
    return sPersonID;
}

void Bill() {

    ::logo.LogoBank();

    int choose5;

    billstarting:

    cout << "\n\n\t 1 -> ADD BILL "
        "\n\t 2 -> SHOW BILLS "
        "\n\t 3 -> PAY BILL "
        "\n\t 4 -> MAIN PAGE "
        "\n\t > CHOOSE AN OPERATION : ";
    cin >> choose5;

    string nameB, ID;
    double amountB = 0.0;
    int index = 0;
    auto& person_bill = all_Bills[IDtranslater(ID)];
    bool find = false;
    string namePayBill;

        switch (choose5) {
        case 1:

            cout << "\n\n\t > ENTER YOUR BILL'S NAME : ";
            cin >> nameB;

            cout << "\n\t > ENTER YOUR BILL'S AMOUNT : ";
            cin >> amountB;

            cout << "\n\n\t YOU ARE DIRECTED ADD BILL PAGE ...";
            system("timeout /t 3 > nul");
            clearScreen();
            addBill(all_Bills, IDtranslater(ID), nameB, amountB);
            goto billstarting;

        case 2:

            if (all_Bills.count(IDtranslater(ID))) {

                if (person_bill.size() > index) {

                    cout << "\n\n\t<- " << currentUser->username << " " << currentUser->usersurname << "'S BILLS ->";

                    for (int i = 0; i < person_bill.size(); i++) {
                        cout << "\n\n\t---------------------------------------------";
                        cout << "\n\t BILL'S NAME   : " << person_bill[i].billName;
                        cout << "\n\t BILL'S AMOUNT : " << person_bill[i].billAmount;
                    }
                    system("timeout /t 3 > nul");
                    clearScreen();
                    goto billstarting;
                    break;

                }
                else {
                    cerr << "\n\n\t\a YOU HAVEN'T ANY BILLS !!!";
                    system("timeout /t 3 > nul");
                    clearScreen();
                    goto billstarting;
                    break;
                }
            }
            else {
                cerr << "\n\n\t\a THERE ISN'T THIS ACCOUNT !!!";
                cout << "\n\t you should create a bill to access this page...";
                system("timeout /t 3 > nul");
                clearScreen();
                goto billstarting;
                break;
            }

        case 3:
            cout << "\n\n\t ENTER BILL NAME THAT WANT PAY : ";
            cin >> namePayBill;

            for (int i = 0; i < person_bill.size(); i++) {

                if(namePayBill == person_bill[i].billName) {
                    find = true;
                    char confirm2 = 'n';

                    cout << "\n\n\t > DO YOU CONFIRM THIS PROCESS ? ( y/n ) : ";
                    cin >> confirm2;

                    if (currentUser->Cash >= person_bill[i].billAmount) {
                        switch (confirm2) {
                        case 'y':
                            currentUser->Cash -= person_bill[i].billAmount;
                            person_bill.erase(person_bill.begin() + i);

                            cout << "\n\n\t # YOU PAID THIS BILL # ";
                            system("timeout /t 3 > nul");
                            clearScreen();
                            goto billstarting;
                        case 'n':
                            system("timeout /t 2 > nul");
                            clearScreen();
                            goto billstarting;
                        }
                    }
                    else {
                        cout << "\n\n\t > YOU HAVEN'T ENOUGH MONEY TO PAT THIS BILL !!!";
                        system("timeout /t 3 > nul");;
                        clearScreen();
                        goto billstarting;
                    }
                }
               
            }

            if (find == false) {
                cout << "\n\n\t > THERE ISN'T ANY BILL THAT HAS THIS NAME !!!";
                system("timeout /t 2 > nul");
                clearScreen();
                goto billstarting;
            }
            break;

        case 4:
            cout << "\n\n\tYou are directed to main page...";
            system("timeout /t 1 > nul");
            clearScreen();
            MainPage();
            break;

        default:
            cout << "\n\n\t YOU ENTERED INVALID NUMBER [ Error Bx008 ] ";
            system("timeout /t 3 > nul");
            clearScreen();
            goto billstarting;
            break;
        } 

}

void addBill(PersonBills& bills, const string& ID, const string& name, double amount) {

    // bills PersonBills mapine gönderirlir ve bu referans olarak yapılır ki kopyası değil direkt kendisi gönderilsin.
    // name ve ID da daha hızlı ( kopyalamadan ) ve değiştirilmeden ( güvenli ) olarak gönderilmesini sağlar.

    bills[ID].push_back({ name, amount });

    // bills olarak referans tutan PersonBills parametre nesnesinin person değişkenine push_back ile o name ve o amount'ta veriler yollanır.
    // bu veriler bill structuresi içinde olduğunu için PersonBills de aynı structure ait vector ifadesini içerdiğinden bunları alabilir.

    // eğer bu bill mapinde ID adında biri yoksa oluşturur ve vectorunu döndürür
    // bir ID anahtarı oluşturup bu anahtara vector<bill> atar
    // eğer bill mapinde bu ID varsa direkt nesnesini vector<bill> döndürür

    cout << "\n\n\t" << currentUser->username << " " << currentUser->usersurname << endl;
    cout << "\t BILL'S NAME   : " << name << endl;
    cout << "\t BILL'S AMOUNT : " << amount << endl;

}

static double totalValue() {
    return currentUser->Cash + (currentUser->goldhave * currentUser->GoldSell) + (currentUser->eurohave * currentUser->EuroSell) + (currentUser->dolarhave * currentUser->DolarSell);
}

void InvestmentPage() {

    ::logo.LogoBank();
    int choose3 = 0;

    investmentpagestart:

    cout << "\n\n\t\t | YOUR INVESTMENTS | ";
    cout << "\n\t-----------------------------------";
    cout << "\n\n\t";
    currentUser->LIRA();
    cout << "\n\n\t Current Dolar Rate ( Buy - Sell ) : " << (currentUser->DolarSell + 1.8) << " - " << currentUser->DolarSell;
    cout << "\n\t";
    currentUser->DOLAR();
    cout << "\n\n\t Current EURO Rate ( Buy - Sell ) : " << (currentUser->EuroSell + 2.1) << " - " << currentUser->EuroSell;
    cout << "\n\t";
    currentUser->EURO();
    cout << "\n\n\t Current GOLD Rate ( Buy - Sell ) : " << (currentUser->GoldSell + 200) << " - " << currentUser->GoldSell;
    cout << "\n\t";
    currentUser->GOLD();

    cout << "\n\n\t\t | CASH AND DEBTS | ";
    cout << "\n\t-----------------------------------";
    cout << "\n\t Cash : " << currentUser->Cash;
    cout << "\n\t Debts : " << currentUser->Debts;
    cout << "\n\t Available Cash : " << currentUser->CurrentCashMoney();
    cout << "\n*t TOTAL VALUE : " << totalValue();

    cout << "\n\n\t 1 - ) SELL GOLD "
        "\n\t 2 - ) BUY GOLD "
        "\n\t 3 - ) SELL DOLAR "
        "\n\t 4 - ) BUY DOLAR "
        "\n\t 5 - ) SELL EURO "
        "\n\t 6 - ) BUY EURO "
        "\n\t 7 - ) WITHDRAW CASH "
        "\n\t 8 - ) DEPOSIT MONEY ";
        "\n\t 9 - ) MAIN PAGE ";
    cout << "\n\t > CHOOISE OPERATION : ";
    double amountInv = 0;

    try {
        cin >> choose3;

        if (choose3 <= 8) {
            switch (choose3) {
            case 1:
                cout << "\n\n\t | AMOUNT OF SELLING GOLD | : ";
                cin >> amountInv;
                sellGold(amountInv);
                break;
            case 2:
                cout << "\n\n\t | AMOUNT OF BUYING GOLD | : ";
                cin >> amountInv;
                buyGold(amountInv);
                break;
            case 3:
                cout << "\n\n\t | AMOUNT OF SELLING DOLAR | : ";
                cin >> amountInv;
                sellDolar(amountInv);
                break;
            case 4:
                cout << "\n\n\t | AMOUNT OF BUYING DOLAR | : ";
                cin >> amountInv;
                buyDolar(amountInv);
                break;
            case 5:
                cout << "\n\n\t | AMOUNT OF SELLING EURO | : ";
                cin >> amountInv;
                sellEuro(amountInv);
                break;
            case 6:
                cout << "\n\n\t | AMOUNT OF BUYING EURO | : ";
                cin >> amountInv;
                buyEuro(amountInv);
                break;
            case 7:
                cout << "\n\n\t | AMOUNT OF WITHDRAWING CASH | : ";
                cin >> amountInv; 
                withdrawCash(amountInv);
                break;
            case 8:
                cout << "\n\n\t | AMOUNT OF DEPOSITING CASH | : ";
                cin >> amountInv;
                depositCash(amountInv);
                break;
            case 9:
                MainPage();
                break;
            }

        }
        else {
            throw choose3;
        }
    }
    catch (int& e) { 
        //bazen sadece exceptionu göndermek throwun kopyasını oluşturur bu da performans kaybına neden olur o yüzden referans ile dirkt throwun değerini çekeriz.
        cout << "\n\n\t !!! YOU ENTERED WRONG NUMBER TRY AGAIN ( Error Bx004 ) !!!";
        system("timeout /t 2 > nul");
        clearScreen();
        goto investmentpagestart;
    }

}