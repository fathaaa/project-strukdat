#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>

using namespace std;


class User{
    private:
        string username;
        string password;

    public:
        User() {} 

        User(const string &username, const string &password)
        {
            this->username = username;
            this->password = password;
        }

        string getUsername() const
        {
            return username;
        }

        string getPassword() const
        {
            return password;
        }
};

class UserDatabase
        {
        private:
            static const int MAX_USERS = 1000;
            User users[MAX_USERS];
            int numUsers;

        public:
            UserDatabase()
            {
                numUsers = 0;
            }

            void loadFromFile(const string &filename)
            {
                ifstream infile(filename);
                if (infile.is_open())
                {
                    string username, password;
                    while (infile >> username >> password && numUsers < MAX_USERS)
                    {
                        User user(username, password);
                        users[numUsers] = user;
                        numUsers++;
                    }
                    infile.close();
                }
            }

            void saveToFile(const string &filename)
            {
                ofstream outfile(filename);
                if (outfile.is_open())
                {
                    for (int i = 0; i < numUsers; i++)
                    {
                        outfile << users[i].getUsername() << " " << users[i].getPassword() << endl;
                    }
                    outfile.close();
                }
            }

            bool usernameExists(const string &username) const
            {
                for (int i = 0; i < numUsers; i++)
                {
                    if (users[i].getUsername() == username)
                    {
                        return true;
                    }
                }
                return false;
            }

            void addUser(const User &user)
            {
                if (numUsers < MAX_USERS)
                {
                    users[numUsers] = user;
                    numUsers++;
                }
            }

            bool authenticate(const string &username, const string &password) const
            {
                for (int i = 0; i < numUsers; i++)
                {
                    if (users[i].getUsername() == username && users[i].getPassword() == password)
                    {
                        return true;
                    }
                }
                return false;
            }
};


class Pesawat
{
    private:
        string kodePenerbangan;
        string asal;
        string tujuan;
        string tanggalBerangkat;
        string waktuBerangkat;
        string waktuTiba;
        int kapasitasPesawat;
        string harga;

    public:
        Pesawat() {
            kapasitasPesawat=20;
        }

        void setKodePenerbangan(const string &kode)
        {
            kodePenerbangan = kode;
        }

        void setAsal(const string &kotaAsal)
        {
            asal = kotaAsal;
        }

        void setTujuan(const string &kotaTujuan)
        {
            tujuan = kotaTujuan;
        }

        void setTanggalBerangkat(const string &tanggal)
        {
            tanggalBerangkat = tanggal;
        }

        string getTanggalBerangkat(){
            return tanggalBerangkat;
        }

        void setWaktuBerangkat(const string &waktu)
        {
            waktuBerangkat = waktu;
        }

        string getWaktuBerangkat(){
            return waktuBerangkat;
        }

        void setWaktuTiba(const string &waktu)
        {
            waktuTiba = waktu;
        }

        void setKapasitasPesawat(int kapasitas)
        {
            kapasitasPesawat = kapasitas;
        }

        int getKapasitas()
        {
            return kapasitasPesawat;
        }

        string getKodeterbang()
        {
            return kodePenerbangan;
        }

        void setHarga(const string &hargapesawat)
        {
            harga = hargapesawat;
        }

        string getHarga()
        {
            return harga;
        }

        void setKapasitas(int a)
        {
            kapasitasPesawat = a;
        }

        void displayData(int n)
        {
            if (n == 0)
            {
                cout << "+------------------+--------------+--------------+---------------------+--------------------+----------------+------------------+--------------+" << endl;
                cout << "| Kode Penerbangan |     Asal     |    Tujuan    | Tanggal Berangkat   | Waktu Berangkat    |   Waktu Tiba   | Kapasitas Pesawat|     Harga    |" << endl;
                cout << "+------------------+--------------+--------------+---------------------+--------------------+----------------+------------------+--------------+" << endl;
            }

            cout << "| " << setw(16) << left << kodePenerbangan << " | " << setw(12) << left << asal << " | " << setw(12) << left << tujuan << " | " << setw(19) << left << tanggalBerangkat << " | " << setw(18) << left << waktuBerangkat << " | " << setw(14) << left << waktuTiba << " | " << setw(16) << left << kapasitasPesawat << " | " << setw(12) << left << harga << " |" << endl;
            
        }

};


