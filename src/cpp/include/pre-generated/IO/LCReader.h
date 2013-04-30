// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef IO_LCREADER_H
#define IO_LCREADER_H 1

#include <string>
#include <vector>

#include "EVENT/LCEvent.h"
#include "EVENT/LCRunHeader.h"
#include "Exceptions.h"
#include "LCIOSTLTypes.h"

namespace IO {

class LCEventListener;
class LCRunListener;

/**Interface for reading data from LCIO.
 * Use LCFactory to instantiate a corresponding LCWriter object
 * for the output format at hand (SIO only, so far).
 *
 * @see LCFactory
 * 
 * @author gaede
 * @version Mar 4, 2003
 */
class LCReader {

public: 
    /// Destructor.
    virtual ~LCReader() { /* nop */; }

    /** Configuration flags for the LCReader instance - to be used with LCFactory::createLCReader(). */
          

    static const int directAccess =  0x00000001 << 0  ;
    /** Opens a file for reading (read-only).
     *
     * @throws IOException
     */
    virtual void open(const std::string & filename) throw (IOException, std::exception )  = 0;

    /** Opens a list of files for reading (read-only). All subsequent
     * read operations will operate on the list, i.e. if an EOF is encountered
     * the next file in the list will be opened and read transparently to the
     * user.
     *
     * @throws IOException
     */
    virtual void open(const std::vector<std::string>  & filenames) throw (IOException, std::exception )  = 0;

    /** Reads the next run header from the file. Returns NULL if
     * 'EOF' read. 
     *
     * @throws IOException
     */
    virtual EVENT::LCRunHeader * readNextRunHeader() throw (IOException, std::exception )  = 0;

    /** Same as readNextRunHeader() but allows to set the access mode 
     *  LCIO::READ_ONLY (default) or LCIO::Update. 
     *
     * @throws IOException
     */
    virtual EVENT::LCRunHeader * readNextRunHeader(int accessMode) throw (IOException, std::exception )  = 0;

    /** Reads the next event from the file. Returns NULL if
     * 'EOF' read. 
     *
     * @throws IOException
     */
    virtual EVENT::LCEvent * readNextEvent() throw (IOException, std::exception )  = 0;

    /** Same as readNextEvent() but allows to set the access mode 
     *  LCIO::READ_ONLY (default) or LCIO::Update. 
     *
     * @throws IOException
     */
    virtual EVENT::LCEvent * readNextEvent(int accessMode) throw (IOException, std::exception )  = 0;

    /** Return the number of events in the file - the file has to be open. In
     *  case several input files are specified in the open() method - 
     *  the number of events in the file that is currently open is returned. 
     */
    virtual int getNumberOfEvents() throw (IOException, std::exception )  = 0;

    /** Return the number of runs (run headers) in the file - the file has to be open. In
     *  case several input files are specified in the open() method - 
     *  the number of runs (run headers) in the file that is currently open is returned. 
     */
    virtual int getNumberOfRuns() throw (IOException, std::exception )  = 0;

    /** Return the run numbers of the runs (run headers) in the file - the file has to be open. In
     *  case several input files are specified in the open() method - 
     *  the run numbers of the runs (run headers) in the file that is currently open is returned. 
     */
    virtual void getRuns(EVENT::IntVec & runs) = 0;

    /** Return the run and event numbers of the events in the file - the file has to be open. In
     *  case several input files are specified in the open() method - 
     *  the  run and event numbers of the events in the file that is currently open are returned.
     *  The size of the vector events will be twice the number of events, where i-th run number
     *  will be in events[2*i] and the i-th event number in  events[2*i+].
     */
    virtual void getEvents(EVENT::IntVec & events) = 0;

  /** Skips the next n events from the current position.
     * @throws IOException
     */
    virtual void skipNEvents(int n) throw (IOException, std::exception )  = 0;

    /** Reads the specified runHeader from file. Returns NULL if
     *  the specified runHeader hasn't been found in the file.
     *
     * @throws IOException
     */
    virtual EVENT::LCRunHeader * readRunHeader(int runNumber) throw (IOException, std::exception )  = 0;

    /** Same as LCEvent* readRunHeader(int runNumber) 
     *  allowing to set the access mode LCIO::READ_ONLY (default) or LCIO::Update.
     *
     * @throws IOException
     */
    virtual EVENT::LCRunHeader * readRunHeader(int runNumber, int accessMode) throw (IOException, std::exception )  = 0;

    /** Reads the specified event from file. Returns NULL if
     *  the specified event hasn't been found in the file.
     *
     * @throws IOException
     */
    virtual EVENT::LCEvent * readEvent(int runNumber, int evtNumber) throw (IOException, std::exception )  = 0;

    /** Same as LCEvent* readEvent(int runNumber, int evtNumber) 
     *  allowing to set the access mode LCIO::READ_ONLY (default) or LCIO::Update.
     *
     * @throws IOException
     */
    virtual EVENT::LCEvent * readEvent(int runNumber, int evtNumber, int accessMode) throw (IOException, std::exception )  = 0;

    /** Closes the output file/stream etc.
     *
     * @throws IOException
     */
    virtual void close() throw (IOException, std::exception )  = 0;

    /** Registers a listener for reading LCEvents from a stream.
     */ 
    virtual void registerLCEventListener(LCEventListener * ls) = 0;

    /** Remove a listener for reading LCEvents from a stream.
     */ 
    virtual void removeLCEventListener(LCEventListener * ls) = 0;

    /** Registers a listener for reading LCEventsLCRunHeaders from a stream.
     */ 
    virtual void registerLCRunListener(LCRunListener * ls) = 0;

    /** Remove a listener for reading LCRunHeaders from a stream.
     */ 
    virtual void removeLCRunListener(LCRunListener * ls) = 0;

    /** Reads the input stream and notifies registered 
     * listeners according to the object type 
     * found in the stream. 
     *
     * @throws IOException
     */
    virtual void readStream() throw (IOException, std::exception )  = 0;

    /** Reads maxRecord from the input stream and notifies registered 
     * listeners according to the object type found in the stream.
     * An exception is thrown if less than maxRecord where read from the file.
     *
     * @throws IOException
     */
    virtual void readStream(int maxRecord) throw (IOException, std::exception )  = 0;
}; // class
} // namespace IO
#endif /* ifndef IO_LCREADER_H */
