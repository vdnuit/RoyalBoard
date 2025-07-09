// Color.h
#ifndef COLOR_H
#define COLOR_H

enum class Color {
    WHITE,
    BLACK
};

inline Color opposite(Color color) {
    return (color == Color::WHITE) ? Color::BLACK : Color::WHITE;
}

#endif // COLOR_H
