#include "renderer_interface.hpp"

class TextRenderer: public QObject, public RendererInterface {
public:
    void open(const QString &filePath) override {
        // Open
    }
    void show() override {
        // Show
    }
    void close() override {
        // Close
    }
}