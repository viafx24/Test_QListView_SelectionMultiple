#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>

class FenPrincipale : public QWidget
{
    Q_OBJECT

    public:
        FenPrincipale();

    private:
        QListView *vue;
        QStringListModel *modele;
        QPushButton *bouton;

    private slots:
        void clicSelection();
};


#endif
