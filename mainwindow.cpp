#include "mainwindow.h"
#include "pluginmanager.h"
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , translator(nullptr)
{
    setupUI();
    setupMenuBar();
    setupToolBar();
    setupStatusBar();
    setupTranslations();
    setupSettings();
    
    // Load plugins
    PluginManager::instance().loadPlugins();
    
    // Set window properties
    setWindowTitle(tr("dyrakDGram"));
    resize(800, 600);
}

MainWindow::~MainWindow()
{
    delete translator;
}

void MainWindow::setupUI()
{
    // Create central widget and layout
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // Create tab widget
    tabWidget = new QTabWidget(centralWidget);
    tabWidget->setTabsClosable(false);
    
    // Create chat tab
    chatTab = new QWidget();
    chatLayout = new QVBoxLayout(chatTab);
    
    // Chat list
    chatList = new QListWidget();
    chatLayout->addWidget(chatList);
    
    // Message display
    messageDisplay = new QTextEdit();
    messageDisplay->setReadOnly(true);
    chatLayout->addWidget(messageDisplay);
    
    // Message input
    QHBoxLayout *inputLayout = new QHBoxLayout();
    messageInput = new QLineEdit();
    sendButton = new QPushButton(tr("Изпрати"));
    inputLayout->addWidget(messageInput);
    inputLayout->addWidget(sendButton);
    chatLayout->addLayout(inputLayout);
    
    // Create settings tab
    settingsTab = new QWidget();
    settingsLayout = new QVBoxLayout(settingsTab);
    
    ghostModeCheckBox = new QCheckBox(tr("Ghost Mode (Скрит режим)"));
    streamerModeCheckBox = new QCheckBox(tr("Streamer Mode (Режим на стриймър)"));
    localPremiumCheckBox = new QCheckBox(tr("Local Premium (Локален Premium)"));
    translatorCheckBox = new QCheckBox(tr("Translator (Преводач)"));
    
    settingsLayout->addWidget(ghostModeCheckBox);
    settingsLayout->addWidget(streamerModeCheckBox);
    settingsLayout->addWidget(localPremiumCheckBox);
    settingsLayout->addWidget(translatorCheckBox);
    
    // DownloaderMachine settings
    settingsLayout->addWidget(new QLabel(tr("Downloader формат")));
    formatComboBox = new QComboBox();
    formatComboBox->addItems({"FLAC", "WAV", "MP3", "AAC"});
    settingsLayout->addWidget(formatComboBox);
    
    settingsLayout->addWidget(new QLabel(tr("Downloader битрейт")));
    bitrateComboBox = new QComboBox();
    bitrateComboBox->addItems({"Lossless", "320 kbps", "256 kbps", "128 kbps"});
    settingsLayout->addWidget(bitrateComboBox);
    
    // Appearance settings
    QHBoxLayout *appearanceLayout = new QHBoxLayout();
    appearanceComboBox = new QComboBox();
    appearanceComboBox->addItem(tr("Светъл режим"));
    appearanceComboBox->addItem(tr("Тъмна тема"));
    appearanceComboBox->addItem(tr("Системна тема"));
    
    customizeAppearanceButton = new QPushButton(tr("Персонализиране на изгледа"));
    appearanceLayout->addWidget(appearanceComboBox);
    appearanceLayout->addWidget(customizeAppearanceButton);
    
    settingsLayout->addLayout(appearanceLayout);
    
    saveSettingsButton = new QPushButton(tr("Запазване на настройките"));
    settingsLayout->addWidget(saveSettingsButton);
    
    // Create history tab
    historyTab = new QWidget();
    historyLayout = new QVBoxLayout(historyTab);
    
    historyLabel = new QLabel(tr("История на съобщенията (Deleted Messages)"));
    deletedMessagesList = new QListWidget();
    
    historyLayout->addWidget(historyLabel);
    historyLayout->addWidget(deletedMessagesList);
    
    // Create media tab
    mediaTab = new QWidget();
    mediaLayout = new QVBoxLayout(mediaTab);
    
    mediaLabel = new QLabel(tr("Медийни предварителни прегледи"));
    previewList = new QListWidget();
    
    mediaLayout->addWidget(mediaLabel);
    mediaLayout->addWidget(previewList);
    
    // Add tabs to tab widget
    tabWidget->addTab(chatTab, tr("Чатове"));
    tabWidget->addTab(settingsTab, tr("Настройки"));
    tabWidget->addTab(historyTab, tr("История"));
    tabWidget->addTab(mediaTab, tr("Медия"));
    
    // Connect signals
    connect(sendButton, &QPushButton::clicked, this, &MainWindow::onSendClicked);
    connect(ghostModeCheckBox, &QCheckBox::toggled, this, &MainWindow::onGhostModeToggle);
    connect(streamerModeCheckBox, &QCheckBox::toggled, this, &MainWindow::onStreamerModeToggle);
    connect(localPremiumCheckBox, &QCheckBox::toggled, this, &MainWindow::onLocalPremiumToggle);
    connect(translatorCheckBox, &QCheckBox::toggled, this, &MainWindow::onTranslationToggle);
    connect(customizeAppearanceButton, &QPushButton::clicked, this, &MainWindow::onAppearanceCustomize);
    connect(saveSettingsButton, &QPushButton::clicked, this, &MainWindow::onMessageHistory);
}

