#include <iostream>
#include <string>
using namespace std;

struct Member {
    string name;
    string status;
    int YearIN;
    double Salry;
};

const int MAX_Member = 100;
Member MemberList[MAX_Member];
int MemberTotal = 0;

void add() {
    if (MemberTotal >= MAX_Member) {
        cout << "Family Member was fuel!\n\n";
        return;
    }
    Member &p = MemberList[MemberTotal];
    cout << "name: "; getline(cin, p.name);
    cout << "Status (Inner / Guard / Chief): "; getline(cin, p.status);
    cout << "Year In: "; cin >> p.YearIN;
    cout << "Salary: "; cin >> p.Salry;
    cin.ignore();
    MemberTotal++;
    cout << "Member Successfully added!\n\n";
}

void show() {
    if (MemberTotal == 0) {
        cout << "Member Data is empty!\n\n";
        return;
    }
    for (int i = 0; i < MemberTotal; i++) {
        cout << i+1 << ". " << MemberList[i].name << ", " << MemberList[i].status
             << ", " << MemberList[i].YearIN << ", " << MemberList[i].Salry << "\n";
    }
    cout << "\n";
}

void edit() {
    if (MemberTotal == 0) {
        cout << "Empty Data, can't edit\n\n";
        return;
    }
    show();
    cout << "Choose Member Number to edit: ";
    int idx; cin >> idx; cin.ignore();
    if (idx < 1 || idx > MemberTotal) {
        cout << "Number not Valid!\n\n";
        return;
    }
    Member &p = MemberList[idx - 1];
    cout << "New Name: "; getline(cin, p.name);
    cout << "New Status: "; getline(cin, p.status);
    cout << "New Year In: "; cin >> p.YearIN;
    cout << "New Salary: "; cin >> p.Salry;
    cin.ignore();
    cout << "Member Data Updated!\n\n";
}

void erase() {
    if (MemberTotal == 0) {
        cout << "Data erased, can't remove!\n\n";
        return;
    }
    show();
    cout << "Choose member Number to remove: ";
    int idx; cin >> idx; cin.ignore();
    if (idx < 1 || idx > MemberTotal) {
        cout << "Number not Valid\n\n";
        return;
    }
   
    for (int i = idx - 1; i < MemberTotal - 1; i++) {
        MemberList[i] = MemberList[i+1];
    }
    MemberTotal--;
    cout << "Member Removed!\n\n";
}

int main() {
int Choose;
do {
    cout << "--- WELCOME TO TONG FAMILY INFORMATION SYSTEM ---\n";
    cout << "1. Add Member\n";
    cout << "2. Edit Member\n";
    cout << "3. Show Member\n";
    cout << "4. Remove Member\n";
    cout << "5. Out\n";
    cout << "Choose menu: ";
    cin >> Choose; cin.ignore();

    switch(Choose) {
        case 1: add(); break;
        case 2: edit(); break;
        case 3: show(); break;
        case 4: erase(); break;
        case 5: cout << "Thank You for Using ur System!\n"; return 0;
        default: cout << "Invalid choice, try again!\n\n";
    }
} while (true);
}