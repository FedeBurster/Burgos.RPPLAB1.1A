#ifndef COLOR_H
#define COLOR_H
struct {
    int colorId;
    char colorNombre[20];
}typedef eColor;

int listarColores(eColor *colores,int length);

#endif
