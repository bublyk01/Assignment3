#include <iostream>
#include <cstring>
#include "pch.h"

extern "C" __declspec(dllexport) char* encrypt(char* rawText, int key);
extern "C" __declspec(dllexport) char* decrypt(char* encryptedText, int key);

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

char* encrypt(char* rawText, int key) {
    size_t len = strlen(rawText);
    char* encryptedText = new char[len + 1];

    for (size_t i = 0; i < len; ++i) {
        encryptedText[i] = encryptChar(rawText[i], key);
    }
    encryptedText[len] = '\0';

    return encryptedText;
}

char* decrypt(char* encryptedText, int key) {
    size_t len = strlen(encryptedText);
    char* decryptedText = new char[len + 1];

    for (size_t i = 0; i < len; ++i) {
        decryptedText[i] = decryptChar(encryptedText[i], key);
    }
    decryptedText[len] = '\0';

    return decryptedText;
}
