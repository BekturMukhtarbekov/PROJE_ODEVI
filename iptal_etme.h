#include <stdio.h>
#include "str_vrb.h"

#ifndef PROJEODEV_IPTAL_ETME_H
#define PROJEODEV_IPTAL_ETME_H

void iptalEt() {
    int iptalID;
    printf("\nIptal etmek istediginiz ucusun numarasini girin:");
    scanf("%d", &iptalID);

    for (int i = 0; i < 10; ++i) {
        if (rez[i] == iptalID) {
            printf("%d numarali ucus rezervasyonu iptal edildi.\n\n", rez[i]);
            rez[i] = 0; // İptal edilen rezervasyonun numarasını sıfırla
            return; // İşlem tamamlandı, fonksiyondan çık
        }
        ucuslar[i].bosYer++;
    }

    printf("Belirtilen numarada bir rezervasyon bulunamadi.\n\n");
}

#endif //PROJEODEV_IPTAL_ETME_H