void kopdisplayjadwal()
    {
        cout << "+----------------------+------------------+--------------+-------------------+------------------+" << endl;
        cout << "|         Nama         | Nomor Penerbangan| Nomor Kursi  | Tanggal Terbang   | Waktu Terbang    |" << endl;
        cout << "+----------------------+------------------+--------------+-------------------+------------------+" << endl;
    }

class Layout
    {
            private:
                map<string, vector<int>> seatLayouts;
                void initializeSeatLayouts()
                {
                    seatLayouts["ILK2109"] = 
                        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
                    seatLayouts["ILK2409"] = 
                        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
                    seatLayouts["ILK2105"] = 
                        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
                }

            public:
                Layout(){initializeSeatLayouts(); }

            void drawAirplane(const string &kodePesawat)
                {
                    cout << "    ____________" << endl;
                    cout << "   /            \\" << endl;
                    cout << "  /              \\" << endl;
                    cout << " /                \\" << endl;
                    cout << "|        *         |" << endl;
                    cout << "|                  |" << endl;
                    cout << "|                  |" << endl;
                    cout << "|                  |" << endl;

                    vector<int> seats = seatLayouts[kodePesawat];

                    for (int i = 0; i < 10; i++)
                    {
                        cout << "|  ";
                        if (seats[i] == -1)
                        {
                            cout << setw(4) << left << "SOLD";
                        }
                        else
                        {
                            cout << setw(4) << left << seats[i];
                        }
                        cout << "  |   ";
                        if (seats[i + 10] == -1)
                        {
                            cout << setw(4) << left << "SOLD";
                        }
                        else
                        {
                            cout << setw(4) << left << seats[i + 10];
                        }
                        cout << "  |" << endl;
                    }

                    cout << "|                  |" << endl;
                    cout << "|                  |" << endl;
                    cout << "|                  |" << endl;
                    cout << "|                  |" << endl;
                    cout << "\\                 /" << endl;
                    cout << " \\               /" << endl;
                    cout << "  \\_____________/" << endl;
                }

                void markSeatAsSold(const string &kodePesawat, int seatNumber)
                {
                    vector<int> &seats = seatLayouts[kodePesawat];
                    if (seatNumber >= 1 && seatNumber <= seats.size())
                    {
                        seats[seatNumber - 1] = -1;
                    }
                }

                void markSeatAsnotSold(const string &kodePesawat, int seatNumber)
                {
                    vector<int> &seats = seatLayouts[kodePesawat];
                    if (seatNumber >= 1 && seatNumber <= seats.size())
                    {
                        seats[seatNumber - 1] = 1;
                    }
                }
};

struct Node {
    string username;
    string nama;
    string tanggallahir;
    string nohp;
    string jenisidentitas;
    string noidentitas;
    string kodePenerbangan;
    int seat;
    string tanggalterbang;
    string waktuterbang;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    Node* getHead() const {
        return head;
    }

    void insertNode(const string& username, const string& nama, const string& tanggallahir,
                    const string& nohp, const string& jenisidentitas, const string& noidentitas,
                    const string& kodePenerbangan, int seat, const string& tanggalterbang,
                    const string& waktuterbang) {
                    Node* newNode = new Node;
                    Node* current = head;
                    while (current != nullptr) {
                    if (current->username == username && current->nama == nama &&
                        current->kodePenerbangan == kodePenerbangan && current->seat == seat) {
                        return;
                    } else{
                    current = current->next;
        }
    }
        newNode->username = username;
        newNode->nama = nama;
        newNode->tanggallahir = tanggallahir;
        newNode->nohp = nohp;
        newNode->jenisidentitas = jenisidentitas;
        newNode->noidentitas = noidentitas;
        newNode->kodePenerbangan = kodePenerbangan;
        newNode->seat = seat;
        newNode->tanggalterbang = tanggalterbang;
        newNode->waktuterbang = waktuterbang;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void saveToFile(const string& filename) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            Node* current = head;
            while (current != nullptr) {
                file << current->username << " " << current->kodePenerbangan << " " << current->seat << " "
                     << current->nama << " " << current->tanggallahir << " " << current->nohp << " "
                     << current->jenisidentitas << " " << current->noidentitas << " "
                     << current->tanggalterbang << " " << current->waktuterbang << endl;
                current = current->next;
            }

            file.close();
        } else {
            cout << "Gagal membuka file." << endl;
        }
    }

    void removeNode(const string& nama, const string& kodePenerbangan, int seat) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->nama == nama && current->kodePenerbangan == kodePenerbangan && current->seat == seat) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            delete current;
            
            return;
        }

        prev = current;
        current = current->next;
    }

    cout << "Data penumpang tidak ditemukan." << endl;
}


    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    

