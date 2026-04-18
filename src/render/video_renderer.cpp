#include "renderer_interface.hpp"

VideoRenderer::VideoRenderer() {
    player = std::make_unique<QMediaPlayer>();
    audioOutput = std::make_unique<QAudioOutput>();
    videoWidget = std::make_unique<QVideoWidget>();
    player->setAudioOutput(audioOutput.get());
    player->setVideoOutput(videoWidget.get());
    player->setLoops(QMediaPlayer::Infinite); // TODO: Allow User To Choose Video TimeStamp
}
void VideoRenderer::open(const QString &filePath) override {
    player->setSource(QUrl::fromLocalFile(filePath));

}
void VideoRenderer::show() override {
    videoWidget->show();
    player->play();
}
void VideoRenderer::close() override {
    player->stop();
    videoWidget->hide();
}
void VideoRenderer::setLooping(bool loop) { // TODO: Might Need To Make Pointer (If Null State Available)
    player->setLoops(loop ? QMediaPlayer::Infinite : 1)
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    VideoRenderer renderer;
    return app.exec();
}