void MainWindow::setupMenuBar()
{
    menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    
    // File menu
    fileMenu = menuBar->addMenu(tr("Файл"));
    exitAction = fileMenu->addAction(tr("Изход"));
    connect(exitAction, &QAction::triggered, this, &MainWindow::onExit);
    
    // Edit menu
    editMenu = menuBar->addMenu(tr("Редакция"));
    settingsAction = editMenu->addAction(tr("Настройки"));
    connect(settingsAction, &QAction::triggered, this, &MainWindow::onFilterSettings);
    
    // View menu
    viewMenu = menuBar->addMenu(tr("Изглед"));
    
    // Tools menu
    toolsMenu = menuBar->addMenu(tr("Инструменти"));
    toolsMenu->addAction(tr("Преводач"));
    toolsMenu->addAction(tr("Медийни прегледи"));
    
    // Help menu
    helpMenu = menuBar->addMenu(tr("Помощ"));
    aboutAction = helpMenu->addAction(tr("Относно"));
    connect(aboutAction, &QAction::triggered, this, &MainWindow::onAbout);
}

void MainWindow::setupToolBar()
{
    QToolBar *toolBar = addToolBar(tr("Основен инструменти"));
    toolBar->addAction(tr("Нов чат"));
    toolBar->addAction(tr("Търсене"));
    toolBar->addAction(tr("Настройки"));
    toolBar->addAction(tr("Помощ"));
}

void MainWindow::setupStatusBar()
{
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    statusBar->showMessage(tr("Готов"));
}

void MainWindow::setupTranslations()
{
    // Load Bulgarian translations
    loadBulgarianTranslations();
}

void MainWindow::loadBulgarianTranslations()
{
    // Create a translator for Bulgarian
    translator = new QTranslator(this);
    
    // Try to load the translation file from the translations directory
    QString translationPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/translations/"; 
    QDir dir(translationPath);
    
    // Create directory if it doesn't exist
    if (!dir.exists()) {
        dir.mkpath(translationPath);
    }
    
    // Load the Bulgarian translation file
    if (translator->load("ayu_bg.qm", translationPath)) {
        QApplication::installTranslator(translator);
        qDebug() << "Bulgarian translations loaded successfully";
    } else {
        qDebug() << "Failed to load Bulgarian translations";
    }
}

void MainWindow::setupSettings()
{
    // Load saved settings
    QSettings settings;
    
    // Load ghost mode setting
    ghostModeCheckBox->setChecked(settings.value("ghostMode", false).toBool());
    
    // Load streamer mode setting
    streamerModeCheckBox->setChecked(settings.value("streamerMode", false).toBool());
    
    // Load local premium setting
    localPremiumCheckBox->setChecked(settings.value("localPremium", false).toBool());
    
    // Load translator setting
    translatorCheckBox->setChecked(settings.value("translator", false).toBool());
    
    // Load appearance setting
    appearanceComboBox->setCurrentIndex(settings.value("appearance", 0).toInt());
}

