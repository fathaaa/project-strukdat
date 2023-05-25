#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

class User
{
private:
    string username;
    string password;

public:
    User() {} // Default constructor

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

const int barispesawat = 100;
const int kolompesawat = 6;

void readDataFromFile(const string &filename, string data[barispesawat][kolompesawat], int &numRows)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        numRows = 0;
        while (getline(file, line) && numRows < barispesawat)
        {
            istringstream iss(line);
            string word;
            int col = 0;
            while (iss >> word && col < kolompesawat)
            {
                data[numRows][col] = word;
                col++;
            }
            numRows++;
        }
        file.close();
    }
}

void printData(const string data[barispesawat][kolompesawat], int numRows)
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < kolompesawat; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

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
    Pesawat() {}

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

    void setWaktuBerangkat(const string &waktu)
    {
        waktuBerangkat = waktu;
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
            cout << "________________________________________________________________________________________________________________________________________________________" << endl;
            cout << "|  Kode Penerbangan  |     Asal      |     Tujuan     |   Tanggal Berangkat  |   Waktu Berangkat   |   Waktu Tiba   | Kapasitas Pesawat|     Harga     |" << endl;
        }

        cout << "| " << setiosflags(ios::left) << setw(18) << kodePenerbangan << " | " << setw(13) << asal << " | " << setw(14) << tujuan << " | " << setw(20) << tanggalBerangkat << " | " << setw(19) << waktuBerangkat << " | " << setw(14) << waktuTiba << " | " << setw(16) << kapasitasPesawat << " |" << setw(14) << harga << " |" << endl;
    }
};

class Penumpang
{
private:
    string username;
    string nama;
    string tanggallahir;
    string nohp;
    string jenisidentitas;
    string noidentitas;
    string KodePenerbangan;
    int seat;

public:
    void settambahan(const string &user, const string &kodeterbang, int kursi)
    {
        username = user;
        KodePenerbangan = kodeterbang;
        seat = kursi;
    }

    void setUsername(string newUsername)
    {
        username = newUsername;
    }
    string getUsername() const
    {
        return username;
    }

    void setNama(string newNama)
    {
        nama = newNama;
    }
    string getNama() const
    {
        return nama;
    }

    void setTanggalLahir(string newTanggalLahir)
    {
        tanggallahir = newTanggalLahir;
    }
    string getTanggalLahir() const
    {
        return tanggallahir;
    }

    void setNoHp(string newNoHp)
    {
        nohp = newNoHp;
    }
    string getNoHp() const
    {
        return nohp;
    }

    void setJenisIdentitas(string newJenisIdentitas)
    {
        jenisidentitas = newJenisIdentitas;
    }
    string getJenisIdentitas() const
    {
        return jenisidentitas;
    }

    void setNoIdentitas(string newNoIdentitas)
    {
        noidentitas = newNoIdentitas;
    }
    string getNoIdentitas() const
    {
        return noidentitas;
    }

    void setKodePenerbangan(string newKodePenerbangan)
    {
        KodePenerbangan = newKodePenerbangan;
    }
    string getKodePenerbangan() const
    {
        return KodePenerbangan;
    }

    void setSeat(int newSeat)
    {
        seat = newSeat;
    }
    int getSeat() const
    {
        return seat;
    }

    void inputData()
    {
        cout << "Silahkan isi data diri anda" << endl;
        cout << "Nama: ";
        cin >> nama;
        cout << "Tanggallahir [DD/MM/YYYY]: ";
        cin >> tanggallahir;
        cout << "Nomor Handphone: ";
        cin >> nohp;
        cout << "Jenis Identitas [KTP/SIM/Passport]: ";
        cin >> jenisidentitas;
        cout << "Nomor Identitas: ";
        cin >> noidentitas;
    }

    void simpanKeFile(const string &filename)
    {
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            file << username << " " << KodePenerbangan << " " << seat << " " << nama << " " << tanggallahir << " " << nohp << " " << jenisidentitas << " " << noidentitas << endl;
            file.close();
        }
        else
        {
            cout << "Input data gagal" << filename << endl;
        }
    }

    void displaysummary()
    {
        cout << "Username: " << username << endl;
        cout << "Kode Penerbangan: " << KodePenerbangan << endl;
        cout << "Nomor kursi: " << seat << endl;
        cout << "Nama penumpang: " << nama << endl;
        cout << "Tanggal Lahir: " << tanggallahir << endl;
        cout << "Nomor Handphone: " << nohp << endl;
        cout << "Jenis Identitas: " << jenisidentitas << endl;
        cout << "Nomor Identitas: " << noidentitas << endl;
    }
};

