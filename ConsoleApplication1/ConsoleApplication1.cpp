#include <iostream>
#include <cstring>

char* encrypt(char* rawText, int key);
char* decrypt(char* encryptedText, int key);

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
    int len = std::strlen(rawText);
    char* encryptedText = new char[len + 1];

    for (int i = 0; i < len; ++i) {
        encryptedText[i] = encryptChar(rawText[i], key);
    }
    encryptedText[len] = '\0';

    return encryptedText;
}

char* decrypt(char* encryptedText, int key) {
    int len = std::strlen(encryptedText);
    char* decryptedText = new char[len + 1];

    for (int i = 0; i < len; ++i) {
        decryptedText[i] = decryptChar(encryptedText[i], key);
    }
    decryptedText[len] = '\0';

    return decryptedText;
}

int main() {
    char text[] = "Hello, World!";
    int key = 1;
    char* encrypted = encrypt(text, key);
    std::cout << "Encrypted Text: " << encrypted << std::endl;

    char* decrypted = decrypt(encrypted, key);
    std::cout << "Decrypted Text: " << decrypted << std::endl;

    delete[] encrypted;
    delete[] decrypted;

    return 0;
}