void MainWindow::onGhostModeToggle(bool checked)
{
    if (checked) {
        messageDisplay->append(tr("Ghost Mode активиран"));
    } else {
        messageDisplay->append(tr("Ghost Mode деактивиран"));
    }
}

void MainWindow::onStreamerModeToggle(bool checked)
{
    if (checked) {
        messageDisplay->append(tr("Streamer Mode активиран"));
    } else {
        messageDisplay->append(tr("Streamer Mode деактивиран"));
    }
}

void MainWindow::onLocalPremiumToggle(bool checked)
{
    if (checked) {
        messageDisplay->append(tr("Local Premium активиран"));
    } else {
        messageDisplay->append(tr("Local Premium деактивиран"));
    }
}

void MainWindow::onTranslationToggle(bool checked)
{
    if (checked) {
        messageDisplay->append(tr("Преводач активиран"));
    } else {
        messageDisplay->append(tr("Преводач деактивиран"));
    }
}

void MainWindow::onAppearanceCustomize()
{
    messageDisplay->append(tr("Персонализиране на изгледа - отвори настройки"));
}

void MainWindow::onMessageHistory()
{
    messageDisplay->append(tr("Показване на историята на съобщенията"));
}

void MainWindow::onMediaPreview()
{
    messageDisplay->append(tr("Медийни предварителни прегледи"));
}

void MainWindow::onFilterSettings()
{
    messageDisplay->append(tr("Настройки на филтрите"));
}

void MainWindow::onAbout()
{
    QMessageBox::about(this, tr("Относно dyrakDGram"),
                       tr("Хибридно приложение между dyrakDGram и exDekstop с поддръжка на български език.\n"
                          "Не изисква Android emulator и е desktop Windows клиент."));
}

