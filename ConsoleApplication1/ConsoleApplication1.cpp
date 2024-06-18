#include <iostream>
#include <cstring>

char* encrypt(char* rawText, int key);

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

char* encrypt(char* rawText, int key) {
    int len = std::strlen(rawText);
    char* encryptedText = new char[len + 1];

    for (int i = 0; i < len; ++i) {
        encryptedText[i] = encryptChar(rawText[i], key);
    }
    encryptedText[len] = '\0';

    return encryptedText;
}

int main() {
    char text[] = "Hello, World!";
    int key = 1;
    char* encrypted = encrypt(text, key);
    std::cout << "Encrypted Text: " << encrypted << std::endl;
    delete[] encrypted;
    return 0;
}
