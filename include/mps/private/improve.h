/*
 * This file is part of MPSolve 3.1.5
 *
 * Copyright (C) 2001-2014, Dipartimento di Matematica "L. Tonelli", Pisa.
 * License: http://www.gnu.org/licenses/gpl.html GPL version 3 or higher
 *
 * Authors:
 *   Leonardo Robol <robol@mail.dm.unipi.it>
 */

/**
 * @file
 *
 * @brief Refining of isolated approximations by means of Newton method.
 */

#ifndef MPS_IMPROVE_H_
#define MPS_IMPROVE_H_

#include <mps/mps.h>

MPS_BEGIN_DECLS

void mps_improve (mps_context * s);

MPS_END_DECLS

#endif /* endif _MPS_IMPROVE_H */