QString MainWindow::interceptNetworkRequest(const QString &requestData)
{
    // Логване на прихванати star заявки
    QFile logFile(QCoreApplication::applicationDirPath() + "/intercept.log");
    QString logEntry;
    // Парсване на JSON за реални ID-та с fallback към regex
    QJsonDocument doc = QJsonDocument::fromJson(requestData.toUtf8());
    QString contentId, userId, chatId;
    bool parsed = false;
    if (!doc.isNull() && doc.isObject()) {
        QJsonObject obj = doc.object();
        if (obj.contains("content_id") || obj.contains("message_id") || obj.contains("id") || obj.contains("user_id") || obj.contains("chat_id")) {
            parsed = true;
            if (obj.contains("content_id")) {
                contentId = obj.value("content_id").toString();
            } else if (obj.contains("message_id")) {
                contentId = obj.value("message_id").toString();
            } else if (obj.contains("id")) {
                contentId = obj.value("id").toString();
            }
            userId = obj.value("user_id").toString();
            chatId = obj.value("chat_id").toString();
        }
    }
    // Fallback regex ако JSON парсването не даде резултати
    if (!parsed || contentId.isEmpty()) {
        QRegularExpression reContent("(?i)(content_id|message_id|id)\s*[:=]\s*[\"']?([\w-]+)[\"']?");
        QRegularExpression reUser("(?i)user_id\s*[:=]\s*[\"']?([\w-]+)[\"']?");
        QRegularExpression reChat("(?i)chat_id\s*[:=]\s*[\"']?([\w-]+)[\"']?");
        QRegularExpressionMatch mContent = reContent.match(requestData);
        QRegularExpressionMatch mUser = reUser.match(requestData);
        QRegularExpressionMatch mChat = reChat.match(requestData);
        if (mContent.hasMatch()) contentId = mContent.captured(2);
        if (mUser.hasMatch()) userId = mUser.captured(1);
        if (mChat.hasMatch()) chatId = mChat.captured(1);
    }
    // NetworkInterceptor wrapper - автоматично прихващане на плащания
    if (requestData.contains("TL_payments_sendStarsForm")) {
        QPluginLoader loader(QCoreApplication::applicationDirPath() + "/plugins/FakePaymentInterceptor.dll");
        QObject *pluginInstance = loader.instance();
        if (pluginInstance) {
            QMetaObject::invokeMethod(pluginInstance, "initialize");
            messageDisplay->append(tr("NetworkInterceptor: Прихваната заявка TL_payments_sendStarsForm"));
            messageDisplay->append(tr("NetworkInterceptor: Връща фалшив TL_payments_paymentResult"));
            return "{\"@type\":\"TL_payments_paymentResult\",\"success\":true,\"status\":\"paid\",\"message\":\"Успешно плащане!\"}";
        }
    }
    // Отключване на съдържание изискващо Stars
    if (requestData.contains("stars_required") || requestData.contains("TL_payments")) {
        // Логване в intercept.log
        if (logFile.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&logFile);
            out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " | contentId: " << contentId << " | userId: " << (userId.isEmpty()?"unknown_user":userId) << " | chatId: " << (chatId.isEmpty()?"unknown_chat":chatId) << " | request: " << requestData.left(200) << "\n";
            logFile.close();
        }
        QPluginLoader unlockLoader(QCoreApplication::applicationDirPath() + "/plugins/UnlockStarsContent.dll");
        QObject *unlockPlugin = unlockLoader.instance();
        if (unlockPlugin) {
            QMetaObject::invokeMethod(unlockPlugin, "initialize");
            if (!contentId.isEmpty()) {
                // Извикване с три параметъра за прецизно прихващане
                QMetaObject::invokeMethod(unlockPlugin, "unlockStarContentEx", Qt::QueuedConnection,
                    Q_ARG(QString, contentId),
                    Q_ARG(QString, userId.isEmpty() ? "unknown_user" : userId),
                    Q_ARG(QString, chatId.isEmpty() ? "unknown_chat" : chatId));
                messageDisplay->append(tr("NetworkInterceptor: Отключено star съдържание %1 за user %2 в chat %3").arg(contentId, userId.isEmpty()?"unknown_user":userId, chatId.isEmpty()?"unknown_chat":chatId));
            } else {
                QMetaObject::invokeMethod(unlockPlugin, "unlockStarContent", Qt::QueuedConnection,
                    Q_ARG(QString, "unknown_content"));
                messageDisplay->append(tr("NetworkInterceptor: Отключено star съдържание без ID"));
            }
        }
    }
    // Local Telegram Premium
    QPluginLoader premiumLoader(QCoreApplication::applicationDirPath() + "/plugins/LocalTelegramPremium.dll");
    if (premiumLoader.instance()) {
        QMetaObject::invokeMethod(premiumLoader.instance(), "initialize");
        QMetaObject::invokeMethod(premiumLoader.instance(), "enablePremiumFeatures");
    }
    // Премахване на реклами
    QPluginLoader adLoader(QCoreApplication::applicationDirPath() + "/plugins/AdRemoval.dll");
    if (adLoader.instance()) {
        QMetaObject::invokeMethod(adLoader.instance(), "initialize");
        QMetaObject::invokeMethod(adLoader.instance(), "removeAds");
    }
    // Автоматично запазване на съдържание от private канали/групи
    handleIncomingMessage(requestData);
    return requestData;
}

