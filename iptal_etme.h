#include <stdio.h>
#include "str_vrb.h"

#ifndef PROJEODEV_IPTAL_ETME_H
#define PROJEODEV_IPTAL_ETME_H

void iptalEt() {
    int i = 0;
    int iptalID;
    printf("\nIptal etmek istediginiz ucusun numarasini girin:");
    scanf("%d", &iptalID);

    for (; i < 10; ++i) {
        if (rez[i] == iptalID) {
            printf("%d numarali ucus rezervasyonu iptal edildi.\n\n", rez[i]);
            rez[i] = 0; // İptal edilen rezervasyonun numarasını sıfırla
            ucuslar[i].bosYer++;
            users[0].walletAmount += ucuslar[i].ucret;
            break;
        }
    }

    // Kullanicinin ucusu iptal ettigini dosyaya kaydeder
    FILE *dosya = fopen("kullanici_islemleri.txt","a");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }
    fprintf(dosya, "%d ID numarali %s %s tarafindan %d no'lu ucus iptal edildi.\n\n", users[0].userId, users[0].name, users[0].surname, ucuslar[i].ucusId);
    fclose(dosya);
}

#endif //PROJEODEV_IPTAL_ETME_H
