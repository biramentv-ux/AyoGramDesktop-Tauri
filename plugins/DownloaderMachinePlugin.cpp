#include "DownloaderMachinePlugin.h"
#include <QDebug>
#include <QRegularExpression>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>

DownloaderMachinePlugin::DownloaderMachinePlugin() : enabled(false) {}

DownloaderMachinePlugin::~DownloaderMachinePlugin() {}

QString DownloaderMachinePlugin::name() const {
    return "DownloaderMachine";
}

QString DownloaderMachinePlugin::version() const {
    return "1.0";
}

void DownloaderMachinePlugin::initialize() {
    enabled = true;
    qDebug() << "DownloaderMachine plugin initialized - режим за сваляне на Spotify съдържание";
}

void DownloaderMachinePlugin::unload() {
    enabled = false;
    qDebug() << "DownloaderMachine plugin unloaded";
}

bool DownloaderMachinePlugin::downloadSpotifyContent(const QString &url) {
    if (!enabled) return false;
    QRegularExpression reSpotify(R"(https://open\.spotify\.com/(track|album|playlist)/[\w]+)");
    if (!reSpotify.match(url).hasMatch()) {
        qDebug() << "DownloaderMachine: Невалиден Spotify URL";
        return false;
    }
    return downloadSpotifyContentEx(url, "FLAC", "Lossless");
}

bool DownloaderMachinePlugin::downloadSpotifyContentEx(const QString &url, const QString &format, const QString &bitrate) {
    if (!enabled) return false;
    QRegularExpression reSpotify(R"(https://open\.spotify\.com/(track|album|playlist)/([\w]+))");
    QRegularExpressionMatch match = reSpotify.match(url);
    if (!match.hasMatch()) {
        qDebug() << "DownloaderMachine: Невалиден Spotify URL";
        return false;
    }
    QString type = match.captured(1);
    QString id = match.captured(2);
    
    // Симулирани метаданни - в реална имплементация се извличат от Spotify API
    QString artistName = "Artist_" + id.left(6);
    QString albumName = (type == "album" || type == "playlist") ? "Album_" + id.left(6) : "Single_" + id.left(6);
    QString trackName = "Track_" + id.left(6);
    
    // Базова папка за сваляне
    QString baseDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Spotify_Downloads";
    
    // Създаване на подпапка по артисти/албум
    QString savePath = baseDir + "/" + type + "/" + artistName + "/" + albumName;
    QDir dir(savePath);
    if (!dir.exists()) {
        if (!dir.mkpath(savePath)) {
            qDebug() << "DownloaderMachine: Неуспешно създаване на директория" << savePath;
            return false;
        }
    }
    
    // Определяне на разширение по формат
    QString extension;
    QString fmtUpper = format.toUpper();
    if (fmtUpper == "FLAC") extension = "flac";
    else if (fmtUpper == "WAV") extension = "wav";
    else if (fmtUpper.startsWith("MP3")) extension = "mp3";
    else if (fmtUpper.startsWith("OGG")) extension = "ogg";
    else extension = "flac";
    
    QString fileName = trackName + "." + extension;
    QString filePath = savePath + "/" + fileName;
    
    // Симулирано създаване на файл
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write("Dummy audio content for " + format + " " + bitrate);
        file.close();
    }
    
    // Запис на метаданни в JSON
    QJsonObject meta;
    meta["url"] = url;
    meta["type"] = type;
    meta["id"] = id;
    meta["artist"] = artistName;
    meta["album"] = albumName;
    meta["track"] = trackName;
    meta["format"] = format;
    meta["bitrate"] = bitrate;
    meta["sample_rate"] = "44kHz"; // По подразбиране
    meta["bit_depth"] = "24-bit";   // По подразбиране
    meta["file_path"] = filePath;
    meta["download_date"] = QDateTime::currentDateTime().toString(Qt::ISODate);
    
    QJsonDocument doc(meta);
    QString metaPath = savePath + "/metadata.json";
    QFile metaFile(metaPath);
    if (metaFile.open(QIODevice::WriteOnly)) {
        metaFile.write(doc.toJson(QJsonDocument::Indented));
        metaFile.close();
    }
    
    qDebug() << "DownloaderMachine: Прихванат Spotify" << type << "URL:" << url;
    qDebug() << "DownloaderMachine: Сваляне в" << format << "с битрейт" << bitrate << "в папка" << savePath;
    qDebug() << "DownloaderMachine: Записан файл" << filePath << "и метаданни" << metaPath;
    
    return true;
}