class Layout
{
private:
    map<string, vector<int>> seatLayouts;
    void loadSoldSeats()
    {
        ifstream inputFile("sold_seats.txt");
        if (inputFile.is_open())
        {
            string kodePesawat;
            int seatNumber;
            while (inputFile >> kodePesawat >> seatNumber)
            {
                seatLayouts[kodePesawat][seatNumber - 1] = -1;
            }
            inputFile.close();
        }
        else
        {
            cout << "Gagal membuka file untuk memuat data seat yang terjual." << endl;
        }
    }

    void initializeSeatLayouts()
    {
        seatLayouts["ILK2109"] = 
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        seatLayouts["ILK2409"] = 
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        seatLayouts["ILK2105"] = 
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    }

    void saveSoldSeat(const string &kodePesawat, int seatNumber)
    {
        ofstream outputFile("sold_seats.txt", ios::app);
        if (outputFile.is_open())
        {
            outputFile << kodePesawat << " " << seatNumber << endl;
            outputFile.close();
        }
        else
        {
            cout << "Gagal membuka file untuk menyimpan data seat yang terjual." << endl;
        }
    }

public:
    Layout()
    {
        loadSoldSeats();         // Memuat data seat yang terjual dari file txt saat program dijalankan
        initializeSeatLayouts(); // Menginisialisasi layout awal seat

        // ...
    }

    void drawAirplane(const string &kodePesawat)
    {
        cout << "    ____________________" << endl;
        cout << "   /                   \\" << endl;
        cout << "  /                     \\" << endl;
        cout << " /                       \\" << endl;
        cout << "|            *            |" << endl;
        cout << "|                         |" << endl;
        cout << "|                         |" << endl;
        cout << "|                         |" << endl;

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

        cout << "|                         |" << endl;
        cout << "|                         |" << endl;
        cout << "|                         |" << endl;
        cout << "|                         |" << endl;
        cout << "\\                        /" << endl;
        cout << " \\                      /" << endl;
        cout << "  \\____________________/" << endl;
    }

    void markSeatAsSold(const string &kodePesawat, int seatNumber)
    {
        vector<int> &seats = seatLayouts[kodePesawat];
        if (seatNumber >= 1 && seatNumber <= seats.size())
        {
            seats[seatNumber - 1] = -1;
        }

        saveSoldSeat(kodePesawat, seatNumber);
    }
};

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

    while (!exitProgram)
    {
        // Tampilkan menu atau fitur-fitur yang tersedia di dalam dashboard
        cout << "1. Pemesanan Tiket" << endl;
        cout << "2. Lihat Tiket saya" << endl;
        cout << "3. Lihat Jadwal Penerbangan" << endl;
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
                    pesawat[i].setKapasitasPesawat(kapasitas);
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

            bool cek = true;
            int temppesawat;
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
                            cek = false;
                            temppesawat = i;
                        }
                        else
                        {
                            cout << "Kursi pesawat telah habis, silahkan pilih penerbangan lain" << endl;
                        }
                    }
                }
            }

            layout.drawAirplane(kodeterbang);
            cout << "Silahkan pilih nomor kursi pesawat anda:";
            int kursi;
            cin >> kursi;
            cout << "Lanjutkan ke pengisian data [Y/N]:";
            char input2;
            cin >> input2;

            if (input2 == 'Y')
            {

                Penumpang data;
                data.inputData();
                data.settambahan(onlineusername, kodeterbang, kursi);
                cout << "ORDER SUMMARY" << endl;
                data.displaysummary();
                cout << "Konfirmasi Pembelian [Y/N]" << endl;
                char konfirmbayar;
                cin >> konfirmbayar;
                if (konfirmbayar == 'Y')
                {
                    data.simpanKeFile("data.txt");
                    pesawat[temppesawat].setKapasitas(pesawat[temppesawat].getKapasitas() - 1);
                    layout.markSeatAsSold(kodeterbang, kursi);

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

        break;
        case 2:
            // Implementasikan logika untuk melihat pesanan di sini

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
                    pesawat[i].setKapasitasPesawat(kapasitas);
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
