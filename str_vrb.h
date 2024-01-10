#ifndef PROJEODEV_STR_VRB_H
#define PROJEODEV_STR_VRB_H

#define MAX_USERS 50


// Kullanici bilgisini temsil etmek icin bir yapi
typedef struct {
    short sira;
    int userId;
    char name[20];
    char surname[20];
    int walletAmount;
    char password[20];
} Kullanici;

// Ucus tarihini temsil etmek icin bir yapi
typedef struct {
    int gun;
    int ay;
    int yil;
} date; // Tanimlamalarda kolaylik saglamak icin burada ve ileride structure'lara yeni isimler verildi

// Ucus bilgilerini temsil etmek icin bir yapi
typedef struct {
    int ucusId;
    char nereden[15];
    char nereye[15];
    short bosYer;
    int ucret; // Added ucret member/
    date tarih;
} Ucus;

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
int rez[10];

//Kullanici degiskenleri
Kullanici users[MAX_USERS]; // Kullanici bilgilerini saklamak icin bir dizi
int userCount = 0; // Kayitli kullanicilarin sayisini tutmak icin bir degisken
int nextUserId = 202401; // Kullanicilarin sisteme kolayca girebilmeleri icin ID numarasi icin bir degisken

void ucuslariYaz() {
    printf("\nUcus numarasi:\tNereden:\tNereye:\t\tBos yer sayisi:\t\tUcreti:\t\tTarihi:\n");
    printf("______________________________\n");
    for (int i = 0; i < 6; ++i) {
        printf("%d\t\t%s\t%s\t\t%hd\t\t\t%d\t\t%d.%d.%d\n", ucuslar[i].ucusId, ucuslar[i].nereden, ucuslar[i].nereye, ucuslar[i].bosYer, ucuslar[i].ucret, ucuslar[i].tarih.gun, ucuslar[i].tarih.ay, ucuslar[i].tarih.yil);
    }
    for (int i = 6; i < 10; ++i) {
        if (i != 6) {
            printf("%d\t\t%s\t\t%s\t\t%hd\t\t\t%d\t\t%d.%d.%d\n", ucuslar[i].ucusId, ucuslar[i].nereden, ucuslar[i].nereye,
                   ucuslar[i].bosYer, ucuslar[i].ucret,  ucuslar[i].tarih.gun, ucuslar[i].tarih.ay,
                   ucuslar[i].tarih.yil);
        } else {
            printf("%d\t\t%s\t\t%s\t%hd\t\t\t%d\t\t%d.%d.%d\n", ucuslar[i].ucusId, ucuslar[i].nereden, ucuslar[i].nereye,ucuslar[i].bosYer, ucuslar[i].ucret, ucuslar[i].tarih.gun, ucuslar[i].tarih.ay,
                   ucuslar[i].tarih.yil);
        }
    }
    printf("______________________________\n");
}


#endif //PROJEODEV_STR_VRB_H
