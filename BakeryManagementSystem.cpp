#include <iostream>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int loginOption;

class Customer;

void view_menu();
void login();
void welcome_int();
void user_options();
void place_order();
void cancel_order();
void billing(Customer customer);
void remove_order();
void view_orders();
void provideFeedback();

class date_time
{
private:
    int hour;
    int minute;
    int seconds;
    int date;
    int month;
    int year;

public:
    void set_hour(int h)
    {
        hour = h;
    }

    void set_min(int m)
    {
        minute = m;
    }

    void set_sec(int s)
    {
        seconds = s;
    }

    void set_date(int d)
    {
        date = d;
    }

    void set_month(int mo)
    {
        month = mo;
    }

    void set_year(int y)
    {
        year = y;
    }

    int get_hour()
    {
        return hour;
    }

    int get_min()
    {
        return minute;
    }

    int get_sec()
    {
        return seconds;
    }

    int get_date()
    {
        return date;
    }

    int get_month()
    {
        return month + 1;
    }

    int get_year()
    {
        return year - 100;
    }
};
void save_feedback(const string &feedback)
{
    ofstream outFile("feedback.txt", ios::app);
    if (!outFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    outFile << feedback << endl;
    outFile.close();
}

void view_feedback()
{
    ifstream inFile("feedback.txt");
    if (!inFile)
    {
        cout << "No feedback available yet." << endl;
        return;
    }

    string feedback;
    cout << "--------------------------------------" << endl;
    cout << "       Feedback from Customers" << endl;
    cout << "--------------------------------------" << endl;
    while (getline(inFile, feedback))
    {
        cout << feedback << endl;
    }
    inFile.close();
}

class bakery
{
    date_time now;

public:
    void setTime()
    {
        time_t currentTime = time(nullptr);
        tm *localTime = localtime(&currentTime);
        int hour = localTime->tm_hour;
        int minute = localTime->tm_min;
        int seconds = localTime->tm_sec;
        int date = localTime->tm_mday;
        int month = localTime->tm_mon;
        int year = localTime->tm_year;
        now.set_hour(hour);
        now.set_min(minute);
        now.set_sec(seconds);
        now.set_date(date);
        now.set_month(month);
        now.set_year(year);
    }

    void getTime()
    {
        cout << endl
             << endl
             << endl
             << setw(114) << now.get_hour() << " : " << now.get_min() << " : " << now.get_sec() << endl;
        cout << setw(115) << now.get_date() << " - " << now.get_month() << " - " << now.get_year();
    }
};

void login_interface()
{
    cout << "\e[1;35m                                                                                      +====================================+\e[m" << endl;
    cout << "\e[1;35m                                                                                      |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                                      |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                                      |\e[m              \e[1mLOGIN AS\e[m              \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                                      |\e[m              1) Admin              \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                                      |\e[m              2) User               \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                                      |\e[m              3) Exit               \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                                      |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                                      |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                                      +====================================+\e[m" << endl;

    login();
}

void admin_interface()
{
    system("cls");

    int admin_option;
    cout << "\e[1;35m                                                                              +====================================+\e[m" << endl;
    cout << "\e[1;35m                                                                              |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                              |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                              |\e[m            \e[1mADMIN OPTION\e[m            \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                              |\e[m         1)Show Order Queue         \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                              |\e[m         2)Remove Order From Queue  \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                              |\e[m         3)View Customer Feedback   \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                              |\e[m         4)Log out                  \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                              |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                              |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                              +====================================+\e[m" << endl
         << endl
         << endl;
    cout << "Option : ";
    cin >> admin_option;
    system("cls");

    switch (admin_option)
    {
    case 1:
    {
        view_orders();
        cout << endl
             << endl
             << endl
             << "\e[1mPRESS ANY KEY FOR ADMIN OPTIONS...\e[m";
        getch();
        system("cls");
        admin_interface();
        break;
    }
    case 2:
    {
        remove_order();
        cout << endl
             << endl
             << endl
             << "\e[1mPRESS ANY KEY FOR ADMIN OPTIONS...\e[m";
        getch();
        system("cls");
        admin_interface();
        break;
    }
    case 3:
    {
        view_feedback();
        cout << endl
             << endl
             << endl
             << "\e[1mPRESS ANY KEY FOR ADMIN OPTIONS...\e[m";
        getch();
        system("cls");
        admin_interface();
        break;
    }
    case 4:
    {
        login_interface();
        break;
    }
    default:
    {
        cout << "\e[1;31mInvalid inpute\e[m";
        getch();
        system("cls");
        admin_interface();
        break;
    }
    }
}

void login()
{
    cout << "\n\nOption : ";
    cin >> loginOption;
    system("cls");
    string username, password;

    switch (loginOption)
    {
    case 1:
        cout << "\e[1m                                                                                               --LOGIN--\e[m" << endl;
        cout << "\e[33m                                                                                              Username: \e[m";
        cin >> username;
        cout << "\e[33m                                                                                              Password: \e[m";
        cin >> password;
        if ((username == "admin123") && (password == "bakery123"))
        {
            admin_interface();
        }
        else
        {
            cout << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << "                                                                                             \e[1;31mWRONG CREDENTIALS!\e[m\n"
                 << endl;
            _getch();
            system("cls");
            login_interface();
        }
        break;
    case 2:
        user_options();
        break;
    case 3:
        welcome_int();
        break;
    default:
    {
        cout << "\e[1;31mInvalid input\e[m";
        getch();
        system("cls");
        login_interface();
        break;
    }
    }
}
class Customer
{
private:
    static int nextCustomerId;

public:
    int customerId;

    string name;
    string address;
    string phone;
    string feedback;

    int item;
    int quantity;
    int totalCost;

    Customer()
    {
        customerId = nextCustomerId++;
        totalCost = 0;
    }

    void inputDetails()

    {
        cout << "\nName: ";
        cin.ignore();
        getline(cin, name);

        cout << "Address: ";
        getline(cin, address);

        cout << "Phone number: ";
        getline(cin, phone);
    }

    void purchase()

    {
        cout << "Choose an item from the menu (by number): ";
        cin >> item;

        cout << "Enter quantity: ";
        cin >> quantity;
    }

    void provideFeedback()
    {
        cout << "Please provide your feedback:\n";
        cin.ignore();
        getline(cin, feedback);
        save_feedback(feedback);
    }

    string return_item()
    {

        switch (item)
        {
        case 1:
            return "Glazed Donut";
        case 2:
            return "Chocolate Frosted Donut";
        case 3:
            return "Jelly-filled Donut";
        case 4:
            return "Cinnamon Sugar Donut";
        case 5:
            return "Vanilla Cream Donut";
        case 6:
            return "Strawberry Cake";
        case 7:
            return "Chocolate Truffle Cake";
        case 8:
            return "Red Velvet Cake";
        case 9:
            return "Fruit Cake";
        case 10:
            return "Pineapple Cake";
        case 11:
            return "Butter Scotch Cake";
        case 12:
            return "Vanilla Cupcake";
        case 13:
            return "Chocolate Cupcake";
        case 14:
            return "Cherry Cupcake";
        case 15:
            return "Blueberry Cupcake";
        case 16:
            return "Strawberry Cupcake";
        case 17:
            return "Chocolate Chip Cookie";
        case 18:
            return "Oatmeal Raisin Cookie";
        case 19:
            return "Sugar Cookie";
        case 20:
            return "Peanut Butter Cookie";
        default:
            return "\e[1;31mInvalid Choice\e[m";
        }
    }

    void displayDetails()
    {
        cout << "\nCustomer ID: " << customerId << endl;
        cout << "\nCustomer Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone number: " << phone << endl;
        cout << "Item: " << item << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total amount: " << totalCost << endl;
    }
};

int Customer::nextCustomerId = 1000;

void billing(Customer customer)
{
    bakery bill;
    bill.setTime();
    cout << "                                                    x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n";
    cout << "                                                                                      BILL                       ";
    bill.getTime();
    cout << "\n                                                        Name: " << customer.name << endl
         << "                                                        Customer ID: " << customer.customerId;
    cout << "\n\n\n                                                                       ITEM                          QUANTITY\n";
    cout << "                                                                " << customer.return_item() << "                   " << customer.quantity << "\n\n\n\n\n";
    cout << "                                                    x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n";
}

void place_order()
{
    ofstream outFile("orders.txt", ios::app);
    if (!outFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    view_menu();

    Customer customer;
    customer.inputDetails();
    outFile << "Customer ID : " << customer.customerId << "\nName : " << customer.name << "\nAddress : " << customer.address << "\nPhone Number : " << customer.phone;
    customer.purchase();
    outFile << "\nItem : " << customer.return_item();
    outFile << "\nQuantity : " << customer.quantity;

    switch (customer.item)
    {
    case 1:
        customer.totalCost += 90 * customer.quantity;
        break;
    case 2:
        customer.totalCost += 100 * customer.quantity;
        break;
    case 3:
        customer.totalCost += 120 * customer.quantity;
        break;
    case 4:
        customer.totalCost += 90 * customer.quantity;
        break;
    case 5:
        customer.totalCost += 100 * customer.quantity;
        break;
    case 6:
        customer.totalCost += 500 * customer.quantity;
        break;
    case 7:
        customer.totalCost += 600 * customer.quantity;
        break;
    case 8:
        customer.totalCost += 500 * customer.quantity;
        break;
    case 9:
        customer.totalCost += 900 * customer.quantity;
        break;
    case 10:
        customer.totalCost += 400 * customer.quantity;
        break;
    case 11:
        customer.totalCost += 800 * customer.quantity;
        break;
    case 12:
        customer.totalCost += 110 * customer.quantity;
        break;
    case 13:
        customer.totalCost += 120 * customer.quantity;
        break;
    case 14:
        customer.totalCost += 120 * customer.quantity;
        break;
    case 15:
        customer.totalCost += 120 * customer.quantity;
        break;
    case 16:
        customer.totalCost += 120 * customer.quantity;
        break;
    case 17:
        customer.totalCost += 30 * customer.quantity;
        break;
    case 18:
        customer.totalCost += 40 * customer.quantity;
        break;
    case 19:
        customer.totalCost += 25 * customer.quantity;
        break;
    case 20:
        customer.totalCost += 35 * customer.quantity;
        break;
    }

    outFile << "\nTotal Amount : " << customer.totalCost << endl;
    outFile.close();

    cout << "\nOrder placed successfully!" << endl;
    cout << "Your customer ID is " << customer.customerId;

    cout << "\e[1m\n\nPRESS ANY KEY FOR THE BILL...\e[m";
    getch();
    system("cls");

    billing(customer);
    cout << "\e[1m\n\nPRESS ANY KEY FOR USER OPTIONS...\e[m";
    getch();
    system("cls");
    user_options();
}

void cancel_order()
{
    int customerId;
    cout << "Enter your Customer ID to cancel the order : ";
    cin >> customerId;

    ifstream inFile("orders.txt");
    if (!inFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    vector<string> lines;
    string line;

    bool found = false;

    while (getline(inFile, line))
    {
        if (line.find("Customer ID : " + to_string(customerId)) != string::npos)
        {
            found = true;
            for (int i = 0; i < 6; ++i)
            {
                if (!getline(inFile, line))
                    break;
            }
            cout << "Order for Customer ID " << customerId << " has been canceled." << endl;
        }
        else
        {
            lines.push_back(line);
        }
    }
    inFile.close();

    if (!found)
    {
        cout << "\e[1;31mNo order found for Customer ID " << customerId << ".\e[m" << endl;
         
        return;
    }

    ofstream outFile("orders.txt");
    if (!outFile)
    {
        cout << "\e[1;31mError opening file!\e[m" << endl;
        return;
    }

    for (const auto &line : lines)
    {
        outFile << line << endl;
    }
    outFile.close();
}

void offer_deals()
{
    cout << "                                                                    \e[1;33mWe have some special deals for you:\e[m";
    cout << endl
         << endl;
    cout << "                                                                    1. Buy 6 donuts and get 1 free!\n";
    cout << "                                                                    2. Family Pack: Buy any 2 cakes and get 1 pastry free!\n";
    cout << "                                                                    3. Weekend Special: 10% of on all orders above Rs. 1000 on Saturdays and Sundays!\n";
    cout << "                                                                    4. Cookie Combo: Buy 5 cookies and get 1 free!\n";
    cout << "                                                                    5. Buy 4 cupcakes and get 1 croissant free!\n";
}

void user_options()
{
    int cust_option;
    cout << "\e[1;35m                                                                                      +====================================+\e[m" << endl;
    cout << "\e[1;35m                                                                                      |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                                      |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                                      |\e[m             \e[1mUSER OPTION\e[m            \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                                      |\e[m              1)View Menu           \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                                      |\e[m              2)View Deals          \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                                      |\e[m              3)Place Order         \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                                      |\e[m              4)Cancel Order        \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                                      |\e[m              5)Feedback            \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                                      |\e[m              6)Exit                \e[1;35m|\e[m" << endl;
    cout << "\e[1;35m                                                                                      |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                                      |                                    |\e[m" << endl;
    cout << "\e[1;35m                                                                                      +====================================+\e[m" << endl;
    
    cout << "\n\nOption : ";
    cin >> cust_option;
    system("cls");

    switch (cust_option)
    {
    case 1:
        view_menu();
        cout << endl
             << endl
             << endl
             << "\e[1mPRESS ANY KEY FOR USER OPTIONS...\e[m";
        getch();
        system("cls");
        user_options();
        break;
    case 2:
        offer_deals();
        cout << endl
             << endl
             << endl
             << "\e[1mPRESS ANY KEY FOR USER OPTIONS...\e[m";
        getch();
        system("cls");
        user_options();
        break;
    case 3:
        place_order();
        break;
    case 4:
        cancel_order();
        cout << endl
             << endl
             << endl
             << "\e[1mPRESS ANY KEY FOR USER OPTIONS...\e[m";
        getch();
        system("cls");
        user_options();
        break;
    case 5:
    {
        Customer cust;
        cust.provideFeedback();
        cout << endl
             << endl
             << endl
             << "\e[1mPRESS ANY KEY TO CONTINUE...\e[m";
        getch();
        system("cls");
        cout << "\e[1m                                                                          Thank you for the review!\e[m";
        cout << endl
             << endl
             << endl
             << "\e[1mPRESS ANY KEY FOR USER OPTIONS...\e[m";
        getch();
        system("cls");
        user_options();
        break;
    }
    case 6:
        login_interface();
        break;
    default:
        cout << "\e[1;31mInvalid Choice\e[m";
        cout << endl
             << endl
             << endl
             << "\e[1mPRESS ANY KEY FOR USER OPTIONS...\e[m";
        getch();
        system("cls");
        user_options();
    }
}

void view_menu()
{
    cout << "                                                                                                      \e[1;36;4m~MENU~\e[m" << endl;
    cout << "\e[1;33m                                                                                      +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m          \e[1mDONUTS\e[m (1 Piece)          \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m    1- Glazed - 90 Rs.              \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m    2- Chocolate Frosted - 100 Rs.  \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m    3- Jelly-filled - 120 Rs.       \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m    4- Cinnamon sugar - 90 Rs.      \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m    5- Vanilla cream - 100 Rs.      \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |====================================|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m           \e[1mCAKES\e[m (1 kg)             \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m    6- Strawberry - 500 Rs.         \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m    7- Chocolate Truffle - 600 Rs.  \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m    8- Red Velvet - 500 Rs.         \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m    9- Fruit - 900 Rs.              \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m   10- Pineapple - 400 Rs.          \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m   11- Butter Scotch - 800 Rs.      \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |====================================|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m         \e[1mCUPCAKES\e[m (1 Piece)         \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m   12- Vanilla - 110 Rs.            \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m   13- Chocolate - 120 Rs.          \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m   14- Cherry - 120 Rs.             \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m   15- Blueberry - 120 Rs.          \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m   16- Strawberry - 120 Rs.         \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |====================================|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m          \e[1mCOOKIES\e[m (1 Piece)         \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m   17- Chocolate Chip - 30 Rs.      \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m   18- Oatmeal Raisin - 40 Rs.      \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m   19- Sugar - 25 Rs.               \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      |\e[m   20- Peanut Butter - 35 Rs.       \e[1;33m|\e[m" << endl;
    cout << "\e[1;33m                                                                                      +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\e[m" << endl;
}

void view_orders()
{
    ifstream inFile("orders.txt");
    if (!inFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    int lineCount = 0;

    cout << "\e[1;34m--------------------------------------\e[m" << endl;
    cout << "       Orders in the System" << endl;
    cout << "\e[1;34m--------------------------------------\e[m" << endl;

    while (getline(inFile, line))
    {
        if (lineCount % 7 == 0 && lineCount != 0)
            cout << "\e[1;34m--------------------------------------\e[m" << endl;
        cout << line << endl;
        lineCount++;
    }

    inFile.close();
}

void remove_order()
{
    ifstream inFile("orders.txt");
    if (!inFile)
    {
        cout << "\e[1;31mError opening file!\e[m" << endl;
        return;
    }

    vector<string> lines;
    string line;
    bool removed = false;
    for (int i = 0; i < 7; ++i)
    {
        if (!getline(inFile, line))
        {
            cout << "\e[1;31mNo orders in the file.\e[m" << endl;
            inFile.close();
            return;
        }
    }

    while (getline(inFile, line))
    {
        lines.push_back(line);
    }
    inFile.close();

    ofstream outFile("orders.txt");
    if (!outFile)
    {
        cout << "\e[1;31mError opening file!\e[m" << endl;
        return;
    }

    for (const auto &line : lines)
    {
        outFile << line << endl;
    }
    outFile.close();

    cout << "\e[1mFirst order from the queue has been removed\e[m" << endl
         << endl;
}

void welcome_int()
{
    cout << "\n\n\n\e[1;31m+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\e[m\n";
    cout << "\e[1;31m|"
         << "\e[m"
         << "                                                                                                                                                                                         "
         << "\e[1;31m|"
         << "\e[m\n";
    cout << "\e[1;31m|"
         << "\e[m"
         << "                                                                                                                                                                                         "
         << "\e[1;31m|"
         << "\e[m\n";
    cout << "\e[1;31m|"
         << "\e[m"
         << "                                                                                                                                                                                         "
         << "\e[1;31m|"
         << "\e[m\n";
    cout << "\e[1;31m|"
         << "\e[m"
         << "                                                                                                                                                                                         "
         << "\e[1;31m|"
         << "\e[m\n";
    cout << "\e[1;31m|"
         << "\e[m"
         << "\e[1;33m                                                                                        WELCOME TO   \e[m                                                                                    "
         << "\e[1;31m|"
         << "\e[m\n";
    cout << "\e[1;31m|"
         << "\e[m"
         << "\e[1;33m                                                                                          BAKESHOP  \e[m                                                                                     "
         << "\e[1;31m|"
         << "\e[m\n";
    cout << "\e[1;31m|"
         << "\e[m"
         << "                                                                                                                                                                                         "
         << "\e[1;31m|"
         << "\e[m\n";
    cout << "\e[1;31m|"
         << "\e[m"
         << "                                                                                                                                                                                         "
         << "\e[1;31m|"
         << "\e[m\n";
    cout << "\e[1;31m|"
         << "\e[m"
         << "                                                                                                                                                                                         "
         << "\e[1;31m|"
         << "\e[m\n";
    cout << "\e[1;31m|"
         << "\e[m"
         << "                                                                                                                                                                                         "
         << "\e[1;31m|"
         << "\e[m\n";
    cout << "\e[1;31m+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\e[m";
    cout << endl
         << endl
         << endl
         << endl
         << "\e[1mPRESS ANY KEY TO CONTINUE...\e[m";
    getch();
    system("cls");
    login_interface();
}

int main()
{
    welcome_int();
    return 0;
}
