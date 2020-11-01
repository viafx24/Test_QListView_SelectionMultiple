#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{
    QVBoxLayout *layout = new QVBoxLayout;

    QStringList listePays;
    listePays << "France" << "Espagne" << "Italie" << "Portugal" << "Suisse";
    modele = new QStringListModel(listePays);

    vue = new QListView ;
    vue->setModel(modele);

    //on ajoute cette ligne pour permettre la selection multiple (aller voir la doc, il y a d'autres options)
    vue->setSelectionMode(QAbstractItemView::ExtendedSelection);

    bouton = new QPushButton("Afficher la sélection");

    layout->addWidget(vue);
    layout->addWidget(bouton);

    setLayout(layout);

    connect(bouton, SIGNAL(clicked()), this, SLOT(clicSelection()));
}

void FenPrincipale::clicSelection()
{
    QItemSelectionModel *selection = vue->selectionModel();
    QModelIndexList listeSelections = selection->selectedIndexes();

    // on crée un QString avec une boucle, on met toutes les données récupérées dedans avant de l'afficher avec le QMessageBox
    QString elementsSelectionnes;

    for (int i = 0 ; i < listeSelections.size() ; i++)
    {
        // QVariant peut stocker un string ou un int
        QVariant elementSelectionne = modele->data(listeSelections[i], Qt::DisplayRole);
        elementsSelectionnes += elementSelectionne.toString() + "<br />";
    }

    QMessageBox::information(this, "Eléments sélectionnés", elementsSelectionnes);
}