void tampilkanDataPenumpang(const LinkedList& linkedList) {
    Node* current = linkedList.getHead();

    if (current == nullptr) {
        cout << "Tidak ada data penumpang yang tersimpan." << endl;
        return;
    }

    cout << "Data Penumpang:" << endl;
    while (current != nullptr) {
    cout << "|------------------- |------------------------------|" << endl;
    cout << "| Username           | " << setw(28) << current->username << " |" << endl;
    cout << "|------------------- |------------------------------|" << endl;
    cout << "| Nama               | " << setw(28) << current->nama << " |" << endl;
    cout << "|------------------- |------------------------------|" << endl;
    cout << "| Tanggal Lahir      | " << setw(28) << current->tanggallahir << " |" << endl;
    cout << "|------------------- |------------------------------|" << endl;
    cout << "| Nomor Handphone    | " << setw(28) << current->nohp << " |" << endl;
    cout << "|------------------- |------------------------------|" << endl;
    cout << "| Jenis Identitas    | " << setw(28) << current->jenisidentitas << " |" << endl;
    cout << "|------------------- |------------------------------|" << endl;
    cout << "| Nomor Identitas    | " << setw(28) << current->noidentitas << " |" << endl;
    cout << "|------------------- |------------------------------|" << endl;
    cout << "| Kode Penerbangan   | " << setw(28) << current->kodePenerbangan << " |" << endl;
    cout << "|------------------- |------------------------------|" << endl;
    cout << "| Nomor Kursi        | " << setw(28) << current->seat << " |" << endl;
    cout << "|------------------- |------------------------------|" << endl;
    cout << "| Tanggal Terbang    | " << setw(28) << current->tanggalterbang << " |" << endl;
    cout << "|------------------- |------------------------------|" << endl;
    cout << "| Waktu Terbang      | " << setw(28) << current->waktuterbang << " |" << endl;
    cout << "|------------------- |------------------------------|" << endl;

        current = current->next;
    }
}

void removeAllNodes() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}



};

void displayJadwal(Node* head, const string& onlineusername) {
    Node* current = head;
    bool found = false;

    cout << "+-------------------------+----------------+-------------+---------------------+----------------+" << endl;
    cout << "|          Nama           |Kode Penerbangan| Nomor Kursi |   Tanggal Terbang   |  Waktu Terbang |" << endl;
    cout << "+-------------------------+----------------+-------------+---------------------+----------------+" << endl;

    while (current != nullptr) {
        if (current->username == onlineusername) {
            bool duplicate = false;
            Node* temp = head;
            while (temp != current) {
                if (temp->nama == current->nama &&
                    temp->kodePenerbangan == current->kodePenerbangan &&
                    temp->seat == current->seat &&
                    temp->tanggalterbang == current->tanggalterbang &&
                    temp->waktuterbang == current->waktuterbang) {
                    duplicate = true;
                    break;
                }
                temp = temp->next;
            }

            if (!duplicate) {
                found = true;
                cout << "| " << setw(23) << current->nama << " | " << setw(14) << current->kodePenerbangan << " | " 
                     << setw(11) << current->seat << " | " << setw(19) << current->tanggalterbang << " | " 
                     << setw(14) << current->waktuterbang << " |" << endl;
            }
        }

        current = current->next;
    }

    cout << "+-------------------------+----------------+-------------+---------------------+----------------+" << endl;

    if (!found) {
        cout << "Data penumpang dengan username " << onlineusername << " tidak ditemukan." << endl;
    }
}

void addSpace(int lines)
    {
        for (int i = 0; i < lines; i++)
        {
            cout << endl;
        }
    }

