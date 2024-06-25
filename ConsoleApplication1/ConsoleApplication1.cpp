#include <iostream>
#include <windows.h>

typedef char* (__cdecl* EncryptFunc)(char*, int);
typedef char* (__cdecl* DecryptFunc)(char*, int);

int main() {
    HINSTANCE hDll = LoadLibrary(TEXT("Dll1.dll"));
    if (hDll == NULL) {
        std::cerr << "Could not find the DLL." << std::endl;
        return EXIT_FAILURE;
    }

    EncryptFunc encrypt = (EncryptFunc)GetProcAddress(hDll, "encrypt");
    DecryptFunc decrypt = (DecryptFunc)GetProcAddress(hDll, "decrypt");

    if (!encrypt || !decrypt) {
        std::cerr << "Could not find the functions." << std::endl;
        FreeLibrary(hDll);
        return EXIT_FAILURE;
    }

    char phrase[] = "Hello, world!";
    int key = 1;

    char* encryptedText = encrypt(phrase, key);
    if (encryptedText) {
        std::cout << "Encrypted Text: " << encryptedText << std::endl;
    }
    else {
        std::cerr << "Could not encrypt" << std::endl;
    }

    char* decryptedText = decrypt(encryptedText, key);
    if (decryptedText) {
        std::cout << "Decrypted Text: " << decryptedText << std::endl;
        delete[] decryptedText;
    }
    else {
        std::cerr << "Could not decrypt." << std::endl;
    }

    delete[] encryptedText;
    FreeLibrary(hDll);
    return EXIT_SUCCESS;
}
