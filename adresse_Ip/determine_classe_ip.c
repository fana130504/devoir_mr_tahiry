#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void determinerClasse(char *ip) {
    int premierOctet;
    sscanf(ip, "%d", &premierOctet);

    if (premierOctet >= 1 && premierOctet <= 126) {
        printf("Classe A");
    } else if (premierOctet >= 128 && premierOctet <= 191) {
        printf("Classe B");
    } else if (premierOctet >= 192 && premierOctet <= 223) {
        printf("Classe C");
    } else if (premierOctet >= 224 && premierOctet <= 239) {
        printf("Classe D (Multicast)");
    } else if (premierOctet >= 240 && premierOctet <= 255) {
        printf("Classe E (Expérimentale)");
    } else {
        printf("Adresse IP invalide");
    }
}

int main() {
    char *data;
    char ip[16];

    printf("Content-type: text/html\n\n");
    printf("<html><body>");

    data = getenv("CONTENT_LENGTH");
    if (data == NULL) {
        printf("<p>Erreur : aucune donnée reçue.</p>");
    } else {
        scanf("ip=%15s", ip);
        printf("<p>Adresse IP : %s</p>", ip);
        printf("<p>Classe : ");
        determinerClasse(ip);
        printf("</p>");
    }

    printf("</body></html>");
    return 0;
}
