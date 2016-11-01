/***
    This file is part of snapcast
    Copyright (C) 2014-2016  Johannes Pohl

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/

#ifndef SPOTIFY_STREAM_H
#define SPOTIFY_STREAM_H

#include "processStream.h"


/// Starts librespot and reads and PCM data from stdout
/**
 * Starts librespot, reads PCM data from stdout, and passes the data to an encoder.
 * Implements EncoderListener to get the encoded data.
 * Data is passed to the PcmListener
 */
class SpotifyStream : public ProcessStream
{
public:
	/// ctor. Encoded PCM data is passed to the PipeListener
	SpotifyStream(PcmListener* pcmListener, const StreamUri& uri);
	virtual ~SpotifyStream();

protected:
	virtual void onStderrMsg(const char* buffer, size_t n);
	virtual void initExeAndPath(const std::string& filename);
};


#endif