#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{
    QVBoxLayout *layout = new QVBoxLayout;

    QStringList listePays;
    listePays << "France" << "Espagne" << "Italie" << "Portugal" << "Suisse";
    modele = new QStringListModel(listePays);

    vue = new QListView ;
    vue->setModel(modele);

    bouton = new QPushButton("Afficher la sélection");

    layout->addWidget(vue);
    layout->addWidget(bouton);

    setLayout(layout);

    connect(bouton, SIGNAL(clicked()), this, SLOT(clicSelection()));
}

void FenPrincipale::clicSelection()
{

    // C'est ces quatres lignes qui sont  un peu lourdes
    // on récupère la selection
    QItemSelectionModel *selection = vue->selectionModel();
    // on récupère l'index (numero de l'element selection)
    QModelIndex indexElementSelectionne = selection->currentIndex();
    // on utilise data pour retrouver le texte à partir de l'index
    QVariant elementSelectionne = modele->data(indexElementSelectionne, Qt::DisplayRole);
    // on affiche la boite de dialogue avec le string récupéré
    QMessageBox::information(this, "Elément sélectionné", elementSelectionne.toString());
}
