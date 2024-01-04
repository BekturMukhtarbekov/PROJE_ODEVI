#include <stdio.h>
#include <ctype.h>
#include "str_vrb.h"

#ifndef PROJEODEV_REZERVASYON_YAPMA_H
#define PROJEODEV_REZERVASYON_YAPMA_H

void rezYap () {
    int secim;
    char onay;
    biletal:
    printf("\nUcus numarasi:\tNereden:\tNereye:\t\tBos yer sayisi:\t\tUcreti:\t\tTarihi:\n");
    printf("______________________________\n");
    for (int i = 0; i < 6; ++i) {
        printf("%d\t\t%s\t%s\t\t%hd\t\t\t%d\t\t%d.%d.%d\n", ucuslar[i].ucusId, ucuslar[i].nereden, ucuslar[i].nereye, ucuslar[i].bosYer, ucuslar[i].ucret, ucuslar[i].tarih.gun, ucuslar[i].tarih.ay, ucuslar[i].tarih.yil);
    }
    for (int i = 6; i < 10; ++i) {
        if (i != 6) {
            printf("%d\t\t%s\t\t%s\t\t%hd\t\t\t%d\t\t%d.%d.%d\n", ucuslar[i].ucusId, ucuslar[i].nereden, ucuslar[i].nereye,
                   ucuslar[i].bosYer, ucuslar[i].ucret, ucuslar[i].tarih.gun, ucuslar[i].tarih.ay,
                   ucuslar[i].tarih.yil);
        } else {
            printf("%d\t\t%s\t\t%s\t%hd\t\t\t%d\t\t%d.%d.%d\n", ucuslar[i].ucusId, ucuslar[i].nereden, ucuslar[i].nereye,ucuslar[i].bosYer, ucuslar[i].ucret, ucuslar[i].tarih.gun, ucuslar[i].tarih.ay,
                   ucuslar[i].tarih.yil);
        }
    }
    printf("______________________________\n");

    printf("\nAlmak istediginiz ucus numarasini seciniz:\n");
    scanf("%d", &secim);
    for (int j = 0; j < 10; j++) {
        if (secim == 500+j) {
            onaylama:
            printf("\n%d TL ucretli %s'den %s'ye ucus bileti almak icin onayliyor musunuz? (e,h):", ucuslar[j].ucret, ucuslar[j].nereden, ucuslar[j].nereye);
            fflush(stdin);// Ek bir güvenlik önlemi, platforma bağlı olarak çalışmayabilir
            onay = getchar();
            onay = toupper(onay);
            if (ucuslar[j].bosYer > 0) {
                switch (onay) {
                    case 'E':
                        if (users[0].walletAmount >= ucuslar[j].ucret){
                            printf("\n%d.%d.%d tarihinde %d numarali ucus biletini almis oldunuz. Bizi tercih ettiginiz icin tesekkur ederiz.\n\n", ucuslar[j].tarih.gun, ucuslar[j].tarih.ay, ucuslar[j].tarih.yil, ucuslar[j].ucusId);
                            ucuslar[j].bosYer--;
                            rez[j] = ucuslar[j].ucusId;
                            users[0].walletAmount -= ucuslar[j].ucret;
                            printf("Kalan bakiyeniz = %d\n\n", users[0].walletAmount);
                        } else
                            printf("\nBakiyeniz yetersizdir.\nBaska hesabinizi deneyiniz.\n");
                        break;
                    case 'H':
                        goto biletal;
                        break;
                    default:
                        printf("Gecersiz secim yaptiniz. Tekrar deneyiniz.");
                        goto onaylama;
                }
            } else {
                printf("Maalesef istediginiz ucusta yer yok. Lutfen baska bir ucus tercih ediniz");
                goto biletal;
            }
        }
    }
}


#endif //PROJEODEV_REZERVASYON_YAPMA_H
