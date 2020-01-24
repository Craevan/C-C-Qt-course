#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog( QWidget* parent = nullptr);

protected:
    void paintEvent( QPaintEvent* event );
    QPushButton* okButton;
    QLabel* labelInfo;
    QVBoxLayout* verticalLayout;
};

#endif // ABOUTDIALOG_H
