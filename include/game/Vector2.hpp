#pragma once

class Vector2 {
    public:
        Vector2(int x, int y);
        void SetX(int x);
        void SetY(int y);
        void Set(int x, int y);
        int GetX();
        int GetY();
    private:
        int x;
        int y;
};