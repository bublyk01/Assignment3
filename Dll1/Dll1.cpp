#include "pch.h"
#include "framework.h"
#include "Dll1.h"
#include <cstring>

extern "C" __declspec(dllexport) char* encrypt(const char* rawText, int key) {
    int len = std::strlen(rawText);
    char* encryptedText = new char[len + 1];

    for (int i = 0; i < len; ++i) {
        encryptedText[i] = encryptChar(rawText[i], key);
    }
    encryptedText[len] = '\0';

    return encryptedText;
}

extern "C" __declspec(dllexport) char* decrypt(const char* encryptedText, int key) {
    int len = std::strlen(encryptedText);
    char* decryptedText = new char[len + 1];

    for (int i = 0; i < len; ++i) {
        decryptedText[i] = decryptChar(encryptedText[i], key);
    }
    decryptedText[len] = '\0';

    return decryptedText;
}

char encryptChar(char ch, int key) {
    if (ch >= 'a' && ch <= 'z') {
        return 'a' + (ch - 'a' + key) % 26;
    }
    else if (ch >= 'A' && ch <= 'Z') {
        return 'A' + (ch - 'A' + key) % 26;
    }
    else {
        return ch;
    }
}

char decryptChar(char ch, int key) {
    if (ch >= 'a' && ch <= 'z') {
        return 'a' + (ch - 'a' - key + 26) % 26;
    }
    else if (ch >= 'A' && ch <= 'Z') {
        return 'A' + (ch - 'A' - key + 26) % 26;
    }
    else {
        return ch;
    }
}
