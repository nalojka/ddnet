#include <engine/storage.h>
#include <game/client/gameclient.h>

class CAssetsManager {
public:
    void LoadCustomTextures() {
        // Путь к папке с текстурами (рядом с exe)
        const char* pFolder = "NalojkaAssets";
        IStorage* pStorage = Storage();

        // Проверяем существование папки
        if(!pStorage->FolderExists(pFolder)) {
            pStorage->CreateFolder(pFolder); // Создаём, если нет
            return;
        }

        // Список файлов для замены
        const char* aFiles[] = {
            "hud.png", "logo.png", "buttons.png", "skin.png" // и т.д.
        };

        // Загружаем каждую текстуру
        for(const char* pFile : aFiles) {
            char aPath[256];
            str_format(aPath, sizeof(aPath), "%s/%s", pFolder, pFile);
            
            if(pStorage->FileExists(aPath)) {
                Graphics()->UnloadTexture(pFile); // Выгружаем старую
                Graphics()->LoadTexture(pFile, aPath); // Загружаем новую
            }
        }
    }
};
