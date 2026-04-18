#ifndef VIDEO_RENDERER_HPP
#define VIDEO_RENDERER_HPP

class VideoRenderer : public QObject, public RendererInterface {
private:
    std::unique_ptr<QMediaPlayer> player;
    std::unique_ptr<QVideoWidget> videoWidget;
    std::unqieu_ptr<QAudioOutput> audioOutput;

public:
    VideoRenderer();
    void open(const QString &filePath) override;
    void show() override;
    void close() override;
    void setUserConfigLooping(bool loop);

};

#endif