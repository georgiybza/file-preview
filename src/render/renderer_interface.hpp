#ifndef RENDERER_INTERFACE_HPP
#define RENDERER_INTERFACE_HPP

#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QApplication>
#include <QString>

class Renderer {
public:
    virtual ~RendererInterface() = default;
    virtual void open(const QString &filePath) = 0;
    virtual void show() = 0;
    virtual void close() = 0;
};

#endif

