#include "ayu_translator.h"

AyuTranslator& AyuTranslator::instance() {
    static AyuTranslator instance;
    return instance;
}

AyuTranslator::AyuTranslator(QObject *parent) : QObject(parent), translator(nullptr) {}

AyuTranslator::~AyuTranslator() {
    delete translator;
}

void AyuTranslator::initializeTranslator() {
    translator = new QTranslator(this);
}

QString AyuTranslator::translateText(const QString& text) {
    if (translator) {
        return translator->translate("MainWindow", text.toUtf8().constData());
    }
    return text;
}

void AyuTranslator::setTranslationProvider(const QString& provider) {
    currentProvider = provider;
}

QString AyuTranslator::getTranslationProvider() const {
    return currentProvider;
}

void AyuTranslator::clearCache() {
    translationCache.clear();
}

bool AyuTranslator::loadTranslationFile(const QString& language, const QString& filename) {
    if (translator->load(filename, language)) {
        return true;
    }
    return false;
}