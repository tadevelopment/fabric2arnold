#ifndef _INCLUDEALL_H_
#define _INCLUDEALL_H_

#pragma once

#include "ai.h"
#include "ai_params.h"

#include "_defines.h"
#include "Fabric2Arnold.h"

#ifdef __linux__ 
#define nullptr 0
#define static_assert(x,y) // not implemented in my version of gcc
#endif

#include "_typemapping_pod.h"
#include "_typemapping_class.h"
#include "_typemapping_opaque.h"
#include "_typemapping.h"

#include "_AtDisplayCallback.h"

#endif
