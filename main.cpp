#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // Set application properties
    app.setApplicationName("dyrakDGram");
    app.setApplicationVersion("1.0");
    app.setOrganizationName("dyrakDGram");
    app.setOrganizationDomain("dyrak_dgram.org");
    
    // Set up locale for Bulgarian language
    QLocale::setDefault(QLocale::Bulgarian);
    
    // Show login dialog first
    LoginDialog login;
    if (login.exec() != QDialog::Accepted) {
        return 0;
    }

    // Create and show main window
    MainWindow window;
    window.show();
    
    return app.exec();
}
