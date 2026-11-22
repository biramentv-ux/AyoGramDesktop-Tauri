#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QListWidget>
#include <QTabWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QTranslator>
#include <QLocale>
#include <QPluginLoader>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onGhostModeToggle(bool checked);
    void onStreamerModeToggle(bool checked);
    void onLocalPremiumToggle(bool checked);
    void onTranslationToggle(bool checked);
    void onAppearanceCustomize();
    void onMessageHistory();
    void onMediaPreview();
    void onFilterSettings();
    void onAbout();
    void onExit();
    void onSendClicked();

private:
    void setupUI();
    void setupMenuBar();
    void setupToolBar();
    void setupStatusBar();
    void setupTranslations();
    void loadBulgarianTranslations();
    void setupSettings();
    QString interceptNetworkRequest(const QString &requestData);
    void handleIncomingMessage(const QString &messageData);

    // UI Elements
    QTabWidget *tabWidget;
    QWidget *chatTab;
    QWidget *settingsTab;
    QWidget *historyTab;
    QWidget *mediaTab;
    
    // Chat tab elements
    QVBoxLayout *chatLayout;
    QListWidget *chatList;
    QTextEdit *messageDisplay;
    QLineEdit *messageInput;
    QPushButton *sendButton;
    
    // Settings tab elements
    QVBoxLayout *settingsLayout;
    QCheckBox *ghostModeCheckBox;
    QCheckBox *streamerModeCheckBox;
    QCheckBox *localPremiumCheckBox;
    QCheckBox *translatorCheckBox;
    QComboBox *appearanceComboBox;
    QComboBox *formatComboBox;
    QComboBox *bitrateComboBox;
    QPushButton *customizeAppearanceButton;
    QPushButton *saveSettingsButton;
    
    // History tab elements
    QVBoxLayout *historyLayout;
    QLabel *historyLabel;
    QListWidget *deletedMessagesList;
    
    // Media tab elements
    QVBoxLayout *mediaLayout;
    QLabel *mediaLabel;
    QListWidget *previewList;
    
    // Menubar
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *toolsMenu;
    QMenu *helpMenu;
    
    // Actions
    QAction *exitAction;
    QAction *aboutAction;
    QAction *settingsAction;
    
    // Translator
    QTranslator *translator;
};

#endif // MAINWINDOW_H