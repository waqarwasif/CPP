#ifndef HEADER_H
#define HEADER_H

void lifeup(int *score)
{
    *score += 100;
}

void lifeup_ref(int &score)
{
    score += 100;
}

template<typename T>
T add(T a, T b)
{
    return a + b;
}

#endif 