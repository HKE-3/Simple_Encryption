#include <stdio.h>
#include <string.h>

#define SHIFT 3 // Kaç karakter kaydýrýlacaðýný belirler

void encrypt(char text[]) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + SHIFT) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + SHIFT) % 26) + 'a';
        }
    }
}

void decrypt(char text[]) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' - SHIFT + 26) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' - SHIFT + 26) % 26) + 'a';
        }
    }
}

int main() {
    char text[100];
    int choice;

    while (1) {
        printf("\n=== BASIT SIFRELEME PROGRAMI ===\n");
        printf("1 - Metni Sifrele\n");
        printf("2 - Sifreli Metni Coz\n");
        printf("3 - Cikis\n");
        printf("Secim yap: ");
        if (scanf("%d", &choice) != 1) {
            printf("Gecersiz giris! Lutfen bir rakam girin.\n");
            while (getchar() != '\n'); // Buffer temizleme
            continue;
        }
        getchar(); // Enter karakterini temizle

        if (choice == 3) {
            printf("Cikis yapiliyor...\n");
            break;
        }

        printf("Metni gir: ");
        if (fgets(text, sizeof(text), stdin) == NULL) {
            printf("Hata: Metin girilemedi!\n");
            continue;
        }
        text[strcspn(text, "\n")] = 0; // Yeni satýr karakterini kaldýr

        if (strlen(text) == 0) {
            printf("Hata: Bos metin girilemez!\n");
            continue;
        }

        if (choice == 1) {
            encrypt(text);
            printf("Sifrelenmis Metin: %s\n", text);
        } else if (choice == 2) {
            decrypt(text);
            printf("Cozulmus Metin: %s\n", text);
        } else {
            printf("Gecersiz secim!\n");
        }
    }

    printf("Devam etmek icin bir tusa basin...\n");
    getchar(); // Konsolun hemen kapanmasýný önler
    return 0;
}



