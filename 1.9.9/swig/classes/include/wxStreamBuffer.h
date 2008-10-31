// wxStreamBuffer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStreamBuffer_h_)
#define _wxStreamBuffer_h_
class wxStreamBuffer
{
public:
	/**
	 * \brief Constructor, creates a new stream buffer using   as a parent stream
and   as the IO mode.   can be: wxStreamBuffer::read,
wxStreamBuffer::write, wxStreamBuffer::read_write.

One stream can have many stream buffers but only one is used internally to
pass IO call (e.g. wxInputStream::Read() -&gt; wxStreamBuffer::Read()), but you
can call directly wxStreamBuffer::Read without any problems. Note that
all errors and messages linked to the stream are stored in the stream, not
the stream buffers: 
	 * \param wxStreamBase&  
	 * \param BufMode  
	*/

   wxStreamBuffer(wxStreamBase&  stream , BufMode  mode ) ;
	/**
	 * \brief Constructor, creates a new empty stream buffer which won't flush any data
to a stream.   specifies the type of the buffer (read, write, read_write).
This stream buffer has the advantage to be stream independent and to
work only on memory buffers but it is still compatible with the rest of the
wxStream classes. You can write, read to this special stream and it will
grow (if it is allowed by the user) its internal buffer. Briefly, it has all
functionality of a ``normal'' stream.

\wxheading{Warning}

The &quot;read_write&quot; mode may not work: it isn't completely finished. 
	 * \param BufMode  
	*/

   wxStreamBuffer(BufMode  mode ) ;
	/**
	 * \brief Constructor. It initializes the stream buffer with the data of the specified
stream buffer. The new stream buffer has the same attributes, size, position
and they share the same buffer. This will cause problems if the stream to
which the stream buffer belong is destroyed and the newly cloned stream
buffer continues to be used, trying to call functions in the (destroyed)
stream. It is advised to use this feature only in very local area of the
program. 
	 * \param const wxStreamBuffer&  
	*/

   wxStreamBuffer(const wxStreamBuffer& buffer ) ;
	/**
	 * \brief Destructor. It finalizes all IO calls and frees all internal buffers if
necessary. 
	*/

  virtual  ~wxStreamBuffer() ;
	/**
	 * \brief Reads a block of the specified   and stores the data in  .
This function tries to read from the buffer first and if more data has been
requested, reads more data from the associated stream and updates the buffer
accordingly until all requested data is read. 
	 * \param void *  
	 * \param size_t   
	*/

  size_t Read(void * buffer , size_t  size ) ;
	/**
	 * \brief Reads a  . The function returns when   is full or when there isn't
data anymore in the current buffer. 
	 * \param wxStreamBuffer *  
	*/

  size_t Read(wxStreamBuffer * buffer ) ;
	/**
	 * \brief Writes a block of the specified   using data of  . The data
are cached in a buffer before being sent in one block to the stream. 
	 * \param const void *  
	 * \param size_t   
	*/

  size_t Write(const void * buffer , size_t  size ) ;
	/**
	 * \brief See  . 
	 * \param wxStreamBuffer *  
	*/

  size_t Write(wxStreamBuffer * buffer ) ;
	/**
	 * \brief Gets a single char from the stream buffer. It acts like the Read call.

\wxheading{Problem}

You aren't directly notified if an error occurred during the IO call. 
	*/

  char GetChar() ;
	/**
	 * \brief Puts a single char to the stream buffer.

\wxheading{Problem}

You aren't directly notified if an error occurred during the IO call. 
	 * \param char   
	*/

  void PutChar(char  c ) ;
	/**
	 * \brief Gets the current position in the stream. This position is calculated from
the   position in the stream and from the internal buffer position: so
it gives you the position in the   stream counted from the start of
the stream. 
	*/

  off_t Tell() const;
	/**
	 * \brief Changes the current position.

  may be one of the following:

\twocolwidtha{5cm} 
	 * \param off_t   
	 * \param wxSeekMode   
	*/

  off_t Seek(off_t  pos , wxSeekMode  mode ) ;
	/**
	 * \brief Resets to the initial state variables concerning the buffer. 
	*/

  void ResetBuffer() ;
	/**
	 * \brief Specifies which pointers to use for stream buffering. You need to pass a pointer on the
start of the buffer end and another on the end. The object will use this buffer
to cache stream data. It may be used also as a source/destination buffer when
you create an empty stream buffer (See  ). 
	 * \param char*  
	 * \param char*  
	*/

  void SetBufferIO(char*  buffer_start , char*  buffer_end ) ;
	/**
	 * \brief Destroys or invalidates the previous IO buffer and allocates a new one of the
specified size.

\wxheading{Warning}

All previous pointers aren't valid anymore.

\wxheading{Remark}

The created IO buffer is growable by the object. 
	 * \param size_t  
	*/

  void SetBufferIO(size_t  bufsize ) ;
	/**
	 * \brief Returns a pointer on the start of the stream buffer. 
	*/

  char * GetBufferStart() const;
	/**
	 * \brief Returns a pointer on the end of the stream buffer. 
	*/

  char * GetBufferEnd() const;
	/**
	 * \brief Returns a pointer on the current position of the stream buffer. 
	*/

  char * GetBufferPos() const;
	/**
	 * \brief Returns the current position (counted in bytes) in the stream buffer. 
	*/

  off_t GetIntPosition() const;
	/**
	 * \brief Sets the current position (in bytes) in the stream buffer.

\wxheading{Warning}

Since it is a very low-level function, there is no check on the position:
specify an invalid position can induce unexpected results. 
	*/

  void SetIntPosition() ;
	/**
	 * \brief Returns the amount of bytes read during the last IO call to the parent stream. 
	*/

  size_t GetLastAccess() const;
	/**
	 * \brief Toggles the fixed flag. Usually this flag is toggled at the same time as 
 . This flag allows (when it has the false value) or forbids
(when it has the true value) the stream buffer to resize dynamically the IO buffer. 
	 * \param bool  
	*/

  void Fixed(bool  fixed ) ;
	/**
	 * \brief Toggles the flushable flag. If   is disabled, no data are sent
to the parent stream. 
	 * \param bool  
	*/

  void Flushable(bool  flushable ) ;
	/**
	 * \brief Flushes the IO buffer. 
	*/

  bool FlushBuffer() ;
	/**
	 * \brief Fill the IO buffer. 
	*/

  bool FillBuffer() ;
	/**
	 * \brief Returns the amount of available data in the buffer. 
	*/

  size_t GetDataLeft() ;
	/**
	 * \brief Returns the parent stream of the stream buffer. 
	*/

  wxStreamBase* Stream() ;
};


#endif
