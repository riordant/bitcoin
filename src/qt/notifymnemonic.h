#ifndef BITCOIN_NOTIFYMNEMONIC_H
#define BITCOIN_NOTIFYMNEMONIC_H


#include <QWizard>
#include <qt/walletmodel.h>

namespace Ui {
    class NotifyMnemonic;
}

class NotifyMnemonic : public QWizard
{
    Q_OBJECT
public:
    explicit NotifyMnemonic(QWidget *parent = 0);
    ~NotifyMnemonic();

    static void notify(std::vector<WalletModel*> walletModels);
private Q_SLOTS:
    void cancelEvent();
private:
    Ui::NotifyMnemonic *ui;
};

#endif //BITCOIN_NOTIFYMNEMONIC_H