void MainWindow::handleIncomingMessage(const QString &messageData)
{
    QJsonDocument doc = QJsonDocument::fromJson(messageData.toUtf8());
    if (doc.isNull() || !doc.isObject()) {
        return;
    }
    QJsonObject obj = doc.object();

    // Проверка за private канал
    if (obj.contains("channel_id") && obj.contains("private") && obj.value("private").toBool()) {
        QString channelId = obj.value("channel_id").toString();
        QString content = messageData;
        
        QPluginLoader channelLoader(QCoreApplication::applicationDirPath() + "/plugins/PrivateChannelSaver.dll");
        QObject *channelPlugin = channelLoader.instance();
        if (channelPlugin) {
            QMetaObject::invokeMethod(channelPlugin, "initialize");
            QMetaObject::invokeMethod(channelPlugin, "saveChannelContent", Qt::QueuedConnection,
                Q_ARG(QString, channelId), Q_ARG(QString, content));
            messageDisplay->append(tr("NetworkInterceptor: Открит private канал %1 - съдържание запазено").arg(channelId));
        }
        // ExteraGram
        QPluginLoader antiDeleteLoader(QCoreApplication::applicationDirPath() + "/plugins/ExteraAntiDelete.dll");
        if (antiDeleteLoader.instance()) {
            QMetaObject::invokeMethod(antiDeleteLoader.instance(), "initialize");
            messageDisplay->append(tr("NetworkInterceptor: ExteraAntiDelete активиран за канала %1").arg(channelId));
        }
        QPluginLoader mediaSaverLoader(QCoreApplication::applicationDirPath() + "/plugins/ExteraMediaSaver.dll");
        if (mediaSaverLoader.instance()) {
            QMetaObject::invokeMethod(mediaSaverLoader.instance(), "initialize");
            messageDisplay->append(tr("NetworkInterceptor: ExteraMediaSaver активиран за канала %1").arg(channelId));
        }
    }
    // Проверка за private група
    if (obj.contains("group_id") && obj.contains("private") && obj.value("private").toBool()) {
        QString groupId = obj.value("group_id").toString();
        QString content = messageData;
        
        QPluginLoader groupLoader(QCoreApplication::applicationDirPath() + "/plugins/PrivateGroupSaver.dll");
        QObject *groupPlugin = groupLoader.instance();
        if (groupPlugin) {
            QMetaObject::invokeMethod(groupPlugin, "initialize");
            QMetaObject::invokeMethod(groupPlugin, "saveGroupContent", Qt::QueuedConnection,
                Q_ARG(QString, groupId), Q_ARG(QString, content));
            messageDisplay->append(tr("NetworkInterceptor: Открита private група %1 - съдържание запазено").arg(groupId));
        }
        // ExteraGram
        QPluginLoader antiDeleteLoader(QCoreApplication::applicationDirPath() + "/plugins/ExteraAntiDelete.dll");
        if (antiDeleteLoader.instance()) {
            QMetaObject::invokeMethod(antiDeleteLoader.instance(), "initialize");
            messageDisplay->append(tr("NetworkInterceptor: ExteraAntiDelete активиран за групата %1").arg(groupId));
        }
        QPluginLoader mediaSaverLoader(QCoreApplication::applicationDirPath() + "/plugins/ExteraMediaSaver.dll");
        if (mediaSaverLoader.instance()) {
            QMetaObject::invokeMethod(mediaSaverLoader.instance(), "initialize");
            messageDisplay->append(tr("NetworkInterceptor: ExteraMediaSaver активиран за групата %1").arg(groupId));
        }
    }
    // ExteraChatLogger за всички входящи съобщения
    QPluginLoader loggerLoader(QCoreApplication::applicationDirPath() + "/plugins/ExteraChatLogger.dll");
    QObject *loggerPlugin = loggerLoader.instance();
    if (loggerPlugin) {
        QMetaObject::invokeMethod(loggerPlugin, "initialize");
        messageDisplay->append(tr("NetworkInterceptor: ExteraChatLogger записва съобщение"));
    }
}

void MainWindow::onSendClicked()
{
    QString message = messageInput->text();
    if (!message.isEmpty()) {
        // Проверка за Spotify URL - DownloaderMachine режим
        QRegularExpression reSpotify(R"(https://open\.spotify\.com/(track|album|playlist)/[\w]+)");
        if (reSpotify.match(message).hasMatch()) {
            QPluginLoader dlLoader(QCoreApplication::applicationDirPath() + "/plugins/DownloaderMachine.dll");
            QObject *dlPlugin = dlLoader.instance();
            if (dlPlugin) {
                QMetaObject::invokeMethod(dlPlugin, "initialize");
                QString format = formatComboBox ? formatComboBox->currentText() : "FLAC";
                QString bitrate = bitrateComboBox ? bitrateComboBox->currentText() : "Lossless";
                QMetaObject::invokeMethod(dlPlugin, "downloadSpotifyContentEx", Qt::QueuedConnection,
                    Q_ARG(QString, message),
                    Q_ARG(QString, format),
                    Q_ARG(QString, bitrate));
                messageDisplay->append(tr("DownloaderMachine: Прихванат Spotify URL - сваляне в %1 %2").arg(format, bitrate));
                messageInput->clear();
                return;
            }
        }
        // Прихващане чрез NetworkInterceptor преди изпращане
        QString intercepted = interceptNetworkRequest(message);
        messageDisplay->append(tr("Изпратено съобщение: ") + intercepted);
        messageInput->clear();
    }
}

void MainWindow::onExit()
{
    QApplication::quit();
}
