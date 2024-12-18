#include <iostream>

using namespace std;

class publication {
public:
    float price;
    string name;
    
    publication() {
        name = "none";
        price = 0.0;
    }

    void getdata(string s) {
        cout << "\nEnter the name of the " << s << ": ";
        cin >> name;
        bool flag = false;
        while (flag == false) {
            cout << "\nEnter the price of the " << s << ": ";
            cin >> price;
            
            try {
                if (price <= 0)
                    throw price;
                else
                    flag = true;
            }
            catch (float x) {
                price = 0.0;
                cout << "\nYou have entered an invalid price.";
                cout << "\nThe price has been set to " << price;
                cout << "\nPlease enter a valid price.";
            }
        }
    }

    inline string getname() {
        return name;
    }
    
    inline float getprice() {
        return price;   
    }
};

class book : public publication {
public:
    int pages;
    
    book() {
        pages = 0;
    }

    void getpages() {
        bool flag = false;
        while (flag == false) {
            cout << "\nEnter the number of pages: ";
            cin >> pages;

            try {
                if (pages <= 0)
                    throw pages;
                else
                    flag = true;
            }
            catch (int x) {
                pages = 0;
                cout << "\nYou have entered an invalid number of pages.";
                cout << "\nThe number of pages has been set to " << pages;
                cout << "\nPlease enter a valid number of pages.";
            }
        }
    }

    void display() { 
        cout << "\nBook Found";
        cout << "\nDetails: ";
        cout << "\nName of the Book: " << getname();
        cout << "\nNumber of pages: " << pages;
        cout << "\nThe price is: " << getprice() << endl;
    }
};

class tape : public publication {
public:
    float time;
    
    tape() {
        time = 0.0;
    }

    void gettime() {
        bool flag = false;
        while (flag == false) {
            cout << "\nEnter the playing time of tape in minutes: ";
            cin >> time;

            try {
                if (time <= 0)
                    throw time;
                else
                    flag = true;
            }
            catch (float x) {
                time = 0.0;
                cout << "\nInvalid value.";
                cout << "\nThe time has been set to " << time;
                cout << "\nPlease enter a valid time.";
            }
        }
    }

    void display() { 
        cout << "\nAudio Cassette Found";
        cout << "\nDetails: ";
        cout << "\nName of the Tape: " << getname();
        cout << "\nPlaying time: " << time << " minutes";
        cout << "\nThe price is: " << getprice() << endl;
    }
};

int main() {
    int choice;
    string n;
    book objb;
    tape objt;

    do {
        cout << "\n1. Insert a book";
        cout << "\n2. Insert an audio cassette";
        cout << "\n3. Display Book Details";
        cout << "\n4. Display audio cassette details";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {    
            case 1:  
                objb.getdata("book");
                objb.getpages();
                cout << "\nRecord inserted!" << endl;
                break;
                
            case 2: 
                objt.getdata("audio cassette"); 
                objt.gettime();
                cout << "\nRecord inserted!" << endl;
                break;
                
            case 3: 
                try {   
                    if (objb.getname() == "none")
                        throw 3;
                    else {
                        objb.display();
                    }
                }
                catch (int x) {
                    cout << "\nNo book has been added yet.";
                    cout << "\nPlease choose the correct option to add a book." << endl;
                }
                break;
                
            case 4: 
                try {   
                    if (objt.getname() == "none")
                        throw 3;
                    else {
                        objt.display();
                    }
                }
                catch (int x) {
                    cout << "\nNo audio cassette has been added yet.";
                    cout << "\nPlease choose the correct option to add an audio cassette." << endl;
                }
                break;
                
            case 5: 
                cout << "\n..........VISIT AGAIN..........";
                break;
        }

    } while (choice != 5);

    cout << "\nEnd of the program.";
    cout << "\nThank you!" << endl;

    return 0;
}
