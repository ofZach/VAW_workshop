/*
	 Copyright (C) 2003 Paul Brossier

	 This program is free software; you can redistribute it and/or modify
	 it under the terms of the GNU General Public License as published by
	 the Free Software Foundation; either version 2 of the License, or
	 (at your option) any later version.

	 This program is distributed in the hope that it will be useful,
	 but WITHOUT ANY WARRANTY; without even the implied warranty of
	 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	 GNU General Public License for more details.

	 You should have received a copy of the GNU General Public License
	 along with this program; if not, write to the Free Software
	 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
	 */

/** @file
 *
 * Histogram function
 *
 * Big hacks to implement an histogram
 */

#ifndef HIST_H
#define HIST_H

#ifdef __cplusplus
extern "C" {
#endif

/** histogram object */
typedef struct _aubio_hist_t aubio_hist_t;

/** histogram creation 
 * \param flow minimum input
 * \param fhig maximum input
 * \param nelems number of histogram columns
 * \param channels number of channels 
 */
aubio_hist_t * new_aubio_hist(smpl_t flow, smpl_t fhig, ba_uint_t nelems, ba_uint_t channels);
/** histogram deletion */
void del_aubio_hist(aubio_hist_t *s);
/** compute the histogram */
void aubio_hist_do(aubio_hist_t *s, fvec_t * input);
/** compute the histogram ignoring null elements */
void aubio_hist_do_notnull(aubio_hist_t *s, fvec_t * input);
/** compute the mean of the histogram */
smpl_t aubio_hist_mean(aubio_hist_t *s); 
/** weight the histogram */
void aubio_hist_weigth(aubio_hist_t *s); 
/** compute dynamic histogram for non-null elements */
void aubio_hist_dyn_notnull (aubio_hist_t *s, fvec_t *input);

#ifdef __cplusplus
}
#endif

#endif
