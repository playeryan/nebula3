#pragma once
#ifndef MESSAGING_MESSAGEWRITER_H
#define MESSAGING_MESSAGEWRITER_H
//------------------------------------------------------------------------------
/**
    @class Messaging::MessageWriter
  
    Implements a binary stream protocol for encoding messages into streams.
    
    (C) 2006 Radon Labs GmbH
*/
#include "io/streamwriter.h"
#include "io/binarywriter.h"

//------------------------------------------------------------------------------
namespace Messaging
{
class Message;

class MessageWriter : public IO::StreamWriter
{
    DeclareClass(MessageWriter);
public:
    /// constructor
    MessageWriter();
    /// set stream to write to
    virtual void SetStream(const Ptr<IO::Stream>& s);
    /// write a complete message to the stream
    void WriteMessage(const Ptr<Message>& msg);

private:
    Ptr<IO::BinaryWriter> binaryWriter;
};

} // namespace Messaging
//------------------------------------------------------------------------------
#endif