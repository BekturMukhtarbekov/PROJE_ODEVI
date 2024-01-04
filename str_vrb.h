#ifndef PROJEODEV_STR_VRB_H
#define PROJEODEV_STR_VRB_H

#define MAX_USERS 50

// Kullanici bilgisini temsil etmek icin bir yapi
typedef struct {
    int userId  ;
    char name[50];
    char surname[50];
    int walletAmount;
    char password[50];
}Kullanici;

//Ucus tarihini temsil etmek icin bir yapi
typedef struct {
    int gun;
    int ay;
    int yil;
}date; // tanimlamalarda kolaylik saglamak icin burada ve ileride structure'lara yeni isimler verildi

//Ucus bilgilerini temsil etmek icin bir structure
typedef struct {
    int ucusId;
    char nereden[25];
    char nereye[25];
    short bosYer;
    int ucret; // Added ucret member/
    date tarih;
}Ucus;

Ucus ucuslar[10] = {{500, "Istanbul\0", "Ankara\0", 7, 3530, {24, 01, 2024}},
                    {501, "Istanbul\0", "Izmir\0", 12, 2870, {12, 01, 2024}},
                    {502, "Istanbul\0", "Antalya\0", 5, 5030, {15, 02, 2024}},
                    {503, "Istanbul\0", "Trabzon\0", 19, 2530, {02, 05, 2024}},
                    {504, "Istanbul\0", "Sivas\0", 21, 2650, {02, 03, 2024}},
                    {505, "Istanbul\0", "Van\0", 25, 3900, {29, 03, 2024}},
                    {506, "Ankara\0", "Istanbul\0", 6, 3760, {18, 02, 2024}},
                    {507, "Ankara\0", "Izmir\0", 3, 3380, {19, 01, 2024}},
                    {508, "Ankara\0", "Antalya\0", 11, 3450, {25, 01, 2024}},
                    {509, "Ankara\0", "Adana\0", 15, 3100, {29, 01, 2024}}};


//Ucus degiskenleri
Ucus flights[10];
int flightCount = 0;
int nextFlightId = 0x154AB77; // Ucus ID no'larini olusturmak icin bir degisken
int rez[10];

//Kullanici degiskenleri
Kullanici users[MAX_USERS]; // Kullanici bilgilerini saklamak icin bir dizi
int userCount = 0; // Kayitli kullanicilarin sayisini tutmak icin bir degisken
int nextUserId = 20230001; // Kullanicilarin sisteme kolayca girebilmeleri icin ID numarasi icin bir degisken


#endif //PROJEODEV_STR_VRB_H
