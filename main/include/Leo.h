#pragma once
#ifndef LEO_H
#define LEO_H

class Leo
{
    private:
        int _vida; // Leo tiene 1 0 3 vidas?

    public:
        Leo();
        int getVida();
        void setVida(int v);
};

#endif // LEO_H

