#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//aplikasi penyimpanan data rawat inap rumah sakit

struct node //node data pasien untuk antrean
{
    string name;
    string ID;
    string critical;
    node* next;
    node* prev;
};

//deklarasi-deklarasi global - Linked List
node* HeadNormal;
node* TailNormal;
node* HeadCrit;
node* TailCrit;

char crit;
char input;
string entri;

//deklarasi-deklarasi global - Hashing
const char apahash[] = "!@#$%^&*()_+-=";
const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char uppercases[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int size = sizeof(apahash);
int sizelow = sizeof (lowercase);
int sizehigh = sizeof (uppercases);

struct hashnode
{
    string Hashtable;
    string TrueHash;
    hashnode* next;
    hashnode* prev;
};

hashnode* HashHead;
hashnode* HashTail;
int hashhash = 0; // hashlist

////////////////////////////////////////
bool check(string entry)
{
    hashnode* go = HashHead;
    while (go != NULL)
    {
        if (entry == go->TrueHash)
        {
            return true;        
        }
        else
        {
            go = go->next;
        }
    }
    return false;
}
string Hashing(string entry)
{
    if (check(entry) == false)
    {
        string NewEntry = entry;
        string notjoji = "";
        int bai = sizeof(NewEntry.size());
        acak :
            for (int j = 0; j < bai; j++)
            {
                notjoji = notjoji + apahash[rand()% :: size];
            }
            for (int k = 0; k<3; k++)
            {
                notjoji = notjoji + lowercase[rand()% :: sizelow];
            }
    cout << "Ping" << endl;

            for (hashnode* cek = HashHead; cek != NULL; cek = cek -> next)
                {
                    if(cek -> Hashtable == notjoji)
                    {
                        goto acak;
                    }
                }
cout << "Ping" << endl;
            hashnode *temp = new hashnode;
                temp -> TrueHash = entry;
                temp -> Hashtable = notjoji;
                hashhash = hashhash + 1;
                if (HashHead == NULL)
                {
                    temp ->next = NULL;
                    temp -> prev = NULL;
                    HashHead = temp;    
                    HashTail = HashHead;
                }
                else
                {
                    temp -> next = NULL;
                    HashTail ->next = temp;
                    temp ->prev = HashTail;
                    HashTail = temp;
                }
        //Alexander
        //$*!@sjader
        //Jimmi Fernandes Rahman
        //^&*#sdfman
        return notjoji;
    }
    else if (check(entry) == true)
    {
        hashnode* search = HashHead;
        while (search != NULL)
        {
            if (entry == search->TrueHash)
            {
                return search->Hashtable;
            }
            else
            {
                search=search->next;
            }
        }
    }
}

void DisplayHash() //display antrean
{
    hashnode* temp;
    temp = HashHead;
    int urut = 1;
    while (temp != NULL)
    {
        cout <<urut <<". " << temp->TrueHash << " -> "<< temp->Hashtable<<endl;
        temp = temp->next;
        urut = urut +1;
    }
}
void Display() //display antrean
{
    node* tempNormal;
    node* tempCrit;
    tempNormal = HeadNormal;
    tempCrit = HeadCrit;
    int urut = 1;
    while (tempCrit != NULL)
    {
        cout << urut <<". " << tempCrit -> ID << " - "<<tempCrit -> name<< " - " << tempCrit->critical<<endl;
        tempCrit = tempCrit ->next;
        urut = urut +1;
    }
    while (tempNormal != NULL)
    {
        cout << urut <<". " << tempNormal -> ID << " - "<<tempNormal -> name<< " - " << tempNormal->critical<<endl;
        tempNormal = tempNormal ->next;
        urut = urut +1;
    }
}

void InsertNormalPatient(string entry, char crit) // masukkan antrean baru untuk pasien yang tidak kritis
//pasien yang tidak kritis akan mengantri dari belakang
{
    node* temp = new node;
    temp -> name = entry;
    temp->ID = Hashing(entry);
    if (crit == '2')
    {
        temp -> critical = "Rawat Inap";
    }
    else if (crit =='1')
    {
        temp -> critical = "Rawat Jalan";
    }

    if (HeadNormal == NULL)
    {
        temp -> next = NULL;
        temp -> prev = NULL;
        HeadNormal = temp;
        TailNormal = HeadNormal;
    }

    else
    {
        TailNormal -> next = temp;
        temp -> next = NULL;
        temp -> prev = TailNormal;
        TailNormal = temp;
    }
}

void InsertEmergencyPatient(string entry, char crit)
{
    node* temp = new node;
    temp -> name = entry;
    temp -> ID = Hashing(entry);
    if (crit == '1')
    {
        temp -> critical = "Mengkhawatirkan";
    }
    else if (crit == '2')
    {
        temp -> critical = "Gawat Darurat";
    }
    else if (crit == '3')
    {
        temp -> critical = "Kronis";
    }

    if (HeadCrit == NULL)
    {
        temp -> next = NULL;
        temp -> prev = NULL;
        HeadCrit = temp;
        TailCrit = HeadCrit;
    }

    else
    {
        HeadCrit -> prev = temp;
        temp -> next = HeadCrit;
        temp -> prev = NULL;
        HeadCrit = temp;
    }
}

void mainMenu();

void daftarPasienNormal(){
    cout << "Masukkan nama pasien yang ingin didaftarkan untuk dirujuk: "; 
    cin.ignore(); getline(cin, entri);
    cout << "Level Kekritisan: " << endl;
    cout << "1. Rawat Jalan" << endl;
    cout << "2. Rawat Inap" << endl;
    cout << "================================" << endl;
    cout << "Masukkan level kekritisan: "; 
    cin >> crit;
    if (crit == '1') // rawat jalan
    {
        Hashing(entri);
            // Ini tidak akan dimasukkan ke queue, karena ini aplikasi rawat inap.
            // Jika pasien blom pernah mendaftar, maka hashing tetap dilakukan.
    }
    else if (crit == '2') // rawat inap biasa
    {
        InsertNormalPatient(entri, crit); //Ini masuk ke pendaftaran struktur queue
    }
    else
    {
        cout << "Input salah. Silahkan ulangi penginputan." << endl;
        mainMenu();
    }
}

void daftarPasienDarurat(){
    cout << "Masukkan nama pasien yang ingin didaftarkan untuk dirujuk: "; 
    cin.ignore(); getline(cin, entri);
    cout << endl;
    cout << "Level Kekritisan: " << endl;
    cout << "1. Mengkhawatirkan" << endl;
    cout << "2. Gawat Darurat" << endl;
    cout << "3. Kronis" << endl;
    cout << "================================" << endl;
    cout << "Masukkan level kekritisan: "; 
    cin >> crit;
    if (crit == '1')
    {
        
    }
    else if (crit == '3')
    {

    }
    else if (crit == '2' )
    {
        
    }
    else
    {
        cout << "Input salah. Silahkan ulangi penginputan." << endl;
        mainMenu();
    }
    InsertEmergencyPatient(entri, crit); // ini struktur pendaftaran stack
}

void pop()
{
    if (HeadCrit != NULL)
    {
        if (HeadCrit ->next == NULL)
        {
            HeadCrit = NULL;
        }
        else
        {
            HeadCrit = HeadCrit -> next;
            HeadCrit -> prev = NULL;
        }
    }
    else
    {
        if (HeadNormal ->next == NULL)
        {
            HeadNormal = NULL;
        }
        else
        {
            HeadNormal = HeadNormal ->next;
            HeadNormal -> prev = NULL;
        }
    }
}

int main () //program utama; berisikan main menu
    {
        mainMenu();
    }

void mainMenu(){
    
    MainMenu:
    system("cls");
    HashTableCheckPoint:
    cout << "=== Aplikasi Administrasi Rawat Inap Rumah Sakit ===" << endl;
    cout << "====================================================" << endl;
    cout << "Antrean Rawat Inap : " << endl;
    Display();
    cout << "====================================================" << endl;
    cout << "Main Menu : "<< endl;
    cout << "1. Daftarkan antrean pasien normal" << endl;
    cout << "2. Daftarkan antrean pasien darurat" << endl;
    cout << "3. Checkout Pasien" << endl;
    cout << "4. Tampilkan key ID" << endl;
    cout << "9. Help" << endl;
    cout << "0. Exit" << endl;
    cout << "====================================================" << endl;
    cout << "Entri: "; 
    cin >> input;
    switch (input)
        {            
            case '0':
                cout << "================================ BYE BYE =====================================" << endl;
                cout << "Thank you for running this program!"<< endl;
                cout << "Made by SpectreOfSolitude, MrJM OF THE DARKSIDE, Ratonhnhaké:ton, and Zwinglee" << endl;
                cout << "==============================================================================" << endl;
                break;
                
            case '1':
                daftarPasienNormal();
                goto MainMenu;
                break;

            case '2':
                daftarPasienDarurat();
                goto MainMenu;
                break;

            case '3': // POP
                pop();
                goto MainMenu;
                break;
                
            case '4': // menampilkan Data Pasien yang di panggil dengan ID 
                cout << "KEY:" << endl;
                DisplayHash();
                cout << endl;
                goto HashTableCheckPoint;
                break;

            case '9' :
                cout << "Petunjuk Penggunaan ";
                cout << "";
                cout << "";
                cout << "";
                cout << "";
                cout << "";
                cout << "";
                cout << "";

            default:
                break;
        }
}