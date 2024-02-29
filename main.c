#include <stdio.h>

#include <raylib.h>

#define COLOR_BACKGROUND GetColor(0x181818FF)

int main(void)
{
    size_t screen = 80;
    InitAudioDevice();
    InitWindow(screen*16, screen*9, "Music Player");
    SetTargetFPS(60);

    Music music = LoadMusicStream("");
    PlayMusicStream(music);

    // int w = GetScreenWidth();
    // int h = GetScreenHeight();

    while (!WindowShouldClose()) {
        UpdateMusicStream(music);
        BeginDrawing();
        {     
            ClearBackground(COLOR_BACKGROUND);

            DrawText("Drop music here", screen*5.5/2, screen*7.5/2, 100, WHITE);

            if (IsFileDropped()) {
                FilePathList droppedFiles = LoadDroppedFiles();
                for (size_t i = 0; i < droppedFiles.count; ++i) {
                    music = LoadMusicStream(droppedFiles.paths[i]);
                    printf("Imprimiendo DroppedFiles = %s\n", droppedFiles.paths[i]);
                }

                UnloadDroppedFiles(droppedFiles);
                PlayMusicStream(music);
				SetMusicVolume(music, 1.0f);
            }

            if (IsKeyPressed(KEY_SPACE)) {
                if (IsMusicStreamPlaying(music)) {
                    PauseMusicStream(music);
                } else {
                    ResumeMusicStream(music);
                }
            }
        }
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}