int main()
{

    UserDatabase userDB;
    Layout layout;
    userDB.loadFromFile("user_info.txt");
    string numseat[20];
    cout << "=============================================" << endl;
    cout << "=                                           =" << endl;
    cout << "=       Welcome to Ilkom Airlines           =" << endl;
    cout << "=                                           =" << endl;
    cout << "=============================================" << endl;
    cout << endl;
    cout << endl;

    bool loggedIn = false;
    string onlineusername;
    string onlineuserpassword;

    while (!loggedIn)
    {
        cout << "1. Masuk" << endl;
        cout << "2. Daftar Akun" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilihan anda adalah:";
        int option;
        cin >> option;
        addSpace(2);

        if (option == 1)
        {
            cout << "Masukkan username anda: ";
            string username;
            cin >> username;
            cout << "Masukkan password anda: ";
            string password;
            cin >> password;

            if (userDB.authenticate(username, password))
            {
                cout << "Anda berhasil masuk ke dalam portal pembelian tiket" << endl;
                onlineusername = username;
                onlineuserpassword = password;
                loggedIn = true;
            }
            else
            {
                cout << "Password atau username salah" << endl;
                cout << "Apakah anda ingin melakukan registrasi? [Y/N]" << endl;
                char input;
                cin >> input;
                if (input == 'Y' || input == 'y')
                {
                    cout << "Masukkan username anda: ";
                    string username;
                    cin >> username;

                    if (userDB.usernameExists(username))
                    {
                        cout << "Username telah digunakan, silahkan menggunakan username lain." << endl;
                    }
                    else
                    {
                        cout << "Masukkan password anda: ";
                        string password;
                        cin >> password;

                        User newUser(username, password);
                        userDB.addUser(newUser);
                        userDB.saveToFile("user_info.txt");

                        cout << "Pendaftaran berhasil!" << endl;
                    }
                }
                else if (input == 'N' || input == 'n')
                {
                    cout << "Silahkan masukkan username dan password ulang" << endl;
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
            }
        }
        else if (option == 2)
        {
            cout << "Masukkan username anda: ";
            string username;
            cin >> username;

            if (userDB.usernameExists(username))
            {
                cout << "Username telah digunakan, silahkan menggunakan username lain." << endl;
            }
            else
            {
                cout << "Masukkan password anda: ";
                string password;
                cin >> password;

                User newUser(username, password);
                userDB.addUser(newUser);
                userDB.saveToFile("user_info.txt");

                cout << "Pendaftaran berhasil!" << endl;
            }
        }
        else if (option == 3)
        {
            cout << "Terima kasih telah menggunakan jasa Ilkom Airlines. Sampai jumpa!" << endl;
        }
    }

    // Program selanjutnya setelah pengguna berhasil masuk
    cout << "Selamat datang di dashboard," << onlineusername << "!" << endl;

    bool exitProgram = false;

    const int MAX_PESAWAT = 3;
    Pesawat pesawat[MAX_PESAWAT];
    

    LinkedList linkedList, tempLL;

    while (!exitProgram)
    {
        cout << "1. Pemesanan Tiket" << endl;
        cout << "2. Lihat Tiket saya" << endl;
        cout << "3. Lihat Jadwal Penerbangan" << endl;
        cout << "4. Batalkan Penerbangan" << endl;
        cout << "9. Keluar" << endl;
        cout << "Pilihan anda adalah:";
        int pilihdashboard;
        cin >> pilihdashboard;
        string data[100][6];
        int numRows = 0;
        string kodeterbang;
        switch (pilihdashboard)
        {
        case 1:
                {
                    ifstream inputFile("pesawat_info.txt");
                    if (inputFile.is_open())
                    {
                        for (int i = 0; i < MAX_PESAWAT; ++i)
                        {
                            string kode, asal, tujuan, tanggal, waktuBerangkat, waktuTiba, harga;
                            int kapasitas;

                            inputFile >> kode >> asal >> tujuan >> tanggal >> waktuBerangkat >> waktuTiba >> kapasitas >> harga;

                            pesawat[i].setKodePenerbangan(kode);
                            pesawat[i].setAsal(asal);
                            pesawat[i].setTujuan(tujuan);
                            pesawat[i].setTanggalBerangkat(tanggal);
                            pesawat[i].setWaktuBerangkat(waktuBerangkat);
                            pesawat[i].setWaktuTiba(waktuTiba);
                            pesawat[i].setHarga(harga);
                        }

                        inputFile.close();

                        for (int i = 0; i < MAX_PESAWAT; ++i)
                        {
                            pesawat[i].displayData(i);
                        }
                    }
                    else
                    {
                        cout << "Failed to open the file." << endl;
                    }
                    cout << "+------------------+--------------+--------------+---------------------+--------------------+----------------+------------------+--------------+" << endl;

                    bool cek = true;
                    int temppesawat;
                    string tanggalfly;
                    string jamfly;
                    while (cek)
                    {
                        cout << "Silahkan ketik kode penerbangan yang dipilih:";
                        cin >> kodeterbang;

                        for (int i = 0; i < MAX_PESAWAT; i++)
                        {
                            if (pesawat[i].getKodeterbang() == kodeterbang)
                            {
                                if (pesawat[i].getKapasitas() > 0)
                                {
                                    pesawat[i].displayData(i);
                                    tanggalfly=pesawat[i].getTanggalBerangkat();
                                    jamfly=pesawat[i].getWaktuBerangkat();
                                    cek = false;
                                    temppesawat = i;
                                    layout.drawAirplane(kodeterbang);
                                    
                                    cout << "Silahkan pilih nomor kursi pesawat anda:";
                                    int kursi;
                                    cin >> kursi;
                                    cout << "Lanjutkan ke pengisian data [Y/N]:";
                                    char input2;
                                    cin >> input2;

                                    if (input2 == 'Y')
                                    { string username, nama, tanggallahir, nohp, jenisidentitas, noidentitas, kodePenerbangan,tanggalterbang, waktuterbang;
                                      int seat;

                                    username = onlineusername;
                                    kodePenerbangan = kodeterbang;
                                    tanggalterbang = pesawat[i].getTanggalBerangkat();
                                    waktuterbang = pesawat[i].getWaktuBerangkat();
                                    seat = kursi;

                                    cout << "Silahkan isi data diri anda" << endl;
                                    cout << "Nama (gunakan '_' sebagai pengganti spasi): ";
                                    cin >> nama;
                                    cout << "Tanggallahir [DD/MM/YYYY]: ";
                                    cin >> tanggallahir;
                                    cout << "Nomor Handphone: ";
                                    cin >> nohp;
                                    cout << "Jenis Identitas [KTP/SIM/Passport]: ";
                                    cin >> jenisidentitas;
                                    cout << "Nomor Identitas: ";
                                    cin >> noidentitas;
                                    linkedList.removeAllNodes();

                                    linkedList.insertNode(username, nama, tanggallahir, nohp, jenisidentitas, noidentitas,kodePenerbangan, seat, tanggalterbang, waktuterbang);

                                        cout << "ORDER SUMMARY" << endl;
                                        linkedList.tampilkanDataPenumpang(linkedList);
                                        cout << "Konfirmasi Pembelian [Y/N]" << endl;
                                        char konfirmbayar;
                                        cin >> konfirmbayar;
                                        if (konfirmbayar == 'Y')
                                        {
                                            
                                            pesawat[temppesawat].setKapasitas(pesawat[temppesawat].getKapasitas() - 1);
                                            layout.markSeatAsSold(kodeterbang, kursi);
            
                                            linkedList.saveToFile("data.txt");

                                            cout << "Pemesanan tiket telah berhasil dilakukan. Terima kasih sudah menggunakan jasa Ilkom Airlines" << endl;
                                        }
                                        else if (konfirmbayar == 'N')
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Anda memasukkan keyword yang salah" << endl;
                                        }
                                    }


                                    
                                }
                                else
                                {
                                    cout << "Kursi pesawat telah habis" << endl;
                                   
                                    

                                }
                            }
                        }
                    }

                    
                }

        break;
        
        case 2:
            {       
                    linkedList.removeAllNodes();
                    ifstream inputFile("data.txt");
                    if (inputFile.is_open()) {
                    string username, nama, tanggallahir, nohp, jenisidentitas, noidentitas, kodePenerbangan, waktuterbang, tanggalterbang;
                    int seat;

                    while (inputFile >> username >> kodePenerbangan >> seat >> nama >> tanggallahir >> nohp >> jenisidentitas >> noidentitas >> tanggalterbang >> waktuterbang) {
                        linkedList.insertNode(username, nama, tanggallahir, nohp, jenisidentitas, noidentitas, kodePenerbangan, seat, tanggalterbang, waktuterbang);
                    }

                    inputFile.close();
                } else {
                    cout << "Gagal membuka file." << endl;
                }

                
                displayJadwal(linkedList.getHead(), onlineusername);

                cout << "Kembali ke menu utama [Y/N] :";
            string answer;
            cin >> answer;
            if(answer == "N"){
                exitProgram = true;
            }

                       
            }

            break;

        case 3:
        {
            ifstream inputFile("pesawat_info.txt");
            if (inputFile.is_open())
            {
                for (int i = 0; i < MAX_PESAWAT; ++i)
                {
                    string kode, asal, tujuan, tanggal, waktuBerangkat, waktuTiba, harga;
                    int kapasitas;

                    inputFile >> kode >> asal >> tujuan >> tanggal >> waktuBerangkat >> waktuTiba >> kapasitas >> harga;

                    pesawat[i].setKodePenerbangan(kode);
                    pesawat[i].setAsal(asal);
                    pesawat[i].setTujuan(tujuan);
                    pesawat[i].setTanggalBerangkat(tanggal);
                    pesawat[i].setWaktuBerangkat(waktuBerangkat);
                    pesawat[i].setWaktuTiba(waktuTiba);
                    
                    pesawat[i].setHarga(harga);
                }

                inputFile.close();

                for (int i = 0; i < MAX_PESAWAT; ++i)
                {
                    pesawat[i].displayData(i);
                }
            }
            
            cout << "+------------------+--------------+--------------+---------------------+--------------------+----------------+------------------+--------------+" << endl;

            cout << "Kembali ke menu utama [Y/N] :";
            string answer;
            cin >> answer;
            if(answer == "N"){
                exitProgram = true;
            }
        }
        break;

        case 4:
        {

    
        ifstream inputFile("data.txt");
        if (inputFile.is_open()) {
        string username, nama, tanggallahir, nohp, jenisidentitas, noidentitas, kodePenerbangan, waktuterbang, tanggalterbang;
        int seat;

        while (inputFile >> username >> kodePenerbangan >> seat >> nama >> tanggallahir >> nohp >> jenisidentitas >> noidentitas >> tanggalterbang >> waktuterbang) {
            tempLL.insertNode(username, nama, tanggallahir, nohp, jenisidentitas, noidentitas, kodePenerbangan, seat, tanggalterbang, waktuterbang);
        }

        inputFile.close();
    } else {
        cout << "Gagal membuka file." << endl;
    }

    displayJadwal(tempLL.getHead(), onlineusername);

    
    cout << "Masukkan nama: ";
    string nama;
    cin >> nama;

    cout << "Masukkan kode penerbangan: ";
    string kodePenerbangan;
    cin >> kodePenerbangan;

    cout << "Masukkan nomor kursi: ";
    int seat;
    cin >> seat;

    tempLL.removeNode(nama, kodePenerbangan, seat);
    ofstream file("data.txt", ofstream::trunc);
    tempLL.saveToFile("data.txt");
    tempLL.removeAllNodes();

    ifstream inputFile("pesawat_info.txt");
            if (inputFile.is_open())
            {
                for (int i = 0; i < MAX_PESAWAT; ++i)
                {
                    string kode, asal, tujuan, tanggal, waktuBerangkat, waktuTiba, harga;
                    int kapasitas;

                    inputFile >> kode >> asal >> tujuan >> tanggal >> waktuBerangkat >> waktuTiba >> kapasitas >> harga;

                    pesawat[i].setKodePenerbangan(kode);
                    pesawat[i].setAsal(asal);
                    pesawat[i].setTujuan(tujuan);
                    pesawat[i].setTanggalBerangkat(tanggal);
                    pesawat[i].setWaktuBerangkat(waktuBerangkat);
                    pesawat[i].setWaktuTiba(waktuTiba);
                    
                    pesawat[i].setHarga(harga);
                }

                inputFile.close();

                for (int i = 0; i < MAX_PESAWAT; ++i)
                {
                    pesawat[i].displayData(i);
                }
            }

    for (int i = 0; i < MAX_PESAWAT; ++i)
        {
                    if(pesawat[i].getKodeterbang()==kodePenerbangan)
                    {
                        pesawat[i].setKapasitas(pesawat[i].getKapasitas() + 1);
                    }
        }
    

    layout.markSeatAsnotSold(kodePenerbangan, seat);
    

    cout <<"Penerbangan anda berhasil dibatalkan";

    cout << "Kembali ke menu utama [Y/N]: ";
    string answer;
    cin >> answer;
    if (answer == "N") {
        exitProgram = true;
    }
}
break;     
        case 9:

            exitProgram = true;
            break;
        default:

            break;
        }
    }

    return 0;
}
