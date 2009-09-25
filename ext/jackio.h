/*
  Copyright (C) 2003-2009 Paul Brossier <piem@aubio.org>

  This file is part of aubio.

  aubio is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  aubio is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with aubio.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef JACKIO_H
#define JACKIO_H

/** 
 * @file
 *
 * Jack driver for aubio
 * 
 */

#ifdef __cplusplus
extern "C"
{
#endif

/** jack object */
typedef struct _aubio_jack_t aubio_jack_t;
/** jack process function */
typedef int (*aubio_process_func_t) (smpl_t ** input,
    smpl_t ** output, int nframes);

/** jack device creation function */
aubio_jack_t *new_aubio_jack (uint_t inchannels, uint_t outchannels,
    uint_t imidichan, uint_t omidichan,
    aubio_process_func_t callback);
/** activate jack client (run jackprocess function) */
uint_t aubio_jack_activate (aubio_jack_t * jack_setup);
/** close and delete jack client */
void aubio_jack_close (aubio_jack_t * jack_setup);

#ifdef __cplusplus
}
#endif

#endif                          /* JACKIO_H */
