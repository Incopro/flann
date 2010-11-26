/***********************************************************************
 * Software License Agreement (BSD License)
 *
 * Copyright 2008-2009  Marius Muja (mariusm@cs.ubc.ca). All rights reserved.
 * Copyright 2008-2009  David G. Lowe (lowe@cs.ubc.ca). All rights reserved.
 *
 * THE BSD LICENSE
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *************************************************************************/

#include "saving.h"

namespace flann
{

template<> flann_datatype_t get_flann_datatype<char>() { return FLANN_INT8; }
template<> flann_datatype_t get_flann_datatype<short>() { return FLANN_INT16; }
template<> flann_datatype_t get_flann_datatype<int>() { return FLANN_INT32; }
template<> flann_datatype_t get_flann_datatype<unsigned char>() { return FLANN_UINT8; }
template<> flann_datatype_t get_flann_datatype<unsigned short>() { return FLANN_UINT16; }
template<> flann_datatype_t get_flann_datatype<unsigned int>() { return FLANN_UINT32; }
template<> flann_datatype_t get_flann_datatype<float>() { return FLANN_FLOAT32; }
template<> flann_datatype_t get_flann_datatype<double>() { return FLANN_FLOAT64; }


const char FLANN_SIGNATURE[] = "FLANN_INDEX";
const char FLANN_VERSION[] = "1.5.0";


IndexHeader load_header(FILE* stream)
{
	IndexHeader header;
	int read_size = fread(&header,sizeof(header),1,stream);

	if (read_size!=1) {
		throw FLANNException("Invalid index file, cannot read");
	}

	if (strcmp(header.signature,FLANN_SIGNATURE)!=0) {
		throw FLANNException("Invalid index file, wrong signature");
	}

	return header;

}

}