/* client_ftp_v1.3.2
 * charger un fichier choisi, du serveur au PC
 * affiche la liste, récupéré sur un fichier txt téléchargé sur le serveur
 * le chargement via un autre répertoire que celui de base est bugé!!
 * */
#include "clientftp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Clientftp w;
    w.show();

    return a.exec();
}
