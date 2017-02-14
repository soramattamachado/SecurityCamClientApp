#ifndef SHAREDFRAMEBUFFER_H
#define SHAREDFRAMEBUFFER_H

#include <list>     // std::list
#include <mutex>    // std::mutex, std::unique_lock
#include "Frame.h"

class SharedFrameBuffer {
public:
    SharedFrameBuffer();
    SharedFrameBuffer(const SharedFrameBuffer& orig);
    virtual ~SharedFrameBuffer();
    void pushBackFrame(Frame frame);
    void assign(std::list<Frame> * frameBuffer);
    void assign(SharedFrameBuffer * frameBuffer);
    Frame popFrontFrame();
    Frame getFrontFrame();
    std::list<Frame> getFrameBuffer();
    bool empty();
    int size();
private:
    std::list<Frame> _frameBuffer;
    std::mutex _bufferMutex;
};

#endif /* SHAREDFRAMEBUFFER_H */

