#include <raylib.h>

int main() 
{
    const Color darkGreen = {20, 160, 133, 255};
    
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    // Rectangle properties
    Rectangle rect = { screenWidth / 2 - 50, screenHeight / 2 - 25, 100, 50 }; // x, y, width, height
    const char* name = "Roshan"; // Your name or any text
    
    // Rectangle movement speed
    Vector2 speed = { 5, 4 };

    InitWindow(screenWidth, screenHeight, "Rectangle with Name");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        // Update rectangle position (simple bounce logic)
        rect.x += speed.x;
        rect.y += speed.y;

        if (rect.x <= 0 || rect.x + rect.width >= screenWidth) speed.x *= -1;
        if (rect.y <= 0 || rect.y + rect.height >= screenHeight) speed.y *= -1;

        BeginDrawing();
            ClearBackground(darkGreen);

            // Draw rectangle
            DrawRectangleRec(rect, RAYWHITE);

            // Draw name centered inside rectangle
            int fontSize = 20;
            int textWidth = MeasureText(name, fontSize);
            int textX = rect.x + (rect.width / 2) - (textWidth / 2);
            int textY = rect.y + (rect.height / 2) - (fontSize / 2);
            DrawText(name, textX, textY, fontSize, BLACK);

        EndDrawing();
    }
    
    CloseWindow();
}
