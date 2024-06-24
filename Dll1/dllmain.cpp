#ifdef DECRYPTIONDLL_EXPORTS
#define DECRYPTIONDLL_API __declspec(dllexport)
#else
#define DECRYPTIONDLL_API __declspec(dllimport)
#endif

extern "C" DECRYPTIONDLL_API char* encrypt(const char* rawText, int key);
extern "C" DECRYPTIONDLL_API char* decrypt(const char* encryptedText, int key);

char encryptChar(char ch, int key);
char decryptChar(char ch, int key);
