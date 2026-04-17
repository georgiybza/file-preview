#include "renderer_interface.hpp"

class VideoRenderer {
private:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QAudioOutput *audioOutput;
public:
    VideoRenderer() {
        player = new QMediaPlayer;
        audioOutput = new QAudioOutput;
        videoWidget = new QVideoWidget;

        player->setAudioOutput(audioOutput);
        player->setVideoOutput(videoWidget);
        player->setSource(QUrl::fromLocalFile("../../tests/VideoFormats/SampleVideo.mp4"));
        player->setLoops(QMediaPlayer::Infinite); // TODO: Allow User To Choose Video TimeStamp

        videoWidget->show();
        player->play();
    }
    void setLooping(bool loop) { // TODO: Might Need To Make Pointer (If Null State Available)
            if (loop) {
                player->setLoops(-1);  // Qt6.2+ built-in loop
            } else {
                player->setLoops(1);
            }
        }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    VideoRenderer renderer;
    return app.exec();
}